#include"LinkedList.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	LinkedList list;

	list.addToHead(100);
	list.addToHead(200);
	list.addToHead(300);
	list.addToHead(400);
	list.addToHead(500);
	list.addToHead(600);

	list.print();

	list.removeFromTail();

	list.print();

	list.insert(3, 900);

	list.insert(4,800);

	list.print();

	cout << list.search(300) << endl;

	system("pause");
	return 0;
}