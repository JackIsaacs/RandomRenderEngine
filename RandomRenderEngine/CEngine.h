#pragma once

class CGame;

class CEngine
{
public:
	CEngine(int argc, char *argv[]);
	~CEngine();

	static CEngine* Get();

	const char* test;


private:
	void ParseArgs(int argc, char *argv[]);

private:

	CGame* Game;


	static CEngine* sSingleton;
};

