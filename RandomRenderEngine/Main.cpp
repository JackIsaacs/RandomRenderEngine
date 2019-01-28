
#include "CEngine.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	CEngine* Engine = new CEngine(argc, argv);
	delete Engine;

	getchar();

	return 0;
}