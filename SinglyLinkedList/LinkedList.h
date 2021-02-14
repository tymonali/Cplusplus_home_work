#pragma once
#include"Node.h"
class LinkedList
{
	Node* head;
	Node* tail;
	int count;
public:
	LinkedList();
	~LinkedList();

	void addToTail(int value);
	void addToHead(int value);
	void removeFromTail();
	void removeFromHead();
	void insert(int index,int value);
	void removeAt(int index);
	int search(int value);
	bool isEmpty();
	void print();
	void clear();
};

