// MUD Programming
// Ron Penton
// (C)2003
// ConnectionManager.h - The class that will manage connections.

#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <list>
#include <iostream>
#include "../thread/ThreadLib.h"
#include "SocketLibTypes.h"
#include "SocketLibErrors.h"
#include "SocketSet.h"
#include "Connection.h"
#include "../basic/GameLog.h"

namespace SocketLib
{

class IConnectionEvent
{
public:

	virtual void ConnectionClosed(DataSocket socket) = 0;

};

// Forward Declarations
template<typename protocol>
class ProtobufConnection;



// ============================================================================
// Description: This connection manager class will manage connections, 
// all identified with an ID. 
// ============================================================================
template<typename protocol>
class ConnectionManager
{

    typedef std::list< ProtobufConnection<protocol> > clist;
    typedef typename std::list< ProtobufConnection<protocol> >::iterator clistitr;

	typedef std::list< std::shared_ptr<IConnectionEvent> > listennerlist;
	typedef typename std::list< std::shared_ptr<IConnectionEvent> >::iterator listennerlistitr;

public:

    // ------------------------------------------------------------------------
	//  ͨ����������ʡ������С�ͷ���ʱ��������һ�����ӹ�����
    // ------------------------------------------------------------------------
    ConnectionManager( int p_maxdatarate = 1024,    // 1 kbyte/second
                       int p_sentimeout = 60,       // 60 seconds
                       int p_maxbuffered = 8192 );  // 8 kbytes

    // ------------------------------------------------------------------------
    //  �������ӹ��������ͷ���������
    // ------------------------------------------------------------------------
    ~ConnectionManager();


    // ------------------------------------------------------------------------
    //  ֪ͨ���ӹ������µ�����
    // ------------------------------------------------------------------------
    void NewConnection( DataSocket& p_socket );


    // ------------------------------------------------------------------------
    //  ��ȡ��ǰʣ����õ�������
    // ------------------------------------------------------------------------
    inline int AvailableConnections() const
    {
        return MAX - (int)m_connections.size();
    }

    // ------------------------------------------------------------------------
    //  ��ȡ��ǰ������
    // ------------------------------------------------------------------------
    inline int TotalConnections() const
    {
        return (int)m_connections.size();
    }

    // ------------------------------------------------------------------------
    //  �ͷ���Ч����
    // ------------------------------------------------------------------------
    void CloseConnections();


    // ------------------------------------------------------------------------
    //  ������������״̬���Ƿ���������Ҫ����
    // ------------------------------------------------------------------------
    void Listen();

    // ------------------------------------------------------------------------
    // Description: �����еĻ������ݶ�����
    // ------------------------------------------------------------------------
    void Send();

    // ------------------------------------------------------------------------
	// 1��������ӵ�socket�Ƿ���յ������ݣ��еĻ��������ݲ�������Ϣ����
	// 2�������������ͨ��socket���ͳ�ȥ
	// 3���ر�������Ч��socket
	// ps����Ϊ�Ƿ�����ģʽ�����Բ�������
    // ------------------------------------------------------------------------
    inline void Manage()
    {
        Listen();
        Send();
        CloseConnections();
    }

	// ------------------------------------------------------------------------
	// Description: �������ݵ�ָ��socket
	// ------------------------------------------------------------------------
	void SendMsg(int iSocket, void* pMsg);

	// ------------------------------------------------------------------------
	// Description: ��������¼��۲���
	// ------------------------------------------------------------------------
	void AddListener(std::shared_ptr<IConnectionEvent> pListenner)
	{
		m_listenners.push_back(pListenner);
	}

	// ------------------------------------------------------------------------
	// Description: ֪ͨ���й۲���
	// ------------------------------------------------------------------------
	void NotifyListenners(clistitr p_itr);

protected:
    // ------------------------------------------------------------------------
    //  This closes a connection within the connection manager; it is assumed
    //  that this is an external call- nothing needs to be notified about 
    //  the connection being closed.
    // ------------------------------------------------------------------------
    void Close( clistitr p_itr );



protected:

    // a list of all the connections within the manager
    clist m_connections;

    // This is the max allowable receiving datarate of the manager, in bytes per
    // second.
    int m_maxdatarate;

    // This is the amount of time in seconds that the manager allows for a socket to
    // successfully send data before it is forcibly closed.
    int m_sendtimeout;

    // This is the maximum number of bytes that are allowed to be buffered by
    // a connection before it is forcibly closed (only determined after a send)
    int m_maxbuffered;

    // a set of sockets that will be polled for socket activity.
    SocketSet m_set;

