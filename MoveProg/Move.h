#pragma once
#include<iostream>
#include<Windows.h>
#include<fstream>
#include <direct.h>
#include <io.h>			// ����� ������
#include<string>

using namespace std;

class Move
{
	enum
	{
		MoveDirr = 1,				// �����������
		Skip,						// ����������
		Move_for_everyone			// ����������� ��� ����
	};
public:
	void moveProg(string pathFrom, string pathTo);
	int moveAction();
};

