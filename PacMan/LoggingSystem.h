#pragma once
#include <iostream>
#include <string>
#include <Windows.h>


class LoggingSystem
{
private:
	LoggingSystem() : _terminateHandler(GetStdHandle(STD_OUTPUT_HANDLE)){}
	static LoggingSystem* _instance;
public:
	LoggingSystem(const LoggingSystem &obj) = delete;
	static LoggingSystem* getInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new LoggingSystem();
			return _instance;
		}
		else
		{
			return _instance;
		}
	}

	void trace(std::string message);
	void info(std::string message);
	void warning(std::string message);
	void error(std::string message);

private:
	HANDLE _terminateHandler;
	void setColor(int color);

};

#define LOG_TRACE(...) LoggingSystem::getInstance()->trace(x);
#define LOG_INFO(x) LoggingSystem::getInstance()->info(x);
#define LOG_WARNING(x) LoggingSystem::getInstance()->warning(x);
#define LOG_ERROR(x) LoggingSystem::getInstance()->error(x);
