#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	phb = nullptr;
	size = 0;
}

PhoneBook::~PhoneBook()
{
	delete[] phb;
}
