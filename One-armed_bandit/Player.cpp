#include "Player.h"

Player::Player()
{
	money = 100;	// ���������� ���� 100 $
}

void Player::operator++()
{
	// ������ ������� +100
	money += 100;
}

void Player::operator--()
{
	// ������
	money -= 1;
}

int Player::Get()
{
	return money;
}
