#include "GeometricFigures.h"

GeometricFigures::GeometricFigures()
{
	a = 0;
	b = 0;
}

GeometricFigures::GeometricFigures(double a, double b)
{
	this->a = a;
	this->b = b;
}

double _Rectangle::square()
{
	return a * b;
}

Circle::Circle(double radius)
{
	this->radius = radius;
}

double Circle::square()
{
	return M_PI * pow(radius, 2) / 2;
}

double Rtriangle::square()
{
	return a * b / 2;
}

double Trapezoid::square()
{
	return (a + b) * h / 2;
}
