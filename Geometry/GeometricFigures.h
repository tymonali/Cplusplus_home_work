#pragma once
#define _USE_MATH_DEFINES
#include<iostream>

#include<cmath>
#include<math.h>

using namespace std;

class GeometricFigures
{
protected:
	double a;
	double b;
public:
	GeometricFigures();
	GeometricFigures(double, double);
	virtual double square() = 0;
};

class _Rectangle:public GeometricFigures
{
public:
	_Rectangle(double a, double b):GeometricFigures(a,b){}
	virtual double square() override;
};

class Circle: public GeometricFigures
{
	double radius;
public:
	Circle(double);
	virtual double square() override;
};

class Rtriangle : public GeometricFigures
{
public:
	Rtriangle(double a, double b) : GeometricFigures(a, b) {}
	// ”наследовано через Figure
	virtual double square() override;
};

class Trapezoid :public GeometricFigures
{
	double h;
public:
	Trapezoid(double a, double b, double h) : GeometricFigures(a, b), h(h) {}
	// ”наследовано через Figure
	virtual double square() override;
};
