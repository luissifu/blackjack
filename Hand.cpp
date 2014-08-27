#include "Hand.h"
bool flagAs=false;
Hand::Hand() {
	cont = 0;
}

std::string Hand::str() {
	std::string value = "";
	for (int i = 0; i < cont; i++)
	{
		value += cards[i].getSuit();
		value += cards[i].getValue();
	}
	return value;
}

void Hand::addCard(Card card) {
	cards.push_back(card);
	cont++;
}

int Hand::getValue() {
	int value = 0;
	int aces = 0;

	for (int i = 0; i < cont; i++)
	{
		if (cards[i].getValue() == 'A')
		{
			aces++;
		}

		value += cards[i].getRealValue();
	}

	if (value > 21 && aces > 0)
	{
		while (aces > 0)
		{
			aces--;
			value -= 10;
			if (value <= 21)
				break;
		}
	}

	return value;
}

void Hand::draw(int x, int y) {
	for (int i = 0; i < cont; i++)
	{
		cards[i].draw(x + i * 60, y);
	}
}

void Hand::clear() {
	cards.clear();
	cont = 0;
}
