#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color B0");

	// ��������� ��� string
	/*string str = "Hello World";
	string str2 = "!!!";
	string str3 = str + str2;
	str3 += ")))";

	cout << str3 << endl;

	char buff[50];
	strcpy_s(buff, str3.c_str());

	cout << buff << endl;*/

	string str = "Hello World";
	str.append("!!!");			// �������� � ����� ������
	cout << str << endl;
	cout << str.at(0) << endl;	// �������� ������� �������
	cout << str[0] << endl;		// ���� �����(���������� at())

	// ������� ������
	/*str.clear();*/

	// ��������� �����
	/*int res = str.compare("Hello World!!!");
	cout << res << endl;*/

	// ��������� ������ �� �������� ������
	/*str.erase(5);

	cout << str << endl;*/

	// �������� �������� � �������� ���������
	//str.erase(2, 6);

	// ����������� ������������ ������������������ ��������
	/*string res;
	res.assign(str, 1, 5);
	cout << res << endl;*/

	// ����� ���������
	/*size_t res = str.find("ello");

	// ��������� �������
	if (res != string::npos)
	{
		cout << "������" << endl;
	}
	else
	{
		cout << "�� �������" << endl;
	}*/

	// ������� � �������� �������
	// ������� � ������
	/*str.insert(0, "Hi! ");
	cout << str << endl;*/

	// �������� ������ �� �������
	/*if (str.empty())
	{
		cout << "������ ������" << endl;
	}
	else
	{
		cout << "������ ����� �������" << endl;
	}*/

	// ������ �����
	/*string s1 = "Hello";
	string s2 = "World";

	swap(s1, s2); // ��� s1.swap(s2);

	cout << "s1 = " << s1 << "\ns2 = " << s2 << endl;*/

	// ��������� ���������
	/*string sub = str.substr(0, 5);
	cout << str << endl << sub << endl;*/



	return 0;
}