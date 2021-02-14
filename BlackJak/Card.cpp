#include "Card.h"

using namespace std;

Card::Card() 
{
	//cout << "Сработка конструктора по умолчанию Card!\n\n";
	this->face = 0;
	this->suit = (Suit)0;

}

void Card::setCard(int f, Suit s) 
{
	this->face = f;
	this->suit = s;
}

void Card::PrintCard() 
{
	if (face >= 6 && face < 10)
	{
		cout << " " << face;
	}
	else if (face == 10)
	{
		cout << face;
	}
	else {
		switch (face) {
		case 11: cout << " J"; break;
		case 12: cout << " Q"; break;
		case 13: cout << " K"; break;
		case 14: cout << " A"; break;
		}
	}
	char c, d, h, s;
	c = 5;
	d = 4;
	h = 3;
	s = 6;
	switch (suit)
	{
	case clubs: cout << c; break;
	case diamonds: cout << d; break;
	case hearts: cout << h; break;
	case spades: cout << s; break;
	}
}

int Card::getFace()
{
	return face;
}

int Card::getScore()
{
	int scor = 0;
	if (face >= 6 && face <= 10)
	{
		scor = scor + face;
	}
	else if (face == 14)
	{
		scor = scor + 11;
	}
	else if(face == 13)
	{
		scor = scor + 4;
	}
	else if (face == 12)
	{
		scor = scor + 3;
	}
	else
	{
		scor = scor + 2;
	}
	return scor;
}