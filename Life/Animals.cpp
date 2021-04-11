#include "Animals.h"

Animals::Animals()
{
	age = 0;
	maxAge = 0;
	level = 0;
	increment = 0;
}

Animals::Animals(int maxAge)
{
	this->maxAge = maxAge;
	this->age = rand() % maxAge + 1;
}

bool Animals::setAge()
{
	if(age < maxAge)
	{
		this->age++;
		return true;
	}
	else 
	{
		return false;
	}
}

int Animals::getIncrement()
{
	return increment;
}
