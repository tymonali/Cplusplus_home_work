#pragma once
#include "Card.h"
#include "Player.h"

class GameData
{
	Player player_1;// ���������� ������ Player
	Player player_2;// ���������� ������ Player
	Card_Batch koloda;// ���������� ������ Card_Batch
	// �������� ��� ������ 1
	int P_1Act();
	// �������� ��� ������ 2
	int P_2Act();
	// ������� ����
	void GameProcess();
	// ����� ����������� ����
	void GameResult();
	// ����/�����
	void Menu();
	// ���� ����
	void SubMenu();
	// �������� ��� ���� ����/�����
	void MenuAction(int menuaction);
	// �������� ��� �������� ����
	void SubmenuAction(int menuaction);
public:
	void Start();
};