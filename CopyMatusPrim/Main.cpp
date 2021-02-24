#include "CDAF.h"

int main(int argc, char* argv[])
{
	CDAF newApp;
	if (argc != 3)
	{
		cout << "CopyDir.exe [pathFrom] [pathTo]\n";
		return 0;
	}
	newApp.copyDir(argv[1], argv[2]);
}