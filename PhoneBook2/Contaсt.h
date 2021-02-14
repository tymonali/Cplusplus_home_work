#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>

using std::cout;
using std::cin;
using std::setw;
using std::endl;

struct Contact
{
	char FIO[100];
	char mobilenum[20];
	char homenum[20];
	char additionalInfo[200];

	void showContact();
	void setContact();
	char* getFIO();
};

