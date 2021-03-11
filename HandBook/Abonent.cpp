#include "Abonent.h"

Abonent::Abonent()
{
	this->companyName = "Unknown";
	this->owner = "Unknown";
	this->phone = "Unknown";
	this->occupation = "Unknown";
	this->address = nullptr;
}

Abonent::Abonent(string companyName, string owner, string phone, string occupation, Address* address)
{
	this->companyName = companyName;
	this->owner = owner;
	this->phone = phone;
	this->occupation = occupation;
	this->address = address;
}

Abonent::~Abonent()
{
	delete address;
	cout << "Destructor ~Abonent()\n";
	Sleep(200);
}

void Abonent::addAbonent()
{
	string street;
	int houseNum;
	int roomNum;
	int type;
	StreetType typs;
	cout << "Enter company name: " << endl;
	getline(cin, companyName);
	cout << "Enter owner: " << endl;
	getline(cin, owner);
	cout << "Enter phone: " << endl;
	getline(cin, phone);
	cout << "Enter occupation: " << endl;
	getline(cin, occupation);
	cout << "Enter street: " << endl;
	getline(cin, street);
	cout << "Select street type: " << endl;
	cout << "[1] Avenue\n[2] Lane\n[3] Bouleward\n[4] I dont known\n";
	cin >> type;
	switch(type)
	{
	case 1:
		typs = Avenue;
		break;
	case 2:
		typs = Lane;
		break;
	case 3:
		typs = Boulevard;
		break;
	case 4:
		typs = Undef;
		break;
	default:
		break;
	}
	cout << "Enter house number: " << endl;
	cin >> houseNum;
	cout << "Enter room number: " << endl;
	cin >> roomNum;
	cin.ignore();
	address = new Address(street, houseNum, roomNum, typs);
}

void Abonent::show()
{
	cout << "Company name: " << companyName << endl
		<< "Owner: " << owner << endl
		<< "Phone: " << phone << endl
		<< "Occupation: " << occupation << endl;
	address->show();
	cout << endl << endl;
}

bool Abonent::compare(int num, string str)
{
	switch (num)
	{
	case 1:
		return (companyName == str) ? true : false;
	case 2:
		return (owner == str) ? true : false;
	case 3:
		return (phone == str) ? true : false;
	case 4:
		return (occupation == str) ? true : false;
	default:
		break;
	}
	return false;
}

StreetType Abonent::strToEnum(string str)
{
	if (str == "Avenue")
	{
		return Avenue;
	}
	else if (str == "Lane")
	{
		return Lane;
	}
	else if (str == "Boulevard")
	{
		return Boulevard;
	}
	else
	{
		return Undef;
	}
}

ostream& operator<<(ostream& os, Abonent& obj)
{
	os << obj.companyName << " " << obj.owner << " " << obj.phone << " " << " " << obj.occupation << " " << *obj.address;
	return os;
}

istream& operator>>(istream& is, Abonent& obj)
{
	is >> obj.companyName;
	is >> obj.owner;
	is >> obj.phone;
	is >> obj.occupation;
	obj.address = new Address;
	is >> *obj.address;
	return is;
}
