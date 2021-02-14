#include"TemplateQueue.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	TemplateQueue<int> tq(8);
	cout << "Count = " << tq.getCount() << "\n";
	cout << "Capacity = " << tq.getCapacity() << "\n";

	tq.Add(100);
	tq.Add(200);
	tq.Add(300);
	tq.Add(400);
	tq.Add(500);
	tq.Add(600);
	tq.PrintL();
	tq.PrintQ();
	tq.addToTail(700);
	tq.addToTail(800);
	tq.Add(900);
	tq.PrintL();
	tq.PrintQ();
	int j = tq.Extract();
	cout << "Extrakt: " << j << "\n";
	cout << "Count = " << tq.getCount() << "\n";
	tq.PrintQ();
	tq.PrintL();

	return 0;
}