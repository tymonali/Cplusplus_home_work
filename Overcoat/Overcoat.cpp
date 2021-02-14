#include "Overcoat.h"

char* Overcoat::Gets()
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

Overcoat::Overcoat()
{
	type = nullptr;
	cost = 0;
}

Overcoat::Overcoat(const Overcoat& copy)
{
	this->type = new char[strlen(copy.type) + 1];
	this->type = copy.type;
	this->cost = copy.cost;
}

void Overcoat::Set()
{
	char* tmp;
	cout << "Enter type of the overcoat:\n";
	tmp = Gets();
	type = new char[strlen(tmp) + 1];
	strcpy_s(type, strlen(tmp) + 1, tmp);
	cout << "Enter cost of the overcoat:\n";
	cin >> cost;
	cin.ignore();
}

void Overcoat::Show()
{
	cout << "Type: " << type << "\n";
	cout << "Cost: " << cost << "\n";
}

Overcoat& Overcoat::operator=(const Overcoat& copy)
{
	if (this->type != nullptr) delete[] type;
	this->type = new char[strlen(copy.type) + 1];
	this->type = copy.type;
	this->cost = copy.cost;
	return *this;
}

bool Overcoat::operator==(const Overcoat& obj)
{
	if (strcmp(this->type, obj.type) == 0) return true;
	return false;
}

bool Overcoat::operator>(const Overcoat& obj)
{
	if (this->cost > obj.cost) return true;
	return false;
}
