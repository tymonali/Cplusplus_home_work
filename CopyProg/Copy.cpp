#include "Copy.h"

void Copy::CopyProg(string pathFrom, string pathTo)
{
	if (_access(pathTo.c_str(), 00) != 0)
	{
		_mkdir(pathTo.c_str());
	}
	_finddata_t* infoFrom = new _finddata_t;					// ������						// ����
	string mask;												// ��� �����
	string newPathFrom, newPathTo;								// ������ � ���� (����)
	mask = pathFrom;											// ������ strcpy_s()
	mask += "\\*.*";											// ����� ��� �����
	// ����� ����������
	long dirHandleFrom = _findfirst(mask.c_str(), infoFrom);
	// ��������� ���������� ��� ������� �� ����������
	long tmpHandleFrom = dirHandleFrom;
	string dot = ".";
	string dotdot = "..";
	int count = 0;
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
			
			// ���� ���� ������� ���������� ��
			if (doCopy == true)
			{
				_chmod(newPathFrom.c_str(), _S_IWRITE);
				count++;
			}
			
			/*
			 *	��������! � ����������� �������� ���� �������� ��������,
			 *	��������� ��� ����� �� ������ � �������!
			 *	������� read-only ���������� ��������� �� ��� �������� Windows!
			 *	� ������� ��� ����������! ���� ��� ������ _chmod()!!!
			 *	������� ������ � �������� ��������� �� ������� ������� ��������
			 *	��������� �������� ���!(������ �������� ������� ����� ������� ���
			 *	����������� �� ���������� :))
			 *	������� � ���� ��������� �� ������� ����� �������� ������ �����!
			 *	� ���, ������ ���� ������� ������ � �� ����!
			 */
			
			// ���� ����������
			if (infoFrom->attrib & _A_SUBDIR)
			{
				int err = _mkdir(newPathTo.c_str());		// ������� ����� � ����������� "����"
				CopyProg(newPathFrom, newPathTo);
			}
			// ���� ����
			else
			{
				/*
				 *	�� ���� ����� � ����� ��������(��������) ����������� �������������
				 *	���� attrib ��������� _finddata_t!
				 *	������ ������ ���� ��� �� ������ �� ����!
				 *	�� ��� ����� � ���������� ������ ��� ������ �������� �
				 *	if(infoFrom->attrib & _A_RDONLY) ������-��!
				 *	������� ����� ��������� 100% ���������� �������!
				 *	_access() � ���������� ���������� 02 - ���������
				 *	-1, ���� ����� ������ ������ ��� ������!
				 */
				
				int f = _access(newPathFrom.c_str(), 02);
				if (f == -1)
				{
					
					cout << "��������!!! ���� " << infoFrom->name;
					cout << " - ����� �������� \"������ ��� ������\"\n";
					cout << "�������� ��������:\n";
					int act = CopyAction();
					switch(act)
					{
					case CopyDir:
						
						break;
					case Skip:
						doWr = true;
						break;
					case Copy_for_everyone:
						doCopy = true;
						break;
					case Cancel:
						exit(0);
					}
				}
				// ���� ������������ �������� ����������, �� ����������
				// ������� ������������ ��� ����������� �����
				if (doWr != true) 
				{
					copyFile(newPathFrom, newPathTo);
					// ���� ������� ���������, �� ������� ����!
					if(count == 1)
					{
						_chmod(newPathFrom.c_str(), _S_IREAD);
						count--;
					}
				}
				CopyProg(newPathFrom, newPathTo);
			}	
		}
		// ������� � ���������� �����/�����
		tmpHandleFrom = _findnext(dirHandleFrom, infoFrom);
		newPathFrom.clear();
	}
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
	cout << "[1] ����������\n";
	cout << "[2] ���������\n";
	cout << "[3] ���������� ���\n";
	cout << "[4] ������\n";
	cin >> action;
	cin.ignore();							// �� ������ ������
	return action;
}
