#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	unsigned short int first = 60000;
	signed short int second = 60000;
	if (second == first) cout << "Числа эквивалентны!\n";	
	else cout << "Числа не эквивалентны!\n";				// Правильный ответ!..

	return 0;
}