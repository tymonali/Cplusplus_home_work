#pragma once
#include<iostream>
#include<Windows.h>
#include<fstream>
#include <direct.h>
#include <io.h>			// ����� ������
#include<string>

using namespace std;

class DeleteEXE
{
	enum
	{
		DeleteDirr = 1,				// �������
		Skip,						// ����������
		Delete_for_everyone,		// ������� ��� ����
		Cancel						// ������
	};
	bool doDelete;
public:
	void deleteProg(string pathFrom);
	int deleteAction();
};

