////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2099, TQ Digital Entertainment, All Rights Reserved
// Author��  zhu
// Created�� 2017/07/10
// Describe����Ϣ������ - ������������ģʽ
////////////////////////////////////////////////////////////////////////
#pragma once
#ifndef _MSG_MGR_H
#define _MSG_MGR_H

#include <google/protobuf/message.h>
#include <deque>
#include "../thread/ThreadLibMutex.h"

using namespace ThreadLib;

namespace zhu 
{
	typedef std::shared_ptr<google::protobuf::Message> MSG_PTR;
	typedef std::deque<MSG_PTR> MSG_DEQUE;
	typedef std::deque<MSG_PTR>::iterator MSG_ITER;

	// ��Ϣ�����������
	const unsigned int MAX_DEQUE_MESSAGE_SIZE = 90000;

	class CMsgMgr
	{
	public:
		// ��ȡʵ��
		static CMsgMgr & getInstance() {
			static CMsgMgr instance;
			return instance;
		}

		// �жϷ�����Ϣ�����Ƿ�Ϊ��
		bool responseMsgEmpty();

		// �жϽ�����Ϣ�����Ƿ�Ϊ��
		bool receivedMsgEmpty();

		// ������Ϣ�����Ͷ�����
		void insertResponseMsg(MSG_PTR pMsg);

		// �ӷ��Ͷ����л�ȡһ����Ϣ
		MSG_PTR getResponseMsg();

		// ����һ����Ϣ�����ն�����
		void insertReceivedMsg(MSG_PTR pMsg);

		// �ӽ��ն����л�ȡһ����Ϣ
		MSG_PTR getReceivedMsg();

	private:
		CMsgMgr() {
			init();
		}
		
		// ��ʼ����Ϣ����
		void init();

	private:
		int					 m_iMaxQueueLen;		  // �����Ϣ��

		MSG_DEQUE			 m_receiveDeq;			  // ������Ϣ����
		MSG_DEQUE			 m_sendDeq;				  // ������Ϣ����

		ThreadLib::Mutex	 m_csReceive;			  // �����ٽ���
		ThreadLib::Mutex	 m_csSend;				  // �����ٽ���

#ifdef WIN32
		HANDLE               m_hRecDeqFullSemaphore;  // ��Ϣ���ܶ������ź���
		HANDLE               m_hRecDeqEmptySemphore;  // ��Ϣ���ܶ��п��ź���
		HANDLE				 m_hSendDeqFullSemphore;  // ��Ϣ���Ͷ������ź���
		HANDLE				 m_hSendDeqEmptySemphore; // ��Ϣ���Ͷ��п��ź���
#endif // WIN32


	};
}


#endif


