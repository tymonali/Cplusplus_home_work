#pragma once
#pragma once
#include<iostream>
using namespace std;
class Mass
{
	int* mas;
	int size;
	static int kol;
public:
	Mass();
	explicit Mass(int);
	Mass(const Mass&);
	Mass(Mass&&);
	static int GetKol();
	Mass& operator=(const Mass&);
	Mass& operator=(Mass&&);
	Mass operator+(const Mass&);
	Mass operator+(const int&) const;
	bool operator==(const Mass&);
	bool operator!=(const Mass&);
	Mass& operator++();
	Mass operator++(int);
	int& operator[](int);
	int operator()(int);
	explicit operator int();
	void Rand() const;
	void Print() const;
	~Mass();
	friend ostream& operator<<(ostream&, const Mass&);
	friend istream& operator>>(istream& is, Mass&);
};

Mass operator+(const int&, const Mass&);


