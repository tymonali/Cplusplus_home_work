#include "Flat.h"

char* Flat::Gets()
{
	char* tmp = nullptr;
	int n = 0;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		tmp = (char*)realloc(tmp, n + 1);
		tmp[n] = ch;
		n++;
	}
	tmp = (char*)realloc(tmp, n + 1);
	tmp[n] = 0;
	return tmp;
}

Flat::Flat()
{
	Addr = nullptr;
	Square = 0;
	Cost = 0;
}

Flat::Flat(Flat& copy)
{
	this->Addr = new char[strlen(copy.Addr) + 1];
	strcpy_s(this->Addr, strlen(copy.Addr) + 1, copy.Addr);
	this->Square = copy.Square;
	this->Cost = copy.Cost;
}

void Flat::Set()
{
	char* tmp;
	cout << "Enter the addres of the flat:\n";
	tmp = Gets();
	this->Addr = new char[strlen(tmp) + 1];
	strcpy_s(this->Addr, strlen(tmp) + 1, tmp);
	cout << "Enter the square of the flat:\n";
	cin >> this->Square;
	cout << "Enter the cost of the flat:";
	cin >> this->Cost;
	cin.ignore();
}

void Flat::Show()
{
	cout << "Address: " << this->Addr << "\n";
	cout << "Square: " << this->Square << "\n";
	cout << "Cost: " << this->Cost << "\n";
}

Flat& Flat::operator=(const Flat& copy)
{
	if (this->Addr != nullptr) delete[] this->Addr;
	this->Addr = new char[strlen(copy.Addr) + 1];
	strcpy_s(this->Addr, strlen(copy.Addr) + 1, copy.Addr);
	this->Square = copy.Square;
	this->Cost = copy.Cost;
	return *this;
}

bool Flat::operator>(const Flat& obj)
{
	if (this->Cost > obj.Cost) return true;
	return false;
}

bool Flat::operator==(const Flat& obj)
{
	if (this->Square == obj.Square) return true;
	return false;
}
