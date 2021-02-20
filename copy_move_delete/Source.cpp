#include<iostream>
#include<Windows.h>
#include<fstream>
#include <direct.h>
#include <io.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color B0");

	if (rename("d:\\DemoDirr02\\Demo.txt", "d:\\DemoDirr01\\Demo.txt") != -1)
	{
		cout << "Succes" << endl;
	}
	else
	{
		cout << "Error" << endl;
	}

	/*if (_mkdir("d:\\DemoDirr01") != 1)
	{
		cout << "Succes" << endl;
	}
	else
	{
		cout << "Error" << endl;
	}*/

	return 0;
}