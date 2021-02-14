#include "AppData.h"

void AppData::Menu()
{
	cout << "[1] Добавить нарушение\n";
	cout << "[2] Вывести на экран базу нарушителей\n";
	cout << "[3] Вывести нарушения по определенному номеру\n";
	cout << "[4] Вывести нарушения по диапазону номеров\n";
	cout << "[0] Выход из программы\n";
}

void AppData::MenuAction(int action)
{
	switch (action)
	{
	// [1] Добавить нарушение
	case 1:
	{
		system("cls");
		int number;
		string str;
		cout << "Введите четырехзначный номер машины:\n";
		cin >> number;
		cin.ignore();
		for (int i = 0; number < 1000 || number > 9999; i++)
		{
			cout << "Номер должен быть четырехзначным!\n";
			cout << "Введите номер еще раз:\n";
			cin >> number;
			cin.ignore();
		}
		cout << "Введите статью нарушения:\n";
		getline(cin, str);
		tree.Add(number, str);
		cout << "Информация добавлена!\n";
		Sleep(1000);
		break;
	}
	// [2] Вывести на экран базу нарушителей
	case 2:
	{
		system("cls");
		tree.Print(tree.GetRoot());
		system("pause");
		break;
	}
	// [3] Вывести нарушения по определенному номеру
	case 3:
	{
		system("cls");
		cout << "Введите номер машины\n";
		int number;
		cin >> number;
		cin.ignore();
		for (int i = 0; number < 1000 || number > 9999; i++)
		{
			cout << "Номер должен быть четырехзначным!\n";
			cout << "Введите номер еще раз:\n";
			cin >> number;
			cin.ignore();
		}
		system("cls");
		tree.PrintNumber(number);
		system("pause");
		break;
	}
	// [4] Вывести нарушения по диапазону номеров
	case 4:
	{
		system("cls");
		int min, max;
		cout << "Введите диапазон номеров машин:\n";
		cout << "Мин: ";
		cin >> min;
		cin.ignore();
		for (int i = 0; min < 1000 || min > 9999; i++)
		{
			cout << "Номер должен быть четырехзначным!\n";
			cout << "Введите номер еще раз:\n";
			cin >> min;
			cin.ignore();
		}
		cout << "Макс: ";
		cin >> max;
		cin.ignore();
		for (int i = 0; max < 1000 || max > 9999; i++)
		{
			cout << "Номер должен быть четырехзначным!\n";
			cout << "Введите номер еще раз:\n";
			cin >> max;
			cin.ignore();
		}
		system("cls");
		tree.PrintByRange(min, max, tree.GetRoot());
		system("pause");
		break;
	}
	case 0:
	{
		system("cls");
		exit(0);
		break;
	}
	}
}

void AppData::Start()
{
	while (true)
	{
		system("cls");
		Menu();
		int action;
		cin >> action;
		cin.ignore();
		MenuAction(action);
	}
}
