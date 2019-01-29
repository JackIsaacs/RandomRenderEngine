#include "CEngine.h"
#include "CGame.h"
#include "EngineMacros.h"
#include "DebugMacros.h"
#include "LogMacros.h"

CEngine* CEngine::sSingleton;

CEngine::CEngine(int argc, char *argv[])
{
	if (sSingleton == nullptr)
	{
		sSingleton = this;
	}

	CMessageLog::LogStartMessage();

	Game = new CGame();

	PRINT(Log, "Test");
}

CEngine::~CEngine()
{
	DELETECHECKED(Game);
}

CEngine* CEngine::Get()
{
	return sSingleton;
}

void CEngine::ParseArgs(int argc, char *argv[])
{

}

