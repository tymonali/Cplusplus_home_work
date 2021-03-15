#pragma once
#include "Manager.h"
class Worker:public Employer
{
public:
	Worker(string name):Employer(name){}
	virtual void print() override;
};

