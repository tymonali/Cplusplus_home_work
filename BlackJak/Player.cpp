#include "Player.h"

Player::Player()
{
	cout << "Сработка конструктора по умолчанию Player!\n\n";
	Sleep(1000);
	money = 0;
	size = 2;			// Первая раздача по две карты 
	nal = new Card[size];
}

Player::Player(const Player& copy)
{
	cout << "Сработка конструктора копирования Player!\n\n";
	Sleep(1000);
	this->size = copy.size;
	this->money = copy.money;
	nal = new Card[size];
	memcpy(nal, copy.nal, sizeof(int) * size);
}

int Player::SetScore()
{
	int tmp = 0;
	for (int i = 0; i < size; i++)
	{
		tmp = tmp + nal[i].getScore();
	}
	money = tmp;
	return money;
}

void Player::PrintNal()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Карта № " << i + 1 << ":";
		nal[i].PrintCard();
		cout << "\n\n";
	}
}

void Player::FirstDistribution(Card_Batch& but)
{
	cout << "Первая раздача!\n\n";
	Sleep(1000);
	nal[0] = but.getCard();
	nal[1] = but.getCard();
}

void Player::SingleDistribution(Card_Batch& but)
{
	cout << "Добавка!\n\n";
	Sleep(1000);
	size++;
	Card* tmp = new Card[size];
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = nal[i];
	}
	tmp[size - 1] = but.getCard();
	delete[] nal;
	nal = tmp;
}

int Player::getScore()
{
	return money;
}

void Player::setSize(int sz)
{
	this->size = sz;
}

void Player::setScore(int scr)
{
	this->money = scr;
}

Player::~Player()
{
	cout << "Сработка деструктора Player!\n\n";
	Sleep(1000);
	delete[] nal;
}
