#include "Conta�t.h"

void Contact::showContact()
{
	cout << "���:\n" << FIO << "\n";
	cout << "������� ���������:\n" << mobilenum << "\n";
	cout << "������� ��������:\n" << homenum << "\n";
	cout << "�������������� ���������� � ��������:\n" << additionalInfo << "\n";
}

void Contact::setContact()
{
	cout << "������� �������_���_��������:\n";
	gets_s(FIO);
	cout << "������� ��������� ����� ��������:\n";
	gets_s(mobilenum);
	cout << "������� �������� ����� ��������:\n";
	gets_s(homenum);
	cout << "������� �������������� ���������� � ��������:\n";
	gets_s(additionalInfo);
}

char* Contact::getFIO()
{
	return FIO;
}
