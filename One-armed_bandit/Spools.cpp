#include "Spools.h"

Spools::Spools()
{
	cout << "сработка конструктора по умолчанию Spools()!!!\n";
	Sleep(1000);
	Elem_of_Spool = 0;
	Suit_Number = 0;
	Suit = 0;
	Spool = nullptr;
}

Spools::Spools(int n, char first)
{
	Elem_of_Spool = n;
	Suit_Number = first;
	Spool = new char[n];
	// «аполнение катушки маст€ми
	for (int i = 0; i < n; i++)
	{
		Spool[i] = i + Suit_Number;
	}
	// ¬ыпавша€ масть
	Suit = Spool[rand() % n];
}

bool Spools::Rotation()
{
	int rollcount = rand() % 500;
	Suit = Spool[rollcount % Elem_of_Spool];
	return true;
}

char Spools::Show()
{
	return Suit;
}


Spools::~Spools()
{
	delete[] Spool;
}