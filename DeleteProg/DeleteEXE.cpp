#include "DeleteEXE.h"

void DeleteEXE::deleteProg(string pathFrom)
{
	_finddata_t* info = new _finddata_t;
	string pathFromTmp;
	pathFromTmp = pathFrom;
	pathFromTmp += "\\*.*";
	long findHandle = _findfirst(pathFromTmp.c_str(), info);
	long tmpHandle = findHandle;

	string newPathFrom;

	string dot = ".";
	string dotdot = "..";

	while (tmpHandle != -1)
	{
		if (dot.compare(info->name) != 0 && dotdot.compare(info->name) != 0)
		{
			bool doWr = false;
			newPathFrom = pathFrom;
			newPathFrom += "\\";
			newPathFrom += info->name;
			if (doDelete == true)
			{
				_chmod(newPathFrom.c_str(), _S_IWRITE);
			}

			if (info->attrib & _A_SUBDIR)
			{
				deleteProg(newPathFrom);
			}
			else
			{
				if(_access(newPathFrom.c_str(), 02) == -1)
				{
					cout << "��������!!! ���� " << info->name;
					cout << " - ����� �������� \"������ ��� ������\"\n";
					cout << "�������� ��������:\n";
					int f = deleteAction();
					switch(f)
					{
					case DeleteDirr:
						_chmod(newPathFrom.c_str(), _S_IWRITE);
						break;
					case Skip:
						doWr = true;
						break;
					case Delete_for_everyone:
						_chmod(newPathFrom.c_str(), _S_IWRITE);
						doDelete = true;
						break;
					case Cancel:
						exit(0);
					}
				}
				if (doWr != true) 
				{
					remove(newPathFrom.c_str());
				}
			}
			newPathFrom.clear();
		}
		tmpHandle = _findnext(findHandle, info);
	}

	_rmdir(pathFrom.c_str());
	delete info;
	_findclose(findHandle);
}

int DeleteEXE::deleteAction()
{
	int action;
	cout << "[1] �������\n";
	cout << "[2] ���������\n";
	cout << "[3] ������� ���\n";
	cout << "[4] ������\n";
	cin >> action;
	cin.ignore();							// �� ������ ������
	return action;
}
