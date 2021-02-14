#include"Drob.h"
#include<conio.h>
int main()
{
	int x, y;
	setlocale(LC_ALL, "");
	cout << "Введите числитель первой дроби => ";
	cin >> x;
	cout << "Введите знаменатель первой дроби => ";
	cin >> y;
	if (y == 0)
	{
		while (y == 0)
		{
			cout << "Знаменатель не может быть равным нулю\n";
			cout << "Введите значение еще раз => ";
			cin >> y;
		}
	}
	Drob d1(x, y);
	d1.Print();
	cout << "\nВведите числитель второй дроби => ";
	cin >> x;
	cout << "Введите знаменатель второй дроби => ";
	cin >> y;
	if (y == 0)
	{
		while (y == 0)
		{
			cout << "Знаменатель не может быть равным нулю\n";
			cout << "Введите значение еще раз => ";
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
		cout << "\t Меню\n";
		cout << "1. Сложение \n";
		cout << "2. Вычитание \n";
		cout << "3. Умножение \n";
		cout << "4. Деление \n";
		cout << "0. Выход \n";
		cin >> t;
		switch (t)
		{
		case 1:
		{
			system("cls");
			rez = d1 + d2;
			rez.Print();
			cout << "Возврат в меню - клавиша Enter\n";
			cout << "Выход из программы - клавиша Esc\n";
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
			cout << "Возврат в меню - клавиша Enter\n";
			cout << "Выход из программы - клавиша Esc\n";
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
			cout << "Возврат в меню - клавиша Enter\n";
			cout << "Выход из программы - клавиша Esc\n";
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
			cout << "Возврат в меню - клавиша Enter\n";
			cout << "Выход из программы - клавиша Esc\n";
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