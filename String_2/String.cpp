#include "String.h"

char* String::Gets()
{
	char ch;
	char* tmp = nullptr;;
	int n = 0;
	while ((ch = getchar()) != '\n')
	{
		tmp = (char*)realloc(tmp, n + 1);
		tmp[n] = ch;
		n++;
	}
	tmp = (char*)realloc(tmp, n + 1);
	tmp[n] = 0;
	return tmp;
}

String::String()
{
	str = (char*)malloc(80);
}

String::String(int size)
{
	str = (char*)malloc(size + 1);
}

String::String(const char* mas) : String(strlen(mas))
{
	strcpy_s(str, strlen(mas) + 1, mas);
}

void String::Set()
{
	char* tmp = nullptr;
	cout << "Enter string:\n";
	tmp = Gets();
	str = (char*)realloc(str, strlen(tmp) + 1);
	strcpy_s(str, strlen(tmp) + 1, tmp);
}

String& String::operator=(const String& copy)
{
	this->str = (char*)realloc(this->str, strlen(copy.str) + 1);
	strcpy_s(this->str, strlen(copy.str) + 1, copy.str);
	return *this;
}

char& String::operator[](int n)
{
	return this->str[n];
}

int String::operator()(char ch)
{
	char* n;
	if ((n = strchr(this->str, ch)))
		return n - this->str;
	else
		return -1;
}

String::operator int()
{
	return strlen(this->str);
}

String& String::operator++()
{
	int size = strlen(this->str);
	this->str = (char*)realloc(this->str, size + 2);
	this->str[size] = ' ';
	this->str[size + 1] = 0;
	return *this;
}

String String::operator++(int)
{
	String tmp = *this;
	int size = strlen(this->str);
	this->str = (char*)realloc(this->str, size + 2);
	this->str[size] = ' ';
	this->str[size + 1] = 0;
	return tmp;
}

String& String::operator--()
{
	int size = strlen(this->str);
	this->str = (char*)realloc(this->str, size);
	this->str[size - 1] = 0;
	return *this;
}

String String::operator--(int)
{
	String tmp = *this;
	int size = strlen(this->str);
	this->str = (char*)realloc(this->str, size);
	this->str[size - 1] = 0;
	return tmp;
}

String::~String()
{
	delete[] str;
}
