/**************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the header file for the space class
 * ************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include "Character.hpp"
#include <iostream>
using namespace std;

class Space
{
	protected:
		string desc;
		string name;

	public:
		Space *up;
		Space *down;
		Space *right;
		Space *left;
		Space();
		void spaceMenu();
		virtual void interact(Character &player) = 0;
		virtual Space* move(Space* pointer) = 0;
		void printMap();
		void printDesc();

};

#endif
