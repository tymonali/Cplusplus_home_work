#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <time.h>

using namespace std;

class Abonents
{
	int id;				// Номер устройства
	int capasity;		// Кол-во страниц
	int count;			// Кол-во элементов в очереди
	int* pages;			// Страницы на печать
public:
	Abonents();			// Конструктор
	~Abonents();		// Деструктор
	Abonents(const Abonents& copy);// Конструктор копирования
	Abonents& operator=(const Abonents& copy);// Перегруженный оператор присваивания

	void setAbon(int number);
	void showAbon();
	int* getPages();
	int getCount();
	int getID();
	int getCapasity();

	void clear();
	bool isEmpty();
	bool isFull();
	void add(int elem);
	int extract();
};

