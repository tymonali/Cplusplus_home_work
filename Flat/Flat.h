#pragma once
#include<iostream>
using namespace std;

class Flat
{
	char* Addr;
	float Square;
	float Cost;
	char* Gets();
public:
	Flat();
	Flat(Flat&);
	void Set();
	void Show();
	Flat& operator=(const Flat&);
	bool operator>(const Flat&);
	bool operator==(const Flat&);
	~Flat() { delete[] Addr; }
};

