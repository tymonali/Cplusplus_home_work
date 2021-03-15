#pragma once
#include<iostream>
using namespace std;

template <typename T>
class List
{
protected:
	int size, count;
	T* array;
public:
	List(int);
	virtual void push(T) = 0;
	virtual T pop() = 0;
	void clear();
	bool isEmpty();
	bool isFull();
	~List();
};

template <typename T>
class Queue :public List<T>
{
public:
	Queue(int size) : List<T>(size) {}
	// ”наследовано через List
	virtual void push(T) override;
	virtual T pop() override;
};

template <typename T>
class Stack : public List<T>
{
public:
	Stack(int size) : List<T>(size) {}
	// ”наследовано через List
	virtual void push(T) override;
	virtual T pop() override;
};

template<typename T>
inline List<T>::List(int size)
{
	this->size = size;
	this->count = 0;
	this->array = new T[size];
}

template<typename T>
inline void List<T>::clear()
{
	count = 0;
}

template<typename T>
inline bool List<T>::isEmpty()
{
	return count == 0;
}

template<typename T>
inline bool List<T>::isFull()
{
	return count == size;
}

template<typename T>
inline List<T>::~List()
{
	delete[] array;
}

template<typename T>
inline void Queue<T>::push(T obj)
{
	if (!this->isFull())
	{
		this->array[this->count - 1] = obj;
		this->count++;
	}
}

template<typename T>
inline T Queue<T>::pop()
{
	if (!this->isEmpty())
	{
		T tmp = this->array[0];
		for (int i = 1; i < this->count; i++)
		{
			this->array[i - 1] = this->array[i];
		}
		this->count--;
		return tmp;
	}
	return NULL;
}

template<typename T>
inline void Stack<T>::push(T obj)
{
	if (!this->isFull())
	{
		this->array[this->count - 1] = obj;
		this->count++;
	}
}

template<typename T>
inline T Stack<T>::pop()
{
	if (!this->isEmpty())
	{
		return this->array[--this->count];
	}
	return NULL;
}