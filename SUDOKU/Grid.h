/*********************************************************
*	Написать программу, которая разгадывает японский	 *
*	кроссворд под названием «Судоку» . Пользователь		 *
*	вводит начальные значения уже существующие в крос-	 *
*	сворде, который необходимо разгадать, и программа	 *
*	выдает на экран готовый результат .					 *
**********************************************************/
#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <stdio.h>
#include <string>

using namespace std;

#define N 9

class Grid
{
	enum ConsoleColor {
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Brown = 6,
		LightGray = 7,
		DarkGray = 8,
		LightBlue = 9,
		LightGreen = 10,
		LightCyan = 11,
		LightRed = 12,
		LightMagenta = 13,
		Yellow = 14,
		White = 15
	};
	int grid[N][N];
	int Attempt;
public:
	// Конструктор по умолчанию
	Grid();
	// Заполнить таблицу самостоятельно
	void Fill_In_Manually();
	// Проверить правильность ввода(вывести на экран)
	void check();
	/*Проверка на наличие такого-же числа в столбце*/
	bool isPresentInCol(int col, int num);
	/*Проверка на наличие такого-же числа в строке*/
	bool isPresentInRow(int row, int num);
	/*Проверка на наличие такого-же числа в квадрате 3х3*/
	bool isPresentInBox(int boxStartRow, int boxStartCol, int num);
	/*Поиск свободного места(со значением 0)*/
	bool findEmptyPlace(int& row, int& col);
	/*Когда похожий элемент не найден*/
	bool isValidPlace(int row, int col, int num);
	/*Решение*/
	bool solveSudoku();
};

