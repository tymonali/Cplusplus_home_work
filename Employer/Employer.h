#pragma once
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

class Employer
{
protected:
	string name;
public:
	Employer(string name);
	virtual void print() = 0;
};
