#pragma once
#include"Node.h"

class Tree
{
	int size;
	Node* root;
public:
	// Конструктор по умолчанию
	Tree();
	// Деструктор
	~Tree();

	// Добавляем узел
	void Add(Node*& head, Node* parent, int value, string str);
	// Добавляем нарушение в уже существующий узел
	void Add(int value, string str);
	// Метод рапечатки всей базы
	void Print(Node* obj);
	// Удаление дерева
	void Delete(Node* obj = 0);
	Node* GetRoot();
	Node* Find(int num, Node* obj);
	void PrintNumber(int value);
	void PrintByRange(int min, int max, Node* obj);
};

