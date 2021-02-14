#pragma once
#include "Card.h"
#include "Player.h"

class GameData
{
	Player player_1;// Переменная класса Player
	Player player_2;// Переменная класса Player
	Card_Batch koloda;// Переменная класса Card_Batch
	// Действия для игрока 1
	int P_1Act();
	// Действия для игрока 2
	int P_2Act();
	// Процесс Игры
	void GameProcess();
	// Вывод результатов игры
	void GameResult();
	// Вход/Выход
	void Menu();
	// Меню Игры
	void SubMenu();
	// Действия для меню Вход/Выход
	void MenuAction(int menuaction);
	// Действия для игрового меню
	void SubmenuAction(int menuaction);
public:
	void Start();
};