/***************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the header file for the kitchen space in the dungeon 
 * program
 * *************************************************************************/
#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include "space.hpp"

class Kitchen: public Space
{
	private: 
		int wolves;
		bool knife;
	public:
		Kitchen();
		void interact(Character &player);
		Space* move(Space* pointer);
};

#endif
