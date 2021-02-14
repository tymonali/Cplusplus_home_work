#include"TemplateArray.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	Array<int> mas, mas1;
	mas.SetSize(3, 5);
	mas.Add(5);
	mas.Add(10);
	mas.SetAt(2, 20);
	int tmp = mas.GetAt(2);
	cout << tmp << endl;
	mas1.SetSize(4, 5);
	mas1.Add(30);
	mas1.Add(40);
	mas.Append(mas1);
	tmp = mas.GetAt(3);
	cout << tmp << endl;
	mas.SetAt(5, 50);
	tmp = mas.GetAt(5);
	cout << tmp << endl;
	tmp = mas.GetAt(6);
	cout << tmp << endl;
	cout << mas.GetData() << endl;
	mas.InsertAt(5, 45);
	tmp = mas.GetAt(5);
	
	cout << tmp << endl;
	mas.RemoveAt(5);
	tmp = mas.GetAt(5);
	cout << tmp << endl;
}