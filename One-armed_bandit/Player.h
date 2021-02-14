#pragma once
class Player
{
	int money;	// деньги игрока
public:
	// Конструктор по умолчанию
	Player();
	void operator++();
	void operator--();
	int Get();
};