/***************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the header file for the hallway space in the dungeon 
 * program
 * *************************************************************************/
#ifndef HALLWAY_HPP
#define HALLWAY_HPP
#include "space.hpp"

class Hallway: public Space
{
	private: 
		bool statue;
		bool key;
		bool potion;
		bool lev1;
		bool lev2;
		bool lev3;
		bool lev4;
	public:
		Hallway();
		void interact(Character &player);
		Space* move(Space* pointer);
};

#endif
