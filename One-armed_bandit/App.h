#pragma once
#include "Game.h"
class App
{
	enum { EXIT, NEW };
	Game* newgame;
public:
	// Пуск
	void Start();
	// Начальное меню с логотипом
	void menu();
	~App() { delete newgame; }
};