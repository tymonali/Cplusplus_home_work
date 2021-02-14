#pragma once
#include"CardBatch.h"
#include"Card.h"
class Player
{
	
	int money;
	int size;
	Card* nal;
public:
	Player();
	// Конструктор копирования
	Player(const Player& copy);
	// Количество очков у игрока
	int SetScore();
	void PrintNal();// Показать карты игрока
	void FirstDistribution(Card_Batch& but);// Первая раздача
	void SingleDistribution(Card_Batch& but);// Последующие раздачи по 1-й карте
	int getScore();// Возврат общих очков игрока
	void setSize(int sz);
	void setScore(int scr);
	~Player();
};
