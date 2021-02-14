#include "Abonents.h"

Abonents::Abonents()
{
	id = 0;
	capasity = count = 0;
	pages = nullptr;
}

Abonents::~Abonents()
{
	delete[] pages;
}

Abonents::Abonents(const Abonents& copy)
{
	this->id = copy.id;
	this->capasity = copy.capasity;
	this->count = copy.count;
	pages = new int[capasity];
	for (int i = 0; i < capasity; i++)
	{
		pages[i] = copy.pages[i];
	}
}

Abonents& Abonents::operator=(const Abonents& copy)
{
	if (this->pages != nullptr)
	{
		delete[] pages;
	}
	count = copy.count;
	capasity = copy.capasity;
	id = copy.id;
	pages = new int[capasity];
	for (int i = 0; i < capasity; i++)
	{
		pages[i] = copy.pages[i];
	}
	return *this;
}

void Abonents::setAbon(int number)
{
	id = number;
	count = rand() % 10 + 1; //Кол-во страниц рандомно
	capasity = count;
	pages = new int[count];
	for (int i = 0; i < count; i++)
	{
		pages[i] = rand() % 100 + 1; //Рандомное содержание страницы
		add(pages[i]);	// Добавляем страницу в очередь
	}
}

void Abonents::showAbon()
{
	cout << "-----\n";
	cout << "id " << id << "\n";
	cout << "-------------------------\n";
	cout << "Страниц сформировано: " << count << "\n";
	cout << "-------------------------\n";
	int h = count * 4;
	for (int i = 0; i < h; i++)
	{
		cout << "-";
	}
	cout << "\n";
	for (int i = 0; i < count; i++)
	{
		cout << setw(3) << pages[i] << "|"; // #include <iomanip>
	}
	cout << "\n";
	for (int i = 0; i < h; i++)
	{
		cout << "-";
	}
	cout << "\n\n";
}

int* Abonents::getPages()
{
	return pages;
}

int Abonents::getCount()
{
	return count;
}

int Abonents::getID()
{
	return id;
}

int Abonents::getCapasity()
{
	return capasity;
}

void Abonents::clear()
{
	count = 0;
}

bool Abonents::isEmpty()
{
	return count == 0;
}

bool Abonents::isFull()
{
	return count == capasity;
}

void Abonents::add(int elem)
{
	if (!isFull())
	{
		pages[count++] = elem;
	}
}

int Abonents::extract()
{
	if (!isEmpty())
	{
		int tmp = pages[0];
		//memcpy(pages, pages + 1, count);
		for (int i = 1; i < count; i++)
		{
			pages[i - 1] = pages[i];
		}
		count--;
		return tmp;
	}
	else
		return-1;
}
