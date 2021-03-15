/*********************************************************
*	�������� ���������, ������� ����������� ��������	 *
*	��������� ��� ��������� ������� . ������������		 *
*	������ ��������� �������� ��� ������������ �����-	 *
*	������, ������� ���������� ���������, ����������	 *
*	������ ������� ������� ��������� .					 *
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
	// ����������� �� ���������
	Grid();
	// ��������� ������� ��������������
	void Fill_In_Manually();
	// ��������� ������������ �����(������� �� �����)
	void check();
	/*�������� �� ������� ������-�� ����� � �������*/
	bool isPresentInCol(int col, int num);
	/*�������� �� ������� ������-�� ����� � ������*/
	bool isPresentInRow(int row, int num);
	/*�������� �� ������� ������-�� ����� � �������� 3�3*/
	bool isPresentInBox(int boxStartRow, int boxStartCol, int num);
	/*����� ���������� �����(�� ��������� 0)*/
	bool findEmptyPlace(int& row, int& col);
	/*����� ������� ������� �� ������*/
	bool isValidPlace(int row, int col, int num);
	/*�������*/
	bool solveSudoku();
};

