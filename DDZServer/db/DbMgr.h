////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2099, TQ Digital Entertainment, All Rights Reserved
// Author��  zhou du
// Created�� 2017/07/10
// Describe�����ݿ������ ��Ҫʵ����ɾ�Ĳ�
////////////////////////////////////////////////////////////////////////

#ifndef DBMGR_H
#define DBMGR_H

#include <map>
#include <vector>
#include <string>
#include <sstream>
//mysql driver
#include <mysql_connection.h>
//mysql execute
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <exception>

#include "../basic/Basic.h"

using namespace std;

////////////////////////////////////////////////////////////////
//���ݿ��쳣��Ϣ
/////////////////////////////////////////////////////////////////
struct CDbException
{
	CDbException(const string &sBuffer) :errorInfo(sBuffer) {};
	~CDbException() throw() {};
	string errorInfo;
};

////////////////////////////////////////////////////////////////
//���ݿ������ 
//
/////////////////////////////////////////////////////////////////
class DbMgr
{
public:
	//�����ֶ����ͣ�
	enum DBTYPE
	{
		DB_INT, //��������
		DB_STR, //�ַ�������
		DB_FLOAT//������
	};

	//���ݼ�¼
	typedef map<string, pair<DBTYPE, string> > RECORD_DATA;
	//��ѯ���ݿⷵ������
	typedef vector<map<string, string> > DB_DATA;
public:
	//��������
	void TestConnect();

	static DbMgr *GetInstance();

	static void DestoryInstance();

	////////////////////////////////////////////////////////////////
	//�������ܣ������¼. 
	//���������
	//sTableName ����
	//mpColumns ����/ֵ��
	//����ֵ�� size_t Ӱ�������
	/////////////////////////////////////////////////////////////////
	size_t InsertRecord(const string &strTableName, const RECORD_DATA &mpColumns);

	////////////////////////////////////////////////////////////////
	//�������ܣ�����Insert-SQL���. 
	//���������
	//sTableName ����
	//mpColumns ����/ֵ��
	//����ֵ��string insert-SQL���
	/////////////////////////////////////////////////////////////////
	string BuildInsertSQL(const string &strTableName, const RECORD_DATA &mpColumns);

	////////////////////////////////////////////////////////////////
	//�������ܣ�ɾ����¼. 
	//���������
	// sTableName ����
	// sCondition where�����,����:where A = B
	//����ֵ��size_t Ӱ�������
	/////////////////////////////////////////////////////////////////
	size_t DeleteRecord(const string &strTableName, const string &strCondition = "");

	////////////////////////////////////////////////////////////////
	//�������ܣ����¼�¼. 
	//���������
	//sTableName ����
	//mpColumns ����/ֵ��
	//sCondition where�����,����:where A = B
	//����ֵ��size_t Ӱ�������
	/////////////////////////////////////////////////////////////////
	size_t UpdateRecord(const string &strTableName, const RECORD_DATA &mpColumns, const string &strCondition);

	////////////////////////////////////////////////////////////////
	//�������ܣ�����Update-SQL���. 
	//���������
	//sTableName ����
	//mpColumns ����/ֵ��
	//sCondition where�����
	//����ֵ��string Update-SQL���
	/////////////////////////////////////////////////////////////////
	string BuildUpdateSQL(const string &strTableName, const RECORD_DATA &mpColumns, const string &strCondition);

	////////////////////////////////////////////////////////////////
	//�������ܣ���ѯ��¼
	//���������sSql sql���
	//����ֵ��
	/////////////////////////////////////////////////////////////////
	DB_DATA QueryRecord(const string& strSql);

	////////////////////////////////////////////////////////////////

private:
	DbMgr() {};

	~DbMgr()
	{
		SAFE_DELETE(m_Instance);
	};

private:
	static DbMgr *m_Instance;
};


#endif