#include "Grid.h"

Grid::Grid()
{
	// ��� ����� ��������� �� ���������!
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
	cout << "������� �������� ����� ������ ������ (������ ���������� ����� ������ 0)\n";
	for(int i = 0; i < N; i++)
	{
		cout << "������� ����� " << i + 1 << "-�� ����:\n";
		for(int j = 0; j < N; j++)
		{
			cout << "No " << j + 1 << ": ";
			cin >> grid[i][j];
			while(grid[i][j] < 0 || grid[i][j] > 9)
			{
				cout << "����� ������ ���� >= 0 � <= 9!!!\n";
				cin >> grid[i][j];
			}
		}
		system("cls");
	}
}

void Grid::check()
{
	
	/*���������� ����������� ���������� ������������ ������*/
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/*���������� ��� �������� ���-�� �������� ���������� �����*/
	int h = 4 * 9;
	/*���������� ��� ������ ����� � ��������� ��������*/
	string s;
	for (int i = 0; i < 9; i++)
	{
		/*���� ��� ������ [i]-��� ������ � �������*/
		for (int j = 0; j < 9; j++)
		{
			// ���� ����� �� ��������, �� ������� ������
			if(grid[i][j] == 0)
			{
				s = " ";
			}
			// ���� ��������, �� ������� ����� � ��������� ����
			else
			{
				// ����������� ����� � ������
				s = to_string(grid[i][j]);
			}
			/*�� ������� � �� ������ �������� ����������� ����� ������� �����*/
			if (j == 2 || j == 5) 
			{
				cout << setw(3) << s;
				/*���� �������� - �����. ���� ���� - ������*/
				SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightRed));
				cout << "|";
				/*����������, ��� ����: ��� ������, ������ ������-�����*/
				SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
			}
			else
			{
				cout << setw(3) << s << "|";
			}
		}
		cout << "\n";
		/*���� ��� ������ [i]-��� ������ � �������� ���������� ������ "-"*/
		for (int a = 0; a < h; a++)
		{
			/*������ � ������ ������ ����� �������� ������ ������*/
			if (i == 2 || i == 5)  
			{
				/*���� �������� - �����. ���� ���� - ������*/
				SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightRed));
				cout << "-";
				/*����������, ��� ����: ��� ������, ������ ������-�����*/
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
	cout << "�������: " << Attempt << endl;
}

/*�������� �� ������� ������-�� ����� � �������*/
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

/*�������� �� ������� ������-�� ����� � ������*/
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

/*�������� �� ������� ������-�� ����� � �������� 3�3*/
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

/*����� ���������� �����(�� ��������� 0)*/
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

/*����� ������� ������� �� ������(���������� �����)*/
bool Grid::isValidPlace(int row, int col, int num)
{
	return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3,
		col - col % 3, num);
}

/*�������*/
bool Grid::solveSudoku()
{
	int row, col;
	/*���� �� �������� ������ ������*/
	if (!findEmptyPlace(row, col)) 
	{
		return true;
	}
	//�������������� ����� �� 1 �� 9
	for (int num = 1; num <= 9; num++) 
	{
		//��������� ���������, ���� ��, ������� ����� � �����
		if (isValidPlace(row, col, num)) 
		{ 
			grid[row][col] = num;
			//���������� ������� � ������ ������� � �����:
			if (solveSudoku() == true) 
			{
				return true;
			}
			//���������� 0 ������, ����� ������� �� ���������
			grid[row][col] = 0; 
			Attempt++;
		}
	}
	return false;
}
