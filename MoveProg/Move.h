#pragma once
#include<iostream>
#include<Windows.h>
#include<fstream>
#include <direct.h>
#include <io.h>			// Поиск файлов
#include<string>

using namespace std;

class Move
{
	enum
	{
		MoveDirr = 1,				// Переместить
		Skip,						// Пропустить
		Move_for_everyone,			// Переместить для всех
		Cancel
	};
	bool doMove;
public:
	void moveProg(string pathFrom, string pathTo);
	int moveAction();
};

