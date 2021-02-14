#include "Tree.h"

Tree::Tree() 
{
	root = NULL;
	size = 0;
}

Tree::~Tree()
{
	cout << "~Tree()\n";
	Delete(root);
}

void Tree::Add(Node*& head, Node* parent, int value, string str)
{
	Node* tmp = new Node;
	tmp->number = value;
	tmp->list = nullptr;
	tmp->left = tmp->right = tmp->parent = NULL;
	if (!head)
	{
		head = tmp;
		Push(head->list, str);
	}
	else
	{
		if (value < head->number)
		{
			Add(head->left, head, value, str);
		}
		else if(value > head->number)
		{
			Add(head->right, head, value, str);
		}
		else // если номер уже есть в базе, добавляем нарушение
		{
			Push(head->list, str);
		}
	}
}

void Tree::Add(int value, string str)
{
	Add(root, NULL, value, str);
}

void Tree::Print(Node* obj)
{
	if (obj)
	{
		Print(obj->left);
		cout << "Номер машины: " << obj->number << endl;
		cout << "Нарушения: " << endl;
		PrintViolations(obj->list);
		Print(obj->right);
	}
}

void Tree::Delete(Node* obj)
{
	cout << "Delete(root)\n";
	if (obj)
	{
		cout << "Delete(obj->left)\n";
		Delete(obj->left);
		cout << "Delete(obj->right)\n";
		Delete(obj->right);
		cout << "ClearViolation(obj->list) in Delete(root)\n";
		ClearViolation(obj->list);
		cout << "delete obj\n";
		delete obj;
	}
}

Node* Tree::GetRoot()
{
	return root;
}

Node* Tree::Find(int num, Node* obj)
{
	if (obj)
	{
		if (num < obj->number)
		{
			Find(num, obj->left);
		}
		else if (num > obj->number)
		{
			Find(num, obj->right);
		}
		else
		{
			return obj;
		}
	}
	else
	{
		//cout << "Такого номера нет в базе!\n";
		return NULL;
	}
}

void Tree::PrintNumber(int value)
{
	 
	
	Node* tmp = Find(value, root);
	if (tmp != NULL) 
	{
		cout << "Номер машины: " << tmp->number << endl;
		cout << "Нарушения: " << endl;
		PrintViolations(tmp->list);
	}
	else
	{
		cout << "Такого номера нет в базе!!!\n";
	}
}

void Tree::PrintByRange(int min, int max, Node* obj)
{
	if (obj)
	{
		Node* tmp = obj;
		if(tmp->left)
		{
			PrintByRange(min, max, obj->left);
		}
		if (min <= obj->number && obj->number <= max)
		{
			cout << "Номер машины: " << tmp->number << endl;
			cout << "Нарушения: " << endl;
			PrintViolations(tmp->list);
		}
		if (obj->right)
		{
			PrintByRange(min, max, obj->right);
		}
	}
}
