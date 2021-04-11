#include "RootEquat.h"

RootEquat::RootEquat(double a, double b)
{
	this->a = a;
	this->b = b;
}

void QuadraticEquation::root()
{
	double d, x1, x2;
	d = pow(b, 2) - 4 * a * c;
	if (d < 0)
	{
		cout << "Нет корней у этого уравнения!\n";
	}
	else if (d > 0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		cout << "x1=" << x1 << "; x2=" << x2 << endl;
	}
	else
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		cout << "x1=" << x1 << endl;
	}
}

void LineEquation::root()
{
	cout << a << "x" << "=" << b << endl;
	cout << "x=" << b / a << endl;
}
