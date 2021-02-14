#pragma once
#include<iostream>
using namespace std;

class Overcoat
{
	char* type;
	float cost;
	char* Gets();
public:
	Overcoat();
	Overcoat(const Overcoat&);
	void Set();
	void Show();
	Overcoat& operator=(const Overcoat&);
	bool operator==(const Overcoat&);
	bool operator>(const Overcoat&);
	~Overcoat() { delete[] type; }
};

