/***************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the header file for the barracks space in the dungeon 
 * program
 * *************************************************************************/
#ifndef BARRACKS_HPP
#define BARRACKS_HPP
#include "space.hpp"

class Barracks: public Space
{
	private: 
		bool lever;
		bool skeleton;
		bool potion;
	public:
		Barracks();
		void interact(Character &player);
		Space* move(Space* pointer);
};

#endif
