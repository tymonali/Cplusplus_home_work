#pragma once
#include <iostream>
#include <string>
#include<Windows.h>
#include<fstream>

using namespace std;

class Address
{
	string street;		//�������� �����
	int houseNum;			//����� ����
	int roomNum;			//����� ��������
	string StreetType;		//��� �����
public:
	Address();
	Address(string street, int houseNum, int roomNum, string streetType);
	void addAddress();
	void Print(Address& obj);
};