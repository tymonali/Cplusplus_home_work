#include "Address.h"

Address::Address()
{
	street = '\0';
	houseNum = 0;
	roomNum = 0;
	StreetType = '0';
}

Address::Address(string street, int houseNum, int roomNum, string streetType)
{
	this->street = street;
	this->houseNum = houseNum;
	this->roomNum = roomNum;
	this->StreetType = streetType;
}

void Address::addAddress()
{

}

void Address::Print(Address& obj)
{
	cout << StreetType << " ";
	cout << street << endl;
	cout << "Дом № " << houseNum << " Комната № " << roomNum << endl;
}
