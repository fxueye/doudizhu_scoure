// MUD Programming
// Ron Penton
// (C)2003
// SocketLibSocket.h - This file contains the definitions for the three
// socket classes: Basic, Data, and Listening.


#ifndef SOCKETLIBSOCKET_H
#define SOCKETLIBSOCKET_H

// ========================================================================
//  Include Files
// ========================================================================
#include "SocketLibTypes.h"
#include "SocketLibErrors.h"


namespace SocketLib
{

    // ========================================================================
    // Class:       Socket
    // Purpose:     Socket���࣬�ṩ�û������ķ��������ȡ�˿ڣ�ip���ر����ӵ�
    //              ��������
    // ========================================================================
    class Socket
    {
    public:
        // ====================================================================
        // Function:    GetSock
        // Purpose:     ��ȡsocket
        // ====================================================================
        inline sock GetSock() const
        {
            return m_sock;
        }


        // ====================================================================
        // Function:    GetLocalPort
        // Purpose:     ��ȡ���ؼ����˿�
        // ====================================================================
        inline port GetLocalPort() const
        {
            return ntohs( m_localinfo.sin_port );
        }

        // ====================================================================
        // Function:    GetLocalAddress
        // Purpose:     ��ȡ���ؼ�����ַ
        // ====================================================================
        inline ipaddress GetLocalAddress() const
        {
            return m_localinfo.sin_addr.s_addr;
        }

        // ====================================================================
        // Function:    Close
        // Purpose:     �ر�����
        // ====================================================================
        void Close();

        // ====================================================================
        // Function:    SetBlocking
        // Purpose:     ���������Ƿ�����ģʽ
        // ====================================================================
        void SetBlocking( bool p_blockmode );

  

    protected:
        // ====================================================================
        // Function:    Socket
        // Purpose:     ���ظù��캯������ֹ�û�ֱ�Ӵ������࣬��ʹ��������д���
        // ====================================================================
        Socket( sock p_socket = -1 );


        sock m_sock;                    // this is the underlying representation
                                        // of the actual socket.

        struct sockaddr_in m_localinfo; // structure containing information
                                        // about the local connection

        bool m_isblocking;              // this tells whether the socket is
                                        // blocking or not.
    };




    // ========================================================================
    // Class:       DataSocket
    // Purpose:     A variation of the BasicSocket base class that handles
    //              TCP/IP data connections.
    // ========================================================================
    class DataSocket : public Socket
    {
    public:
        // ====================================================================
        // Function:    DataSocket
        // Purpose:     Constructs the data socket with optional values
        // ====================================================================
        DataSocket( sock p_socket = -1 );

        // ====================================================================
        // Function:    GetRemoteAddress
        // Purpose:     ��ȡԶ��ip��ַ
        // ====================================================================
        inline ipaddress GetRemoteAddress() const
        {
            return m_remoteinfo.sin_addr.s_addr;
        }


        // ====================================================================
        // Function:    GetRemotePort
        // Purpose:     ��ȡԶ�̶˿�
        // ====================================================================
        inline port GetRemotePort() const
        {
            return ntohs( m_remoteinfo.sin_port );
        }


        // ====================================================================
        // Function:    IsConnected
        // Purpose:     ��ǰsocket�Ƿ�������
        // ====================================================================
        inline bool IsConnected() const
        {
            return m_connected;
        }


        // ====================================================================
        // Function:    Connect
        // Purpose:     ����ǰsocket���ӵ���һ��socket�������ǰsocket�����ӽ���
		//				ʧ��
        // ====================================================================
        void Connect( ipaddress p_addr, port p_port );

        // ====================================================================
        // Function:    Send
        // Purpose:     ��������
        // ====================================================================
        int Send( const char* p_buffer, int p_size );

        // ====================================================================
        // Function:    Receive
        // Purpose:     ��������
        // ====================================================================
        int Receive( char* p_buffer, int p_size );

        // ====================================================================
        // Function:    Close
        // Purpose:     �ر�����
        // ====================================================================
        void Close();

    protected:

        bool m_connected;               // is the socket connected?

        struct sockaddr_in m_remoteinfo;// structure containing information
        // about the remote connection

    };



    // ========================================================================
    // Class:       ListeningSocket
    // Purpose:     ����socket�����ڼ����ͻ�������
    // ========================================================================
    class ListeningSocket : public Socket
    {
    public:

        // ====================================================================
        // Function:    ListeningSocket
        // Purpose:     Constructor. Constructs the socket with initial values
        // ====================================================================
        ListeningSocket();

        // ====================================================================
        // Function:    Listen
        // Purpose:     ����ָ���˿�
        // p_port:      This is the port that the socket will listen on.
        // ====================================================================
        void Listen( port p_port );

        // ====================================================================
        // Function:    Accept
        // Purpose:     This is a blocking function that will accept an 
        //              incomming connection and return a data socket with info
        //              about the new connection.
        // ====================================================================
        DataSocket Accept();

        // ====================================================================
        // Function:    IsListening
        // Purpose:     ��ȡ�Ƿ����
        // ====================================================================
        inline bool IsListening() const
        {
            return m_listening;
        }


        // ====================================================================
        // Function:    Close
        // Purpose:     �ر�socket
        // ====================================================================
        void Close();

    protected:
        bool m_listening;               // is the socket listening?

    };


}   // end namespace SocketLib


#endif
