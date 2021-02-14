/*
* 1.	Создайте класс Время, в котором реализованы опера-
* ции сложения, вычитания, сравнения, ввода и вывод
* на экран. Возможность конвертации времени из аме-
* риканского формата am (pm): 10:00 pm = 22:00, 12:00
* pm =00:00.
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
class Time
{
	long hours;// Часы
	long minutes;// Минуты
	long seconds;// Секунды
public:
	// Конструктор по умолчанию
	Time() 
	{
		seconds = 0;
		minutes = 0;
		hours = 0;
	}
	// Перегруженный конструктор
	Time(long hours, long minutes, long seconds) 
	{
		this->seconds = seconds;
		this->minutes = minutes;
		this->hours = hours;
	}
	// Конструктор копирования(на всякий случай)
	Time(const Time& copy)
	{
		hours = copy.hours;
		minutes = copy.minutes;
		seconds = copy.seconds;
	}
	// Преобразование секунд в чч:мм:сс
	void ConvertSecToTime(long sec);
	// Перевод чч:мм:сс в секунды
	long ConvertTimeToSec();
	// Гетеры для переменных класса:
	long getSeconds()
	{
		return seconds;
	}

	long getMinutes()
	{
		return minutes;
	}

	long getHours()
	{
		return hours;
	}

	void setHours(long h)
	{
		this->hours = h;
	}
	// Перегруженный оператор сложения
	Time operator+(const Time& t)
	{
		Time tmp;
		tmp.hours = hours;
		tmp.minutes = minutes;
		tmp.seconds = seconds;
		long l, r, rez;
		l = tmp.ConvertTimeToSec();
		r = (t.hours * 3600) + (t.minutes * 60) + t.seconds;
		rez = l + r;
		tmp.ConvertSecToTime(rez);
		return tmp;
	}
	// Перегруженный оператор вычитания
	Time operator-(const Time& t)
	{
		Time tmp;
		tmp.hours = hours;
		tmp.minutes = minutes;
		tmp.seconds = seconds;
		long l, r, rez, temp;
		l = tmp.ConvertTimeToSec();
		r = (t.hours * 3600) + (t.minutes * 60) + t.seconds;
		if (l < r)
		{
			temp = l;
			l = r;
			r = temp;
			cout << "Входящие параметры поменялись местами!\n";
			Sleep(1500);
		}
		rez = l - r;
		tmp.ConvertSecToTime(rez);
		return tmp;
	}
	// Перегруженный оператор сравнения
	bool operator==(const Time& t)
	{
		if (hours != t.hours || minutes != t.minutes || seconds != t.seconds)
			return false;
		return true;
	}
	// Перегруженный оператор не равно
	bool operator!=(const Time& t)
	{
		return !(*this == t);
	}
	// Оператор вывода на экран объекта класса
	friend ostream& operator << (ostream& os, const Time& t);
	// Оператор заполнения объекта класса
	friend istream& operator >> (istream& is, Time& t);
};
// Реализация некоторых методов класса
ostream& operator << (ostream& os, const Time& t)
{
	if (t.hours < 10)
	{
		os << "0" << t.hours << " ч, ";
	}
	else
	{
		os << t.hours << " ч, ";
	}
	if (t.minutes < 10)
	{
		os << "0" << t.minutes << " мин, ";
	}
	else
	{
		os << t.minutes << " мин, ";
	}
	if (t.seconds < 10)
	{
		os << "0" << t.seconds << " сек";
	}
	else
	{
		os << t.seconds << " сек"; 
	}
	return os;
}

istream& operator >> (istream& is, Time& t)
{
	cout << "Введите время в формате чч:мм:сс (: = пробел)\n";
	is >> t.hours >> t.minutes >> t.seconds;
	return is;
}

void Time::ConvertSecToTime(long sec)
{
	hours = sec / 3600;
	minutes = (sec % 3600) / 60;
	seconds = sec % 60;
}

long Time::ConvertTimeToSec()
{
	long sec;
	sec = (hours * 3600) + (minutes * 60) + seconds;
	return sec;
}

// Класс с методами для меню
class MetodsForMenu
{
public:
	//
	static long ConvTimeToSec()
	{
		Time t1;
		long sec;
		cin >> t1;
		sec = t1.ConvertTimeToSec();
		return sec;
	}
	//
	static Time Add()
	{
		Time tmp, l, r;
		cout << "Первый временной параметр:\n";
		cin >> l;
		cout << "Второй временyой параметр:\n";
		cin >> r;
		tmp = l + r;
		return tmp;
	}
	//
	static Time Dif()
	{
		Time tmp, l, r;
		cout << "Первый временной параметр:\n";
		cin >> l;
		cout << "Второй временyой параметр:\n";
		cin >> r;
		tmp = l - r;
		return tmp;
	}
	//
	static bool/*void*/  Compar()
	{
		Time t1, t2, rez;
		cout << "Первый временной параметр:\n";
		cin >> t1;
		cout << "Второй временной параметр в секудах:\n";
		long r;
		cin >> r;
		t2.ConvertSecToTime(r);
		cout << t1 << " и " << r << " сек - (" << t2 << ")";
		if (t1 == t2)
		{
			cout << "Введенные параметры времени равны!\n";
			Sleep(1500);
			return true;//Вдруг где-то пригодится?
		}
		else
		{
			cout << "Введенные параметры времени не равны\n";
			Sleep(1500);
			return false;
		}
		
	}
	// 
	static Time Converting_time()
	{
		Time tmp1, tmp2(12,0,0);
		short a;
		cout << "Внимание! ЗАЩИТЫ ОТ НЕКОРРЕКТНОГО ВВОДА НЕТ!!!\n";
		cout << "Что введете, то и получите!\n";
		cout << "[1] am\n";
		cout << "[2] pm\n";
		cin >> a;
		cin >> tmp1;
		if (a == 2)
		{
			tmp1 = tmp1 + tmp2;
			if (tmp1.getHours() == 24)
			{
				tmp1.setHours(0);
			}
			return tmp1;
		}
	}
};

// Класс управляющий программой
class Application
{
	enum actions
	{
		conversion = 1,
		add, 
		dif,
		compar,
		Converting_time,
		endProg
	};
private:
	void MainMenu()
	{
		cout << "[1] Преобразование времени\n";
		cout << "[2] Сложение времени\n";
		cout << "[3] Вычитание времени\n";
		cout << "[4] Сравнение времени\n";
		cout << "[5] Конвертация времени из am/pm в h24\n";
		cout << "[6] Выход из программы\n";
	}

	void runAction(int menuAction)
	{
		switch (menuAction)
		{
		case conversion:
			system("cls");
			cout << MetodsForMenu::ConvTimeToSec() << " секунд\n";
			Sleep(3500);
			break;
		case add:
			system("cls");
			cout << MetodsForMenu::Add() << "\n";
			Sleep(3500);
			break;
		case dif:
			system("cls");
			cout << MetodsForMenu::Dif();
			Sleep(3500);
			break;
		case compar:
			system("cls");
			cout << MetodsForMenu::Compar();
			Sleep(3500);
			break;
		case Converting_time:
			system("cls");
			cout << MetodsForMenu::Converting_time();
			Sleep(3500);
			break;
		case endProg:
			system("cls");
			exit(0);
			break;
		
		}
	}

public: 
	void start() 
	{
		int action;
		do
		{
			system("cls");
			MainMenu();
			cin >> action;
			runAction(action);
		}
		while (true);
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color 70");
	Application app;
	app.start();
	return 0;
}