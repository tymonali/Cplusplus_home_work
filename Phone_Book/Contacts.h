#pragma once
#include<iostream>
#include<Windows.h>

using std::cout;
using std::cin;
using std::endl;

class Contacts
{
	char Fio[50];
	char homeNumber[14];
	char workNumber[14];
	char mobileNumber[14];
	char infoContakt[200];
public:
	void Vvod();
	void Show();
	char* GetFio();
};

