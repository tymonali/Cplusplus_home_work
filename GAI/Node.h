/*
Реализовать базу данных ГАИ по штрафным квитан-
циям с помощью бинарного дерева. Ключом будет
служить номер автомашины, значением узла — спи-
сок правонарушений. Если квитанция добавляется
в первый раз, то в дереве появляется новый узел, а в
списке данные по правонарушению; если нет, то дан-
ные заносятся в существующий список. Необходимо
также реализовать следующие операции:
■■ Полная распечатка базы данных (по номерам машин
и списку правонарушений, числящихся за ними).
■■ Распечатка данных по заданному номеру.
■■ Распечатка данных по диапазону номеров.
*/
#pragma once
#include<iostream>
#include<string>
#include<Windows.h>

using std::string;

using namespace std;

struct violation
{
	string viol;
	violation* next;
};

struct Node
{
	int number;
	Node* left, *right, *parent;
	violation* list;
};

void Push(violation*& node, string newStr);
void ClearViolation(violation*& head);
void PrintViolations(violation* obj);