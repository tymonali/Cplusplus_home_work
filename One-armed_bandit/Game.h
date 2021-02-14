#pragma once
#include"Spools.h"
#include"Player.h"
#include<conio.h>

class Game
{
	// Цвета шрифта и фона
	enum ConsoleColor 
	{
		Black, Blue, Green, Cyan, Red, Mfgenta, Brown, LightGray, DarkGray,
		Lightblue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
	};
	// Переменная класса Player
	Player newplayer;
	// Три переменных типа Spools(бобины)
	Spools S1, S2, S3;
public:
	// Перегруженный конструктор
	Game(int count, char first);
	// Описываем игровой процесс
	bool Start();
	// Метод для вращения всех катушек
	void Rotation_all();
	// Сравнение мастей(символов)
	bool isWin();
	// Интерфейс автомата!!! Содрал на GitHub-е
	void SpoolShow();
	// Метод для установки цветов шрифта и фона
	void SetColor(int text, int background);
	// Мерцание экрана!!! Содрал на GitHub-е
	void Shimmer();
};