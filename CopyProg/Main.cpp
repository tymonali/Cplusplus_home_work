#include"Copy.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	Copy copy;
	copy.CopyProg("d:\\DemoDirr01", "d:\\DemoDirr02");
	
	
	//copy.CopyProg(argv[1], argv[2]);
	
	/*
	"D:\Учеба Академия ШАГ\C++\ООП\GitHub\HomeWork\Debug\CopyProg.exe" d:\DemoDirr01 d:\DemoDirr02
	*/

	return 0;
}