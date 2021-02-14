#pragma once
#include"Abonents.h"
class PrinterServer
{
	int count;
	int capasity;
	Abonents* abns;
public:
	PrinterServer();
	PrinterServer(int col);
	~PrinterServer();

	void setQueueAbns();
	void showAbns();
	void showQueue();
	int getCountAbns();
	int getCapasityAbns();
	Abonents* getAbns();

	bool isEmpty();
	bool isFull();
	void clear();
	void add(Abonents elem);
	Abonents extract();
};

