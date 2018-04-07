/********************************************************************************
 * Program: dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the main file for the dungeon program which intializes
 * the rooms and player and runs the game
 * *****************************************************************************/
#include "dh.hpp"
#include "armory.hpp"
#include "entrance.hpp"
#include "kitchen.hpp"
#include "hallway.hpp"
#include "barracks.hpp"
#include "troll.hpp"
#include "treasure.hpp"
#include "Character.hpp"
#include "space.hpp"
#include <string>
#include <iostream>
using namespace std;

int main()
{
//	Space* rooms[3][3];
	bool play = true;

	while (play)
	{
		//Introduction to the game
		cout << "****************************************************" << endl;
		cout << "		  Dungeon Crawler		     " << endl;
		cout << "****************************************************\n" << endl;
		cout << "You awaken in a dark, cold room, unaware of how you \n";
		cout << "got there. Next to you is a note that reads \"Welcome\n";
		cout << "to the game. You will notice wounds all over your \n";
		cout << "body. Each task you perform and each move you make \n";
		cout << "will cause these wounds to open. You must find the \n";
		cout << "teleportation scroll to escape this lair and get to\n";
		cout << "a cleric before your time runs out. Good luck..\"\n";
		cout << "****************************************************\n";
		cout << "Starting Health: 30\n";
		cout << "Goal: Get teleportation scroll\n" << endl;
		
		//Initalize player and rooms
		Character player;
		Space* entrance = new Entrance();
		Space* armory = new Armory();
		Space* dh = new Dh();
		Space* kitchen = new Kitchen();
		Space* hallway = new Hallway();
		Space* barracks = new Barracks();
		Space* troll = new Troll();
		Space* treasure = new Treasure();

		//Link together rooms
		entrance->up = armory;
		
		armory->down = entrance;
		armory->left = dh;
	
		dh->right = armory;
		dh->up = troll;
		dh->left = kitchen;

		kitchen->right = dh;
		kitchen->up = hallway;

		hallway->down = kitchen;
		hallway->right = barracks;

		barracks->left = hallway;
		barracks->down = dh;

		troll->down = dh;
		troll->right = treasure;

		treasure->left = troll;

		//Set pointer to entrance and print description
		Space *tempPtr = entrance;
		tempPtr->printDesc();
		int choice;		

		//Run game while player alive and hasn't won
		while (player.getHealth() > 0 && !player.getWin())
		{	
			tempPtr->spaceMenu();
			cin >> choice;

			switch (choice)
			{
				case 1:	//User chooses to interact with space
					tempPtr->interact(player);
					break;
				case 2: //User chooses to print map
					tempPtr->printMap();
					break;
				case 3: //User chooses to use a potion
					player.usePotion();
					break;		
				case 4: //User chooses to move to next room
					tempPtr = tempPtr->move(tempPtr);
					player.hurt(1); // hurt player for moving
					break;
			}
		
		//Print out players current stats
		cout << "----------------------------------------------\n";
		cout << "Current Health: " << player.getHealth() << endl;
		cout << "Current Bag: " << endl;
		player.printBag();
		cout << "----------------------------------------------\n";
		}
		
		//game has ended, if player died output that
		if (player.getHealth() <= 0)
		{
			cout << "\nYou have lost all your health and died ";
			cout << "in the dungeon." << endl;
		}
		else //If player didn't die, congratulate on win
		{
			cout << "\nCongratulations! You teleport out of ";
			cout << "the dungeon to safety" << endl;
		}

		//Prompt user to play again
		int playAgain;
		cout << "\nWould you like to play again?" << endl;
		cout << "1. Yes\n";
		cout << "2. No" << endl;
		cin >> playAgain;

		//input validation
		while (playAgain < 1 || playAgain > 2 || cin.fail())
		{
			cout << "\nError. Please select from below." << endl;
			cout << "1. Yes\n";
			cout << "2. No" << endl;
			
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> playAgain;
		}

		if (playAgain == 2) //If user chooses no, exit program
		{
			play = false;
			cout <<"Thank you for playing" << endl;
		}
	
		//Prevent any memory leaks
		delete entrance;
		delete armory;
		delete dh;
		delete kitchen;
		delete hallway;
		delete barracks;
		delete troll;
		delete treasure;
	}

	return 0;
}
