#include "Player.h"

Player::Player()
{
	money = 100;	// Изначально есть 100 $
}

void Player::operator++()
{
	// каждый выигрыш +100
	money += 100;
}

void Player::operator--()
{
	// Ставка
	money -= 1;
}

int Player::Get()
{
	return money;
}
