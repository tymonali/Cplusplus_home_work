#pragma once
class Player
{
	int money;	// ������ ������
public:
	// ����������� �� ���������
	Player();
	void operator++();
	void operator--();
	int Get();
};