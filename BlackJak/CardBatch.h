#pragma once
#include "Card.h"

class Card_Batch {
	Card* cards;
	int size;
public:
	// ����������� �� ���������
	Card_Batch();
	// ������������� �����������
	Card_Batch(int sz);
	// ����������� �����������
	Card_Batch(const Card_Batch& copy);
	// �������� ������ ����
	void setCard_Batch();
	// ����������� ������
	void Shuffle();
	// ����� ������ �� �����
	void display();
	Card getKoloda();
	// ������ ����� �� ������
	Card getCard();
	void setSize(int sz);
	~Card_Batch();
};