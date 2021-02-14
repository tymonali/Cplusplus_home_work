#pragma once
#include<iostream>
using namespace std;
class Drob
{
	int chisl;
	int znam;
public:
	Drob();
	void Set();
	void Sum(Drob);
	void Razn(Drob);
	void Prod(Drob);
	void Div(Drob);
	void Print();
	Drob operator+(Drob&);
	Drob operator-(Drob&);
	Drob operator*(Drob&);
	Drob operator/(Drob&);
	Drob& operator++();
	Drob operator++(int);
	Drob& operator--();
	Drob operator--(int);
};
