#pragma once
#include "Animals.h"
class Location
{
	Fox* foxes;
	Rabbit* rabbits;
	Grass* grass;
	int countFox, countRabbit, countGrass;
	int maxEssence;
	int year;
public:
	Location(int);
	bool addYear();
	void setAge(Animals*, int&);
	void del(Animals*, int&, int);
	void print();
	~Location();
};

