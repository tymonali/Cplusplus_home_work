//
// Created by Denver on 06.03.2021.
//

#pragma once
#include "Address.h"

class Abonent {
    string companyName;            //название фирмы
    string owner;                //владелец
    string phone;                //номер телефона
    string occupation;            //род деятельности
    Address* address;            //адрес
public:
    Abonent();
    Abonent(string companyName, string owner, string phone,
        string occupation, Address* address);
    ~Abonent();
    void addAbonent();
    void show();
    bool compare(int num, string str);
    StreetType strToEnum(string str);
    friend ostream& operator << (ostream& os, Abonent& obj);
    friend istream& operator >> (istream& is, Abonent& obj);
};
