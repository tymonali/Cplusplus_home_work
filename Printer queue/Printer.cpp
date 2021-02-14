#include "Printer.h"

void Printer::Menu()
{
	cout << "\t\t\tИмитация очереди печати принтера\n\n";
	cout << "\t\t\t\t   [1] Start\n";
	cout << "\t\t\t\t   [0] Exit\n";
}

bool Printer::MenuAction(int action)
{
	switch (action)
	{
	case 0:
	{
		return false;
		break;
	}
	case 1:
	{
		Data();
		return true;
		break;
	}
	}
}

void Printer::Data()
{
	int n;
	cout << "Введите кол-во компьютеров, подключенных к принтеру:\n";
	cin >> n;
	PrinterServer PS(n);
	PS.setQueueAbns();
	PS.showAbns();
	system("pause");
	for (int i = 0; i < PS.getCapasityAbns(); i++)
	{
		cout << "\nid " << i + 1 << ":\n";
		PS.extract();
	}
	system("pause");
}

void Printer::start()
{
	int action;
	while (true)
	{
		system("cls");
		Menu();
		cin >> action;
		if (!MenuAction(action))
		{
			break;
		}
	}
}
