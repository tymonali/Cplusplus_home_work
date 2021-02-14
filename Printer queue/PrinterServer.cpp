#include "PrinterServer.h"

PrinterServer::PrinterServer()
{
	//cout << "PrinterServer()\n";
	Sleep(100);
	count = capasity = 0;
	abns = nullptr;
}

PrinterServer::PrinterServer(int col)
{
	//cout << "PrinterServer(int col)\n";
	Sleep(100);
	this->capasity = col;
	count = 0;
	abns = new Abonents[capasity];
}

PrinterServer::~PrinterServer()
{
	//cout << "~PrinterServer()\n";
	Sleep(100);
	delete[] abns;
}

void PrinterServer::setQueueAbns()
{
	cout << "Запрос на печать:";
	for (int i = 0; i < capasity; i++)
	{
		abns[i].setAbon(i+1);
		add(abns[i]);
		cout << " id " << i + 1 << ";";
		Sleep(500);
	}
	cout << "\n";
}

void PrinterServer::showAbns()
{
	for (int i = 0; i < capasity; i++)
	{
		abns[i].showAbon();
	}
	cout << "\n\n";
}

void PrinterServer::showQueue()
{
	cout << "В очереди: \n";
	for (int i = 0; i < count; i++)
	{
		cout << "id " << i + 1 << " ;";
	}
	cout << "\n";
}

int PrinterServer::getCountAbns()
{
	return count;
}

int PrinterServer::getCapasityAbns()
{
	return capasity;
}

Abonents* PrinterServer::getAbns()
{
	return abns;
}

bool PrinterServer::isEmpty()
{
	return count == 0;
}

bool PrinterServer::isFull()
{
	return count == capasity;
}

void PrinterServer::clear()
{
	count = 0;
}

void PrinterServer::add(Abonents elem)
{
	//cout << "Count = " << count << "\n";
	if (!isFull())
	{
		abns[count++] = elem;
	}
}

Abonents PrinterServer::extract()
{
	if (!isEmpty())
	{
		Abonents tmp = abns[0];

		for (int j = 0; j < tmp.getCapasity(); j++)
		{
			
			cout << "Напечатано: " << tmp.extract() << "\n";
			Sleep(1000);
		}
		for (int i = 1; i < count; i++)
		{
			abns[i - 1] = abns[i];
		}
		count--;
		return tmp;
	}
	else
		cout << "Очередь пуста!!!\n";
}
