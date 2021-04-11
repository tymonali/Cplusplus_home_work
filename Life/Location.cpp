#include "Location.h"
#define F_MAXAGE 10
#define R_MAXAGE 4
#define G_MAXAGE 2


Location::Location(int maxEssence)
{
	this->year = 0;
	this->maxEssence = maxEssence;
	this->countFox = rand() % this->maxEssence + 1;
	this->countRabbit = rand() % this->maxEssence + 1;
	this->countGrass = rand() % this->maxEssence + 1;
	foxes = new Fox[maxEssence];
	rabbits = new Rabbit[maxEssence];
	grass = new Grass[maxEssence];
	for(int i = 0; i < countFox; i++)
	{
		foxes[i] = Fox(F_MAXAGE);
	}
	for(int i = 0; i < countRabbit; i++)
	{
		rabbits[i] = Rabbit(R_MAXAGE);
	}
	for(int i = 0; i < countGrass; i++)
	{
		grass[i] = Grass(G_MAXAGE);
	}
}

bool Location::addYear()
{
	cout << "Год " << year << endl;
	cout << "Состояние места обитания на начало года\n";
	print();
	int tmp;
	if(countFox > 1 && countFox < 5)
	{
		tmp = countFox;
		for(int i = tmp; i < tmp + foxes[0].getIncrement() && countFox < maxEssence; i++)
		{
			foxes[i] = Fox(F_MAXAGE);
			countFox++;
		}
	}
	else
	{
		cout << "Все лисы вымерли!\n";
		return false;
	}
	if (countRabbit > 1)
	{
		tmp = countRabbit;
		for (int i = tmp; i < tmp + rabbits[0].getIncrement() && countRabbit < maxEssence; i++)
		{
			rabbits[i] = Rabbit(R_MAXAGE);
			countRabbit++;
		}
	}
	else
	{
		cout << "Все зайцы вымерли\n";
		return false;
	}
	if (countGrass > 1)
	{
		tmp = countGrass;
		for (int i = tmp; i < tmp + grass[0].getIncrement() && countGrass < maxEssence; i++)
		{
			grass[i] = Grass(G_MAXAGE);
			countGrass++;
		}
	}
	setAge(foxes, countFox);
	setAge(rabbits, countRabbit);
	setAge(grass, countGrass);
	if (countFox > countRabbit)
	{
		countRabbit--;
	}
	if (countRabbit > countGrass)
	{
		countGrass = 0;
	}

	cout << endl << "Состояние места обитания на конец года\n";
	print();
	system("pause");
	this->year++;
	return true;
}

void Location::setAge(Animals* mas, int& count)
{
	int tmp = count;
	for (int i = 0; i < tmp; i++)
	{
		if (!mas[i].setAge())
		{
			del(mas, count, i);
		}
	}
}

void Location::del(Animals*mas, int& count, int index)
{
	for (int i = index; i < count - 1; i++)
	{
		mas[i] = mas[i + 1];
	}
	count--;
}

void Location::print()
{
	cout << "Кол-во лисов в месте обитания: " << this->countFox << endl;
	cout << "Кол-во зайцев в месте обитания: " << countRabbit << endl;
	cout << "Трава в месте обитания: " << countGrass << endl;
}

Location::~Location()
{
	delete[] foxes;
	delete[] rabbits;
	delete[] grass;
}
