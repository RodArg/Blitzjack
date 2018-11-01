#include<string>
#include <sstream>
#include <vector>
#include <iostream>
using std::string;
using namespace std;
string operator*(const string& s, unsigned int n) {
	stringstream out;
	while (n--)
		out << s;
	return out.str();
}

class Card {
	public:
		Card(int value, char csuit) {
			val = value;
			suit = csuit;
			switch (suit) {
				case 'S':
					suit_utf = "$S"; //u8"\u2660"; //Black Spade
					break;
				case 'H':
					suit_utf = "$H"; //u8"\u2661"; //White Heart
					break;
				case 'C':
					suit_utf = "$C"; //u8"\u2662"; //Black Club
					break;
				case 'D':
					suit_utf = "$D"; //u8"\u2663"; //White Diamond
					break;
			}
		}
		int getCardVal() { return val; }
		string buildCard(string number, string symbol);
		void printCardVals();
		void printCard();
		
	private:
		int val;
		char suit;
		string suit_utf;
};

string Card::buildCard(string number, string symbol) {
	string flat = "_"; //u8"\u2500"; // ─
	string topleft = "+"; // u8"\u250c"; // ┌
	string topright = "+"; // u8"\u2510"; // ┐
	string side = "|"; // u8"\u2502"; // │
	string botleft = "+"; // u8"\u2514"; // └
	string botright = "+"; // u8"\u2519"; // ┘

	string top = topleft + flat * 8 + topright + "\n";
	string line = side + "........" + side + "\n";
	string bot = botleft + flat * 8 + botright;

	string topnum = side + number + "......." + side + "\n";
	string symline = side + "..." + symbol + "..." + side + "\n";
	string botnum = side + "......." + number + side + "\n";
	string card = top + topnum + line * 2 + symline + line * 2 + botnum + bot;

	return card;
}

void Card::printCardVals() {
	cout << "Card Value: " << val << endl;
	cout << "Card Suit: " << suit << endl;
	cout << "Card Suit UTF:" << suit_utf << endl;
}

void Card::printCard() {
	string num;
	switch (val) {
	case 1:
		num = "A";
		break;
	case 11:
		num = "J";
		break;
	case 12:
		num = "Q";
		break;
	case 13:
		num = "K";
		break;
	default:
		num = to_string(val);
		break;
	}
	string card = buildCard(num, suit_utf);
	cout << card << endl;
}