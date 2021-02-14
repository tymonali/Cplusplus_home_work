#include "App.h"



void App::Menu()
{
	cout << "[1] Добавить контакт\n";
	cout << "[2] Изменить контакт\n";
	cout << "[3] Удалить контакт\n";
	cout << "[4] Сохранить телефонную книгу\n";
	cout << "[5] Загрузить телефонную книгу\n";
	cout << "[6] Найти контакт\n";
	cout << "[7] Показать телефонную книгу\n";
	cout << "[8] Показать результаты последнего поиска\n";
	cout << "[0] Exit\n";
}

void App::menuAction(int action)
{
	switch (action)
	{
	case 1:	//Добавить контакт
	{
		system("cls");
		pb.AddCont();
		cout << "Контакт добавлен!\n";
		Sleep(1000);
		break;
	}
	case 2:
	{
		system("cls");
		cout << "Введите номер контакта\n";
		int pos;
		cin >> pos;
		cin.ignore();
		while (pos > pb.getSize())
		{
			cout << "В телефонной книге только " << pb.getSize() << " контактов!\n";
			cout << "Введите номер контакта\n";
			cin >> pos;
			cin.ignore();
		}
		pb.editCont(pos);
		break;
	}
	case 3:	//Удалить контакт
	{
		system("cls");
		cout << "Введите номер контакта\n";
		int pos;
		cin >> pos;
		cin.ignore();
		while (pos > pb.getSize())
		{
			cout << "В телефонной книге только " << pb.getSize() << " контактов!\n";
			cout << "Введите номер контакта\n";
			cin >> pos;
			cin.ignore();
		}
		pb.deletePos(pos);
		//cout << "Контакт Удален!\n";
		Sleep(1000);
		break;
	}
	case 4:	//Сохранить тел книгу
	{
		system("cls");
		pb.Write_File(pb.getBook(), pb.getSize(), "data.txt");
		break;
	}
	case 5:	//Загрузить тел книгу
	{
		system("cls");
		pb.Read_File(pb.getBook(), pb.getSize(), "data.txt");
		break;
	}
	case 6:	//Найти контакт
	{
		system("cls");
		cout << "[1] По ФИО\n";
		cout << "[2] По номеру'\n";
		int num;
		cin >> num;
		cin.ignore();
		switch (num)
		{
		case 1:
			pb.findByFIO();
			_getch();

			break;
		case 2:
			pb.findByNum();
			_getch();

			break;
		}
		
		break;
	}
	case 7:	//Показать тел книгу
	{
		system("cls");
		pb.showBook();
		_getch();
		break;
	}
	case 8:
	{
		system("cls");
		pb.Read_File(pb.getBook(), pb.getSize(), "search.txt");
		pb.showBook();
		_getch();
		pb.Read_File(pb.getBook(), pb.getSize(), "data.txt");
		break;
	}
	case 0:
	{
		exit(0);
		break;
	}
	}
}

void App::start()
{
	while (true) 
	{
		system("cls");
		Menu();
		int action;
		cin >> action;
		cin.ignore();
		menuAction(action);
	}
}
