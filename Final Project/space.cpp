/**************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the functional description of the Space class which
 * is an abstract class to move through the text based game
 * ***********************************************************************/
#include "space.hpp"
#include <iostream>
using namespace std;

Space::Space()
{
	up = NULL;
	down = NULL;
	right = NULL;
	left = NULL;
}

void Space::spaceMenu()
{
	cout << "\n\nYou are currently in the " << name << "." << endl;
	cout << "What would you like to do?\n" << endl;
	cout << "1. Interact with environment\n";
	cout << "2. View Map\n";
	cout << "3. Use potion\n";
	cout << "4. Move" << endl;

}

void Space::printMap()
{
	cout << " _______         " << endl;
	cout << "|__5__| |        1. Entrance" << endl;
	cout << "| |   | |        2. Armory" << endl;
	cout << "| |  _|6|__      3. Dining Hall" << endl;
	cout << "|4| |7| |_8|     4. Kitchen" << endl;
	cout << "| |_|_|_|__      5. Hallway" << endl;
	cout << "|_|__3__| 2|     6. Barracks" << endl;
	cout << "     ___|__|     7. Master Room" << endl;
	cout << "    |__1___|     8. Treasure Room" << endl;
}

void Space::printDesc()
{
	cout << desc << endl;
}
	

