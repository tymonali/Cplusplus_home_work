#pragma once
#include "Contacts.h"


class PhoneBook
{
	Contacts* phb;
	int size;
public:
	PhoneBook();
	~PhoneBook();

	void add();
	void print();

};

