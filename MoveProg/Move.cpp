#include "Move.h"

void Move::moveProg(string pathFrom, string pathTo)
{
	if(_access(pathTo.c_str(),00) != 0)
	{
		_mkdir(pathTo.c_str());
	}
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
			bool doWr = false;
			// копирование пути к текущей директории
			newPathFrom = pathFrom;
			// Формирование пути к новой директории
			newPathFrom += "\\";
			newPathFrom += infoFrom->name;
			newPathTo = pathTo;
			newPathTo += "\\";
			newPathTo += infoFrom->name;
			if(doMove == true)
			{
				_chmod(newPathFrom.c_str(), _S_IWRITE);
			}
			// Если директория
			if (infoFrom->attrib & _A_SUBDIR)
			{
				rename(newPathFrom.c_str(), newPathTo.c_str());
				moveProg(newPathFrom, newPathTo);
			}
			// Если файл
			else
			{
				int f = _access(newPathFrom.c_str(), 02);
				if (f == -1)
				{
					cout << "Внимание!!! Файл " << infoFrom->name;
					cout << " - имеет аттрибут \"Только для чтения\"\n";
					cout << "Выберите действие:\n";
					int act = moveAction();
					switch(act)
					{
					case MoveDirr:
						_chmod(newPathFrom.c_str(), _S_IWRITE);
						break;
					case Skip:
						doWr = true;
						break;
					case Move_for_everyone:
						doMove = true;
						break;
					case Cancel:
						exit(0);
					}
				}
				if (doWr != true) 
				{
					rename(newPathFrom.c_str(), newPathTo.c_str());
				}
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
	cout << "[4] Отмена\n";
	cin >> action;
	cin.ignore();							// На всякий случай
	return action;
}
