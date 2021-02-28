//Здесь находятся функции переименования и удаления
#include <cstdio>
//Здесь находятся функции для поиска файлов
#include <io.h>
#include <string>
#include <Windows.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Переименовать существующий файл
void RenameFile();

//Удалить существующий файл
void RemoveFile();

//Поиск файлов в каталоге
void Dir();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	//предлагаем выбрать пункт меню для выполнения
	cout << "Выберите номер операции:\n";

	// Выбор пользователя
	char ch;
	do
	{
		//Переименовать
		cout << "[1] Переименовать\n";
		//Удалить
		cout << "[2] Удалить\n";
		// Просмотреть некоторую папку (каталог)
		cout << "[3] Просмотреть содержимое\n";
		// Выход
		cout << "[0] Выход\n";
		cin >> ch;
		cin.ignore();

		//анализируем и вызываем
		//соответствующую функцию
		switch(ch)
		{
		case '1':
			RenameFile();
			break;
		case '2':
			RemoveFile();
			break;
		case '3':
			Dir();
			break;
		}
	} while (ch != '0');// выход из программы
	
	return 0;
}

//Переименовать существующий файл
void RenameFile()
{
	string oldName, newName;
	//В одной переменной запомним существующее имя
	//(oldName),
	cout << "Введите старое имя:\n";
	getline(cin, oldName);

	//А в другой новое имя(newName)
	cout << "Введите новое имя:\n";
	getline(cin, newName);

	//Произведем переименование и проверку результата
	if(rename(oldName.c_str(), newName.c_str()) != 0)
	{
		cout << "Ошибка!\n Не удалось переименовать файл!\n";
		cout << "Проверьте старое и новое имя файлов!\n";
	}
	else
	{
		cout << "Succes!!!\n";
	}
}

//Удалить существующий фай
void RemoveFile()
{
	string name;

	//Получаем имя и путь к удаляемому файлу
	cout << "Введите путь к файлу и его имя\n";
	getline(cin, name);

	//Удаляем файл и проверяем результат
	if (remove(name.c_str()) != 0)
	{
		cout << "Ошибка, не удалось удалить файл!\n";
		cout << "Проверьте путь и имя файла!\n";
	}
	else
	{
		cout << "Succes!\n";
	}
}

//Поиск файлов в каталоге
void Dir()
{
	//Запросим ПУТЬ (например, папка Temp на диске C,
	//запишется таким вот образом: c:\temp\)
	string path;
	cout << "Введите полный путь (например, C:\\):\n";
	getline(cin, path);

	//Запросим маску файлов
	string mask;
	cout << "Введите маску файла (например, *.* или *.txt*):\n";
	getline(cin, mask);

	//Соединив две строки, мы получим результат
	//т.е. что хочет найти пользователь и где
	path += mask;

	//Объявление указателя fileinfo
	//на структуру _finddata_t
	//и создание динамического объекта
	//структуры _finddata_t

	_finddata_t* fileinfo = new _finddata_t;
	/*
		fileinfo — указатель на объект структуры, в который
		запишется информация о следующем найденном файле.
	*/

	//Начинаем поиск
	long done = _findfirst(path.c_str(), fileinfo);
	/*
		 done — уникальный номер группы файлов в памяти.
	*/

	//если done будет равняться -1,
	//то поиск вести бесмысленно
	int MayWeWork = done;

	//Счетчик, содержит информацию о количестве
	//найденых файлов.
	int count = 0;

	while(MayWeWork != -1)
	{
		count++;
		// Распечатали имя найденного файла
		cout << fileinfo->name << endl;

		//Пытаемся найти следующий файл из группы
		MayWeWork = _findnext(done, fileinfo);						
	}
	//Вывод сообщения о количестве найденных файлов.
	cout << "Файлов найдено: " << count << endl;

	// Очистка памяти
	_findclose(done);
	delete fileinfo;
}