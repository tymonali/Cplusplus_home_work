#pragma once
#include"NodeD.h"

template<class T>
class TemplateQueue
{
	int capacity;
	int count;
	Node<T>* head;
	Node<T>* tail;
public:
	TemplateQueue();
	TemplateQueue(int n);
	~TemplateQueue();
	void addToTail(T value);// Добавить в хвост списка
	void removeFromHead();
	void Add(T value);	// Добавить в очередь
	T Extract();
	bool isFullQ();
	bool isEmptyQ();	// Пустая очередь
	bool isEmptyL();	// Список пуст
	void PrintQ();		// печать очереди
	void PrintL();		// Печать списка
	void Clear();
	int getCount();
	int getCapacity();
};

template<class T>
inline TemplateQueue<T>::TemplateQueue()
{
	capacity = 0;
	count = 0;
	head = tail = nullptr;
}

template<class T>
inline TemplateQueue<T>::TemplateQueue(int n)
{
	capacity = n;
	count = 0;
	head = tail = nullptr;
	//cout << "Count(const) = " << count << "\n";
}

template<class T>
inline TemplateQueue<T>::~TemplateQueue()
{
	while (!isEmptyQ())
	{
		Clear();
	}
}

template<class T>
inline void TemplateQueue<T>::addToTail(T value)
{
	//новый узел
	Node<T>* node = new Node<T>;
	node->value = value;

	//список пуст
	if (isEmptyQ()) {
		head = tail = node;
	}
	else {		//список не пуст
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	count++;
}

template<class T>
inline void TemplateQueue<T>::removeFromHead()
{
	if (!isEmptyL())
	{
		Node<T>* tmp = head->next;
		delete head;
		head = tmp;
		if (head != nullptr)
		{
			head->prev = nullptr;
		}
		count--;
	}
}

template<class T>
inline void TemplateQueue<T>::Add(T value)
{
	if (isFullQ())
	{
		//cout << "Count(Add) = " << count << "\n";
		cout << "Очередь заполнена!!!\n";
		cout << "Нажмите любую клавишу...\n";
		_getch();
	}
	else
	{
		addToTail(value);
	}
}

template<class T>
inline T TemplateQueue<T>::Extract()
{
	if (isEmptyQ())
	{
		return 0;
	}
	else
	{
		Node<T>* tmp = head;
		head = head->next;
		count--;
		return tmp->value;
	}
}

template<class T>
inline bool TemplateQueue<T>::isFullQ()
{
	return count == capacity;
}

template<class T>
inline bool TemplateQueue<T>::isEmptyQ()
{
	return count == 0;
}

template<class T>
inline bool TemplateQueue<T>::isEmptyL()
{
	return head == nullptr;
}

template<class T>
inline void TemplateQueue<T>::PrintQ()
{
	Node<T>* tmp = head;
	for (int i = 0; i < count; i++)
	{
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

template<class T>
inline void TemplateQueue<T>::PrintL()
{
	if (!isEmptyL())
	{
		Node<T>* tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp->value << " ";
			tmp = tmp->next;
		}
		cout << "\n";
	}
}

template<class T>
inline void TemplateQueue<T>::Clear()
{
	if (!isEmptyL())
	{
		while (!isEmptyL())
		{
			removeFromHead();
		}
		head = tail = nullptr;
	}
}

template<class T>
inline int TemplateQueue<T>::getCount()
{
	return count;
}

template<class T>
inline int TemplateQueue<T>::getCapacity()
{
	return capacity;
}
