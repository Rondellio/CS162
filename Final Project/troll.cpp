/***************************************************************************
 * Program: dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the functional description of the troll space for
 * the dungeon program
 * ************************************************************************/
#include "troll.hpp"

//Default constructor for Troll room that sets name, description, and tasks
Troll::Troll()
{
	desc = "The foul stench of troll thrusts itself into your nostrils\nas you enter this room. Oil lines run the length of the floor\nleading up to a troll dripping in the liquid. He shouts at you\n\"You shall never escape!\"";
	name = "Troll Lair";
	troll = true;
	key = false;

}

//Function to allow user to interact with the room
void Troll::interact(Character &player)
{	
	int choice;
	char opt;
	
	//Prompt user for what they want to interact with
	cout << "\nWhat would you like to interact with?" << endl;
	cout << "1. Troll\n";
	cout << "2. Oil" << endl;

	cin >> choice;

	//Input validation
	while (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "\nError. Please enter a valid choice below" << endl;
		cout << "1. Troll\n";
		cout << "2. Oil" << endl;

		cin.clear();
		cin.ignore(10000, '\n');
		cin >> choice;
	}

	switch (choice)
	{
		case 1:	//User chooses to interact with troll
			if (troll)	//If troll still alive, troll beats user
			{
				cout << "You charge headstrong at the troll, ready ";
				cout << "to take it down. You chop off its arm and ";
				cout << "realize it's regenerating!" << endl;
				cout << "It swings at you with its massive arms ";
				cout << "knocking you down. There must be a way to ";
				cout << "stop the regneration.." << endl;
				player.hurt(5);
			}
			else if (!key)	//troll is dead and user doesn't have key, get key
			{
				cout << "You stand triumphantly over the smoldering body ";
				cout << "of the troll, removing its tooth for ";
				cout << "future bragging rights." << endl;
				cout << "You remove the silver key from around ";
				cout << "its neck and put it in your pouch" << endl;
				player.addItem("skey");
				key = true;
				player.hurt(1);
			}
			else	//Tasks are complete, nothing left to do on troll
			{
				cout << "The corpse continues to rot in the flames. A ";
				cout << "piece of flesh burns you as you touch it." << endl;
				player.hurt(1);
			}
			break;
		case 2:	//Player interacts with oil
			if (player.findItem("torch"))	//If player has torch on them, light oil
			{
				cout << "You use the torch on the oil and the troll ";
				cout << "goes up in flames. You notice that it's no ";
				cout << "longer regenerating and move in." << endl;

				if (player.findItem("axe"))	//If user has axe, use axe
				{
					cout << "You swing your massive axe and chop ";
					cout << "the troll in half." << endl;
					troll = false;
				}
				else if (player.findItem("sword")) //If user has sword, use sword
				{
					cout << "You slice all around the trolls body ";
					cout << "with your sword, cutting off limb ";
					cout << "after limb until it lays lifeless" << endl;
					troll = false;
				}
				else if (player.findItem("knife")) // If user has knife, use knife
				{
					cout << "You throw the knife into the troll's ";
					cout << "heart as it collapses into a burning ";
					cout << "mound of flesh" << endl;
					troll = false;
				}
				else	//If user has no weapons, use torch to
				{
					cout << "You use the torch to keep the troll ";
					cout << "at bay as it slowly burns to death" << endl;
					troll = false;
				}
				cout << "You see a glint of something around the troll's ";
				cout << "neck from the light of the flames" << endl;
				player.hurt(1);
			}
			else	//If player doesn't have torch, give hint as to what to do
			{
				cout << "\nThe oil seems very flammable. As you inspect ";
				cout << "it closer you slip and hurt yourself" << endl;
				player.hurt(1);
			}
	}
}

//Function to allow user to move between rooms
Space* Troll::move(Space* pointer)
{	
	int choice;

	//Ask user which direction to go
	cout << "\nWhich direction would you like to go?" << endl;
	cout << "1. Right (Treasure Room)\n";
	cout << "2. Down (Dining Hall)\n";	
	cin >> choice;

	//Input validation
	while (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "\nError. Please select from below" << endl;
		cout << "1. Right (Treasure Room)\n";
		cout << "2. Down (Dining Hall) \n";

		cin.clear();
		cin.ignore(10000, '\n');
		cin >> choice;
	}


	if (choice == 1)	//User selects right
	{	
		if (troll)	//If troll is alive, tell user they can't go
		{
			cout << "\nYou can't get past the troll!" << endl;
			return pointer;
		}
		else if (!key)	//If user has no key, tell user they can't go
		{
			cout << "\nYou need the key to get ";
			cout << "through the door" << endl;
			return pointer;
		}
		else		//Otherwise, go into treasure room
		{
			right->printDesc();
			return right;
		}
	}
	else		//User selects down
	{
		return down;	
	}
}
