//
// Created by Denver on 06.03.2021.
//

#pragma once
#include "Abonent.h"



class HandBook
{
    Abonent* abonents;
    int count;
    int capacity;
public:
    HandBook();
    ~HandBook();
    void setCapacity();
    void add();
    int menuCompare();
    string searchAct(int num);
    void search();
    void show();
    void save();
    void load();
};