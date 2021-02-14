#include "AppData.h"

void AppData::Menu()
{
	cout << "[1] �������� ���������\n";
	cout << "[2] ������� �� ����� ���� �����������\n";
	cout << "[3] ������� ��������� �� ������������� ������\n";
	cout << "[4] ������� ��������� �� ��������� �������\n";
	cout << "[0] ����� �� ���������\n";
}

void AppData::MenuAction(int action)
{
	switch (action)
	{
	// [1] �������� ���������
	case 1:
	{
		system("cls");
		int number;
		string str;
		cout << "������� �������������� ����� ������:\n";
		cin >> number;
		cin.ignore();
		for (int i = 0; number < 1000 || number > 9999; i++)
		{
			cout << "����� ������ ���� ��������������!\n";
			cout << "������� ����� ��� ���:\n";
			cin >> number;
			cin.ignore();
		}
		cout << "������� ������ ���������:\n";
		getline(cin, str);
		tree.Add(number, str);
		cout << "���������� ���������!\n";
		Sleep(1000);
		break;
	}
	// [2] ������� �� ����� ���� �����������
	case 2:
	{
		system("cls");
		tree.Print(tree.GetRoot());
		system("pause");
		break;
	}
	// [3] ������� ��������� �� ������������� ������
	case 3:
	{
		system("cls");
		cout << "������� ����� ������\n";
		int number;
		cin >> number;
		cin.ignore();
		for (int i = 0; number < 1000 || number > 9999; i++)
		{
			cout << "����� ������ ���� ��������������!\n";
			cout << "������� ����� ��� ���:\n";
			cin >> number;
			cin.ignore();
		}
		system("cls");
		tree.PrintNumber(number);
		system("pause");
		break;
	}
	// [4] ������� ��������� �� ��������� �������
	case 4:
	{
		system("cls");
		int min, max;
		cout << "������� �������� ������� �����:\n";
		cout << "���: ";
		cin >> min;
		cin.ignore();
		for (int i = 0; min < 1000 || min > 9999; i++)
		{
			cout << "����� ������ ���� ��������������!\n";
			cout << "������� ����� ��� ���:\n";
			cin >> min;
			cin.ignore();
		}
		cout << "����: ";
		cin >> max;
		cin.ignore();
		for (int i = 0; max < 1000 || max > 9999; i++)
		{
			cout << "����� ������ ���� ��������������!\n";
			cout << "������� ����� ��� ���:\n";
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
