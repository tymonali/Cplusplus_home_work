#pragma once
#include <iostream>
#include<Windows.h>

using namespace std;

class Animals
{
protected:
	int age, maxAge;
	int level;
	int increment;
public:
	Animals();
	Animals(int);
	bool setAge();
	int getIncrement();
};

class Fox: public Animals
{
public:
	Fox():Animals(){}
	Fox(int age) :Animals(age)
	{
		level = 0;
		increment = 1;
	}
};

class Rabbit:public Animals
{
public:
	Rabbit():Animals(){}
	Rabbit(int age):Animals(age)
	{
		level = 1;
		increment = 2;
	}
};

class Grass:public Animals
{
public:
	Grass():Animals(){}
	Grass(int age):Animals(age)
	{
		level = 2;
		increment = 4;
	}
};