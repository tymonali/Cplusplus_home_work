#pragma once
#include "Employer.h"
class Manager:public Employer
{
public:
	Manager(string name):Employer(name){}
	virtual void print() override;
};

