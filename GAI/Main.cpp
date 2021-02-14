#include"AppData.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	AppData app;

	app.Start();

	system("pause");
	return 0;
}