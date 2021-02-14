#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>	//	_getch();

using std::cout;
using std::cin;
using std::endl;

template <typename T>
struct Node
{
	T value;		//значение списка
	Node* next;		//указатель на следующий элемент
	Node* prev;		//указатель на предыдущий элемент

	Node();
};

template <typename T>
Node<T>::Node()
{
	value = NULL;
	next = prev = nullptr;
}

