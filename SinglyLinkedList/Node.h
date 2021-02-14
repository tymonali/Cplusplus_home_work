#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

struct Node
{
	int value;
	Node* next;

	Node();
};

