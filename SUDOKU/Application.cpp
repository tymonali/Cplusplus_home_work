#include "Application.h"
#include <conio.h>
void Application::mainMenu()
{
	cout << "[1]   ����������� ������ �������!\n";
	cout << "[2]   ������ ���������� ���������\n";
	cout << "[ESC] �����\n";
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
