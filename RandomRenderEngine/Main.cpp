
#include "CEngine.h"
#include <stdio.h>
#include <iostream>

int main(int argc, char *argv[])
{
	CEngine* Engine = new CEngine(argc, argv);
	delete Engine;

	getchar();

	return 0;
}