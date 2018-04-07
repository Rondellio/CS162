/************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the functional description file for the dining hall
 * space
 * **********************************************************************/
#include "dh.hpp"

//Default constructor for dining hall, sets name, description, and events
Dh::Dh()
{
	desc = "You enter a room with a large table. In the middle, a fireplace\nsits, unlit. Directly to your right you see a closed iron gate\nand against the far wall a closed door.";
	name = "Dining Hall";
	hearth = false;
	potion = false;
	door = false;

}

//Function to allow user to interact with room
void Dh::interact(Character &player)
{	
	int choice;
	char axe;

	//Options for users to interact with
	cout << "\nWhat would you like to interract with?" << endl;
	cout << "1. Portcullis\n";
	cout << "2. Fireplace\n";
	cout << "3. Door" << endl;
	
	cin >> choice;

	//Input validation
	while (choice < 1 || choice > 3 || cin.fail())
	{
		cout << "\nError. Please enter valid option below." << endl;
	
		cout << "1. Portcullis\n";
		cout << "2. Fireplace\n";
		cout << "3. Door" << endl;
	
		cin.clear();
		cin.ignore(10000,'\n');
		cin >> choice;
	}

	switch (choice)
	{
		case 1: 	//User selects Portcullis, but cannot open it
			cout << "\nThe iron gate is locked closed. As ";
			cout << "you approach a dart hits you from the ";
			cout << "other side." << endl;
			player.hurt(2);
			break;
		case 2:		//User selects Fireplace
			if (!potion) // If user has not found potion yet, find potion
			{		
				cout << "\nAs you approach you feel a breeze coming ";
				cout << "from behind. Perhaps there is a way to move ";
				cout << "it.." << endl;

				cout << "\nYou find a health potion on top of the hearth." << endl;
				player.addItem("hpot");
				potion = true;
				player.hurt(1);
			}
			else if (player.findItem("axe") && !hearth) 
			//If user has axe, ask if they would like to use it to open hearth.
			{
				cout << "\nThe axe! Attempt to use the axe for leverage(Y/N)? ";
				cin >> axe;

				//Input validation
				if (axe != 'n' && axe != 'N' && axe != 'y' && axe != 'Y')
				{
					cout << "\nError, please select Y or N. ";
					cin.clear();
					cin.ignore();
					cin >> axe;
				}

				//If user selects yes, break axe and open hearth
				if (axe == 'y' || axe == 'Y') 
				{
					cout << "\nYou wedge the axe in a crack behind the ";
					cout << "mantle. The axe breaks, sending a splinter ";
					cout << "into your arm, but the hearth is opened! " << endl;
					hearth = true;
					player.removeItem("axe");
					player.hurt(1);
				}
				//if user selects no, prompt there must be a way to open it.
				else
				{
					cout << "\nThere must be another way to open it.." << endl;
				}
				player.hurt(1);
			}
			//If player has used strength potion and hearth is still closed
			else if (player.getStrength() > 1 && !hearth)
			{
				cout << "\nYou push the hearth open, revealing a hidden ";
				cout << "passage. " << endl;
				hearth = true;
				player.hurt(1);
			}
			else if (hearth) // If hearth is already opened
			{
				cout << "\nThe fireplace has already opened to the passage."<< endl;
			}
			else //If user has no axe or strength potion
			{
				cout << "\nThere must be a way to open it.." << endl;
			}
			break;
		case 3: // Interact with door
			if (!door) // If door hasn't been opened
			{
				cout << "\nThe odor of raw meat overwhelms you ";
				cout << "as you open the door, dizzying you." << endl;
				door = true;
				player.hurt(1);
			}
			else // If door has been opened
			{
				cout << "The door is already open." << endl;
				player.hurt(1);
			}
			break;
	}
}

//Function to allow user to move to other spaces
Space* Dh::move(Space* pointer)
{
	int choice;	

	
	//Prompt user for direction to go
	cout << "\nWhich direction would you like to go?" << endl;
	cout << "1. Left (Kitchen)\n";
	cout << "2. Right (Armory)\n";
	
	if (hearth) //if hearth is opened, include troll lair
	{
		cout << "3. Up (Troll Lair)" << endl;
	}
	else
	{
		cout << "3. Up " << endl;
	}	
	cin >> choice;

	//input validation
	while (choice < 1 || choice > 3 || cin.fail())
	{
		cout << "\nError. Please select from below" << endl;
		cout << "1. Left (Kitchen)\n";
		cout << "2. Right (Armory) \n";
		if (hearth)
		{
			cout << "3. Up (Troll Lair)" << endl;
		}	
		else
		{
			cout << "3. Up " << endl;
		}
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> choice;
	}

	switch (choice)
	{
		case 1: // User chooses left
			if (door) // door is open, print description and move left
			{
				left->printDesc();
				return left;
			}
			else //Door is closed still
			{
				cout << "\nThe door is still closed! " << endl;
				return pointer;
			}
		case 2: // User chooses right, move right
			return right;
		case 3: // User chooses up
			if (hearth) // If hearth has been opened
			{
				up->printDesc();
				return up;
			}
			else	//If hearth is not opened
			{
				cout << "\nYou can't go that way yet!" << endl;
				return pointer;
			}
	}
}
