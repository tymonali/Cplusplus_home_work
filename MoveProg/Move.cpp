#include "Move.h"

void Move::moveProg(string pathFrom, string pathTo)
{
	_finddata_t* infoFrom = new _finddata_t;					// Откуда
	_finddata_t* infoTo = new _finddata_t;						// Куда
	string pathTmp;												// Для маски
	string newPathFrom, newPathTo;								// Откуда и куда (путь)
	pathTmp = pathFrom;											// Вместо strcpy_s()
	pathTmp += "\\*.*";											// Найти все файлы
	// поиск директории
	long dirHandleFrom = _findfirst(pathTmp.c_str(), infoFrom);
	// временный дескриптор для прохода по директории
	long tmpHandleFrom = dirHandleFrom;
	string dot = ".";
	string dotdot = "..";
	while (tmpHandleFrom != -1)
	{
		// Игнорируем "." и ".."
		if (dot.compare(infoFrom->name) != 0 && dotdot.compare(infoFrom->name) != 0)
		{
			// копирование пути к текущей директории
			newPathFrom = pathFrom;
			// Формирование пути к новой директории
			newPathFrom += "\\";
			newPathFrom += infoFrom->name;
			newPathTo = pathTo;
			newPathTo += "\\";
			newPathTo += infoFrom->name;
			// Если директория
			if (infoFrom->attrib & _A_SUBDIR)
			{
				cout << "Dir: " << infoFrom->name << endl;
				cout << "Path: \n" << newPathFrom << endl << endl;
				rename(newPathFrom.c_str(), newPathTo.c_str());
				moveProg(newPathFrom, newPathTo);
			}
			// Если файл
			else
			{
				cout << "File: " << infoFrom->name << endl;
				cout << "Path: \n" << newPathFrom << endl << endl;
				rename(newPathFrom.c_str(), newPathTo.c_str());
				moveProg(newPathFrom, newPathTo);
			}
		}
		// Переход к следующему файлу/папке
		tmpHandleFrom = _findnext(dirHandleFrom, infoFrom);
		//newPathFrom.clear();
	}
	delete infoFrom;
	_findclose(dirHandleFrom);
}

int Move::moveAction()
{
	int action;
	cout << "[1] Переместить\n";
	cout << "[2] Пропустиь\n";
	cout << "[3] Переместить все\n";
	cin >> action;
	cin.ignore();							// На всякий случай
	return action;
}
