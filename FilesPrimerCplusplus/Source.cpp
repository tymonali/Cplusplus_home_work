#include<iostream>
#include<Windows.h>
#include<fstream>

using namespace std;

class Person
{
	char firstName[30];
	char lastName[30];
	int age;
public:
	Person()
	{
		firstName[0] = lastName[0] = '\0';
		age = 0;
	}
	Person(const char* firstName, const char* lastName, int age)
	{
		this->age = age;
		strcpy_s(this->firstName, firstName);
		strcpy_s(this->lastName, lastName);
	}
	friend ostream& operator << (ostream& os, const Person& obj);
	friend istream& operator >> (istream& is, Person& obj);
};

ostream& operator << (ostream& os, const Person& obj)
{
	os << obj.firstName << " " << obj.lastName << " " << obj.age;
	return os;
}

istream& operator >> (istream& is, Person& obj)
{
	is >> obj.firstName;
	is >> obj.lastName;
	is >> obj.age;
	return is;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color B0");

	/*Person ps("Мороз","Артём",38);
	cout << ps;

	cout << "\nВведите имя фамилию и возраст через энтер\n";
	cin >> ps;

	cout << ps;*/

	//ofstream out("demo.txt", ios::out | ios::binary);
	// //Проверка файла на открытие
	//if (out.is_open())
	//{
	//	const char* str = "Hallo World!!!";
	//	out.write(str, strlen(str));
	//	// Закрытие файла
	//	out.close();
	//}

	//ifstream in("demo.txt", ios::in | ios::binary);
	//if (in.is_open())
	//{
	//	char buff[100];
	//	//in.read(buff, 100);
	//	while (!in.eof())
	//	{
	//		in.getline(buff, 100);
	//		cout << buff << endl;
	//	}
	//	in.close();
	//}

	/*Person person("Мороз","Артём",38);
	ofstream out("Person.bin", ios::out | ios::binary);
	if (out.is_open())
	{
		out << person;
		out.close();
	}*/

	/*Person person;
	ifstream in("Person.bin", ios::in | ios::binary);
	if (in.is_open())
	{
		in >> person;
		cout << person << endl;
		in.close();
	}*/

	/*int size = 3;
	Person* people = new Person[size];
	people[0] = Person("Мороз", "Артём", 38);
	people[1] = Person("Пупкин", "Вася", 31);
	people[2] = Person("Иванова", "Маша", 32);
	ofstream out("people.bin", ios::out | ios::binary);
	if (out.is_open())
	{
		out << size << endl;
		for (int i = 0; i < size; i++)
		{
			out << people[i];
		}
		cout << "Succes" << endl;
		out.close();
	}*/

	/*ifstream in("people.bin", ios::in | ios::binary);
	if (in.is_open())
	{
		int size;
		in >> size;
		Person* people = new Person[size];
		for (int i = 0; i < size; i++)
		{
			Person p;
			in >> p;
			people[i] = p;
			cout << p << endl;
		}
		
		in.close();
	}*/

	const char* source = "Person.bin";
	const char* destination = "../Person.bin";

	ifstream in(source, ios::binary);
	ofstream out(destination, ios::binary);

	if (in.is_open() && out.is_open())
	{
		out << in.rdbuf();
		cout << "Succes!" << endl;
		in.close();
		out.close();
	}

	return 0;
}