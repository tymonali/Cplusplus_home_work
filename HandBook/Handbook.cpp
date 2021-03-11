#include "Handbook.h"

HandBook::HandBook()
{
	this->abonents = nullptr;
	count = 0;
	capacity = 0;
}

HandBook::~HandBook()
{
	delete[] abonents;
}

void HandBook::setCapacity()
{
	cout << "Enter size of hanbook:\n";
	cin >> capacity;
}

void HandBook::add()
{
	if (count < capacity)
	{
		abonents[count++].addAbonent();
		cout << "Add is succesful!\n";
		Sleep(1000);
	}
	else
	{
		cout << "This handbook is full!\n";
	}
}

int HandBook::menuCompare()
{
	system("cls");
	int num;
	cout << "Specify search parameters:\n";
	cout << "[1] Search by company name\n";
	cout << "[2] Search by business owner\n";
	cout << "[3] Search by phone number\n";
	cout << "[4] Search by occupation\n";
	cin >> num;
	cin.ignore();
	return num;
}

string HandBook::searchAct(int num)
{
	string str;
	switch (num)
	{
	case 1:
		cout << "Enter search name:\n";
		getline(cin, str);
		break;
	case 2:
		cout << "Enter search owner:\n";
		getline(cin, str);
		break;
	case 3:
		cout << "Enter search phone:\n";
		getline(cin, str);
		break;
	case 4:
		cout << "Enter search occupation:\n";
		getline(cin, str);
		break;
	default:
		break;
	}
	return str;
}

void HandBook::search()
{
	if(count == 0)
	{
		system("cls");
		cout << "Handbook is empty!\n";
		system("pause");
	}
	else 
	{
		int num = menuCompare();
		string str = searchAct(num);
		system("cls");
		cout << "\nThe search returned the following results:\n\n";
		int f = 0;
		for (int i = 0; i < count; i++)
		{
			if (abonents[i].compare(num, str))
			{
				abonents[i].show();
				f++;
				system("pause");
			}
		}
		if(f == 0)
		{
			cout << "No matches found!\n";
			system("pause");
		}
	}
}

void HandBook::show()
{
	if(count == 0)
	{
		system("cls");
		cout << "Handbook is empty!\n";
		system("pause");
	}
	else 
	{
		system("cls");
		for (int i = 0; i < count; i++)
		{
			abonents[i].show();
		}
		system("pause");
	}
}

void HandBook::save()
{
	if(count == 0)
	{
		system("cls");
		cout << "No data to save!\n";
		system("pause");
	}
	else 
	{
		ofstream out("handbook.bin", ios::binary);
		out << count << " ";
		out << capacity << " ";
		for (int i = 0; i < count; i++)
		{
			out << abonents[i];
		}
		out.close();
		cout << "Recording successful\n";
		Sleep(1000);
	}
}

void HandBook::load()
{
	ifstream in("handbook.bin", ios::binary);
	if (in.is_open())
	{
		in >> count;
		in >> capacity;
		abonents = new Abonent[capacity];
		for (int i = 0; i < count; i++)
		{
			in >> abonents[i];
		}
	}
	else
	{
		int size;
		cout << "Enter hanbook size:\n";
		cin >> size;
		cin.ignore();
		abonents = new Abonent[size];
		count = 0;
		capacity = size;
	}
	in.close();
}
