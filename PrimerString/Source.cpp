#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color B0");

	// Операторы для string
	/*string str = "Hello World";
	string str2 = "!!!";
	string str3 = str + str2;
	str3 += ")))";

	cout << str3 << endl;

	char buff[50];
	strcpy_s(buff, str3.c_str());

	cout << buff << endl;*/

	string str = "Hello World";
	str.append("!!!");			// Добавить в конец строки
	cout << str << endl;
	cout << str.at(0) << endl;	// Получить нулевой элемент
	cout << str[0] << endl;		// Тоже самое(перегрузка at())

	// Очистка строки
	/*str.clear();*/

	// Сравнение строк
	/*int res = str.compare("Hello World!!!");
	cout << res << endl;*/

	// Обрезание строки на заданную длинну
	/*str.erase(5);

	cout << str << endl;*/

	// Удаление символов в заданном диапазоне
	//str.erase(2, 6);

	// Копирование определенной последовательности символов
	/*string res;
	res.assign(str, 1, 5);
	cout << res << endl;*/

	// Поиск подстроки
	/*size_t res = str.find("ello");

	// Подстрока найдена
	if (res != string::npos)
	{
		cout << "Удачно" << endl;
	}
	else
	{
		cout << "Не найдено" << endl;
	}*/

	// Вставка в заданную позицию
	// Вставка в начало
	/*str.insert(0, "Hi! ");
	cout << str << endl;*/

	// Проверка строки на пустоту
	/*if (str.empty())
	{
		cout << "Строка пустая" << endl;
	}
	else
	{
		cout << "Строка имеет символы" << endl;
	}*/

	// Замена строк
	/*string s1 = "Hello";
	string s2 = "World";

	swap(s1, s2); // или s1.swap(s2);

	cout << "s1 = " << s1 << "\ns2 = " << s2 << endl;*/

	// Получение подстроки
	/*string sub = str.substr(0, 5);
	cout << str << endl << sub << endl;*/



	return 0;
}