#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include <iomanip>
using namespace std;

class Spools
{
	int Elem_of_Spool;		// ���������� ��������� � �������
	char* Spool;            // ���� ������� � ����������
	char Suit_Number;		// ������ ����� � ������� (� 3)
	char Suit;			    // ����� �������� �� �������
public:
	// ����������� �� ���������
	Spools();
	// ������������� �����������
	Spools(int n, char first);
	// �������� �������
	bool Rotation();
	// ����� �����
	char Show();
	// ����������
	~Spools();
};