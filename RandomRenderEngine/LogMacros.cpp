#include "LogMacros.h"

#include "EngineMacros.h"
#include <stdio.h>
#include <ctime>
#include <fstream>
#include <iostream>

std::string CMessageLog::TimeToString()
{
	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	strftime(buffer, sizeof(buffer), "%H:%M:%S", &timeinfo);
	std::string str(buffer);

	return str;
}

std::string CMessageLog::DateToString()
{
	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	strftime(buffer, sizeof(buffer), "%Y-%m-%e %H:%M:%S", &timeinfo);
	std::string str(buffer);

	return str;
}


void CMessageLog::Log_Internal(char* buffer)
{
	char LogBuffer[1024];
	sprintf_s(LogBuffer, "%s %s\n", TimeToString().c_str(), buffer);

	printf(LogBuffer);
	LogBufferToFile(LogBuffer);
}

void CMessageLog::LogBufferToFile(char* buffer)
{
	CreateDirectory(PATH_LOG, 0);
	
	char filenamebuffer[128];
	sprintf_s(filenamebuffer, "%s/Log.txt", PATH_LOG);

	std::ofstream File(filenamebuffer, std::ios::app);
	File << buffer;
	File.close();
}

void CMessageLog::LogStartMessage()
{
	CreateDirectory(PATH_LOG, 0);

	char filenamebuffer[128];
	sprintf_s(filenamebuffer, "%s/Log.txt", PATH_LOG);

	std::ofstream File(filenamebuffer, std::ios::app);
	File << "\n\n=============================================\n";
	File << "Engine Started: " << DateToString() << "\n";
	File << "=============================================\n\n";
	File.close();
}



