#pragma once
#include "Card.h"

class Card_Batch {
	Card* cards;
	int size;
public:
	// Конструктор по умолчанию
	Card_Batch();
	// Перегруженный конструктор
	Card_Batch(int sz);
	// Конструктор копирования
	Card_Batch(const Card_Batch& copy);
	// Создание колоды карт
	void setCard_Batch();
	// Перетусовка колоды
	void Shuffle();
	// Вывод колоды на экран
	void display();
	Card getKoloda();
	// Первая карта из колоды
	Card getCard();
	void setSize(int sz);
	~Card_Batch();
};