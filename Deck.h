//
//  Deck.h
//  BlackJack
//
//  Luis Sifuentes A01138688
//  
//

#ifndef __BlackJack__Deck__
#define __BlackJack__Deck__

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <vector>
#include "Card.h"

class Deck
{
public:
	// Constructor
	Deck();
	
	// Otros Metodos
	void shuffle();
	Card dealCard();
	std::string str();
	
private:
	// Atributos
	std::stack<Card> deck;
	std::vector<Card> stddeck;
};

#endif
