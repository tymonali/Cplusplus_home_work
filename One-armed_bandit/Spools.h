#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include <iomanip>
using namespace std;

class Spools
{
	int Elem_of_Spool;		// Количество элементов в катушке
	char* Spool;            // Одна катушка с элементами
	char Suit_Number;		// Первая масть в таблице (№ 3)
	char Suit;			    // Масть выпавшая на катушке
public:
	// Конструктор по умолчанию
	Spools();
	// Перегруженный конструктор
	Spools(int n, char first);
	// Вращение катушки
	bool Rotation();
	// Вывод масти
	char Show();
	// Деструктор
	~Spools();
};