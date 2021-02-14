#include "Contaсt.h"

void Contact::showContact()
{
	cout << "ФИО:\n" << FIO << "\n";
	cout << "Телефон мобильный:\n" << mobilenum << "\n";
	cout << "Телефон домашний:\n" << homenum << "\n";
	cout << "Дополнительная информация о контакте:\n" << additionalInfo << "\n";
}

void Contact::setContact()
{
	cout << "Введите Фамилию_Имя_Отчество:\n";
	gets_s(FIO);
	cout << "Введите мобильный номер телефона:\n";
	gets_s(mobilenum);
	cout << "Введите домашний номер телефона:\n";
	gets_s(homenum);
	cout << "Введите дополнительную информацию о контакте:\n";
	gets_s(additionalInfo);
}

char* Contact::getFIO()
{
	return FIO;
}
