#include "Application.h"
#include <conio.h>
void Application::mainMenu()
{
	cout << "[1]   Просмотреть пример решения!\n";
	cout << "[2]   Ввести нерешенный кроссворд\n";
	cout << "[ESC] Выход\n";
}

void Application::start()
{
	while (true) 
	{
		system("cls");
		mainMenu();
		switch(_getch())
		{
		case 49:
			system("cls");
			g.check();
			system("pause");
			g.solveSudoku();
			g.check();
			system("pause");
			break;
		case 50:
			g.Fill_In_Manually();
			g.check();
			system("pause");
			g.solveSudoku();
			g.check();
			system("pause");
			break;
		case 27:
			exit(0);
		}
	}
}
