/***************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the header file for the treasure space in the dungeon 
 * program
 * *************************************************************************/
#ifndef TREASURE_HPP
#define TREASURE_HPP
#include "space.hpp"

class Treasure: public Space
{
	public:
		Treasure();
		void interact(Character &player);
		Space* move(Space* pointer);
};

#endif
