#include <iostream>
#include "CardBatch.h"
#include"Player.h"
#include "GameData.h"
using namespace std;

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");
	srand(time(0));

	GameData g;
	g.Start();
	return 0;
}