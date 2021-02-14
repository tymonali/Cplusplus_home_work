#pragma once
#include"Contañt.h"

class PhoneBook
{
	Contact* book;
	int size;
public:
	PhoneBook();
	~PhoneBook();

	void AddCont();
	void editCont(int pos);
	void showBook();
	int& getSize();
	Contact*& getBook();
	void findByFIO();
	void findByNum();
	void deletePos(int pos);
	void Write_File(Contact* mas, int n, const char* puth);
	void Read_File(Contact*& mas, int& n, const char* puth);
	
};

