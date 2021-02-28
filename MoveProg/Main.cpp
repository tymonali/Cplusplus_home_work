#include "Move.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	Move move;
	move.moveProg("d:\\DemoDirr01", "d:\\DemoDirr02");

	//move.moveProg(argv[1], argv[2]);
	/*
	"D:\Учеба Академия ШАГ\C++\ООП\GitHub\HomeWork\Debug\copy_move_delete(Copy).exe" d:\DemoDirr01 d:\DemoDirr02
	*/

	return 0;
}