#pragma once
#include<iostream>
#include<Windows.h>
#include<fstream>
#include <direct.h>
#include <io.h>			// Поиск файлов
#include<string>

using namespace std;

class DeleteEXE
{
	enum
	{
		DeleteDirr = 1,				// Удалить
		Skip,						// Пропустить
		Delete_for_everyone,		// Удалить для всех
		Cancel						// Отмена
	};
	bool doDelete;
public:
	void deleteProg(string pathFrom);
	int deleteAction();
};

