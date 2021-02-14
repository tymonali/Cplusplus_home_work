#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	book = nullptr;
	size = 0;
}

PhoneBook::~PhoneBook()
{
	cout << "Деструктор\n";
	delete[] book;
}

void PhoneBook::AddCont()
{
	Contact* tmp = new Contact[size + 1];
	if (book != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			tmp[i] = book[i];
		}
		tmp[size].setContact();
		delete[]book;
		book = tmp;
		size++;
	}
	else
	{
		book = new Contact[size + 1];
		book[0].setContact();
		size++;
	}
	// Сразу сортируем
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (_stricmp(book[j].FIO, book[j + 1].FIO) > 0)
			{
				Contact tmp = book[j];
				book[j] = book[j + 1];
				book[j + 1] = tmp;
			}
		}
	}
}

void PhoneBook::editCont(int pos)
{
	book[pos - 1].setContact();
}

void PhoneBook::showBook()
{
	for (int i = 0; i < size; i++)
	{
		cout << "№ " << i + 1 << "\n";
		book[i].showContact();
	}
	cout << "\n";
}

int& PhoneBook::getSize()
{
	return size;
}

Contact*& PhoneBook::getBook()
{
	return book;
}

void PhoneBook::findByFIO()
{
	char tmpFIO[100];
	cout << "Введите ФИО искомого контакта:\n";
	gets_s(tmpFIO);
	bool f = false;
	int sizetmp = 0;
	for (int i = 0; i < size; i++)
	{
		if (_stricmp(book[i].FIO, tmpFIO) == 0)
		{
			f = true;
			sizetmp++;
			cout << "№ " << i + 1 << "\n";
			book[i].showContact();
		}
	}
	if (f == false)
	{
		cout << "Такого контакта нет в телефонной книге!\n";
	}
	else 
	{
		cout << "\nСохранить результат поиска в файл?\n";
		cout << "[1] да\n[2] нет\n";
		int num;
		cin >> num;
		cin.ignore();
		if (num == 1)
		{
			Contact* tmp = new Contact[sizetmp];
			int j = 0;
			for (int i = 0; i < size; i++)
			{
				if (_stricmp(book[i].FIO, tmpFIO) == 0)
				{
					tmp[j] = book[i];
					j++;
				}
			}
			Write_File(tmp, sizetmp, "search.txt");
			delete[] tmp;
		}
	}
}

void PhoneBook::findByNum()
{
	char tmpNUM[20];
	cout << "Введите номер телефона искомого контакта:\n";
	gets_s(tmpNUM);
	bool f = false;
	int sizetmp = 0;
	for (int i = 0; i < size; i++)
	{
		if (_stricmp(book[i].mobilenum, tmpNUM) == 0 || _stricmp(book[i].homenum, tmpNUM) == 0)
		{
			f = true;
			sizetmp++;
			cout << "№ " << i + 1 << "\n";
			book[i].showContact();
		}
	}
	if (f == false)
	{
		cout << "Контакта с таким номером нет в телефонной книге!\n";
	}
	else
	{
		cout << "\nСохранить результат поиска в файл?\n";
		cout << "[1] да\n[2] нет\n";
		int num;
		cin >> num;
		cin.ignore();
		if (num == 1)
		{
			Contact* tmp = new Contact[sizetmp];
			int j = 0;
			for (int i = 0; i < size; i++)
			{
				if (_stricmp(book[i].mobilenum, tmpNUM) == 0 || _stricmp(book[i].homenum, tmpNUM) == 0)
				{
					tmp[j] = book[i];
					j++;
				}
			}
			Write_File(tmp, sizetmp, "search.txt");
			delete[] tmp;
		}
	}
}

void PhoneBook::deletePos(int pos)
{
	Contact* tmp = new Contact[size - 1];
	for (int i = 0; i < pos - 1; i++)
	{
		tmp[i] = book[i];
		cout << "tmp[" << i + 1 << "] = book[" << i + 1 << "]\n";		
	}
	for (int i = pos; i < size; i++)
	{
		tmp[i-1] = book[i];
		cout << "tmp[" << i + 1 << "] = book[" << i + 1 << "]\n";
	}
	delete[] book;
	book = tmp;
	cout << "Контакт Удален!\n";
	Sleep(1000);
	size--;
}

void PhoneBook::Write_File(Contact* mas, int n, const char* puth)
{
	FILE* pf;
	fopen_s(&pf, puth, "w");
	if (pf)
	{
		fwrite(&n, sizeof(n), 1, pf);
		fwrite(mas, sizeof(mas[0]), n, pf);
		fclose(pf);
		cout << "Файл записан успешно!!!\n";
		Sleep(1000);
	}
	else
	{
		cout << "Error.\n";
	}
}

void PhoneBook::Read_File(Contact*& mas, int& n, const char* puth)
{
	FILE* pf;
	fopen_s(&pf, puth, "r");
	if (pf)
	{
		fread(&n, sizeof(n), 1, pf);
		mas = (Contact*)malloc(n * sizeof(Contact));
		fread(mas, sizeof(mas[0]), n, pf);
		fclose(pf);
		cout << "Файл успешно считан!!!\n";
		Sleep(1000);
	}
	else
	{
		cout << "Error.\n";
	}
}
