/***************************************************************************
 * Program: dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the functional description of the barracks space for
 * the dungeon program
 * ************************************************************************/
#include "barracks.hpp"

//Default constructor for barracks to set name, description, and tasks
Barracks::Barracks()
{
	desc = "You enter a room with bunks running down both walls. On the\nfar end you see an iron gate, with a lever next to it. In \none bunk lies the skeleton of a dead solider, grasping onto\nsome sort of potion";
	name = "Barracks";
	lever = false;
	skeleton = true;
	potion = true;
	
}

//Function to allow user to interact with objects in room
void Barracks::interact(Character &player)
{	
	int choice;
	char opt;
	
	//Prompt user for what object to interact with
	cout << "\nWhat would you like to interact with?" << endl;
	cout << "1. Lever\n";
	cout << "2. Skeleton" << endl;

	cin >> choice;

	//Input validation
	while (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "\nError. Please enter a valid choice below" << endl;
		cout << "1. Lever\n";
		cout << "2. Skeleton" << endl;

		cin.clear();
		cin.ignore(10000, '\n');
		cin >> choice;
	}

	switch (choice)
	{
		case 1:	//User selects to interact with lever
			if (!lever)	//lever is up, pull down to open gate
			{
				cout << "\nYou pull the lever down and hear ";
				cout << "groaning as the iron portcullis ";
				cout << "raises up." << endl;
				lever = true;
				player.hurt(1);
			}
			else		//Lever is down, push it up to close gate
			{
				cout << "\nThe portcullis slams down, ";
				cout << "sealing itself once again." << endl;
				lever = false;
				player.hurt(1);
			}
			break;

		case 2:	//User selects to interact with skeleton
			if (skeleton) //If skeleton is still alive
			{
				cout << "\nThe skeleton bursts to life as ";
				cout << "you reach for the potion. It ";
				cout << "pulls out a blow dart and shoots ";
				cout << "it your direction." << endl;

				//If user has a shield, block dart
				if (player.findItem("sword"))
				{
					cout << "You use your shield to ";
					cout << "block the dart." << endl;
				}
				//If user has no shield, dart hits player
				else
				{
					cout << "The dart catches you in ";
					cout << "the neck." << endl;
					player.hurt(2);
				}

				cout << "The skeleton crumbles to pieces ";
				cout << "leaving the potion behind." << endl;
				skeleton = false;	//Skeleton dies
			}

			else if (potion) //Potion has not been taken, ask to drink
			{
				cout << "\nThis potion seems different than ";
				cout << "the prevoius ones.. drink it(Y/N)?" << endl;
				
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> opt;

				//Input validation
				while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
				{
					cout << "Error. Please input Y or N." << endl;
					
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> opt;
				}

				if (opt == 'y' || opt == 'Y') //If user selects yes, drink potion
				{
					cout << "\nYou feel a new strength course through ";
					cout << "your body." << endl;
					player.addStrength(2);	//Add strength to open hearth
					potion = false;		//remove potion
				}
				else
				{
					cout << "\nYou leave the potion on the body." << endl;
				}
				player.hurt(1);
			}
			else	//Player has killed skeleton and drank potion
			{
				cout << "\nNothing of interest, just a pile of bones" << endl;
				player.hurt(1);
			}
			
	}
}

//Function to allow player to move to another room
Space* Barracks::move(Space* pointer)
{	
	int choice;

	//Prompt user for direction to go
	cout << "\nWhich direction would you like to go?" << endl;
	cout << "1. Left (Hallway)\n";
	cout << "2. Down (Dining Hall)\n";	
	cin >> choice;

	//Input validation
	while (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "\nError. Please select from below" << endl;
		cout << "1. Left (Hallway)\n";
		cout << "2. Down (Dining Hall) \n";

		cin.clear();
		cin.ignore(10000, '\n');
		cin >> choice;
	}

	if (choice == 1)	//User selects left, move left
	{	
		return left;
	}
	else if (!lever)	//If gate is down, tell user they can't pass
	{
		cout << "\nThe gate is still down!" << endl;
		return pointer;
	}
	else	//If gate is up, allow user to pass and close gate again
	{
		cout << "\nThe portcullis slams closed behind you." << endl;
		lever = false;
		return down;
		
	}

}
