#include "Application.h"

Application::Application()
{
	newLocation = nullptr;
}

Application::~Application()
{
	delete newLocation;
}

void Application::startLife()
{
	char ch;
	while (true)
	{
		cout << "Начать новую историю? (y/n)\n";
		ch = getchar();
		switch (ch)
		{
		case 'y':
		{
			newLocation = new Location(10);
			runApp();
			break;
		}
		case 'n':
			exit(0);
		default:
			break;
		}
	}
}

bool Application::runApp()
{
	while (true)
	{
		if (!newLocation->addYear())
		{
			cout << "Конец истории!";
			break;
		}
	}
	return false;
}
