#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <io.h>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::istream;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::fstream;

enum StreetType {
    Undef,		//не известно
    Avenue,		//проспект
    Lane,		//переулок
    Boulevard	//бульвар
};

class Address
{
    string street;		    //название улицы
    int houseNum;			//номер дома
    int roomNum;			//номер квартиры
    StreetType type;		//тип улицы
public:
    Address();
    Address(string street, int houseNum, int roomNum, StreetType type);
    void show();
    bool operator == (const Address& obj);
    friend ostream& operator << (ostream& os, Address& obj);
    inline friend istream& operator >> (istream& is, StreetType& obj);
    friend istream& operator >> (istream& is, Address& obj);
};


