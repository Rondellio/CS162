/***************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the header file for the entrance space in the dungeon 
 * program
 * *************************************************************************/
#ifndef ENTRANCE_HPP
#define ENTRANCE_HPP
#include "space.hpp"

class Entrance: public Space
{
	private: 
		bool torch;
		bool brazier;
		bool door;
	public:
		Entrance();
		void interact(Character &player);
		Space* move(Space* pointer);
};

#endif
