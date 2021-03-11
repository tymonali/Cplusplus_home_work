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
    Undef,		//�� ��������
    Avenue,		//��������
    Lane,		//��������
    Boulevard	//�������
};

class Address
{
    string street;		    //�������� �����
    int houseNum;			//����� ����
    int roomNum;			//����� ��������
    StreetType type;		//��� �����
public:
    Address();
    Address(string street, int houseNum, int roomNum, StreetType type);
    void show();
    bool operator == (const Address& obj);
    friend ostream& operator << (ostream& os, Address& obj);
    inline friend istream& operator >> (istream& is, StreetType& obj);
    friend istream& operator >> (istream& is, Address& obj);
};


