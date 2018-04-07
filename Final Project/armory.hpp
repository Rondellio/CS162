/**************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the header file for the armory space
 * ************************************************************************/
#ifndef ARMORY_HPP
#define ARMORY_HPP
#include "space.hpp"

class Armory: public Space
{
	private:
		bool weapon;
	public:
		Armory();
		void interact(Character &player);
		Space* move(Space* pointer);
};

#endif
