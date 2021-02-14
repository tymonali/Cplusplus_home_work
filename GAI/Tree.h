#pragma once
#include"Node.h"

class Tree
{
	int size;
	Node* root;
public:
	// ����������� �� ���������
	Tree();
	// ����������
	~Tree();

	// ��������� ����
	void Add(Node*& head, Node* parent, int value, string str);
	// ��������� ��������� � ��� ������������ ����
	void Add(int value, string str);
	// ����� ��������� ���� ����
	void Print(Node* obj);
	// �������� ������
	void Delete(Node* obj = 0);
	Node* GetRoot();
	Node* Find(int num, Node* obj);
	void PrintNumber(int value);
	void PrintByRange(int min, int max, Node* obj);
};

