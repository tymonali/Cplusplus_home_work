#pragma once
#include<iostream>
#include<stdio.h>
#include<io.h>
#include<direct.h>

using namespace std;

enum
{
	CANCEL,
	REWRITE,
	SKIP,
	REWRITEFORALL
};

class CDAF
{
	bool rewriteForAll = false;
public:
	bool copyDir(char[], char[]);
	void copyFile(char[], char[]);
	int rewriteMenu(char[]);
};

