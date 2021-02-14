#include"Printer.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");
	srand(time(0));

	Printer p;

	p.start();

	return 0;
}