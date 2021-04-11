#pragma once
#include<iostream>
#include<cmath>

using namespace std;

class RootEquat
{
protected:
	double a, b;
public:
	RootEquat(double a, double b);
	virtual void root() = 0;
};

class QuadraticEquation:public RootEquat
{
	double c;
public:
	QuadraticEquation(double a, double b, double c): RootEquat(a,b), c(c){}
	virtual void root() override;
};

class LineEquation:public RootEquat
{
public:
	LineEquation(double a, double b):RootEquat(a,b){}
	virtual void root() override;
};
