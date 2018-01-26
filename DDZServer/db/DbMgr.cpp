////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2099, TQ Digital Entertainment, All Rights Reserved
// Author��  zhou du
// Created�� 2017/07/10
// Describe�����ݿ������ ��Ҫʵ����ɾ�Ĳ�
////////////////////////////////////////////////////////////////////////

#include "DbMgr.h"
#include "ConnectionPool.h"
#include "../basic/Basic.h"

using namespace sql;

DbMgr *DbMgr::m_Instance = NULL;

void DbMgr::TestConnect()
{
	mysql::MySQL_Driver *pDriver;
	Connection *pCon;
	Statement *pState;
	ResultSet *pResult;
	pDriver = sql::mysql::get_mysql_driver_instance();
	pCon = pDriver->connect("tcp://127.0.0.1:3306", "root", "123456a");
	pState = pCon->createStatement();
	pCon->setSchema("mysql");
	//SQL query
	pResult = pState->executeQuery("select count(1) as userNum from user");
	while (pResult->next()) {
		int id = pResult->getInt("userNum");
		cout << "db test: db user account Num[" << id << "]" << endl;
	}

	// Release.
	SAFE_DELETE(pResult);
	SAFE_DELETE(pState);
	SAFE_DELETE(pCon);
	SAFE_DELETE(pDriver);
}

DbMgr *DbMgr::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = NEW DbMgr();
	}
	return m_Instance;
}

void DbMgr::DestoryInstance()
{
	if (m_Instance != NULL)
	{
		SAFE_DELETE(m_Instance);
	}
}

string DbMgr::BuildInsertSQL(const string &strTableName, const RECORD_DATA &mpColumns)
{
	ostringstream sColumnNames;//����
	ostringstream sColumnValues;//��ֵ

	RECORD_DATA::const_iterator itEnd = mpColumns.end();

	for (RECORD_DATA::const_iterator it = mpColumns.begin(); it != itEnd; ++it)//ƴ��sql�ַ���
	{
		if (it == mpColumns.begin())
		{
			sColumnNames << "`" << it->first << "`";
			if (it->second.first == DB_INT)
			{
				sColumnValues << it->second.second;
			}
			else if (it->second.first == DB_FLOAT)
			{
				sColumnValues << it->second.second;
			}
			else
			{
				sColumnValues << "'" << it->second.second << "'";
			}
		}
		else
		{
			sColumnNames << ",`" << it->first << "`";
			if (it->second.first == DB_INT)
			{
				sColumnValues << "," + it->second.second;
			}
			else if (it->second.first == DB_FLOAT)
			{
				sColumnValues << "," + it->second.second;
			}
			else
			{
				sColumnValues << ",'" << it->second.second << "'";
			}
		}
	}
	ostringstream os;
	os << "insert into " << strTableName << " (" << sColumnNames.str() << ") values(" << sColumnValues.str() << ")";
	return os.str();
}

size_t DbMgr::InsertRecord(const string &strTableName, const RECORD_DATA &mpColumns)
{
	string strSql = BuildInsertSQL(strTableName, mpColumns);

	//���һ������
	std::shared_ptr<Connection> con = CConnectionPool::Instance().Instance().GetConnect();
	std::shared_ptr<Statement> stmt(con->createStatement());
	int iAffectedRows = stmt->executeUpdate(SQLString(strSql.c_str()));
	CConnectionPool::Instance().Instance().ReturnConnect(con);
	if (iAffectedRows != 0)
	{
		logger_error("�������ݴ���,�������ݵĸ�ʽ");
		throw CDbException(string("�������ݴ���,�������ݵĸ�ʽ"));
	}

	return iAffectedRows;//����ǰһ�� MySQL ������Ӱ��ļ�¼����
}

