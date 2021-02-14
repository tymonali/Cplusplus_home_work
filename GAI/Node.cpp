#include "Node.h"

void Push(violation*& node, string newStr)
{
	violation* tmp = new violation;
	tmp->viol = newStr;
	tmp->next = NULL;

	if (node == NULL)
	{
		node = tmp;
	}
	else
	{
		tmp->next = node;
		node = tmp;
	}
}

void ClearViolation(violation*& obj)
{
	violation* curr = obj;
	while (curr)
	{
		violation* temp = curr->next;
		delete curr;
		curr = temp;
	}
}

void PrintViolations(violation* obj)
{
	violation* curr = obj;
	while (curr)
	{
		cout << curr->viol << endl;
		curr = curr->next;
	}
}
