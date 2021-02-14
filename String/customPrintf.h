#pragma once
#include <iostream>
#include <stdarg.h>

using namespace std;

class customPrintf
{
	bool isAvailableFormat(char symb);

public:
	void custom_Printf(const char* format, ...);
};