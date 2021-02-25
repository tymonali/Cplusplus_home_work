#include"Copy.h"



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	Copy copy;
	copy.CopyProg("d:\\DemoDirr01", "d:\\DemoDirr02");

	//copy.Copy(argv[1], argv[2]);
	/*
	"D:\Учеба Академия ШАГ\C++\ООП\GitHub\HomeWork\Debug\copy_move_delete(Copy).exe" d:\DemoDirr01 d:\DemoDirr02
	*/

	return 0;
}