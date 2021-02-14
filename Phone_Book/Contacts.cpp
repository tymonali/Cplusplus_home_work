#include "Contacts.h"

void Contacts::Vvod()
{
	cout << "Введите полное имя контакта:\n";
	gets_s(Fio);
	cout << "Введите домашний номер телефона контакта:\n";
	gets_s(homeNumber);
	cout << "Введите рабочий номер телефона контакта:\n";
	gets_s(workNumber);
	cout << "Введите мобильный номер телефона контакта:\n";
	gets_s(mobileNumber);
	cout << "Введите дополнительную информацию о контакте:\n";
	gets_s(infoContakt);
}

void Contacts::Show()
{
	cout << "Полное имя:\n" << Fio << "\n\n";
	cout << "Домашний номер:\n" << homeNumber << "\n\n";
	cout << "Рабочий номер:\n" << workNumber << "\n\n";
	cout << "Мобильный номер:\n" << mobileNumber << "\n\n";
	cout << "Дополнительная информация:\n" << infoContakt << "\n\n";
}

char* Contacts::GetFio()
{
    return Fio;
}
