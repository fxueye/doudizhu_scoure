////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2099, TQ Digital Entertainment, All Rights Reserved
// Author��  zhu
// Created�� 2017/10/24
// Describe�����������
////////////////////////////////////////////////////////////////////////
#include "basic/basic.h"
#include "basic/ConfigMgr.h"
#include "protocol/Protobuf.h"
#include "socket/ListeningManager.h"
#include "socket/SocketLib.h"
#include <string>
#include "message/MsgMgr.h"
#include "thread/ThreadLib.h"
#include "module/ModuleMgr.h"
#include "db/ConnectionPool.h"

using namespace SocketLib;
using namespace zhu;
using namespace std;
using namespace basic;
using namespace ThreadLib;

bool done = false;

// Socket������
template<typename protocol>
void SocketThreadHandler(void* pData) 
{
	ConnectionManager<protocol>* pConnectionManager = (ConnectionManager<protocol>*)(pData);
	while (!done)
	{
		try
		{
			// 1��������ӵ�socket�Ƿ���յ������ݣ��еĻ��������ݲ�������Ϣ����
			// 2�������������ͨ��socket���ͳ�ȥ
			// 3���ر�������Ч��socket
			pConnectionManager->Manage();

			ThreadLib::YieldThread();
		}
		catch (SocketLib::Exception& e)
		{
			// catch socket errors
			logger_error("socket error {}", e.PrintError());
		}
		catch (std::exception& e)
		{
			// catch standard errors
			logger_error("standard error {}", e.what());
		}
		catch (...)
		{
			logger_error("connectionManager->Manage() error");
		}
	}
}

// ���������Ӻ���
template<typename protocol>
void NewConnectionThreadHandler(void* pData) {
	ListeningManager<protocol>* pListener = (ListeningManager<protocol>*)(pData);
	while (!done)
	{
		try
		{
			pListener->Listen();

			ThreadLib::YieldThread();
		}
		catch (SocketLib::Exception& e)
		{
			// catch socket errors
			logger_error("socket error {}", e.PrintError());
		}
		catch (std::exception& e)
		{
			// catch standard errors
			logger_error("standard error {}", e.what());
		}
		catch (...)
		{
			logger_error("handle new connection error");
		}

	}
}

// ��Ϣ���ն��д�����
template<typename protocol>
void RecvMsgQueueThreadHandler(void* pData) {
	while (!done)
	{
		try
		{
			// �ж���û�д��������Ϣ����
			if (CMsgMgr::getInstance().receivedMsgEmpty())
			{
				ThreadLib::YieldThread();
				continue;
			}
			MSG_PTR pMsg = CMsgMgr::getInstance().getReceivedMsg();
			if (NULL == pMsg.get())
			{
				logger_error("ReceivedMsg is illegal");
				return;
			}
			logger_debug("begin handle received msg, type {}", pMsg->GetTypeName());
			// ��Ϸҵ���߼�����
			CModuleMgr<CProtobuf>::Instance().DispatchMsg(pMsg);
		}
		//catch (sql::SQLException&e)
		//{
		//	logger_error("{}", e.what());
		//}
		catch (std::exception& e)
		{
			// catch standard errors
			logger_error("standard error {}", e.what());
		}
		catch (...) {
			logger_error("handle receive msg error");
		}
	}
}

// ��Ϣ���Ͷ��д�����
template<typename protocol>
void SendMsgQueueThreadHandler(void* pData) {
	ConnectionManager<protocol>* pConnectionManager = (ConnectionManager<protocol>*)(pData);
	while (!done)
	{
		try
		{
			// �ж���û�д��������Ϣ����
			if (CMsgMgr::getInstance().responseMsgEmpty())
			{
				ThreadLib::YieldThread();
				continue;
			}
			MSG_PTR pMsg = CMsgMgr::getInstance().getResponseMsg();
			std::shared_ptr<zhu::SelfDescribingMessage> pRespMsg = dynamic_pointer_cast<zhu::SelfDescribingMessage>(pMsg);
			if (NULL == pRespMsg.get())
			{
				logger_error("dynamic_pointer_cast msg failed, msg type {}", pMsg->GetTypeName());
				continue;
			}
			for (int i = 0; i < pRespMsg->socket_size(); i++)
			{
				pConnectionManager->SendMsg(pRespMsg->socket(i), pRespMsg.get());
			}
		}
		catch (SocketLib::Exception& e)
		{
			// catch socket errors
			logger_error("socket error {}", e.PrintError());
		}
		catch (std::exception& e)
		{
			// catch standard errors
			logger_error("standard error {}", e.what());
		}
		catch (...)
		{
			logger_error("Send Msg Thread error");
		}
	}
}

