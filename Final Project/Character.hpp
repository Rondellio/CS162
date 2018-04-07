/*****************************************************************************
 * Program: dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the header file for the character class of the
 * dungeon program
 * ***************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>
using namespace std;

class Character
{
	protected:
		int health;
		int strength;
		bool win;
		vector<string> bag;
	public:
		Character();
		void addItem(string);
		void removeItem(string);
		bool findItem(string);
		void hurt(int);
		void heal(int);
		int getHealth();
		int getStrength();
		void addStrength(int);
		void usePotion();
		void printBag();
		void setWin();
		bool getWin();
};

#endif
