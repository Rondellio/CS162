/*****************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the functional description for the armory space class
 * in the dungeon program
 * **************************************************************************/
#include "armory.hpp"

//Default constructor to set name, description, and events in armory
Armory::Armory()
{
	desc = "You enter a room full of old rusted pieces of metal. Helms,\nbreastplates, and weapons lay broken all around you. Against\nthe far wall you see a massive two-headed axe, and next to\nit a sword crossed in front of a shield";
	name = "Armory";
	weapon = false;
}

//Function to allow interaction within the armory
void Armory::interact(Character &player)
{
	int choice;
	char opt;

	if (!weapon) //If user has not yet selected a weapon, prompt which they would like
	{
		cout << "\nTwo weapon sets lie against the wall. Which would you like ";
		cout << "to pickup?" << endl;
	
		cout << "1. Two-handed Axe\n";
		cout << "2. Sword and Shield\n";
		cout << "3. None" << endl;
		cin >> choice;

		//Input validation
		while (choice < 1 || choice > 3 || cin.fail())
		{
			cout << "\nError. Invalid selection. Please choose from below" << endl;
			cout << "1. Two-handed Axe\n";
			cout << "2. Sword and Shield\n";
			cout << "3. None" << endl;
	
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> choice;
		}


		switch (choice)
		{
			case 1:	//User selects axe, axe is added to bag
				cout << "\nYou heave up the massive axe over your shoulder. ";
				cout << "The blade knicks your back as you do." << endl;
				player.addItem("axe");
				weapon = true;
				player.hurt(1);
				break;	
			case 2:	//User selects sword, sword is added to bag
				cout << "\nYou strap the shield to your arm and place ";
				cout << "the sword and sheath around your waist. The wood ";
				cout << "from the shield spliters into your arm." << endl;
				player.addItem("sword");
				weapon = true;
				player.hurt(1);
				break;
			case 3: //User selects neither and leaves the weapons
				cout << "\nYou leave the weapons on the ground" << endl;
				player.hurt(1);
		}
	}
	else 	//If user already has selected a weapon, prompt if they want to switch
	{
		cout << "\nYou already have a weapon!" << endl;
		cout << "Would you like to switch (Y/N)?" << endl;
		cin.clear();
		cin.ignore(10000,'\n');
		cin >> opt;

		//Input validation
		while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
		{
			cout << "Error. Please select Y or N" << endl;
			cin.clear();
			cin.ignore(10000,'\n');
			cin >> opt;
		}

		if (opt == 'y' || opt == 'Y')	//if user wants to switch, trade weapon
		{
			if (player.findItem("sword"))
			{
				cout << "\nYou grab the heavy axe and sling it over your shoulder." << endl;
				player.removeItem("sword");
				player.addItem("axe");
			}
			else
			{
				cout << "\nYou grab the sword and shield and strap them to yourself." << endl;
				player.removeItem("axe");
				player.addItem("sword");
			}
		}
		else 	//If user says no, keep their current weapon
		{
			cout << "\nYou keep your weapon." << endl;
		}
		player.hurt(1);
	}
}


//Function to allow user to move into next rooms
Space* Armory::move(Space* pointer)
{
	int choice;

	//Prompt user for direction to go
	cout << "\nWhich direction would you like to go?" << endl;
	cout << "1. Left (Dining Hall)\n";
	cout << "2. Down (entrance)\n";	
	cin >> choice;

	//Input validation
	while (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "Error. Please select from below" << endl;
		cout << "1. Left (Dining Hall)\n";
		cout << "2. Down (Entrance) \n";

		cin.clear();
		cin.ignore(10000, '\n');
		cin >> choice;
	}

	if (choice == 1) // User selects left, print description and move left
	{
		left->printDesc();	
		return left;
	}
	else 	//User selects down, print description and move down
	{
		return down;
	}
}

