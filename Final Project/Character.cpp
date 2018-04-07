/****************************************************************************
 * Program: dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the functional description of the character class.
 * This class contains all of the functions related to the characters stats
 * and their bag
 * **************************************************************************/
#include "Character.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

//Default constructor, sets the characters stats
Character::Character()
{
	strength = 1;
	health = 30;
	win = false;
}

//Function to add items to bag
void Character::addItem(string item)
{
	if (bag.size() < 3)	//Check if bag is full. If not, add item
	{
		bag.push_back(item);
	}
	else	//If bag full, ask user if they would like to remove an item
	{
		cout << "Error. Bag is full. Remove item (Y/N)? ";
		char rem;
		cin >> rem;

		//input validation
		while (rem != 'n' && rem != 'N' && rem != 'y' && rem != 'Y')
		{
			cout << "Error. Please select Y or N. ";
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> rem;
		}
		
		if (rem == 'y' || rem == 'Y') //If user says yes
		{
			//print list of items currently in bag
			for (int x = 0; x < bag.size(); x++)
			{
				cout << x+1 << ". " << bag[x] << endl;
			}

			int del;
		
			//ask user which they would like to remove
			cout << "Which would you like to delete? ";
			cin >> del;

			//Input validation
			while (del < 1 || del > bag.size() || cin.fail())
			{
				cout << "Error. Please select from below\n";
				
				for (int x = 0; x < bag.size(); x++)
				{
					cout << x+1 << ". " << bag[x] << endl;
				}
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> del;
			}
			
			bag.erase(bag.begin() + del-1); // remove item
			bag.push_back(item);		//add new item
		}
	}
}

//Function to print out contents currently in bag
void Character::printBag()
{
	for (int x = 0; x < bag.size(); x++)
	{
		cout << x+1 << ". " << bag[x] << endl;
	}
}

//Function to remove item from the bag
void Character::removeItem(string item)
{
	for (int x = 0; x < bag.size(); x++)
	{
		if (bag[x] == item)
		{
			bag.erase(bag.begin() + x);
			x = bag.size()-1;
		}
	}
}

//Function to check if an item is in the bag
bool Character::findItem(string item)
{
	bool found = false; //initially not found

	//cycle through bag
	for (int x = 0; x < bag.size(); x++)
	{
		if (bag[x] == item) //item found
		{
			found = true;
		}
	}
	
	return found; //says whether item is found
}

//Function to deal damage to player
void Character::hurt(int dmg)
{
	health -= dmg;
}

//Function to heal player
void Character::heal(int dmg)
{
	health += dmg;
}

//Function to get current health
int Character::getHealth()
{
	return health;
}			

//Function to return characters current strength
int Character::getStrength()
{
	return strength;
}

//Function to add strength, used for strength potion
void Character::addStrength(int str)
{
	strength += str;
}

//Function to use a healing potion
void Character::usePotion()
{
	if (health == 30) //Check if users health is already full
	{
		cout << "You're already at full health!" << endl;
	}
	else if (!findItem("hpot"))//Check if user has a potion
	{
		cout << "You have no potions to use." << endl;
	}
	else
	{
		cout << "You drink down the potion and ";
		cout << "feel rejuvinated." << endl;
		health += 10; // add health to user
		if (health > 30) // if health goes over max
		{
			health = 30; //set health to max
		}
		removeItem("hpot"); // remove potion from bag
	}
}

//Function to say character won
void Character::setWin()
{
	win = true;
}

//Function to see if character has won
bool Character::getWin()
{
	return win;
}
