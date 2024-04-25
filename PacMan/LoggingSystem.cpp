#include "LoggingSystem.h"
LoggingSystem* LoggingSystem::_instance = nullptr;
void LoggingSystem::trace(std::string message)
{
	int color = 15;
	setColor(color);
	std::cout << "[TRACE]: "  << message << std::endl;
}

void LoggingSystem::info(std::string message)
{
	int color = 11;
	setColor(color);
	std::cout << "[INFO]: " << message << std::endl;
}

void LoggingSystem::warning(std::string message)
{
	int color = 14;
	setColor(color);
	std::cout << "[WARNING]: " << message << std::endl;
}

void LoggingSystem::error(std::string message)
{
	int color = 12;
	setColor(color);
	std::cout << "[ERROR]: " << message << std::endl;
	exit(-1);
}

void LoggingSystem::setColor(int color)
{
	SetConsoleTextAttribute(_terminateHandler, color);
}
