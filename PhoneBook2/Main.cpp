#include"PhoneBook.h"
#include"App.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	App app;
	app.start();

	/*PhoneBook pb;
	pb.Read_File(pb.getBook(), pb.getSize(), "data.txt");
	pb.showBook();*/
	
	return 0;
}