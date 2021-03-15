#pragma once
#include "Worker.h"
class President:public Employer
{
public:
	President(string name):Employer(name){}
	virtual void print()override;
};

