#include "GameLog.h"
#include "FileUtil.h"
#include <vector>
#include "ConfigMgr.h"
#include <iostream>

std::unique_ptr<CGameLog> logger;

bool CGameLog::initLogger(const std::string & fileName, int sizeMb, int numFiles)
{
	// ��־Ŀ¼���������ȴ���Ŀ¼
	if (!basic::CFileUtil::isDirExist("./log"))
		basic::CFileUtil::createDir("./log");

	if (logger)
		return true;

	// ����CGamelog
	logger.reset(new CGameLog);

	try {
		// ָ��ʵ�������Ŀ¼
		std::vector<spdlog::sink_ptr> sinks;
		
		// ����̨�����־����
		string log2Console = basic::CConfigMgr::getConfigParam("log.enableconsole", "true");
		if (log2Console == "true") {
#ifdef WIN32
			sinks.push_back(std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>());
#else
			sinks.push_back(std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>());
#endif
		}

		// ������ļ�
		sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>
			(fileName, sizeMb * 1024L * 1024, numFiles));

		// ����logger
		auto spdLogger = std::make_shared<spdlog::logger>("server", begin(sinks), end(sinks));

		// �������ڸ�ʽ
		spdLogger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%t] [%l] %v");

		// ����spdLogger���õ�logger
		logger->setSpdLogger(spdLogger);

		// ע��logger
		spdlog::register_logger(logger->getSpdlogger());

		// ͬ���������
		string logAsync = basic::CConfigMgr::getConfigParam("log.async", "false");
		if (logAsync == "true")
		{
			string q_size = basic::CConfigMgr::getConfigParam("log.q_size", "4096");
			spdlog::set_async_mode(atoi(q_size.c_str()));
		}

		// ��������ȼ�
		string logLevel = basic::CConfigMgr::getConfigParam("log.level", "error");
		setLogLevel(logLevel);
	}
	catch (const spdlog::spdlog_ex& ex) {
		std::cout << "logger initialization failed: " << ex.what() << std::endl;
		return false;
	}
	return true;
}

void CGameLog::setLogLevel(std::string & level)
{
	if (!logger) return;

	spdlog::level::level_enum spdlevel = spdlog::level::level_enum::err;
	if (level == "trace") {
		spdlevel = spdlog::level::level_enum::trace;
	}
	else if (level == "debug") {
		spdlevel = spdlog::level::level_enum::debug;
	}
	else if (level == "info") {
		spdlevel = spdlog::level::level_enum::info;
	}
	else if (level == "warn") {
		spdlevel = spdlog::level::level_enum::warn;
	}
	else if (level == "err") {
		spdlevel = spdlog::level::level_enum::err;
	}
	else if (level == "critical") {
		spdlevel = spdlog::level::level_enum::critical;
	}
	else if (level == "off") {
		spdlevel = spdlog::level::level_enum::off;
	}

	logger->getSpdlogger()->set_level(spdlevel);

	// debugʱ�����������־
#ifdef _DEBUG
#else
	logger->getSpdlogger().get()->flush_on(spdlevel);
#endif // _DEBUG
}

std::shared_ptr<spdlog::logger>& CGameLog::getSpdlogger()
{
	if (!m_spdLogger) {
		// δ��ʼ��spdlog
		std::cout << "logger not initialized" << std::endl;
		assert(0);
	}
	return m_spdLogger;
}

CGameLog::~CGameLog()
{
	std::cout << "tear down CGameLog" << std::endl;
	string logAsync = basic::CConfigMgr::getConfigParam("log.async", "false");
	if (logAsync == "true")
	{
		m_spdLogger->flush();
	}
}

CGameLog::CGameLog() {}
