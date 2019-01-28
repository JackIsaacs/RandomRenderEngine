#include "LogMacros.h"
#include <stdio.h>
#include <string>
#include <ctime>

std::string NowToString()
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

void SMessageLog::Log_Internal(char* buffer)
{
	printf("%s %s\n", NowToString().c_str(), buffer);
}
