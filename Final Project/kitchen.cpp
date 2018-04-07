/***************************************************************************
 * Program: dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the functional description of the kitchen space for
 * the dungeon program
 * ************************************************************************/
#include "kitchen.hpp"

//Default constructor to set name, description, and tasks for kitchen
Kitchen::Kitchen()
{
	desc = "You come into a kitchen, littered with carcasses. Directly\nin front of you is a counter with some cooking utensils. \nOn the far side of the room you hear something gnawing on\nflesh and bone. 4 dark red eyes stare back at you"; 
	name = "Kitchen";
	wolves = 2;
	knife = true;
	
}

//Function to allow user to interact with things in kitchen
void Kitchen::interact(Character &player)
{
	int kit;
	int knifeOption;
	
	//Prompt user for what they want to do
	cout << "\nWhat would you like to interact with?" << endl;
	cout << "1. Counter\n";
	cout << "2. Eyes" << endl;

	cin >> kit;

	//Input validation
	while (kit < 1 || kit > 2 || cin.fail())
	{
		cout << "\nError. Please enter a valid choice below" << endl;
		cout << "1. Counter\n";
		cout << "2. Eyes" << endl;

		cin.clear();
		cin.ignore(10000, '\n');
		cin >> kit;
	}

	switch (kit)
	{
		case 1: //user chooses counter
			if (knife) // If knife is still on counter, prompt for what to do
			{
				cout << "\nYou pick up a knife. What would you like to ";
				cout << "do with it?" << endl;
	
				cout << "1. Keep it\n";
				cout << "2. Throw it\n";
				cout << "3. Leave it" << endl;

				cin >> knifeOption;
				
				//Input validation
				while (knifeOption < 1 || knifeOption > 3 || cin.fail())
				{
					cout << "\nError. Enter a valid choice below" << endl;
					cout << "1. Keep it\n";
					cout << "2. Throw it\n";
					cout << "3. Leave it" << endl;
				
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> knifeOption;
				}
		
				switch (knifeOption)
				{
					case 1: //User chooses to keep knife, add to bag
						cout << "\nYou add the item to your bag. It stabs ";
						cout << "you as it falls in."  << endl;
						player.addItem("knife");
						knife = false;
						player.hurt(1);
						break;
				
					case 2: //User chooses to throw knife, hit a wolf if any are left
						if (wolves > 1)
						{
							cout << "\nYou throw the knife in the direction of ";
							cout << "the eyes and hear a loud squeal as one ";
							cout << "set disappears. Your wound opens slightly" << endl;
							wolves -= 1;
							knife = false;
							player.hurt(1);
						}
						else //User throws knife across room at nothing
						{
							cout << "\nYou throw the knife across the room. ";
							cout << "It hits a pot, making a loud noise and ";
							cout << "deafening you slightly." << endl;
							player.hurt(1);
						}
						break;
					case 3: //User chooses to leave knife
						cout << "\nYou set the knife back down, but knick your ";
						cout << "hand with the blade." << endl;
						player.hurt(1);
						break;
				}
			}
			else //If knife has already been found, nothing left
			{
				cout << "You find nothing of interest, but hit your head";
				cout << " on a cubbard" << endl;
				player.hurt(1);
			}
			break;

		case 2: //User chooses to interact with wolves. User will lose health equal
			//to number of wolves, increasing depending on weapon used.
			cout << "\nYou approach the eyes slowly. " << wolves << " wolves ";
			cout << "attack you, but you fend them off with your ";

			if (player.findItem("axe")) //player has axe, use axe to fight
			{
				cout << "axe, cleaving your way to victory." << endl;
				player.hurt(1*wolves);
			}
			else if (player.findItem("sword")) //Player has sword, use sword to fight
			{
				cout << "sword and shield, chopping your way to victory." << endl;
				player.hurt(1*wolves);
			}
			else if (player.findItem("knife")) //Player has knife, use knife to fight
			{
				cout << "knife, stabbing your way to victory." << endl;
				player.hurt(2*wolves);
			}
			else 		//Player has no weapons, uses fists to fight. 
			{
				cout << "fists, punching your way to victory." << endl;
				player.hurt(3*wolves);
			}
			wolves = 0;
			break;
	}
}


//Function to allow user to move to another room
Space* Kitchen::move(Space* pointer)
{
	int choice;

	//If there are still wolves alive, don't let user pass
	if (wolves > 0)
	{
		cout << "\nYou can't pass! " << wolves << "wolves ";
		cout << "Block the way!";
		return pointer;
	}
	else //If all wolves are dead, prompt for direction.
	{
		cout << "\nWhich direction would you like to go?" << endl;
		cout << "1. Up (Hallway)\n";
		cout << "2. Right (Dining Hall)\n";	
		cin >> choice;

		//Input validation
		while (choice < 1 || choice > 2 || cin.fail())
		{
			cout << "\nError. Please select from below" << endl;
			cout << "1. Up (Hallway)\n";
			cout << "2. Right (Dining Hall) \n";

			cin.clear();
			cin.ignore(10000, '\n');
			cin >> choice;
		}

		if (choice == 1)	//User selects up
		{	
			up->printDesc();
			return up;
		}
		else			//User selects right
		{
			return right;
		}
	}
}
