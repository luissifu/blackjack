#include "Hand.h"

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
	for (int i = 0; i < cont; i++)
	{
		value += cards[i].getRealValue();
	}
	return value;
}

void Hand::draw(int x, int y) {
	for (int i = 0; i < cards.size(); i++)
	{
		cards[i].draw(x + i * 60, y);
	}
}