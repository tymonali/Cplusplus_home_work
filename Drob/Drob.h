#pragma once
#include<iostream>
using namespace std;

class Drob
{
	int ch;
	int zn;
	int gcd(int, int);//gsd � NOK ������ � �����������
	int NOK(int, int);
	int NOD(int, int);// ������ ���(�������� �������)
public:
	Drob();
	Drob(int, int);
	void Print();
	Drob Add(Drob);
	Drob Subtraction(Drob);
	Drob Multiplication(Drob);
	Drob Division(Drob);
	Drob operator+(const Drob& obj);
	Drob operator-(const Drob& obj);
	Drob operator*(const Drob& obj);
	Drob operator/(const Drob& obj);
};