#include "GameData.h"

int GameData::P_1Act()
{
	int act;
	system("cls");
	cout << "Игрок 1:\n\n";
	player_1.PrintNal();
	player_1.SetScore();
	cout << "Всего очков: " << player_1.getScore() << "\n\n";
	if (player_1.getScore() >= 21)
	{
		return 0;
	}
	cout << "[1] Продолжить\n";
	cout << "[0] Стоп\n";
	cin >> act;
	return act;
}

int GameData::P_2Act()
{
	int act;
	system("cls");
	cout << "Игрок 2:\n\n";
	player_2.PrintNal();
	player_2.SetScore();
	cout << "Всего очков: " << player_2.getScore() << "\n\n";
	if (player_2.getScore() >= 21)
	{
		return 0;
	}
	cout << "[1] Продолжить\n";
	cout << "[0] Стоп\n";
	cin >> act;
	return act;
}

void GameData::GameProcess()
{
	int act = 1;
	int score1,score2;
	while (act != 0)
	{
		switch (P_1Act())
		{
		case 1:
			system("cls");
			cout << "Игрок 1:\n";
			player_1.SingleDistribution(koloda);
			player_1.PrintNal();
			player_1.SetScore();
			cout << "Всего очков: " << player_1.getScore() << "\n\n";
			system("pause");
			break;
		case 0:
			act = 0;
			break;
		}
		switch (P_2Act())
		{
		case 1:
			player_2.SingleDistribution(koloda);
			system("cls");
			cout << "Игрок 2:\n";
			player_2.PrintNal();
			player_2.SetScore();
			cout << "Всего очков: " << player_2.getScore() << "\n\n";
			system("pause");
			break;
		case 0:
			act = 0;
			break;
		}
	}
}

void GameData::GameResult()
{
	system("cls");
	if (player_1.getScore() < 21 && player_2.getScore() < 21)
	{
		if (player_1.getScore() > player_2.getScore())
		{
			cout << "Победа присвоена Игроку 1!\n";
		}
		else if (player_1.getScore() == player_2.getScore())
		{
			cout << "Ничья!\n";
		}
		else
		{
			cout << "Победа присвоена Игроку 2!\n";
		}
	}
	else if (player_1.getScore() > 21 || player_2.getScore() > 21)
	{
		if (player_1.getScore() > 21)
		{
			cout << "Игрок 1 проиграл!\n";
		}
		else
		{
			cout << "Игрок 2 проиграл!\n";
		}
	}
	else if (player_1.getScore() == 21 || player_2.getScore() == 21)
	{
		if (player_1.getScore() == 21)
		{
			cout << "Игрок 1 - Чистая победа!!!\n";
		}
		else
		{
			cout << "Игрок 2 - Чистая победа!!!\n";
		}
	}
	system("pause");
	koloda.setSize(36);
	player_1.setSize(2);
	player_2.setSize(2);
	player_1.setScore(0);
	player_2.setScore(0);
}

void GameData::Menu()
{
	Card c;
	c.Emblema();
	cout << "[1] Старт игры\n";
	cout << "[0] Выход\n";
}

void GameData::SubMenu()
{
	Card A;
	A.Emblema();
	cout << "[1] Взять колоду\n";
	cout << "[2] Перетусовать колоду\n";	
	cout << "[3] Показать колоду\n";	
	cout << "[4] Начать игру\n";
	cout << "[0] Выход\n";	
}

void GameData::MenuAction(int menuaction)
{
	if (menuaction == 1)
	{
		int action;
		do
		{
			system("cls");
			SubMenu();
			cin >> action;
			SubmenuAction(action);
		} while (action != 0);
	}
}

void GameData::SubmenuAction(int menuaction)
{
	switch (menuaction)
	{
	case 1:
		system("cls");
		koloda.setCard_Batch();
		break;
	case 2:
		system("cls");
		koloda.Shuffle();
		break;
	case 3:
		system("cls");
		koloda.display();
		system("pause");
		break;
	case 4:
		system("cls");
		player_1.FirstDistribution(koloda);
		player_2.FirstDistribution(koloda);
		GameProcess();
		GameResult();
		break;
	}
}

void GameData::Start()
{
	int action;
	do
	{
		system("cls");
		Menu();
		cin >> action;
		MenuAction(action);
	}
	while (action != 0);

}
