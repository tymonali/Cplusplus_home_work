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
	T value;		//�������� ������
	Node* next;		//��������� �� ��������� �������
	Node* prev;		//��������� �� ���������� �������

	Node();
};

template <typename T>
Node<T>::Node()
{
	value = NULL;
	next = prev = nullptr;
}

