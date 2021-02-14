#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = tail = nullptr;
	count = 0;
}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::addToTail(int value)
{
	Node* node = new Node;
	node->value = value;
	if (isEmpty())
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}
	count++;
}

void LinkedList::addToHead(int value)
{
	Node* node = new Node;
	node->value = value;
	if (isEmpty())
	{
		head = tail = node;
	}
	else
	{
		node->next = head;
		head = node;
	}
	count++;
}

void LinkedList::removeFromTail()
{
	//список не пуст
	if (!isEmpty()) {
		//временный указатель для прохода по списку
		Node* tmp = head;

		//перебор списка
		while (tmp->next != nullptr && tmp->next != tail) {
			tmp = tmp->next;
		}


		if (count == 1) {
			delete tmp;
			head = tail = nullptr;
		}
		else {
			delete tail;
			tail = tmp;
			tail->next = nullptr;
		}

		count--;
	}
}

void LinkedList::removeFromHead()
{
	if (!isEmpty())
	{
		Node* tmp = head->next;
		delete head;
		head = tmp;
		count--;
	}
}

void LinkedList::insert(int index, int value)
{
	Node* node = new Node;
	node->value = value;
	if (!isEmpty() && index < count - 1)
	{
		Node* left = head;
		for (int i = 0; i < index-1; i++)
		{
			left = left->next;
		}
		Node* right = left->next;

		left->next = node;
		node->next = right;
		count++;
	}
}

void LinkedList::removeAt(int index)
{
	if (!isEmpty() && index < count - 1)
	{
		Node* left = head;
		for (int i = 0; i < index - 1; i++)
		{
			left = left->next;
		}
		Node* right = left->next->next;
		delete left->next;
		left->next = right;
	}
}

int LinkedList::search(int value)
{
	int idx = -1;
	if (!isEmpty()) 
	{
		Node* tmp = head;
		for (int i = 1; i < count; i++)
		{
			tmp = tmp->next;
			if (value == tmp->value)
			{
				idx = i;
				break;
			}
		}
	}
	return idx + 1;
}

bool LinkedList::isEmpty()
{
	return head == nullptr;
}

void LinkedList::print()
{
	Node* tmp = head;
	if (!isEmpty())
	{
		while (tmp != nullptr)
		{
			cout << setw(4) << tmp->value << "|";
			tmp = tmp->next;
		}
		cout << endl;
	}
}

void LinkedList::clear()
{
	if (!isEmpty())
	{
		while (!isEmpty())
		{
			removeFromHead();
		}
		head = tail = nullptr;
	}
}
