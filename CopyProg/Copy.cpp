#include "Copy.h"

void Copy::CopyProg(string pathFrom, string pathTo)
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
				//if (infoFrom->attrib & _A_RDONLY)	// ��� ����� ������ �� �������!!!
				//{
				//	cout << " - ������ ��� ������" << endl;
				//}
				cout << "Path: \n" << newPathFrom << endl << endl;
				_mkdir(newPathTo.c_str());
				CopyProg(newPathFrom, newPathTo);
			}
			// ���� ����
			else
			{
				cout << "File: " << infoFrom->name << endl;
				cout << "Path: \n" << newPathFrom << endl << endl;
				copyFile(newPathFrom, newPathTo);
				CopyProg(newPathFrom, newPathTo);
			}
		}
		// ������� � ���������� �����/�����
		tmpHandleFrom = _findnext(dirHandleFrom, infoFrom);
		newPathFrom.clear();
	}
	//if (infoFrom->attrib & _A_RDONLY)		// � ����� ������� ������ ���� ����!!!
	//{
	//	cout << infoFrom->name << "\n����� (����) ����� �������� ������ ��� ������\n" << endl;
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
	cout << "[1] ����������\n";
	cout << "[2] ���������\n";
	cout << "[3] ���������� ���\n";
	cin >> action;
	cin.ignore();							// �� ������ ������
	return action;;
}
