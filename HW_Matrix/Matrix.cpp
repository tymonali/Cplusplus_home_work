#include<iostream>
#include<Windows.h>
#include<iomanip>
using namespace std;

class Matrix
{
	int** mas;
	int rows, columns;
public:
	// ����������� �� ���������:
	Matrix()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "�������� ������������ �� ���������!\n";
		Sleep(1000);
		rows = 0;
		columns = 0;
		mas = NULL;
	}
	//������������� �����������
	Matrix(int st, int ct)		
	{
		cout << "�������� �������������� ������������!\n";
		Sleep(1000);
		// ��������� ������ ��� ��������� ������ � �������
		rows = st; 
		columns = ct;
		mas = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			mas[i] = new int[columns];
		}
	}
	// ������������� �������� ��������(������ ��� ���������� �� ������� ������)
	Matrix operator+(Matrix& ob)
	{
		cout << "�������� ��������� + \n";
		Sleep(1000);
		// ���� ���-�� ����� � �������� �������:
		if (columns == ob.columns && rows == ob.rows)
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < columns; j++)
					mas[i][j] = mas[i][j] + ob.mas[i][j];
			return *this;
		}
		// ���� �� �������:
		else cout << "\n ������� �� ���������� ��� ��������[" << rows << "][" << columns << "]";
	}
	// ������������� �������� ������������
	Matrix operator=(const Matrix& ob)
	{
		cout << "\n�������� ��������� = \n";
		Sleep(1000);
		// ���� ������, �������� ������������� ����� ������, ���-�� ��������,
		// �� ��� �������:
		if (this->mas != NULL)
		{
			for (int i = 0; i < rows; i++)
			{
				delete[]mas[i];
			}
			delete[]mas;
		}
		// ������� ����� ������ � ����������� ����������� �������:
		columns = ob.columns;
		rows = ob.rows;
		mas = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			mas[i] = new int[columns];
		}
		// �������� � ����� ������, ������������� ������:
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				mas[i][j] = ob.mas[i][j];
			}
		}
		return *this;
	}
	// ������������� �������� ���������
	Matrix operator*(Matrix& ob)
	{
		cout << "�������� ��������� *\n";
		Sleep(1000);
		if (columns == ob.columns && rows == ob.rows)
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < columns; j++)
					mas[i][j] = mas[i][j] * ob.mas[i][j];
			return *this;
		}
		else cout << "\n ������� �� ���������� ��� ���������[" << rows << "][" << columns << "]";
	}
	// ����� ��� ���������������� �������
	Matrix transport()
	{
		// ��������� ������
		Matrix temp;
		temp.rows = this->rows;
		temp.columns = this->columns;
		temp.mas = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			temp.mas[i] = new int[columns];
		}
		// �������� mas �� ��������� ������
		for (int i = 0, t = 1; i < rows; i++)
			for (int j = 0; j < columns; j++)
				temp.mas[i][j] = this->mas[i][j];
		// ������� mas
		for (int i = 0; i < rows; i++)
		{
			delete[]mas[i];
		}
		delete[]mas;
		// ������ ������� ������� � ������
		rows = temp.columns; 
		columns = temp.rows;
		// �������� ����� ������ ��� mas
		this->mas = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			this->mas[i] = new int[columns];
		}
		// �������� � ����� mas ������ �� temp�
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				this->mas[i][j] = temp.mas[j][i];// � ������ ����� ������������ �������
		return *this;

	}
	// ����� ��������� ������� �������
	int get(int st, int ct, int input_output_element)
	{
		if (input_output_element == 1 && st <= rows && ct <= columns)
		{
			cout << mas[st][ct];
		}
		else if (input_output_element == 0) cin >> mas[st][ct];
		else return mas[st][ct];
	}
	//����� �������
	void show()
	{
		int h = 5 * columns;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << setw(4) << mas[i][j] << "|";
			}
			cout << "\n";
			for (int i = 0; i < h; i++)
			{
				cout << '-';
			}
			cout << "\n";
		}
		cout << "\n";
	}
	//���������� �������
	void input(int avto, int st, int ct)
	{
		if (mas != NULL)
		{
			for (int i = 0; i < rows; i++)
			{
				delete[]mas[i];
			}
			delete[]mas;
		}
		if (st > 0 && ct > 0)
		{
			rows = st; columns = ct;
		}
		else
		{
			cout << "\n������� ���-�� ����� - ";
			cin >> rows;
			cout << "\n������� ���-�� �������� - ";
			cin >> columns;
		}
		mas = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			mas[i] = new int[columns];
		}
		if (!avto)
		{
			for (int i = 0, t = 1; i < rows; i++)
				for (int j = 0; j < columns; j++)
					mas[i][j] = t++;
		}
		else for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
			{
				cout << "\n��������� ������� [" << i << "][" << j << "] = ";
				cin >> mas[i][j];
			}
	}
	Matrix(Matrix& copy)		//����������� �����������
	{
		cout << "�������� ������������ �����������!\n";
		Sleep(1000);
		this->columns = copy.columns;
		this->rows = copy.rows;
		this->mas = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			this->mas[i] = new int[columns];
		}
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				this->mas[i][j] = copy.mas[i][j];
	}
	// ����������
	~Matrix()		
	{
		cout << "�������� �����������!\n";
		Sleep(1000);
		for (int i = 0; i < rows; i++)
		{
			delete[]mas[i];
		}
		delete[] mas;
		
	}
};
class MetodsForMenu
{
	enum matrix
	{
		input,
		output,
		element
	};
	static Matrix A, B;
public:
	static void AddA()
	{
		int a, b, c;
		cout << "\n������ ���-�� ����� - ";
		cin >> a;
		cout << "\n������ ���-�� �������� - ";
		cin >> b;
		cout << "\n[0] - ��������������\n[1] - ��������� ��������������\n";
		cin >> c;
		A.input(c, a, b);
		A.show();
	}
	static void AddB()
	{
		int a, b, c;
		cout << "\n������ ���-�� ����� - ";
		cin >> a;
		cout << "\n������ ���-�� �������� - ";
		cin >> b;
		cout << "\n[0] - ��������������\n[1] - ��������� ��������������\n";
		cin >> c;
		B.input(c, a, b);
		B.show();
	}
	static void ShowElementA()
	{
		int a, b;
		cout << "\n������� ����� �������� �������_1 [][]\n";
		cin >> a >> b;
		A.get(a, b, output);
	}
	static void ShowElementB()
	{
		int a, b;
		cout << "\n������� ����� �������� �������_2 [][]\n";
		cin >> a >> b;
		B.get(a, b, output);
	}
	static void Plus()
	{
		A = A + B;
		A.show();
	}
	static void Multiplication()
	{
		A = A * B;
		A.show();
	}
	static void Assignment()
	{
		A = B;
		A.show();
	}
	static void TranspA()
	{
		A.transport();
		A.show();
	}
	static void TranspB()
	{
		B.transport();
		B.show();
	}
};
Matrix MetodsForMenu::A;
Matrix MetodsForMenu::B;
class Menu
{
	void menu()
	{
		cout << "\n[1] - ������� �������_1 ��������� N �� M";
		cout << "\n[2] - ����� �� ����� �������� �������_1";
		cout << "\n[3] - ������� �������_2 ��������� N �� M";
		cout << "\n[4] - ����� �� ����� �������� �������_2";
		cout << "\n[5] - �������_1 + �������_2";
		cout << "\n[6] - �������_1 * �������_2";
		cout << "\n[7] - �������_1 = �������_2";
		cout << "\n[8] - ���������������� �������_1";
		cout << "\n[9] - ���������������� �������_2";
		cout << "\n[0] - �����\n";
	}
	void menuAction(int menuaction)
	{
		switch (menuaction)
		{
		case 1:// ������� �������_1 ��������� N �� M
		{
			system("cls");
			MetodsForMenu::AddA();
			system("pause");
			break;
		}
		case 2:// ����� �� ����� �������� �������_1
		{
			system("cls");
			MetodsForMenu::ShowElementA();
			system("pause");
			break;
		}
		case 3:// ������� �������_2 ��������� N �� M
		{
			system("cls");
			MetodsForMenu::AddB();
			system("pause");
			break;
		}
		case 4:// ����� �� ����� �������� �������_2
		{
			system("cls");
			MetodsForMenu::ShowElementB();
			system("pause");
			break;
		}
		case 5:// �������_1 + �������_2
		{
			system("cls");
			MetodsForMenu::Plus();
			system("pause");
			break;
		}
		case 6:// �������_1 * �������_2
		{
			system("cls");
			MetodsForMenu::Multiplication();
			system("pause");
			break;
		}
		case 7:// �������_1 = �������_2
		{
			system("cls");
			MetodsForMenu::Assignment();
			system("pause");
			break;
		}
		case 8:// ���������������� �������_1
		{
			system("cls");
			MetodsForMenu::TranspA();
			system("pause");
			break;
		}
		case 9:// ���������������� �������_2
		{
			system("cls");
			MetodsForMenu::TranspB();
			system("pause");
			break;
		}
		}
	}
public:
	void Start()
	{
		int action;
		do
		{
			system("cls");
			menu();
			cin >> action;
			menuAction(action);
		} 
		while (action != 0);
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");
	srand(time(0));
	Menu m;
	m.Start();
	return 0;
}