#include <iostream>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"

using namespace std;

int main() {
	Deck deck;
	deck.shuffle();

	for (int i = 0; i < 52; i++)
	{
		deck.dealCard().muestra();
	}

	int ch;
	cin >> ch;
	cout<<"rubyisfag"<<endl;
}
