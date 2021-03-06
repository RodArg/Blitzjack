#pragma once
#include "stdafx.h"
#include "game.h"
#include <io.h>
#include <iostream>
using namespace std;
int main()
{
	bool run = true;
	cout << "Welcome to Blitzjack" << endl;
	//cout << "Choose your difficulty: " << endl;
	//cout << "Easy (E), Medium (M), or Hard (H)" << endl;
	//char diff;
	//cin >> diff;
	char response;
	//cout << "Rules (r), Continue (c), Quit (q)" << endl;
	//cin >> response;
	
	while (run) {
		int money;
		cout << "Enter the amount of money you'll start with:" << endl;
		cin >> money;
		Game game(money);
		game.initial();
		while (!game.isStanding()) {
			game.gameState();
			char action;
			cout << "Choose your action:" << endl << "(H)it - (S)tand" << endl;
			cin >> action;
			switch (action) {
				case 'H':
					game.hit();
					break;
				case 'S':
					game.stand();
					break;
				default:
					cout << "I don't recognize that, try again" << endl;
					break;
			if (game.isStanding()) {
				game.dealerTurn();
			}
			}
		}
	}
	


    return 0;
}



