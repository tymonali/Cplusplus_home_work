#include "DeleteEXE.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	DeleteEXE del;
	del.deleteProg("d:\\DemoDirr02");

	//copy.CopyProg(argv[1], argv[2]);
	/*
	"D:\Учеба Академия ШАГ\C++\ООП\GitHub\HomeWork\Debug\copy_move_delete(Copy).exe" d:\DemoDirr01 d:\DemoDirr02
	*/

	return 0;
}