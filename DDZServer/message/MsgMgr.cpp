#include "MsgMgr.h"
#include "../basic/GameLog.h"
#include "../basic/ConfigMgr.h"
#include <string>

using namespace std;

void zhu::CMsgMgr::init() {
	// �������ļ��ж�ȡ���������Ϣ��
	string strMsgQueueSize = basic::CConfigMgr::getConfigParam("msg.queue.size", "9999");
	m_iMaxQueueLen = atoi(strMsgQueueSize.c_str());
	if (0 == m_iMaxQueueLen)
	{
		// ����Ĭ��ֵ
		m_iMaxQueueLen = MAX_DEQUE_MESSAGE_SIZE;
	}

	// �������ն����ź���
	m_hRecDeqEmptySemphore = CreateSemaphore(NULL, m_iMaxQueueLen, m_iMaxQueueLen, NULL);
	m_hRecDeqFullSemaphore = CreateSemaphore(NULL, 0, m_iMaxQueueLen, NULL);
	// �������Ͷ����ź���
	m_hSendDeqEmptySemphore = CreateSemaphore(NULL, m_iMaxQueueLen, m_iMaxQueueLen, NULL);
	m_hSendDeqFullSemphore = CreateSemaphore(NULL, 0, m_iMaxQueueLen, NULL);

	if (NULL == m_hRecDeqEmptySemphore ||
		NULL == m_hRecDeqFullSemaphore ||
		NULL == m_hSendDeqEmptySemphore ||
		NULL == m_hSendDeqFullSemphore)
	{
		logger_error("�ź�������ʧ�ܣ��������޷�����!");
		exit(1);
	}
}

bool zhu::CMsgMgr::responseMsgEmpty()
{
	bool bFlag = false;

	// ���ٽ���Դ���з����ǻ����
	m_csSend.Lock();

	if (m_sendDeq.empty())
		bFlag = true;

	m_csSend.Unlock();
	
	return bFlag;
}

bool zhu::CMsgMgr::receivedMsgEmpty()
{
	bool bFlag = false;

	// ���ٽ���Դ���з����ǻ����
	m_csReceive.Lock();

	if (m_receiveDeq.empty())
		bFlag = true;

	m_csReceive.Unlock();

	return bFlag;
}

void zhu::CMsgMgr::insertResponseMsg(MSG_PTR pMsg)
{
	// ��Ϣ����ȴ�
	WaitForSingleObject(m_hSendDeqEmptySemphore, INFINITE);

	m_csSend.Lock();
	// ����Ϣ�������
	m_sendDeq.emplace_back(pMsg);
	m_csSend.Unlock();

	// ���ź���+1
	ReleaseSemaphore(m_hSendDeqFullSemphore, 1, NULL);
}

zhu::MSG_PTR zhu::CMsgMgr::getResponseMsg()
{
	// û����Ϣ��ȴ�
	WaitForSingleObject(m_hSendDeqFullSemphore, INFINITE);
	MSG_PTR msg = NULL;

	m_csSend.Lock();
	// ȡ����Ϣ���е�һ����Ϣ
	if (!m_sendDeq.empty()) {
		MSG_ITER it = m_sendDeq.begin();
		msg = *it;
		m_sendDeq.pop_front();
	}
	m_csSend.Unlock();

	// ���ź���+1
	ReleaseSemaphore(m_hSendDeqEmptySemphore, 1, NULL);

	return msg;
}

void zhu::CMsgMgr::insertReceivedMsg(MSG_PTR pMsg)
{
	// ��Ϣ����ȴ�
	WaitForSingleObject(m_hRecDeqEmptySemphore, INFINITE);

	m_csReceive.Lock();
	m_receiveDeq.emplace_back(pMsg);
	m_csReceive.Unlock();

	// ���ź���+1
	ReleaseSemaphore(m_hRecDeqFullSemaphore, 1, NULL);
}

zhu::MSG_PTR zhu::CMsgMgr::getReceivedMsg()
{
	// û����Ϣ��ȴ�
	WaitForSingleObject(m_hRecDeqFullSemaphore, INFINITE);
	MSG_PTR msg = NULL;

	m_csReceive.Lock();
	// ȡ����Ϣ���е�һ����Ϣ
	if (!m_receiveDeq.empty()) {
		MSG_ITER it = m_receiveDeq.begin();
		msg = *it;
		m_receiveDeq.pop_front();
	}
	m_csReceive.Unlock();

	// ���ź���+1
	ReleaseSemaphore(m_hRecDeqEmptySemphore, 1, NULL);

	return msg;
}
