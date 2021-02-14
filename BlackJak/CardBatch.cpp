#include "CardBatch.h"

Card_Batch::Card_Batch() 
{
	cout << "Сработка конструктора по умолчанию Card_Batch!\n\n";
	Sleep(1000);
	size = 36;
	cards = new Card[size];
}

Card_Batch::Card_Batch(int sz)
{
	cout << "Сработка прегруженного конструктора Card_Batch!\n\n";
	Sleep(1000);
	this->size = sz;
	cards = new Card[size];
}

Card_Batch::Card_Batch(const Card_Batch& copy)
{
	cout << "Сработка конструктора копирования Card_Batch!\n\n";
	Sleep(1000);
	this->size = copy.size;
	cards = new Card[size];
	memcpy(cards, copy.cards, sizeof(int) * size);
}

//Создание колоды карт
void Card_Batch::setCard_Batch() 
{
	cout << "Создание колоды карт!\n\n";
	Sleep(1000);
	if (cards != NULL)
	{
		delete[] cards;
	}
	cards = new Card[size];
	for (int i = 0; i < size; i++) 
	{
		int f = (i % 9) + 6;		// От 6-ти до 14-ти
		Suit s = Suit(i / 9);		// 9 нулей, 9 единиц, 9 двоек, 9 троек
		cards[i].setCard(f, s);
	}
	//cout << "\n\n";
}

//Тусуется колода карт
void Card_Batch::Shuffle() 
{
	cout << "Перетусовка колоды!\n\n";
	Sleep(1000);
	srand(time(0));
	for (int i = 0; i < size; i++) 
	{
		int k = rand() % 36;		//выбираем случайную карту
		Card temp = cards[i];		//и меняем ее с текущей
		cards[i] = cards[k];
		cards[k] = temp;
	}

}

void Card_Batch::display() 
{
	for (int i = 0; i < size; i++) 
	{
		cards[i].PrintCard();
		cout << setw(2) << "|";
		if (!((i + 1) % 9))			// начинаем новую строку после каждой 13-й карты
			cout << endl;
	}
	cout << "\n\n";
}

Card Card_Batch::getKoloda()
{
	return *cards;
}

Card Card_Batch::getCard()
{
	Card oneCard;
	oneCard = cards[0];
	Card* tmp = new Card[size - 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = cards[i + 1];
	}
	delete[] cards;
	size--;
	cards = tmp;
	cout << "В колоде осталось " << size << " карт\n\n";
	return oneCard;
}

void Card_Batch::setSize(int sz)
{
	this->size = sz;
}

Card_Batch::~Card_Batch()
{
	cout << "Сработка деструктора Card_Batch!\n\n";
	Sleep(1000);
	delete[] cards;
}

