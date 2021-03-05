#include "Move.h"

void Move::moveProg(string pathFrom, string pathTo)
{
	if(_access(pathTo.c_str(),00) != 0)
	{
		_mkdir(pathTo.c_str());
	}
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
			bool doWr = false;
			// ����������� ���� � ������� ����������
			newPathFrom = pathFrom;
			// ������������ ���� � ����� ����������
			newPathFrom += "\\";
			newPathFrom += infoFrom->name;
			newPathTo = pathTo;
			newPathTo += "\\";
			newPathTo += infoFrom->name;
			if(doMove == true)
			{
				_chmod(newPathFrom.c_str(), _S_IWRITE);
			}
			// ���� ����������
			if (infoFrom->attrib & _A_SUBDIR)
			{
				rename(newPathFrom.c_str(), newPathTo.c_str());
				moveProg(newPathFrom, newPathTo);
			}
			// ���� ����
			else
			{
				int f = _access(newPathFrom.c_str(), 02);
				if (f == -1)
				{
					cout << "��������!!! ���� " << infoFrom->name;
					cout << " - ����� �������� \"������ ��� ������\"\n";
					cout << "�������� ��������:\n";
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
	cout << "[4] ������\n";
	cin >> action;
	cin.ignore();							// �� ������ ������
	return action;
}