size_t DbMgr::DeleteRecord(const string &strTableName, const string &strCondition)
{
	ostringstream sSql;

	sSql << "delete from " << strTableName << " " << strCondition;

	//���һ������
	std::shared_ptr<Connection> con = CConnectionPool::Instance().GetConnect();
	std::shared_ptr<Statement> stmt(con->createStatement());
	int iAffectedRows = stmt->executeUpdate(SQLString(sSql.str()));
	CConnectionPool::Instance().Instance().ReturnConnect(con);
	if (iAffectedRows != 0)
	{
		logger_error("ɾ�����ݴ���,�������ݵĸ�ʽ");
		throw CDbException(string("ɾ�����ݴ����������ݵĸ�ʽ"));
	}

	return iAffectedRows;
}

size_t DbMgr::UpdateRecord(const string &strTableName, const RECORD_DATA &mpColumns, const string &strCondition)
{
	string sSql = BuildUpdateSQL(strTableName, mpColumns, strCondition);

	//���һ������
	std::shared_ptr<Connection> con = CConnectionPool::Instance().GetConnect();
	std::shared_ptr<Statement> stmt(con->createStatement());
	int iAffectedRows = stmt->executeUpdate(SQLString(sSql.c_str()));
	CConnectionPool::Instance().Instance().ReturnConnect(con);
	if (iAffectedRows != 0)
	{
		logger_error("�������ݴ���,�������ݵĸ�ʽ");
		throw CDbException(string("�������ݴ����������ݵĸ�ʽ"));
	}

	return iAffectedRows;//����ǰһ�� MySQL ������Ӱ��ļ�¼����
}

string DbMgr::BuildUpdateSQL(const string &strTableName, const RECORD_DATA &mpColumns, const string &strWhereFilter)
{
	ostringstream sColumnNameValueSet;

	RECORD_DATA::const_iterator itEnd = mpColumns.end();

	for (RECORD_DATA::const_iterator it = mpColumns.begin(); it != itEnd; ++it)//ƴ��sql�ַ���
	{
		if (it == mpColumns.begin())
		{
			sColumnNameValueSet << "`" << it->first << "`";
		}
		else
		{
			sColumnNameValueSet << ",`" << it->first << "`";
		}

		if (it->second.first == DB_INT)
		{
			sColumnNameValueSet << "= " << it->second.second;
		}
		else if (it->second.first == DB_FLOAT)
		{
			sColumnNameValueSet << "= " << it->second.second;
		}
		else
		{
			sColumnNameValueSet << "= '" << it->second.second << "'";
		}
	}
	ostringstream os;
	os << "update " << strTableName << " set " << sColumnNameValueSet.str() << " " << strWhereFilter;
	return os.str();
}

DbMgr::DB_DATA DbMgr::QueryRecord(const string& strSql)
{
	DB_DATA dbData;

	//���һ������
	std::shared_ptr<Connection> con = CConnectionPool::Instance().GetConnect();
	std::shared_ptr<Statement> stmt(con->createStatement());
	std::shared_ptr<ResultSet> result(stmt->executeQuery(SQLString(strSql.c_str())));
	CConnectionPool::Instance().Instance().ReturnConnect(con);

	if (!result.get())
	{
		logger_error("��ѯ���ݼ�����");
		throw  CDbException(string("��ѯ���ݼ�����"));
	}

	vector<string> vecField;//�ֶ�������
	ResultSetMetaData *pResMeta = result->getMetaData();
	int iNumCols = pResMeta->getColumnCount();
	for (int i = 0; i < iNumCols; ++i) {
		SQLString strColumnLabel = pResMeta->getColumnLabel(i + 1);
		const std::string strColName = strColumnLabel.asStdString();
		vecField.emplace_back(strColName);//�����ֶ���
	}

	map<string, string> mapRow;
	while (result->next())
	{
		mapRow.clear();

		for (size_t i = 0; i < vecField.size(); i++)
		{
			mapRow[vecField[i]] = result->getString(vecField[i]);
		}
		dbData.emplace_back(mapRow);
	}

	return dbData;
}

