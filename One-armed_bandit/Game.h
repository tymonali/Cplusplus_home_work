#pragma once
#include"Spools.h"
#include"Player.h"
#include<conio.h>

class Game
{
	// ����� ������ � ����
	enum ConsoleColor 
	{
		Black, Blue, Green, Cyan, Red, Mfgenta, Brown, LightGray, DarkGray,
		Lightblue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
	};
	// ���������� ������ Player
	Player newplayer;
	// ��� ���������� ���� Spools(������)
	Spools S1, S2, S3;
public:
	// ������������� �����������
	Game(int count, char first);
	// ��������� ������� �������
	bool Start();
	// ����� ��� �������� ���� �������
	void Rotation_all();
	// ��������� ������(��������)
	bool isWin();
	// ��������� ��������!!! ������ �� GitHub-�
	void SpoolShow();
	// ����� ��� ��������� ������ ������ � ����
	void SetColor(int text, int background);
	// �������� ������!!! ������ �� GitHub-�
	void Shimmer();
};