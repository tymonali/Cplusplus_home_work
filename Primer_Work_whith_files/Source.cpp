#include <iostream>
#include <direct.h>
#include <io.h>
#include <Windows.h>

using namespace std;

void removeDir(const char* path)
{
	int size = strlen(path) + 50;
	char* _tmpPath = new char[size];
	strcpy_s(_tmpPath, size, path);
	strcat_s(_tmpPath, size, "\\*.*");

	_finddata_t* info = new _finddata_t;
	long findHandle = _findfirst(_tmpPath, info);
	long tmpHandle = findHandle;

	// ���� ���� ���������� �����
	while (tmpHandle != -1)
	{
		if (strcmp(info->name, ".") != 0 && strcmp(info->name, "..") != 0)          
		{
			// ����������
			char* newPath = new char[size];
			// ����������� ���� � ������� ����������
			strcpy_s(newPath, size, path);
			// ������������ ���� � ����� ����������
			strcat_s(newPath, size, "\\");
			strcat_s(newPath, size, info->name);
			if (info->attrib & _A_SUBDIR)
			{

				//cout << "DIR: " << info->name << endl;
				// ����� ��������(������� � �������� ����������)
				removeDir(newPath);
				//cout << "Removed dir: " << newPath << endl;
			}
			// ����
			else
			{
				//cout << "FILE: " << info->name << endl;
				// �������� �����
				remove(newPath);
				cout << "Removed FILE: " << newPath << endl;
			}
			delete[] newPath;
		}
		// ������� � ���������� �����/�����
		tmpHandle = _findnext(findHandle, info);
	}
	// �������� �����
	_rmdir(path);
	cout << "Removed DIR: " << path << endl;

	delete info;
	_findclose(findHandle);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");
	/*
		_mkdir
		_rmdir
	*/
	// �������� ����������
	/*
	if (_mkdir("Some directory") != -1)
	{
		cout << "Succes created!" << endl;
	}
	else
	{
		cout << "Error!!!" << endl;
	}*/

	// ��������������
	//rename("Some directory", "Some renamed directory");

/*
	if (_rmdir("Some renamed directory") != -1)
	{
		cout << "Succes!" << endl;
	}
	else
	{
		cout << "Error!!!" << endl;
	}
*/

	removeDir("C:\\Users\\Denver\\Desktop\\Demo");

	return 0;
}