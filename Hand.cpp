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
	int value2=0;
	if(value=0)
    {
        flagAs=false;
    }
	for (int i = 0; i < cont; i++)
	{   value2=value;
		value += cards[i].getRealValue();
		if((value-value2)==11)
        {
            flagAs=true;
        }
        if(flagAs)
        {
            if(value>21)
            {
                value-=10;
                flagAs=false;
            }
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
