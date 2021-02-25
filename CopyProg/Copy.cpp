#include "Copy.h"

void Copy::CopyProg(string pathFrom, string pathTo)
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
				//if (infoFrom->attrib & _A_RDONLY)	// Вот здесь ничего не выводит!!!
				//{
				//	cout << " - только для чтения" << endl;
				//}
				cout << "Path: \n" << newPathFrom << endl << endl;
				_mkdir(newPathTo.c_str());
				CopyProg(newPathFrom, newPathTo);
			}
			// Если файл
			else
			{
				cout << "File: " << infoFrom->name << endl;
				cout << "Path: \n" << newPathFrom << endl << endl;
				copyFile(newPathFrom, newPathTo);
				CopyProg(newPathFrom, newPathTo);
			}
		}
		// Переход к следующему файлу/папке
		tmpHandleFrom = _findnext(dirHandleFrom, infoFrom);
		newPathFrom.clear();
	}
	//if (infoFrom->attrib & _A_RDONLY)		// А здесь выводит только один файл!!!
	//{
	//	cout << infoFrom->name << "\nПапка (файл) имеет параметр только для чтения\n" << endl;
	//}
	
	
	delete infoFrom;
	_findclose(dirHandleFrom);
}

void Copy::copyFile(string copyFrom, string copyTo)
{
	FILE* inputFile, * outputFile;
	fopen_s(&outputFile, copyFrom.c_str(), "r");
	fopen_s(&inputFile, copyTo.c_str(), "w");
	char buffer[255];
	if (outputFile && inputFile)
	{
		while (!feof(outputFile))
		{
			fgets(buffer, 255, outputFile);
			fputs(buffer, inputFile);
		}
	}
}

int Copy::CopyAction()
{
	int action;
	cout << "[1] Копировать\n";
	cout << "[2] Пропустиь\n";
	cout << "[3] Копировать все\n";
	cin >> action;
	cin.ignore();							// На всякий случай
	return action;;
}
