#include "Deck.h"

Deck::Deck() {
	//Clubs
	stddeck.push_back(Card('S', 'A'));
	stddeck.push_back(Card('S', '2'));
	stddeck.push_back(Card('S', '3'));
	stddeck.push_back(Card('S', '4'));
	stddeck.push_back(Card('S', '5'));
	stddeck.push_back(Card('S', '6'));
	stddeck.push_back(Card('S', '7'));
	stddeck.push_back(Card('S', '8'));
	stddeck.push_back(Card('S', '9'));
	stddeck.push_back(Card('S', 'T'));
	stddeck.push_back(Card('S', 'J'));
	stddeck.push_back(Card('S', 'Q'));
	stddeck.push_back(Card('S', 'K'));
	//Spades
	stddeck.push_back(Card('C', 'A'));
	stddeck.push_back(Card('C', '2'));
	stddeck.push_back(Card('C', '3'));
	stddeck.push_back(Card('C', '4'));
	stddeck.push_back(Card('C', '5'));
	stddeck.push_back(Card('C', '6'));
	stddeck.push_back(Card('C', '7'));
	stddeck.push_back(Card('C', '8'));
	stddeck.push_back(Card('C', '9'));
	stddeck.push_back(Card('C', 'T'));
	stddeck.push_back(Card('C', 'J'));
	stddeck.push_back(Card('C', 'Q'));
	stddeck.push_back(Card('C', 'K'));
	//Hearts
	stddeck.push_back(Card('H', 'A'));
	stddeck.push_back(Card('H', '2'));
	stddeck.push_back(Card('H', '3'));
	stddeck.push_back(Card('H', '4'));
	stddeck.push_back(Card('H', '5'));
	stddeck.push_back(Card('H', '6'));
	stddeck.push_back(Card('H', '7'));
	stddeck.push_back(Card('H', '8'));
	stddeck.push_back(Card('H', '9'));
	stddeck.push_back(Card('H', 'T'));
	stddeck.push_back(Card('H', 'J'));
	stddeck.push_back(Card('H', 'Q'));
	stddeck.push_back(Card('H', 'K'));
	//Diamonds
	stddeck.push_back(Card('D', 'A'));
	stddeck.push_back(Card('D', '2'));
	stddeck.push_back(Card('D', '3'));
	stddeck.push_back(Card('D', '4'));
	stddeck.push_back(Card('D', '5'));
	stddeck.push_back(Card('D', '6'));
	stddeck.push_back(Card('D', '7'));
	stddeck.push_back(Card('D', '8'));
	stddeck.push_back(Card('D', '9'));
	stddeck.push_back(Card('D', 'T'));
	stddeck.push_back(Card('D', 'J'));
	stddeck.push_back(Card('D', 'Q'));
	stddeck.push_back(Card('D', 'K'));
}

void Deck::shuffle() {
	while (!deck.empty())
	{
		deck.pop();
	}

	bool inDeck[52] {
		false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false
	};

 	std::srand(std::time(0) + std::clock());

	for (int i = 0; i < 52; i++)
	{
		int rndnum = std::rand()%52;
		while (inDeck[rndnum])
		{
			rndnum = std::rand()%52;
		}

		inDeck[rndnum] = true;
		
		deck.push(stddeck[rndnum]);
	}
}

Card Deck::dealCard() {
	if (!deck.empty())
	{
		Card c = deck.top();
		deck.pop();
		return c;
	}

	return Card('S', 'A');
}

std::string Deck::str() {
	return "Deck";
}