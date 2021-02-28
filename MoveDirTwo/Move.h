#pragma once
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <string>
#include <direct.h>
#include <Windows.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

enum
{
	CANCEL,
	REWRITE,
	SKIP,
	REWRITEFORALL
};

enum
{
	REMOVE = 1,
	REMOVEFORALL = 3
};

class Move
{
	bool rewriteForAll = false;
	bool deleteForAll = false;
public:
	bool moveDir(string, string);

	void copyFile(string, string);
	int rewriteMenu(string);
	int deleteMenu(string);
};

