/***************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the header file for the troll space in the dungeon 
 * program
 * *************************************************************************/
#ifndef TROLL_HPP
#define TROLL_HPP
#include "space.hpp"

class Troll: public Space
{
	private: 
		bool troll;
		bool key;
	public:
		Troll();
		void interact(Character &player);
		Space* move(Space* pointer);
};

#endif
