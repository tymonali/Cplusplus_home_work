#include "Grid.h"

Grid::Grid()
{
	// Так будет заполнено по умолчанию!
	int G[N][N] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}};
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			grid[i][j] = G[i][j];
		}
	}
	Attempt = 0;
}

void Grid::Fill_In_Manually()
{
	cout << "Введите извесные цифры Вашего судоку (вместо неизвесных чисел ставим 0)\n";
	for(int i = 0; i < N; i++)
	{
		cout << "Введите цифры " << i + 1 << "-го ряда:\n";
		for(int j = 0; j < N; j++)
		{
			cout << "No " << j + 1 << ": ";
			cin >> grid[i][j];
			while(grid[i][j] < 0 || grid[i][j] > 9)
			{
				cout << "Число должно быть >= 0 и <= 9!!!\n";
				cin >> grid[i][j];
			}
		}
		system("cls");
	}
}

void Grid::check()
{
	
	/*Получаение дескриптора устройства стандартного вывода*/
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/*Переменная для подсчета кол-ва символов разделения строк*/
	int h = 4 * 9;
	/*Переменная для вывода числа в строковом значении*/
	string s;
	for (int i = 0; i < 9; i++)
	{
		/*Цикл для вывода [i]-той строки с цифрами*/
		for (int j = 0; j < 9; j++)
		{
			// если число не известно, то выводим пробел
			if(grid[i][j] == 0)
			{
				s = " ";
			}
			// Если известно, то выводим число в строковом виде
			else
			{
				// преобразуем число в строку
				s = to_string(grid[i][j]);
			}
			/*На третьем и на шестом столбцах разделитель будет другого цвета*/
			if (j == 2 || j == 5) 
			{
				cout << setw(3) << s;
				/*Цвет символов - Синий. Цвет фона - Черный*/
				SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightRed));
				cout << "|";
				/*Возвращаем, как было: фон черный, символ светло-серый*/
				SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
			}
			else
			{
				cout << setw(3) << s << "|";
			}
		}
		cout << "\n";
		/*Цикл для вывода [i]-той строки с символом разделения строки "-"*/
		for (int a = 0; a < h; a++)
		{
			/*третья и шестая строка будут отделены другим цветом*/
			if (i == 2 || i == 5)  
			{
				/*Цвет символов - Синий. Цвет фона - Черный*/
				SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightRed));
				cout << "-";
				/*Возвращаем, как было: фон черный, символ светло-серый*/
				SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
			}
			else
			{
				cout << "-";
			}
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "Попыток: " << Attempt << endl;
}

/*Проверка на наличие такого-же числа в столбце*/
bool Grid::isPresentInCol(int col, int num)
{
	for (int row = 0; row < N; row++) 
	{
		if (grid[row][col] == num) 
		{
			return true;
		}
	}
	return false;
}

/*Проверка на наличие такого-же числа в строке*/
bool Grid::isPresentInRow(int row, int num)
{
	for (int col = 0; col < N; col++)
	{
		if (grid[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

/*Проверка на наличие такого-же числа в квадрате 3х3*/
bool Grid::isPresentInBox(int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++) 
	{
		for (int col = 0; col < 3; col++) 
		{
			if (grid[row + boxStartRow][col + boxStartCol] == num) 
			{
				return true;
			}
		}
	}
	return false;
}

/*Поиск свободного места(со значением 0)*/
bool Grid::findEmptyPlace(int& row, int& col)
{
	for (row = 0; row < N; row++) 
	{
		for (col = 0; col < N; col++) 
		{
			if (grid[row][col] == 0)
			{ 
				return true;
			}
		}
	}
	return false;
}

/*Когда похожий элемент не найден(подходящее место)*/
bool Grid::isValidPlace(int row, int col, int num)
{
	return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3,
		col - col % 3, num);
}

/*Решение*/
bool Grid::solveSudoku()
{
	int row, col;
	/*Если не осталось пустых клеток*/
	if (!findEmptyPlace(row, col)) 
	{
		return true;
	}
	//действительные числа от 1 до 9
	for (int num = 1; num <= 9; num++) 
	{
		//проверьте валидацию, если да, введите число в сетку
		if (isValidPlace(row, col, num)) 
		{ 
			grid[row][col] = num;
			//рекурсивно перейти к другим клеткам в сетке:
			if (solveSudoku() == true) 
			{
				return true;
			}
			//Установить 0 клетке, когда условия не выполнены
			grid[row][col] = 0; 
			Attempt++;
		}
	}
	return false;
}