	// a list of all the listenner interest at connection status
	listennerlist m_listenners;
};





// ------------------------------------------------------------------------
// This creates a connection manager using a maximum datarate, buffer size,
// and a send timeout limit.
// ------------------------------------------------------------------------
template<typename protocol>
ConnectionManager<protocol>::
ConnectionManager( int p_maxdatarate,    
                   int p_sentimeout,
                   int p_maxbuffered )
{
    m_maxdatarate = p_maxdatarate;
    m_sendtimeout = p_sentimeout;
    m_maxbuffered = p_maxbuffered;
}

// ------------------------------------------------------------------------
//  Destructs the manager, closing every connection contained within.
// ------------------------------------------------------------------------
template<typename protocol>
ConnectionManager<protocol>::~ConnectionManager()
{
    // close every socket in the manager
    clistitr itr;

    for( itr = m_connections.begin(); itr != m_connections.end(); ++itr )
        itr->CloseSocket();
}



// ------------------------------------------------------------------------
//  This notifies the manager that there is a new connection available
// ------------------------------------------------------------------------
template<typename protocol>
void ConnectionManager<protocol>::NewConnection( DataSocket& p_socket )
{
    // turn the socket into a connection
	ProtobufConnection<protocol> conn( p_socket );

	// �����Ѵ����
    if( AvailableConnections() == 0 )
    {
		logger_warn("Connections reach the maximum {}, not accept new connection", MAX);

        // �ر�����
        conn.CloseSocket();
    }
    else
    {
        // ������ӵ�m_connections
        m_connections.emplace_back( conn );

        // ��ȡsocket�������ã�����ֱ��ʹ��conn����Ϊconn�Ǿֲ�����
        Connection<protocol>& c = *m_connections.rbegin();

        // ��������Ϊ������ģʽ
        c.SetBlocking( false );

        // ����������ӵ�set
        m_set.AddSocket( c );
    }
}


// ------------------------------------------------------------------------
//  This physically closes a connection within the connection manager
// ------------------------------------------------------------------------
template<typename protocol>
void ConnectionManager<protocol>::Close( clistitr p_itr )
{
	logger_info("connection {}:{} �ر�, sock {}", SocketLib::GetIPString(p_itr->GetRemoteAddress()),
		p_itr->GetRemotePort(), p_itr->GetSock());

	// notify all listenners connection closed
	NotifyListenners(p_itr);

    // clear the socket descriptor from the socket set
    m_set.RemoveSocket( *p_itr );
	
    // physically close the connection
    p_itr->CloseSocket();
	
    // erase the connection from the list
    m_connections.erase( p_itr );
}





// ------------------------------------------------------------------------
// This determines if any sockets need to be listened on.
// ------------------------------------------------------------------------
template<typename protocol>
void ConnectionManager<protocol>::Listen()
{
    int socks = 0;
    if( TotalConnections() > 0 )
    {
        socks = m_set.Poll();
    }

    // detect if any sockets have action on them
    if( socks > 0 )
    {

        // two iterators; c means "current". This is done due to the 
        // awkward nature of iterating through a map with the 
        // ability to remove items
        clistitr itr = m_connections.begin();
        clistitr c;

        // loop through every connection
        while( itr != m_connections.end() )
        {
            // keep the current connection in "c", and move "itr" to 
            // the next item
            c = itr++;

            // check if there is any activity
            if( m_set.HasActivity( *c ) )
            {
                try
                {
                    // receive as much data as you can.
                    c->Receive();

                    // check to see if the connection is flooding.
                    if( c->GetCurrentDataRate() > m_maxdatarate )
                    {
						logger_warn("CurrentDataRate({}) > m_maxdatarate({}), close socket",
							c->GetCurrentDataRate(), m_maxdatarate);
                        // too much data was sent, tell the
                        // protocol handler
                        c->Close();

                        // close the connection
                        Close( c );
                    }
                }

                // this block catches any fatal exceptions that
                // were thrown when receiving new data. The only
                // exceptions thrown are major errors, and the 
                // socket should immediately be closed. So,
                // the protocol handler is told that the connection
                // hung up, and the socket is closed.
                catch( ... )
                {
                    c->Close();
                    Close( c );
                }

            }   // end activity check

        }   // end socket loop

    }   // end check for number of sockets returned by select()
}


// ------------------------------------------------------------------------
// Description: This goes through all the connections and sends all
//              buffered data.
// ------------------------------------------------------------------------
template<typename protocol>
void ConnectionManager<protocol>::Send()
{
    // ʹ��������������һ��ָ��ǰλ�ã�һ�������ƶ�ָ����һ��λ��
    clistitr itr = m_connections.begin();
    clistitr c;

    // ������������
    while( itr != m_connections.end() )
    {
        c = itr++;

        // now try to send all buffered data on the socket.
        try
        {
            c->SendBuffer();

            // check to see if there are problems sending to the connection
            // these are usually caused by exploits or client crashes.
            if( c->GetBufferedBytes() > m_maxbuffered || 
                c->GetLastSendTime() > m_sendtimeout )
            {
                c->Close();
                Close( c );
            }
        }
        catch( ... )
        {
            c->Close();
            Close( c );
        }
    }   // end while-loop
}



// ------------------------------------------------------------------------
//  Goes through all the connections in the manager and checks if they
//  need to be closed.
// ------------------------------------------------------------------------
template<typename protocol>
void ConnectionManager<protocol>::CloseConnections()
{
    clistitr itr = m_connections.begin();
    clistitr c;

    while( itr != m_connections.end() )
    {
        // retain the value of the iterator in "c" while moving "itr" forward
        c = itr++;

        if( c->Closed() )
            Close( c );
    }
}

template<typename protocol>
void ConnectionManager<protocol>::SendMsg(int iSocket, void* pMsg)
{
	clistitr it = m_connections.begin();
	while (it != m_connections.end())
	{
		if (it->GetSock() == iSocket)
		{
			it->Protocol().SendString(*it, pMsg);
			break;
		}
		it++;
	}
}

template<typename protocol>
void ConnectionManager<protocol>::NotifyListenners(clistitr p_itr)
{
	for each (auto listener in m_listenners)
	{
		listener->ConnectionClosed(*p_itr);
	}
}

}   // end namespace SocketLib

#endif

