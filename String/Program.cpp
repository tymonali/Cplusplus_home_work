#include "Data.h"
#include<Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	ProgrammData app;
	app.start();

	return 0;
}