#pragma once
#include "player.h"
#include <iostream>
const int FUNDS_DEF = 5000;
class Game {
	public:
		Game(int funds) {
			if(funds > 0)
				player.addToWallet(funds);
			else {
				cout << "Yikes... we're setting your bank to $5000 uwu" << endl;
				player.addToWallet(FUNDS_DEF);
			}

		}
		bool isStanding() { return standing; }
		void initial();
		//actions
		void hit();
		void stand() { standing = true; }
		void split();
		void double_action();
		void surrender();

		void dealerTurn();
		void gameState();
	private:
		Deck deck;
		int turn_num;
		Player dealer;
		Player player;
		bool standing = false;
};

void Game::initial() {
	player.addToHand(deck.getRandomCard());
	dealer.addToHand(deck.getRandomCard());
	player.addToHand(deck.getRandomCard());
	dealer.addToHand(deck.getRandomCard());
}

void Game::hit() {
	player.addToHand(deck.getRandomCard());
}

void Game::dealerTurn() {
	while (dealer.getHandValue() <= 16)
		dealer.addToHand(deck.getRandomCard());
}

void Game::gameState() {
	cout << "Dealer:" << endl;
	for (Card card : dealer.getHand()) {
		card.printCard();
	}
	cout << endl;
	cout << "Player:" << endl;
	for (Card card : player.getHand()) {
		card.printCard();
	}
	cout << "Player Bank: $" << player.getWallet() << endl;
}