#pragma once
#include"customPrintf.h"

using namespace std;

class ProgrammData
{
	int a, b;

	void menu();
	bool runAction(int action);

public:
	void start();
	customPrintf ProgData();
};