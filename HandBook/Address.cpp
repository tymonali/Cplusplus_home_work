#include "Address.h"

Address::Address()
{
	street = "Unknown";
	houseNum = 0;
	roomNum = 0;
	type = Undef;
}

Address::Address(string street, int houseNum, int roomNum, StreetType type)
{
	this->street = street;
	this->houseNum = houseNum;
	this->roomNum = roomNum;
	this->type = type;
}

void Address::show()
{
	string Type;
	if (type == Avenue)
	{
		Type = "Avenue";
	}
	else if (type == Lane)
	{
		Type = "Lane";
	}
	else if (type == Boulevard)
	{
		Type = "Boulevard";
	}
	else
	{
		Type = "Street";
	}
	cout << "Address: " << street << " " << Type << ", " << houseNum << "/" << roomNum;
}

bool Address::operator==(const Address& obj)
{
	if(this->street == obj.street 
		&& this->type == obj.type
		&& this->houseNum == obj.houseNum
		&& this->roomNum == obj.roomNum)
	{
		return true;
	}
	return false;
}

inline istream& operator >> (istream& is, StreetType& obj)
{
	int tmp;
	is >> tmp;
	obj = (StreetType)tmp;
	return is;
}

ostream& operator<<(ostream& os, Address& obj)
{
	os << obj.street << " " << obj.type << " " << obj.houseNum << " " << obj.roomNum << endl;
	return os;
}

istream& operator>>(istream& is, Address& obj)
{
	
	is >> obj.street;
	is >> obj.type;
	is >> obj.houseNum;
	is >> obj.roomNum;
	return is;
}
