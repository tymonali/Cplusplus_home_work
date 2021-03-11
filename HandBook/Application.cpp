#include "Application.h"

void Application::start()
{
	hb = new HandBook;
	hb->load();
	int action;
	while(true)
	{
		system("cls");
		mainMenu();
		cin >> action;
		cin.ignore();
		switch(action)
		{
		case 0:
			exit(0);
			break;
		case 1:
			hb->add();
			break;
		case 2:
			hb->search();
			break;
		case 3:
			hb->show();
			break;
		case 4:
			hb->save();
		default:
			break;
		}
	}
}

void Application::mainMenu()
{
	cout << "Select action:\n";
	cout << "[1] Add record;\n";
	cout << "[2] Find record(s);\n";
	cout << "[3] Show all records\n";
	cout << "[4] Save to file;\n";
	cout << "[0] Exit.\n";
}
