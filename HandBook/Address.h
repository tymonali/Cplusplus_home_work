#pragma once
#include <iostream>
#include <string>
#include<Windows.h>
#include<fstream>

using namespace std;

class Address
{
	string street;		//название улицы
	int houseNum;			//номер дома
	int roomNum;			//номер квартиры
	string StreetType;		//тип улицы
public:
	Address();
	Address(string street, int houseNum, int roomNum, string streetType);
	void addAddress();
	void Print(Address& obj);
};