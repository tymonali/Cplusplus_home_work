#include"Flat.h"

int main()
{
	Flat obj1, obj2, obj3;
	obj1.Set();
	obj2.Set();
	obj3 = obj1;
	cout << "Obj1\n";
	obj1.Show();
	cout << "Obj2\n";
	obj2.Show();
	cout << "Obj3\n";
	obj3.Show();
	if (obj2 == obj3)
	{
		cout << "This flats are the same.\n";
	}
	else
	{
		cout << "This flats are not the same.\n";
	}
	if (obj2 > obj3)
	{
		cout << "obj2 is more expensive then a obj3.\n";
	}
	else
	{
		cout << "obj2 is not more expensive then a obj3.\n";
	}
}