#include <iostream>
#include <Windows.h>

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color B0");

	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}

	return 0;
}