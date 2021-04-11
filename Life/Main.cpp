#include <time.h>
#include "Application.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");
	srand(time(0));
	Application* newApplication = new Application;
	newApplication->startLife();
}