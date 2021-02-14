#include "Game.h"

Game::Game(int count, char first) : S1(count, first),S2(count, first),S3(count, first)
{
	/*
		����������� ������ ������� �����
		���� �������� ���������� first, �� �����
		������������ ����� ������ ��������, ��������
		�� ������
		� ���� �������� ���������� count, �� �����
		���������(���������) ���-�� ��������� � �������
	*/
}

bool Game::Start()
{
	while (true)
	{
		char key;
		if (newplayer.Get() <= 0)
		{
			system("cls");
			cout << "������� ��� �����...\n����� ����� �������...\n";
			_getch();
			return true;
		}
		system("cls");
		cout << "\n���� ������: " << newplayer.Get() << " $" << endl;
		SpoolShow();
		// ������, ���� ���������� Enter
		while ((key = _getch()) == 13)
		{
			--newplayer;
			Rotation_all();
			// ���� ������� ��� �����(�������)
			if (isWin()) 
			{
				++newplayer; // +100
				Shimmer();   // �������� ������
			}
			break;
		}
		if (key == 32)
		{
			return true;
		}
	}
}

void Game::Rotation_all()
{
	S1.Rotation();
	S2.Rotation();
	S3.Rotation();
}

bool Game::isWin()
{
	return S1.Show() == S2.Show() && S1.Show() == S3.Show();
}

void Game::SpoolShow()
{
	SetColor(Blue, LightCyan);
	cout << "            \t\t    *J  A  C  K  P  O  T*                " << endl;
	SetColor(Red, LightCyan);
	cout << "            \t\t ==========================             " << endl;
	cout << "            \t\t-||     ___  ___  ___     ||-           " << endl;
	cout << "            \t\t-||       /    /    /     ||-           " << endl;
	cout << "            \t\t-||      /    /    /      ||-           " << endl;
	cout << "            \t\t   ~~~~~~~~~~~~~~~~~~~~~~~       " << endl;
	SetColor(Green, LightCyan);
	cout << "             \t\t   $$$$$$$$$$$$$$$$$$$$$$$       " << endl;
	SetColor(Red, LightCyan);
	cout << "             \t\t  ========================= @     " << endl;
	SetColor(Black, LightCyan);
	cout << "             \t\t   _______________________      " << endl;
	cout << "             \t\t                                 " << endl;
	cout << "             \t\t        -------------\n";
	cout << "             \t\t        |";
	for (int i = 0; i < 3; i++)
	{
		
		if (i == 0)
			cout << setw(2) << S1.Show() << " |";
		else if (i == 1) 
			cout << setw(2) << S2.Show() << " |";
		else
			cout << setw(2) << S3.Show() << " |";
	}
	cout << endl;
	cout << "             \t\t        -------------\n";
	cout << "             \t\t   _______________________     " << endl;

	SetColor(Red, LightCyan);
	cout << "\t\t          =========================            " << endl;
	SetColor(Blue, LightCyan);
	cout << "\t\t          =========================            " << endl;
	SetColor(Red, LightCyan);
	cout << "\t\t         / __________  ___________ \\          " << endl;
	cout << "\t\t        / /Enter ����\\/Space �����\\ \\       " << endl;
	cout << "\t\t       /_____________________________\\        " << endl;
	SetColor(Black, LightCyan);
	cout << "\t\t       |  ________________________   |         " << endl;
}

void Game::SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Game::Shimmer()
{
	for (int i = system("color B0"); i
		< system("color 10")
		< system("color 20")
		< system("color 30")
		< system("color 40")
		< system("color 50")
		< system("color 60")
		< system("color 40")
		< system("color 80")
		< system("color 90")
		< system("color 10")
		< system("color 20")
		< system("color 30")
		< system("color 40")
		< system("color 50")
		< system("color 60")
		< system("color 40")
		< system("color 80")
		< system("color 90")
		< system("color 10")
		< system("color 20")
		< system("color 30")
		< system("color 40")
		< system("color 50")
		< system("color 60")
		< system("color 40")
		< system("color 80")
		< system("color 90")
		< system("color 10")
		< system("color 20")
		< system("color 30")
		< system("color 40")
		< system("color A0")
		< system("color B0")
		< system("color 40")
		< system("color B0"); i++) 
	{
		cout << i++;
		Sleep(2);
		/*
			���� ������ ��� ����, ����� ������� � ����������, �� ����� �������
			��� ������� �� ������ ����!
		*/
	}

}