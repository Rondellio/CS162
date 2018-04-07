/****************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the header file for the dining hall space
 * ***************************************************************************/
#ifndef DH_HPP
#define DH_HPP
#include "space.hpp"

class Dh: public Space
{
	private:
		bool hearth;
		bool potion;
		bool door;
	public:
		Dh();
		void interact(Character &player);
		Space* move(Space* pointer);	
};

#endif
