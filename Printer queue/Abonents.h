#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <time.h>

using namespace std;

class Abonents
{
	int id;				// ����� ����������
	int capasity;		// ���-�� �������
	int count;			// ���-�� ��������� � �������
	int* pages;			// �������� �� ������
public:
	Abonents();			// �����������
	~Abonents();		// ����������
	Abonents(const Abonents& copy);// ����������� �����������
	Abonents& operator=(const Abonents& copy);// ������������� �������� ������������

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

