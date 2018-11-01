#pragma once
#include "deck.h"
class Player {
	public:
		vector<Card> getHand() { return hand; }
		int getHandValue() { return hand_val; }
		void addToHand(Card card) { hand.push_back(card); hand_val += card.getCardVal(); }
		void clearHand() { hand.clear(); hand_val = 0; }

		int getWallet() { return wallet; }
		void addToWallet(int amt) { wallet += amt; }
		void emptyWallet() { wallet = 0; }
	private: 
		vector<Card> hand;
		int hand_val;
		int wallet;
};
