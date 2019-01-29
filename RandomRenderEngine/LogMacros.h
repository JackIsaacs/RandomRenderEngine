#pragma once

#include <windows.h>
#include <vector>
#include <string.h>
#include <string>

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define Log			"Log"
#define Warning		"Warning"
#define Error		"Error"

#define PRINT(Category, cformat, ...) {	\
	char formatBuffer[1024]; \
	char outputBuffer[1024]; \
	sprintf_s(formatBuffer, cformat, __VA_ARGS__); \
	sprintf_s(outputBuffer, "[%s:%d] [%s] %s", __FILENAME__, __LINE__, Category, formatBuffer); \
	CMessageLog::Log_Internal(outputBuffer); \
}

class CMessageLog
{
public:
	static void LogStartMessage();

	/** Do not use outside of LogMacros.h */
	static void Log_Internal(char* buffer);

private:
	/** Log a buffer to a file */
	static void LogBufferToFile(char* buffer);

	static std::string DateToString();
	static std::string TimeToString();
};