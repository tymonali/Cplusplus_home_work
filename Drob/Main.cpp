#include"Drob.h"
#include<conio.h>
int main()
{
	int x, y;
	setlocale(LC_ALL, "");
	cout << "������� ��������� ������ ����� => ";
	cin >> x;
	cout << "������� ����������� ������ ����� => ";
	cin >> y;
	if (y == 0)
	{
		while (y == 0)
		{
			cout << "����������� �� ����� ���� ������ ����\n";
			cout << "������� �������� ��� ��� => ";
			cin >> y;
		}
	}
	Drob d1(x, y);
	d1.Print();
	cout << "\n������� ��������� ������ ����� => ";
	cin >> x;
	cout << "������� ����������� ������ ����� => ";
	cin >> y;
	if (y == 0)
	{
		while (y == 0)
		{
			cout << "����������� �� ����� ���� ������ ����\n";
			cout << "������� �������� ��� ��� => ";
			cin >> y;
		}
	}
	Drob d2(x, y);
	d2.Print();
	cout << "\n";
	Drob rez;
	int t;
	do
	{
		system("cls");
		cout << "\t ����\n";
		cout << "1. �������� \n";
		cout << "2. ��������� \n";
		cout << "3. ��������� \n";
		cout << "4. ������� \n";
		cout << "0. ����� \n";
		cin >> t;
		switch (t)
		{
		case 1:
		{
			system("cls");
			rez = d1 + d2;
			rez.Print();
			cout << "������� � ���� - ������� Enter\n";
			cout << "����� �� ��������� - ������� Esc\n";
			char ch;
			ch = _getch();
			if (ch == 27) t = 0;
			break;
		}
		case 2:
		{
			system("cls");
			rez = d1 - d2;
			rez.Print();
			cout << "������� � ���� - ������� Enter\n";
			cout << "����� �� ��������� - ������� Esc\n";
			char ch;
			ch = _getch();
			if (ch == 27) t = 0;
			break;
		}
		case 3:
		{
			system("cls");
			rez = d1 * d2;
			rez.Print();
			cout << "������� � ���� - ������� Enter\n";
			cout << "����� �� ��������� - ������� Esc\n";
			char ch;
			ch = _getch();
			if (ch == 27) t = 0;
			break;
		}
		case 4:
		{
			system("cls");
			rez = d1 / d2;
			rez.Print();
			cout << "������� � ���� - ������� Enter\n";
			cout << "����� �� ��������� - ������� Esc\n";
			char ch;
			ch = _getch();
			if (ch == 27) t = 0;
			break;
		}
		case 0:
		{
			exit(0);
		}
		default:
			break;
		}
	} while (t != 0);
	return 0;
}