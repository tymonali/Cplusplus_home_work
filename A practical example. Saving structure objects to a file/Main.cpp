#include <iostream>
#include <string>
#include <cstdio>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//структура, хранящая
//информацию о человеке

struct Man
{
	// Имя
	string str;
	// Возраст
	int age;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	//Создание объектов структуры
	Man A, B;
	// запись в объект A
	// информации, полученной с клавиатуры
	cout << "Введите имя:\n";
	getline(cin, A.str);
	cout << "Введите возраст:\n";
	cin >> A.age;

	// Открытие файла на запись
	FILE* f;
	fopen_s(&f, "Test.txt", "w");
	if (!f)
	{
		exit(0);
	}
	// Запись объекта в файл
	fwrite(&A, sizeof(Man), 1, f);
	fclose(f);

	// Открытие файла на чтение
	fopen_s(&f, "Test.txt", "r");
	if (!f)
	{
		exit(0);
	}
	// Считывание содержимого файла
	// в объект B
	fread(&B, sizeof(Man), 1, f);

	fclose(f);

	// Показ результата на экран

	cout << "Имя - " << B.str << "\nВозраст - " << B.age << endl;
	
	return 0;
}