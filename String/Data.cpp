#pragma once
#include "Data.h"

void ProgrammData::menu()
{
	cout << "[1] Старт" << endl;
	cout << "[0] Выход" << endl;
}

bool ProgrammData::runAction(int action)
{
	switch (action) 
	{
	case 0:
		return false;
		break;
	case 1:
		ProgData();
		cout << endl;
		system("pause");
		break;
	}
	return true;
}

void ProgrammData::start()
{
	int action;
	while (true) 
	{
		system("cls");

		menu();
		cin >> action;
		if (!runAction(action))
		{
			break;
		}
	}
}

customPrintf ProgrammData::ProgData()
{
	customPrintf d;
	d.custom_Printf("C%d%f%s%f%s%f%s%f%s", "Program Files", "Adobe", "bin", "adobe.exe");
	return d;
}