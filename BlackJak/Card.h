#pragma once
#include <iostream>
#include<Windows.h>
#include<iomanip>
#include<time.h>
using namespace std;
//#include <string.h>

using namespace std;

enum Suit { clubs, diamonds, hearts, spades };

class Card {
private:
	Suit suit;
	int face;
public:
	Card();
	void setCard(int, Suit);
	void PrintCard();
	int getFace();
	int getScore();
	void Emblema()
	{
		cout << "\n\n";
		cout << "$$$$$  $$      $$$$   $$$$  $$  $$ " << "   $$$$     $$  " << " $$$$$$  $$$$   $$$$  $$  $$" << endl;
		cout << "$$  $$ $$     $$  $$ $$  $$ $$ $$  " << "  $$  $$  $$$$  " << "     $$ $$  $$ $$  $$ $$ $$" << endl;
		cout << "$$$$$  $$     $$$$$$ $$     $$$$   " << "     $$     $$  " << "     $$ $$$$$$ $$     $$$$" << endl;
		cout << "$$  $$ $$     $$  $$ $$  $$ $$ $$  " << "  _$$       $$  " << " $$  $$ $$  $$ $$  $$ $$ $$" << endl;
		cout << "$$$$$  $$$$$$ $$  $$  $$$$  $$  $$ " << "  $$$$$$    $$  " << "  $$$$  $$  $$  $$$$  $$  $$" << endl;


		cout << "\t\t\t ------- " << "	" << " ------- " << endl;
		cout << "\t\t\t|" << char(4) << "     " << char(4) << "|" << "	" << "|" << char(3) << "     " << char(3) << "|" << endl;
		cout << "\t\t\t|   *   |" << "	" << "|  * *  |" << endl;
		cout << "\t\t\t|  * *  |" << "	" << "|  * *  |" << endl;
		cout << "\t\t\t|  * *  |" << "	" << "|  **   |" << endl;
		cout << "\t\t\t|  * *  |" << "	" << "|  * *  |" << endl;
		cout << "\t\t\t|   **  |" << "	" << "|  * *  |" << endl;
		cout << "\t\t\t|" << char(4) << "     " << char(4) << "|" << "	" << "|" << char(3) << "     " << char(3) << "|" << endl;
		cout << "\t\t\t ------- " << "	" << " ------- " << endl;
	}
};