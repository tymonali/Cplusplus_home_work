#include "App.h"



void App::Menu()
{
	cout << "[1] �������� �������\n";
	cout << "[2] �������� �������\n";
	cout << "[3] ������� �������\n";
	cout << "[4] ��������� ���������� �����\n";
	cout << "[5] ��������� ���������� �����\n";
	cout << "[6] ����� �������\n";
	cout << "[7] �������� ���������� �����\n";
	cout << "[8] �������� ���������� ���������� ������\n";
	cout << "[0] Exit\n";
}

void App::menuAction(int action)
{
	switch (action)
	{
	case 1:	//�������� �������
	{
		system("cls");
		pb.AddCont();
		cout << "������� ��������!\n";
		Sleep(1000);
		break;
	}
	case 2:
	{
		system("cls");
		cout << "������� ����� ��������\n";
		int pos;
		cin >> pos;
		cin.ignore();
		while (pos > pb.getSize())
		{
			cout << "� ���������� ����� ������ " << pb.getSize() << " ���������!\n";
			cout << "������� ����� ��������\n";
			cin >> pos;
			cin.ignore();
		}
		pb.editCont(pos);
		break;
	}
	case 3:	//������� �������
	{
		system("cls");
		cout << "������� ����� ��������\n";
		int pos;
		cin >> pos;
		cin.ignore();
		while (pos > pb.getSize())
		{
			cout << "� ���������� ����� ������ " << pb.getSize() << " ���������!\n";
			cout << "������� ����� ��������\n";
			cin >> pos;
			cin.ignore();
		}
		pb.deletePos(pos);
		//cout << "������� ������!\n";
		Sleep(1000);
		break;
	}
	case 4:	//��������� ��� �����
	{
		system("cls");
		pb.Write_File(pb.getBook(), pb.getSize(), "data.txt");
		break;
	}
	case 5:	//��������� ��� �����
	{
		system("cls");
		pb.Read_File(pb.getBook(), pb.getSize(), "data.txt");
		break;
	}
	case 6:	//����� �������
	{
		system("cls");
		cout << "[1] �� ���\n";
		cout << "[2] �� ������'\n";
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
	case 7:	//�������� ��� �����
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
