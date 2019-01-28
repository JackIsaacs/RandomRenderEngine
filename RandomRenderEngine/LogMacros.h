#pragma once
#include <vector>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define Log "Log"
#define Warning "Warning"
#define Error "Error"

#define PRINT(Category, cformat, ...) {	\
	char formatBuffer[1024]; \
	char outputBuffer[1024]; \
	sprintf_s(formatBuffer, cformat, __VA_ARGS__); \
	sprintf_s(outputBuffer, "[%s:%d] [%s] %s", __FILENAME__, __LINE__, Category, formatBuffer); \
	SMessageLog::Log_Internal(outputBuffer); \
}

struct SMessageLog
{
	static void Log_Internal(char* buffer);
};