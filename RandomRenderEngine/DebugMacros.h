#pragma once

#include <cmath> 
#include <windows.h>
#include <iosfwd>


#define MSGBOX(title, message, icon) \
{ \
   MessageBox(NULL, message, title, icon); \
}

//////////////////////////////////////////////////////////////////////////
// Fatal

#define FATALERROR_TEXT "A Fatal Error Has Occured"

#define FATALMESSAGE_MSG(message) { MSGBOX(FATALERROR_TEXT, message, MB_OK | MB_ICONERROR); exit(0); };
#define FATALMESSAGE() FATALMESSAGE_MSG("");

#define FATAL() FATALMESSAGE();
#define FATAL_MSG(message) FATALMESSAGE_MSG(message);

//////////////////////////////////////////////////////////////////////////
// General Debug

#define DEBUGBREAK()  __debugbreak(); 
#define CHECKNAN(f) { if (std::isnan(f) || std::isinf(f)) { DEBUGBREAK(); } }
