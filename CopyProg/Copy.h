#pragma once
#include<iostream>
#include<Windows.h>
#include<fstream>
#include <direct.h>
#include <io.h>			// Поиск файлов
#include<string>

using namespace std;

class Copy
{
	enum
	{
		CopyDir = 1,					// Копировать
		Skip,							// Пропустить
		Copy_for_everyone,				// Копировать для всех
		Cancel							// Отмена
	};
	bool doCopy;
public:
	void CopyProg(string pathFrom, string pathTo);
	void copyFile(string copyFrom, string copyTo);
	int CopyAction();
};

