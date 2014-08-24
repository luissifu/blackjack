//
//  Hand.h
//  BlackJack
//
//  Luis Sifuentes A01138688
//  
//

#ifndef __BlackJack__Hand__
#define __BlackJack__Hand__

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

class Hand {
	public:
		Hand();
		std::string str();
		void addCard(Card card);
		int getValue();
		void draw(int x, int y);
		void clear();
	private:
		std::vector<Card> cards;
		int cont;
};

#endif
