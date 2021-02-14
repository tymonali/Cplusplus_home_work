#include "Mass.h"
int Mass::kol = 0;
Mass::Mass()
{
	mas = nullptr;
	size = 0;
	kol++;
}

Mass::Mass(int n)
{
	size = n;
	mas = (int*)malloc(size * sizeof(int));
	kol++;
}

Mass::Mass(const Mass& copy)
{
	size = copy.size;
	mas = (int*)malloc(size * sizeof(int));
	memcpy(mas, copy.mas, sizeof(int) * size);
	kol++;
}

Mass::Mass(Mass&& copy)
{
	size = copy.size;
	mas = copy.mas;
	copy.mas = nullptr;
	kol++;
}

int Mass::GetKol()
{
	return kol;
}

Mass& Mass::operator=(const Mass& copy)
{
	if (this->mas != nullptr) free(mas);
	size = copy.size;
	mas = (int*)malloc(size * sizeof(int));
	memcpy(mas, copy.mas, sizeof(int) * size);
	return *this;
}

Mass& Mass::operator=(Mass&& copy)
{
	if (mas != nullptr) free(mas);
	size = copy.size;
	mas = copy.mas;
	copy.mas = nullptr;
	return *this;
}

Mass Mass::operator+(const Mass& obj)
{
	Mass tmp;
	tmp.size = (size < obj.size) ? size : obj.size;
	tmp.mas = (int*)malloc(tmp.size * sizeof(int));
	for (int i = 0; i < tmp.size; i++)
	{
		tmp.mas[i] = mas[i] + obj.mas[i];
	}
	return tmp;
}

Mass Mass::operator+(const int& n) const
{
	Mass tmp;
	tmp.size = size;
	tmp.mas = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		tmp.mas[i] = mas[i] + n;
	}
	return tmp;
}

bool Mass::operator==(const Mass& obj)
{
	if (size != obj.size) return false;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] != obj.mas[i]) return false;
	}
	return true;
}

bool Mass::operator!=(const Mass& obj)
{
	return !(*this == obj);
}

Mass& Mass::operator++()
{
	mas = (int*)realloc(mas, (size + 1) * sizeof(int));
	mas[size] = rand() % 25;
	size++;
	return *this;
}

Mass Mass::operator++(int n)
{
	Mass tmp = *this;
	mas = (int*)realloc(mas, (size + 1) * sizeof(int));
	mas[size] = rand() % 25;
	size++;
	return tmp;
}

int& Mass::operator[](int i)
{
	if (i < 0)
		return mas[0];
	if (i > size - 1)
		return mas[size - 1];
	return mas[i];
}

int Mass::operator()(int num)
{
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == num) return i;
	}
	return -1;
}

Mass::operator int()
{
	int s = 0;
	for (int i = 0; i < size; i++)
	{
		s += mas[i];
	}
	return s;
}

void Mass::Rand() const
{
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 25;
	}
}

void Mass::Print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << "\t";
	}
	cout << "\n";
}

Mass::~Mass()
{
	free(mas);
	kol--;
}

Mass operator+(const int& n, const Mass& obj)
{
	Mass tmp = obj + n;
	return tmp;
}

ostream& operator<<(ostream& os, const Mass& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		os << obj.mas[i] << "\t";
	}
	return os;
}

istream& operator>>(istream& is, Mass& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		cout << "Vvedite mas[" << i << "]: ";
		is >> obj.mas[i];
	}
	return is;
}
