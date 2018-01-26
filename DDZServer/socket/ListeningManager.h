// MUD Programming
// Ron Penton
// (C)2003
// ListningManager.h - This module contains the listening manager
// class, which manages incomming connections on a listening socket


#ifndef LISTENINGMANAGER_H
#define LISTENINGMANAGER_H


// ========================================================================
//  Include Files
// ========================================================================
#include "SocketLibTypes.h"
#include "SocketLibSocket.h"
#include "SocketSet.h"
#include "SocketLibErrors.h"
#include "ConnectionManager.h"
#include <vector>

namespace SocketLib
{

// Forward declarations
template<typename protocol>
class ConnectionManager;


// ====================================================================
// Description: This is the function that will be used when executing 
//              the listening thread
// ====================================================================


// ========================================================================
// Description: The listening manager class will manage up to 64 listening
//              sockets, monitoring all of them using select(). Whenever
//              a new socket is accepted, it is then sent to its 
//              accompanying connection manager.
// ========================================================================
template<typename protocol>
class ListeningManager
{
public:

    // ====================================================================
    // Description: ���һ�������˿�
    // ====================================================================
    void AddPort( port p_port );


    // ====================================================================
    // Description: ����һ�����ӹ�����
    // ====================================================================
    void SetConnectionManager( ConnectionManager<protocol>* p_manager );



    // ====================================================================
    // Description: �������пͻ�������
    // ====================================================================
    void Listen();

//private:
	// ====================================================================
	// Description: ��������������
	// ====================================================================
	ListeningManager();


	// ====================================================================
	// Description: �����������ر����м���socket
	// ====================================================================
	~ListeningManager();

protected:
    // ����socket��ÿ��ListeningSocket��Ӧ����һ���˿�
    std::vector<ListeningSocket> m_sockets;

    // ����poll
    SocketSet m_set;

    // ���ӹ��������ڹ���accept������
    ConnectionManager<protocol>* m_manager;
};






// ====================================================================
// Description: construct the manager
// ====================================================================
template<typename protocol>
ListeningManager<protocol>::ListeningManager()
{
    m_manager = 0;
}


// ====================================================================
// Description: The destructor should close all of the listening socks
// ====================================================================
template<typename protocol>
ListeningManager<protocol>::~ListeningManager()
{   
    // just close all the listening sockets
    for( size_t i = 0; i < m_sockets.size(); i++ )
    {
        m_sockets[i].Close();
    }
}


// ====================================================================
// Description: This adds a port to the manager
// ====================================================================
template<typename protocol>
void ListeningManager<protocol>::AddPort( port p_port )
{
    if( m_sockets.size() == MAX )
    {
        Exception e( ESocketLimitReached );
        throw( e );
    }

    // ����һ������socket
    ListeningSocket lsock;

    // �����˿�
    lsock.Listen( p_port );

    // ����Ϊ������ģʽ
    lsock.SetBlocking( false );

    // add the socket to the socket vector
    m_sockets.push_back( lsock );

    // add the socket descriptor to the set
    m_set.AddSocket( lsock );
}


// ====================================================================
// Description: This function tells the listening manager about which
//              connection manager it should use whenever a new
//              socket is accepted.
// ====================================================================
template<typename protocol>
void ListeningManager<protocol>::
SetConnectionManager( ConnectionManager<protocol>* p_manager )
{
    // set the new action function
    m_manager = p_manager;
}


template<typename protocol>
void ListeningManager<protocol>::Listen()
{
    // ����һ��socket���ڼ�������������
    DataSocket datasock;

    // detect if any sockets have action on them
    if( m_set.Poll() > 0 )
    {
        // loop through every listening socket
        for( size_t s = 0; s < m_sockets.size(); s++ )
        {
            // check to see if the current socket has a connection waiting
            if( m_set.HasActivity( m_sockets[s] ) )
            {
                try
                {
                    // ��������
                    datasock = m_sockets[s].Accept();					

                    // ���ӹ��������������
                    m_manager->NewConnection( datasock );
                }

                // catch any exceptions, and rethrow it if it isn't
                // EWOULDBLOCK. This is done because of a connection
                // exploit that is possible, by causing a socket to
                // detect a connection, but then not be able to retrieve
                // the connection once it gets to the accept call.
                // So, if the connection would block, this just ignores
                // it, but if any other error occurs, it is rethrown.
                catch( Exception& e )
                {
                    if( e.ErrorCode() != EOperationWouldBlock )
                    {
                        throw e;
                    }
                }
            }   // end activity check
        }   // end socket loop
    }   // end check for number of active sockets

}




}   // end namespace SocketLib


#endif
