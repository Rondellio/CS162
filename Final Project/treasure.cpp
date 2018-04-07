/***************************************************************************
 * Program: dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the functional description of the treasure space for
 * the dungeon program
 * ************************************************************************/
#include "treasure.hpp"

//Default constructor to set name, description and links
Treasure::Treasure()
{
	desc = "This marble lined room eminates an aura of cleanliness.\nSomehow, even the stench of the burning troll fades from\nmind. In the middle lies a golden chest, brightly glowing\nas if somehow magical";
	name = "Treasure Room";
	
}

//Function to allow interaction within the treasure space
void Treasure::interact(Character &player)
{	
	int choice;

	//Ask user if they would like to interact with chest
	cout << "What would you like to interact with?" << endl;
	cout << "1. Treasure Chest" << endl;
	cin >> choice;

	//Input validation
	while (choice != 1 || cin.fail())
	{
		cout << "Error. Please select from below." << endl;
		cin.clear();
		cin.ignore(10000,'\n');
		cin >> choice;
	}
	
	if (player.findItem("key"))	//If player has the key
	{
		cout << "\nYou take the golden key from your pouch and ";
		cout << "open the chest, revealing the teleportation ";
		cout << "scroll. " << endl;
		player.setWin();	//Player wins
	}
	else		//player does not have key
	{
		cout << "\nThe chest is locked! There must be another ";
		cout << "key somewhere else. A tiny spike stabs your ";
		cout << "hand as you pull it away" << endl;
		player.hurt(1);
	}
}

//Function to allow player to move to other rooms
Space* Treasure::move(Space* pointer)
{
	int choice;	

	cout << "Where would you like to go? " << endl;
	cout << "1. Left (Troll Lair)" << endl;
	
	cin >> choice;

	//Input Validation
	while (choice != 1 || cin.fail())
	{
		cout << "Error, invalid option.";
		cout << " Please choose from below" << endl;
		cout << "1. Left (Troll Lair)" << endl;

		cin.clear();
		cin.ignore(10000, '\n');
		cin >> choice;
	}

	return left;
}
