/***************************************************************************
 * Program: Dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the functional description for the entrance space class
 * which is the first room of the dungeon
 * **************************************************************************/
#include "entrance.hpp"

//Default constructor to set name, description, and events in entrance
Entrance::Entrance()
{
	desc = "You find yourself in a damp cavern, lit only by torchlight.\nAt the far end of the cavern you see a closed door next to\nan unlit brazier.";
	name = "Entrance";
	torch = false;
	brazier = false;
	door = false;
	
}

//Function to give user choices of how they want to interact with the entrance
void Entrance::interact(Character &player)
{
	int choice;

	//Give user options of what to interact with
	cout << "\nWhat would you like to interract with?" << endl;
	cout << "1. Torch on wall\n";
	cout << "2. Brazier\n";
	cout << "3. Door" << endl;
	
	cin >> choice;

	//Input validation
	while (choice < 1 || choice > 3 || cin.fail())
	{
		cout << "\nError. Please enter valid option below." << endl;
	
		cout << "1. Torch on wall\n";
		cout << "2. Brazier\n";
		cout << "3. Door" << endl;
	
		cin.clear();
		cin.ignore(10000,'\n');
		cin >> choice;
	}

	switch (choice)
	{
		case 1: //Interacting with torch
			if (!torch)//If torch hasn't been taken
			{
				cout << "\nYou take a torch from the wall. One of the ";
				cout << "embers hits you in the eye." << endl;
				torch = true;
				player.addItem("torch");
				player.hurt(1);
			}
			else //If torch has been taken
			{
				cout << "\nYou already have a torch!";
				cout << " You burn yourself trying to grab another" <<endl;
				player.hurt(2);
			}
			break;
		case 2://Interacting with Brazier
			if (brazier) //If brazier is already lit by torch
			{
				cout << "\nThe brazier is already lit! You burn ";
				cout << "your hand trying to light it again." << endl;
				player.hurt(2);
			}
			if (torch)//If brazier hasn't been lit, and user has torch light it
			{
				cout << "\nYou light the brazier with your torch.";
				cout << " A rumble comes from the door" << endl;
				brazier = true;
				player.hurt(1);
			}
			else //If brazier hasn't been lit and user doesn't have torch
			{
				cout << "\n The brazier is full of coals. As you ";
				cout << "reach inside you are poked by a shard ";
				cout << "of glass." << endl;
				player.hurt(1);
			}
			break;
		case 3://Interaction with door
			if (door)//Door has been opened already
			{
				cout << "\nYou try to close the door, but pinch ";
				cout << "your finger in the process." << endl;
				player.hurt(1);
			}
			else if (brazier)//If brazier has been lit
			{
				cout << "\nYou slide open the door with ease." << endl;
				door = true;
				player.hurt(1);
			}
			else //If brazier hasn't been lit yet
			{
				cout << "\nThe door won't budge! You strain a muscle ";
				cout << "trying to force it open" << endl;
				player.hurt(1);
			}
	}
}

//Function to allow user to move from entrance
Space* Entrance::move(Space* pointer)
{
	int choice;
	

	//Prompt user for where to go
	cout << "\nWhere would you like to move to?" << endl;
	cout << "1. up (Armory)" << endl;
	cin >> choice;

	//Input validation
	while (choice != 1 || cin.fail())
	{
		cout << "\nError. Please select from below." << endl;
		cout << "1. up (Armory)" << endl;
	}
	
	//If door has not been opened yet
	if (!door)
	{
		cout << "\nThe door is still closed!" << endl;
		return pointer;	
	}
	else 	//if door has been opened, print description of next area and move
	{
		up->printDesc();
		return up;
	}
}
