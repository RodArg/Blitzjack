#pragma once
#include "cards.h"
#include <vector>
class Deck {
	public:
		Deck() {
			for (char suit : suits)
				for (int value : values)
					deck.push_back(Card(value, suit));
		}
		vector<Card> getDeck();
		void shuffleDeck();
		Card getRandomCard();

		typedef vector<Card>::iterator iterator;
		typedef vector<Card>::const_iterator const_iterator;
		
		iterator begin() {
			return deck.begin();
		}
		iterator end() {
			return deck.end();
		}


	private:
		vector<Card> deck;
		vector<int> values = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
		vector<char> suits = { 'S','H','C','D' };
		/*
		map<char, string> my_map = {
		{ 'S', "\u2660"}, //Black Spade
		{ 'H', "\u2661"}, //White Heart
		{ 'C', "\u2662"}, //Black Club
		{ 'D', "\u2663"}  //White Diamond
		};
		*/
};

vector<Card> Deck::getDeck() {
	return deck;
}

void Deck::shuffleDeck() {
	int cards_tot = deck.size();
	for (int i = 0; i < cards_tot - 2; i++) {
		int randy = rand() % (cards_tot - i) + i;
		Card temp = deck[i];
		deck[i] = deck[randy];
		deck[randy] = temp;
	}
}

Card Deck::getRandomCard() {
	Card card = deck.back();
	deck.pop_back();
	return card;
}