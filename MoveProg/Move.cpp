#include "Move.h"

void Move::moveProg(string pathFrom, string pathTo)
{
	_finddata_t* infoFrom = new _finddata_t;					// ������
	_finddata_t* infoTo = new _finddata_t;						// ����
	string pathTmp;												// ��� �����
	string newPathFrom, newPathTo;								// ������ � ���� (����)
	pathTmp = pathFrom;											// ������ strcpy_s()
	pathTmp += "\\*.*";											// ����� ��� �����
	// ����� ����������
	long dirHandleFrom = _findfirst(pathTmp.c_str(), infoFrom);
	// ��������� ���������� ��� ������� �� ����������
	long tmpHandleFrom = dirHandleFrom;
	string dot = ".";
	string dotdot = "..";
	while (tmpHandleFrom != -1)
	{
		// ���������� "." � ".."
		if (dot.compare(infoFrom->name) != 0 && dotdot.compare(infoFrom->name) != 0)
		{
			// ����������� ���� � ������� ����������
			newPathFrom = pathFrom;
			// ������������ ���� � ����� ����������
			newPathFrom += "\\";
			newPathFrom += infoFrom->name;
			newPathTo = pathTo;
			newPathTo += "\\";
			newPathTo += infoFrom->name;
			// ���� ����������
			if (infoFrom->attrib & _A_SUBDIR)
			{
				cout << "Dir: " << infoFrom->name << endl;
				cout << "Path: \n" << newPathFrom << endl << endl;
				rename(newPathFrom.c_str(), newPathTo.c_str());
				moveProg(newPathFrom, newPathTo);
			}
			// ���� ����
			else
			{
				cout << "File: " << infoFrom->name << endl;
				cout << "Path: \n" << newPathFrom << endl << endl;
				rename(newPathFrom.c_str(), newPathTo.c_str());
				moveProg(newPathFrom, newPathTo);
			}
		}
		// ������� � ���������� �����/�����
		tmpHandleFrom = _findnext(dirHandleFrom, infoFrom);
		//newPathFrom.clear();
	}
	delete infoFrom;
	_findclose(dirHandleFrom);
}

int Move::moveAction()
{
	int action;
	cout << "[1] �����������\n";
	cout << "[2] ���������\n";
	cout << "[3] ����������� ���\n";
	cin >> action;
	cin.ignore();							// �� ������ ������
	return action;
}
