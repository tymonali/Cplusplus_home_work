#include "Contacts.h"

void Contacts::Vvod()
{
	cout << "������� ������ ��� ��������:\n";
	gets_s(Fio);
	cout << "������� �������� ����� �������� ��������:\n";
	gets_s(homeNumber);
	cout << "������� ������� ����� �������� ��������:\n";
	gets_s(workNumber);
	cout << "������� ��������� ����� �������� ��������:\n";
	gets_s(mobileNumber);
	cout << "������� �������������� ���������� � ��������:\n";
	gets_s(infoContakt);
}

void Contacts::Show()
{
	cout << "������ ���:\n" << Fio << "\n\n";
	cout << "�������� �����:\n" << homeNumber << "\n\n";
	cout << "������� �����:\n" << workNumber << "\n\n";
	cout << "��������� �����:\n" << mobileNumber << "\n\n";
	cout << "�������������� ����������:\n" << infoContakt << "\n\n";
}

char* Contacts::GetFio()
{
    return Fio;
}