template<typename protocol>
void CreateGameServiceThread(ThreadLib::ThreadID* phandle, ListeningManager<typename protocol>& listener,
	ConnectionManager<typename protocol>& connectionManager)
{
	// ����Socket�����߳�
	*phandle = ThreadLib::Create(SocketThreadHandler<protocol>, (void*)&connectionManager);
	phandle++;

	// ���������������߳�
	*phandle = ThreadLib::Create(NewConnectionThreadHandler<protocol>, (void*)&listener);
	phandle++;

	// ������Ϣ���ն��д����߳�
	*phandle = ThreadLib::Create(RecvMsgQueueThreadHandler<protocol>, nullptr);
	phandle++;

	// ������Ϣ���Ͷ��д����߳�
	*phandle = ThreadLib::Create(SendMsgQueueThreadHandler<protocol>, (void*)&connectionManager);
	phandle++;
}

// ���ÿ���̨���
void ConfigConsole()
{
#ifdef WIN32
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
	{
		logger_warn("GetStdHandle failed");
	}
	DWORD fdwSaveOldMode;
	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
	{
		logger_warn("GetConsoleMode failed");
	}
	if (!SetConsoleMode(hStdin, fdwSaveOldMode & ~ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT))
	{
		logger_warn("SetConsoleMode failed");
	}
#endif
}

int main() 
{
	// �����߳�ID����
	// ʹ���ĸ��̣߳�һ�����Ӽ����̣߳�һ�����ӹ����̣߳�һ������Ϣ�̣߳�һ������Ϣ�߳�
	ThreadLib::ThreadID threadHandles[4];

	// ��ʼ����־�ļ�
	CGameLog::initLogger("log/game.log", 10, 10);

	try {
		ConfigConsole();

		logger_info("����˳�ʼ��");

		//��ʼ��mysql����
		CConnectionPool::Instance();

		// ��������������
		ListeningManager<CProtobuf> listener;
		string strPort = CConfigMgr::getConfigParam("port", "9876");
		listener.AddPort(atoi(strPort.c_str()));

		// �������ӹ�����
		string strMaxDatarate = CConfigMgr::getConfigParam("maxdatarate", "1024");
		string strSenTimeout = CConfigMgr::getConfigParam("sentimeout", "60");
		string strMaxBuffered = CConfigMgr::getConfigParam("maxbuffered", "65536");
		ConnectionManager<CProtobuf> connectionManager(
			atoi(strMaxDatarate.c_str()), atoi(strSenTimeout.c_str()), atoi(strMaxBuffered.c_str()));
		listener.SetConnectionManager(&connectionManager);

		// ������Ϣ������ʵ��
		CMsgMgr::getInstance();

		// ��ʼ��ģ�������
		CModuleMgr<CProtobuf>::Instance().SetConnectionManager(&connectionManager);
		CModuleMgr<CProtobuf>::Instance().InitModules();

		// �����߳�
		CreateGameServiceThread(threadHandles, listener, connectionManager);

		logger_info("�����������ɹ�");

		// ���տ���̨����
		const int BUF_SIZE = 128;
		char inputBuf[BUF_SIZE];
		while (!done)
		{
			cin.getline(inputBuf, BUF_SIZE);
			if (0 == strlen(inputBuf))
			{
				continue;
			}

			if (_strcmpi(inputBuf, "quit") == 0 || _strcmpi(inputBuf, "exit") == 0)
			{
				done = true;
				break;
			}
		}
	}
	catch (zhu::Exception e) {

	}
	

	return 0;
}
