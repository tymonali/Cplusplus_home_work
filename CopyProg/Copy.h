#pragma once
#include<iostream>
#include<Windows.h>
#include<fstream>
#include <direct.h>
#include <io.h>			// ����� ������
#include<string>

using namespace std;

class Copy
{
	enum
	{
		CopyDirr,					// ����������
		Skip,						// ����������
		Copy_for_everyone			// ���������� ��� ����
	};
public:
	void CopyProg(string pathFrom, string pathTo);
	void copyFile(string copyFrom, string copyTo);
	int CopyAction();
};

