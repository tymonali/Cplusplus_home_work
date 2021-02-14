#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
struct Elem
{
	int OwnerPoints; //���� �������
	int OppPoints; //���� ���������
	char Match[10]; //����
	char Name[20]; //�������
	char Opponent[20]; //��������
	Elem* left, * right, * parent;
};

class Tree
{
	//������
	Elem* root;
public:
	Tree();
	~Tree();
	//������ �� ���������� ����
	void Print(Elem* Node);
	//����� �� ���������� ����
	Elem* Search(Elem* Node, char* key);
	//min �� ���������� ����
	Elem* Min(Elem* Node);
	//max �� ���������� ����
	Elem* Max(Elem* Node);
	//��������� ��� ���������� ����
	Elem* Next(Elem* Node);
	//���������� ��� ���������� ����
	Elem* Previous(Elem* Node);
	//������� ����
	void Insert(Elem* z);
	//�������� ����� ��� ���������� ����,
	//0 - �������� ����� ������
	void Del(Elem* z = 0);
	//�������� ������
	Elem* GetRoot();
};

Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	Del();
}

//����������� ����� ������
void Tree::Print(Elem* Node)
{
	if (Node != 0)
	{
		Print(Node->left);
		cout << Node->Name
			<< Node->Match
			<< Node->Opponent
			<< endl;
		Print(Node->right);
	}
}

Elem* Tree::Search(Elem* Node, char* k)
{
	//���� ���� ���� � ����� �� ���������
	while (Node != 0 && strcmp(k, Node->Name) != 0)
	{
		if (strcmp(k, Node->Name) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	return Node;
}

Elem* Tree::Min(Elem* Node)
{
	//����� ������ "������" ����
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}

Elem* Tree::Max(Elem* Node)
{
	//����� ������ "�������" ����
	if (Node != 0)
		while (Node->right != 0)
			Node = Node->right;
	return Node;
}

Elem* Tree::Next(Elem* Node)
{
	Elem* y = 0;
	if (Node != 0)
	{
		//���� ���� ������ �������
		if (Node->right != 0)
			return Min(Node->right);
		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node ������
		while (y != 0 && Node == y->right)
		{
			//�������� �����
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

Elem* Tree::Previous(Elem* Node)
{
	Elem* y = 0;
	if (Node != 0)
	{
		//���� ���� ����� �������
		if (Node->left != 0)
			return Max(Node->left);
		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node �����
		while (y != 0 && Node == y->left)
		{
			//�������� �����
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

Elem* Tree::GetRoot()
{
	return root;
}

void Tree::Insert(Elem* z)
{
	//�������� ���
	z->left = NULL;
	z->right = NULL;
	Elem* y = NULL;
	Elem* Node = root;
	//����� �����
	while (Node != 0)
	{
		//������� ��������
		y = Node;
		if (strcmp(z->Name, Node->Name) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	//��������� ��������
	z->parent = y;
	if (y == 0) //������� ������ (������������)
		root = z;
	//��� ���� ������?
	else if (strcmp(z->Name, y->Name) < 0)
		y->left = z;
	else
		y->right = z;
}

void Tree::Del(Elem* z)
{
	//�������� �����
	if (z != 0)
	{
		Elem* Node, * y;
		//�� 2 �������
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);
		if (y->left != 0)
			Node = y->left;
		else
			Node = y->right;
		if (Node != 0)
			Node->parent = y->parent;
		//��������� �������� ����?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//����� �� ��������?
			y->parent->left = Node;
		else
			//������ �� ��������?
			y->parent->right = Node;
		if (y != z)
		{
			//����������� ������ ����
			strcpy(z->Name, y->Name);
			strcpy(z->Opponent, y->Opponent);
			strcpy(z->Match, y->Match);
			z->OppPoints = y->OppPoints;
			z->OwnerPoints = y->OwnerPoints;
		}
		delete y;
	}
	else //�������� ����� ������
		while (root != 0)
			Del(root);
}

//��������� �������
Tree tournament;
void Game(char Commands[][20], int N)
{
	int i, j;
	int p1, p2; //����
	//������ ������� ������ � ������ �� 2 ���� -
	//���� � � ������
	int k;
	Elem* temp;
	for (k = 0; k < 2; k++)
		for (i = 0; i < N - 1; i++)
			for (j = i + 1; j < N; j++)
			{
				temp = new Elem;
				if (k == 0)
				{
					//1 ����
					strcpy(temp->Name, Commands[i]);
					strcpy(temp->Opponent, Commands[j]);
				}
				else
				{
					//2 ����
					strcpy(temp->Name, Commands[j]);
					strcpy(temp->Opponent, Commands[i]);
				}
				p1 = rand() % 6;
				p2 = rand() % 6;
				if (p1 > p2)
				{
					temp->OwnerPoints = 3;
					temp->OppPoints = 0;
				}
				else if (p1 == p2)
				{
					temp->OwnerPoints = 1;
					temp->OppPoints = 1;
				}
				else
				{
					temp->OwnerPoints = 0;
					temp->OppPoints = 3;
				}
				//������ �����
				sprintf(temp->Match, " %d : %d ", p1, p2);
				//���������� ������
				tournament.Insert(temp);
			}
}

void main()
{
	srand(time(0));
	const int N = 4;
	char Commands[4][20] =
	{
	"Arsenal",
	"Liverpool",
	"Lids United",
	"Manchester United"
	};
	//����
	Game(Commands, N);
	//����� �����������
	tournament.Print(tournament.GetRoot());
}