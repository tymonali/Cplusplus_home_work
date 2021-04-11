#include "GeometricFigures.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");
	
	GeometricFigures* fig[4] = {new _Rectangle(52.4, 65.2),
								new Circle(25.5),
								new Rtriangle(5.3, 7.8),
								new Trapezoid(14.1,18.4, 10.5)};
	cout << "Прямоугольник S = " << fig[0]->square() << endl;
	cout << "Круг S = " << fig[1]->square() << endl;
	cout << "Треугольник S = " << fig[2]->square() << endl;
	cout << "Трапеция S = " << fig[3]->square() << endl;
}