#include<iostream>
#include<Windows.h>
#include<iomanip>
using namespace std;

class Matrix
{
	int** mas;
	int rows, columns;
public:
	// Конструктор по умолчанию:
	Matrix()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "Сработка конструктора по умолчанию!\n";
		Sleep(1000);
		rows = 0;
		columns = 0;
		mas = NULL;
	}
	//Перегруженный конструктор
	Matrix(int st, int ct)		
	{
		cout << "Сработка перегруженного конструктора!\n";
		Sleep(1000);
		// Выделение памяти под введенные строки и столбцы
		rows = st; 
		columns = ct;
		mas = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			mas[i] = new int[columns];
		}
	}
	// Перегруженный оператор сложения(только для одинаковых по размеру матриц)
	Matrix operator+(Matrix& ob)
	{
		cout << "Сработка оператора + \n";
		Sleep(1000);
		// Если кол-во строк и столбцов совпали:
		if (columns == ob.columns && rows == ob.rows)
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < columns; j++)
					mas[i][j] = mas[i][j] + ob.mas[i][j];
			return *this;
		}
		// Если не совпали:
		else cout << "\n Матрицы не совместимы для сложения[" << rows << "][" << columns << "]";
	}
	// Перегруженный оператор присваивания
	Matrix operator=(const Matrix& ob)
	{
		cout << "\nСработка оператора = \n";
		Sleep(1000);
		// Если массив, которому присваиваются новые данные, чем-то заполнен,
		// Мы его удаляем:
		if (this->mas != NULL)
		{
			for (int i = 0; i < rows; i++)
			{
				delete[]mas[i];
			}
			delete[]mas;
		}
		// Создаем новый массив с параметрами присваемого массива:
		columns = ob.columns;
		rows = ob.rows;
		mas = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			mas[i] = new int[columns];
		}
		// Копируем в новый массив, присваеваемые данные:
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				mas[i][j] = ob.mas[i][j];
			}
		}
		return *this;
	}
	// Перегруженный оператор умножения
	Matrix operator*(Matrix& ob)
	{
		cout << "Сработка оператора *\n";
		Sleep(1000);
		if (columns == ob.columns && rows == ob.rows)
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < columns; j++)
					mas[i][j] = mas[i][j] * ob.mas[i][j];
			return *this;
		}
		else cout << "\n Матрицы не совместимы для умножения[" << rows << "][" << columns << "]";
	}
	// Метод для транспонирования матрицы
	Matrix transport()
	{
		// Временный массив
		Matrix temp;
		temp.rows = this->rows;
		temp.columns = this->columns;
		temp.mas = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			temp.mas[i] = new int[columns];
		}
		// Копируем mas во временный массив
		for (int i = 0, t = 1; i < rows; i++)
			for (int j = 0; j < columns; j++)
				temp.mas[i][j] = this->mas[i][j];
		// Удаляем mas
		for (int i = 0; i < rows; i++)
		{
			delete[]mas[i];
		}
		delete[]mas;
		// Меняем местами столбцы и строки
		rows = temp.columns; 
		columns = temp.rows;
		// Выделяем новую память для mas
		this->mas = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			this->mas[i] = new int[columns];
		}
		// Копируем в новый mas данные из tempа
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				this->mas[i][j] = temp.mas[j][i];// В строку будет передаваться столбец
		return *this;

	}
	// Взять отдельный элемент матрицы
	int get(int st, int ct, int input_output_element)
	{
		if (input_output_element == 1 && st <= rows && ct <= columns)
		{
			cout << mas[st][ct];
		}
		else if (input_output_element == 0) cin >> mas[st][ct];
		else return mas[st][ct];
	}
	//показ матрицы
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
	//заполнение матрицы
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
			cout << "\nВведите кол-во строк - ";
			cin >> rows;
			cout << "\nВведите кол-во столбцов - ";
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
				cout << "\nНазначьте элемент [" << i << "][" << j << "] = ";
				cin >> mas[i][j];
			}
	}
	Matrix(Matrix& copy)		//конструктор копирования
	{
		cout << "Сработка конструктора копирования!\n";
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
	// Деструктор
	~Matrix()		
	{
		cout << "Сработка деструктора!\n";
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
		cout << "\nВедите кол-во строк - ";
		cin >> a;
		cout << "\nВедите кол-во столбцов - ";
		cin >> b;
		cout << "\n[0] - Автозаполнение\n[1] - Заполнить самостоятельно\n";
		cin >> c;
		A.input(c, a, b);
		A.show();
	}
	static void AddB()
	{
		int a, b, c;
		cout << "\nВедите кол-во строк - ";
		cin >> a;
		cout << "\nВедите кол-во столбцов - ";
		cin >> b;
		cout << "\n[0] - Автозаполнение\n[1] - Заполнить самостоятельно\n";
		cin >> c;
		B.input(c, a, b);
		B.show();
	}
	static void ShowElementA()
	{
		int a, b;
		cout << "\nВведите адрес элемента матрицы_1 [][]\n";
		cin >> a >> b;
		A.get(a, b, output);
	}
	static void ShowElementB()
	{
		int a, b;
		cout << "\nВведите адрес элемента матрицы_2 [][]\n";
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
		cout << "\n[1] - Создать матрицу_1 размерами N на M";
		cout << "\n[2] - Вывод на экран элемента матрицы_1";
		cout << "\n[3] - Создать матрицу_2 размерами N на M";
		cout << "\n[4] - Вывод на экран элемента матрицы_2";
		cout << "\n[5] - Матрица_1 + Матрица_2";
		cout << "\n[6] - Матрица_1 * Матрица_2";
		cout << "\n[7] - Матрица_1 = Матрица_2";
		cout << "\n[8] - Транспонирование Матрицы_1";
		cout << "\n[9] - Транспонирование Матрицы_2";
		cout << "\n[0] - Выход\n";
	}
	void menuAction(int menuaction)
	{
		switch (menuaction)
		{
		case 1:// Создать матрицу_1 размерами N на M
		{
			system("cls");
			MetodsForMenu::AddA();
			system("pause");
			break;
		}
		case 2:// Вывод на экран элемента матрицы_1
		{
			system("cls");
			MetodsForMenu::ShowElementA();
			system("pause");
			break;
		}
		case 3:// Создать матрицу_2 размерами N на M
		{
			system("cls");
			MetodsForMenu::AddB();
			system("pause");
			break;
		}
		case 4:// Вывод на экран элемента матрицы_2
		{
			system("cls");
			MetodsForMenu::ShowElementB();
			system("pause");
			break;
		}
		case 5:// Матрица_1 + Матрица_2
		{
			system("cls");
			MetodsForMenu::Plus();
			system("pause");
			break;
		}
		case 6:// Матрица_1 * Матрица_2
		{
			system("cls");
			MetodsForMenu::Multiplication();
			system("pause");
			break;
		}
		case 7:// Матрица_1 = Матрица_2
		{
			system("cls");
			MetodsForMenu::Assignment();
			system("pause");
			break;
		}
		case 8:// Транспонирование Матрицы_1
		{
			system("cls");
			MetodsForMenu::TranspA();
			system("pause");
			break;
		}
		case 9:// Транспонирование Матрицы_2
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