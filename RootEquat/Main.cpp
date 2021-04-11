#include"RootEquat.h"
#include <Windows.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");
	QuadraticEquation qe(9, 8, 1);
	LineEquation le(6, 36);
	qe.root();
	le.root();
}