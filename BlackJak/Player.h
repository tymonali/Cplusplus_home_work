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
	// ����������� �����������
	Player(const Player& copy);
	// ���������� ����� � ������
	int SetScore();
	void PrintNal();// �������� ����� ������
	void FirstDistribution(Card_Batch& but);// ������ �������
	void SingleDistribution(Card_Batch& but);// ����������� ������� �� 1-� �����
	int getScore();// ������� ����� ����� ������
	void setSize(int sz);
	void setScore(int scr);
	~Player();
};
