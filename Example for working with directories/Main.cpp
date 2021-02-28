#include <iostream>
#include <direct.h>
#include <cstdio>
#include <Windows.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Переименовать существующую директорию
void RenameDirectory();

//Удалить существующую директорию
void RemoveDirectory();

//создать директорию
void CreateDirectory();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	cout << "Введите номер операции:\n";
	char ch;
	do
	{
		cout << "[1] Переименовать\n";
		cout << "[2] Удалить\n";
		cout << "[3] Создать\n";
		cout << "[0] выход\n";
		cin >> ch;
		cin.ignore();

		switch (ch)
		{
		case '1':
			RenameDirectory();
			break;
		case '2':
			RemoveDirectory();
			break;
		case '3':
			CreateDirectory();
			break;
		}
	}
	while (ch != '0');
	
	return 0;
}

//Переименовать существующую директорию
void RenameDirectory()
{
	string oldName, newName;
	
	//В одной переменной запомним
	//существующее имя (oldName),
	cout << "Введите старое имя:\n";
	getline(cin, oldName);

	//А в другой новое имя(newName)
	cout << "Введите новое имя:\n";
	getline(cin, newName);

	//Произведем переименование и проверку результата
	if (rename(oldName.c_str(), newName.c_str()))
	{
		cout << "Error!\n";
	}
	else
	{
		cout << "Success!\n";
	}
}

//Удалить существующую директорию
void RemoveDirectory()
{
	string name;
	
	//Получаем имя и путь к удаляемой директории
	cout << "Enter name:\n";
	getline(cin, name);

	//Удаляем директорию и проверяем результат
	if (_rmdir(name.c_str()) == -1)
	{
		cout << "Error!" << endl;
	}
	else
	{
		cout << "Success!\n";
	}
}

//Создать директорию
void CreateDirectory()
{
	string name;

	//Получаем имя и путь к создаваемой директории
	cout << "Enter name:\n";
	getline(cin, name);

	//Создаем директорию и проверяем результат
	if (_mkdir(name.c_str()) == -1)
	{
		cout << "Error!\n";
	}
	else
	{
		cout << "Success!\n";
	}
}
