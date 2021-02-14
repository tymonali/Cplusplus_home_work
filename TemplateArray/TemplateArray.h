#pragma once
#include<iostream>
#include<Windows.h>

using std::cout;
using std::cin;
using std::endl;

template <class T>
class Array
{
	T* array;	// ������(������)
	int size;	// ������ �������
	int grow;	// ���������� ��� ����������� �������
	int maxindex;// ����������� ������ ����������� �������
public:
	// ����������� �� ���������
	Array();
	// ����������� �����������
	Array(Array& copy);
	// ����������
	~Array();

	// ������ �� �������:
	// - ������� ������ �������
	int GetSize();
	// - ���������� ������ ������� � ����������� �� grow
	void SetSize(int size, int grow);
	// - ������� ������ ���������� ��������(�� ������)
	int GetUpperBound();
	// - ������ ������?
	bool IsEmpty();
	// - ������� ����� ������� � �������
	void FreeExtra();
	// - ��������
	void RemoveAll();
	// - ������� �������� �������� �� �������
	T GetAt(int n);
	// - ����������(��������) ��������(value) ������� � ������������ �����(n)
	bool SetAt(int n, T value);
	// - ��������� �������� ������� �������
	T* operator[](int n);
	// - ��������� � ������ ����� ��������
	void Add(T value);
	// - �������� ���� ��������
	Array& Append(Array& obj);
	// - �������� ������������
	Array& operator=(Array&);
	// - ����� ������ �������
	T* GetData();
	// - ������� ��������(-��) � �������� �������
	bool InsertAt(int, T value);
	// - �������� ��������(-��) � �������� �������.
	void RemoveAt(int);
};

template<class T>
inline Array<T>::Array()
{
	// ��������� �������� ����� ������
	array = nullptr;
	size = 0;
	grow = 0;
	maxindex = -1;
}

template<class T>
inline Array<T>::Array(Array& copy)
{
	//cout << "�������� ����������� �����������!\n";
	this->maxindex = copy.maxindex;
	this->size = copy.size;
	this->grow = copy.grow;
	this->array = new T[size];
	for (int i = 0; i <= this->maxindex; i++)
	{
		this->array[i] = copy.array[i];
	}
}

// - ����������
template<class T>
inline Array<T>::~Array()
{
	//cout << "����������\n";
	delete[]array;
}

// - ������� ������ �������
template<class T>
inline int Array<T>::GetSize()
{
	//cout << "GetSize\n";
	return size;
}


template<class T>
inline void Array<T>::SetSize(int size, int grow)
{
	//cout << "SetSize\n";
	if (array == nullptr)
	{
		//cout << "malloc\n";
		array = new T[size];
	}
	else
	{
		//cout << "Realloc\n";
		// - ��������� ������
		T* tmpArr = new T[size];
		// �������� ������� ������ �� ���������
		for (int i = 0; i < size; i++)
		{
			tmpArr[i] = array[i];
		}
		// ������� ������� ������
		delete[] array;
		// ����������� ��������� ������ ��������������� ������� ������
		array = tmpArr;
		
	}
	// ����������� ����� ������ ���������� � ����� ����������
	this->size = size;
	this->grow = grow; 
	if (maxindex > this->size)maxindex = size;
	/*cout << "Size = " << size << "\nGrow = " << grow << "\n";
	cout << "Maxindex = " << maxindex << "\n";*/
}


template<class T>
inline int Array<T>::GetUpperBound()
{
	return maxindex;
}

template<class T>
inline bool Array<T>::IsEmpty()
{
	return maxindex == -1;
}

template<class T>
inline void Array<T>::FreeExtra()
{
	T* tmpArr = new T[size];
	for (int i = 0; i < size; i++)
	{
		tmpArr[i] = array[i];
	}
	delete[] array;
	array = tmpArr;
	size = maxindex;
}

template<class T>
inline void Array<T>::RemoveAll()
{
	if (array)
	{
		delete[] array;
		array = nullptr;
		size = 0;
		maxindex = -1;
		grow = 0;
	}
}

template<class T>
inline T Array<T>::GetAt(int n)
{
	Array tmp = *this;
	if (tmp[n])
	{
		return *tmp[n];
	}
	else return NULL;
}

template<class T>
inline bool Array<T>::SetAt(int n, T value)
{
	if (n < size)
	{
		Array tmp = *this;
		*tmp[n] = value;
		if (tmp.maxindex < n)tmp.maxindex = n;
		*this = tmp;
		for (int i = 0; i < size; i++)
		{
			cout << i << " = " << array[i] << "\n";
		}
		return true;
	}
	
	return false;
}

template<class T>
inline T* Array<T>::operator[](int n)
{
	if (n < size)
	{
		return &array[n];
	}
	else
	{
		return nullptr;
	}
}

template<class T>
inline void Array<T>::Add(T value)
{
	if ((maxindex + 1) == size)
	{
		size += grow;
		T* tmpArr = new T[size];
		for (int i = 0; i < size; i++)
		{
			tmpArr[i] = array[i];
		}
		delete[] array;
		array = tmpArr;
	}
	array[++maxindex] = value;
	for (int i = 0; i < size; i++)
	{
		cout << i << " = " << array[i] << "\n";
	}
}

template<class T>
inline Array<T>& Array<T>::Append(Array<T>& obj)
{
	this->maxindex = this->size + obj.maxindex;
	int newsize = this->size + obj.size;
	T* tmpArr = new T[newsize];
	for (int i = 0; i < newsize; i++)
	{
		tmpArr[i] = array[i];
	}
	delete[] array;
	this->array = tmpArr;
	for (int i = 0; i < obj.size; i++)
	{
		this->array[size + i] = obj.array[i];
	}
	this->size = newsize;
	for (int i = 0; i < size; i++)
	{
		cout << i << " = " << array[i] << "\n";
	}
	return *this;
}

template<class T>
inline Array<T>& Array<T>::operator=(Array<T>& obj)
{
	this->maxindex = obj.maxindex;
	this->size = obj.size;
	this->grow = obj.grow;
	T* tmpArr = new T[this->size];
	for (int i = 0; i < this->maxindex; i++)
	{
		tmpArr[i] = array[i];
	}
	delete[] array;
	this->array = tmpArr;
	for (int i = 0; i <= this->maxindex; i++)
	{
		this->array[i] = obj.array[i];
	}
	return *this;
}

template<class T>
inline T* Array<T>::GetData()
{
	return array;
}

template<class T>
inline bool Array<T>::InsertAt(int n, T value)
{
	if ((maxindex + 1) < size)
	{
		if (n > maxindex)
		{
			array[n] = value;
			maxindex = n;
		}
		else
		{
			for (int i = size - 2; i >= n; i--)
			{
				array[i + 1] = array[i];
			}
			array[n] = value;
			maxindex++;
		}
		return true;
	}
	return false;
}

template<class T>
inline void Array<T>::RemoveAt(int n)
{
	if (n < size)
	{
		for (int i = n; i < maxindex; i++)
		{
			array[n] = array[n + 1];
		}
		maxindex--;
	}
}

