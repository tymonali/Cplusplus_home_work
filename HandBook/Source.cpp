#include "Application.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color B0");
	/*Application app;
	app.start();*/

	
	
	Address ad("Паганини", 14 ,2, "Проспект");

	ad.Print(ad);

	return 0;
}