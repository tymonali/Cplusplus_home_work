#pragma once
#include<iostream>
using namespace std;

class String
{
	char* str;
	char* Gets();
public:
	String();
	String(int);
	String(const char*);
	void Set();
	char* Get() { return str; }
	void Show() { cout << str << "\n"; }
	String& operator=(const String&);
	char& operator[](int);
	int operator()(char);
	operator int();
	String& operator++();
	String operator++(int);
	String& operator--();
	String operator--(int);
	~String();
};

