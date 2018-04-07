/***************************************************************************
 * Program: dungeon
 * Author: Ron Walters
 * Date: 3/20/18
 * Description: This is the functional description of the hallway space for
 * the dungeon program
 * ************************************************************************/
#include "hallway.hpp"

//Default constructor for hallway sets name, description and tasks
Hallway::Hallway()
{
	desc = "You enter a long hallway, with a statue standing in the middle.\nAround the base of the statue, a lever sits in each of the 4\ncardinal directions.";
	name = "Hallway";
	statue = false;
	key = true;
	potion = true;
	lev1 = false;
	lev2 = true;
	lev3 = true;
	lev4 = false;
	
}

//Function to allow user to interact with tasks of room
void Hallway::interact(Character &player)
{	
	int choice;
	char opt;
	
	//Prompt user for which item they would like to interact with
	cout << "\nWhat would you like to interact with?" << endl;
	cout << "1. Statue\n";
	cout << "2. Switch 1\n";
	cout << "3. Switch 2\n";
	cout << "4. Switch 3\n";
	cout << "5. Switch 4" << endl;

	cin >> choice;

	//Input validation
	while (choice < 1 || choice > 5 || cin.fail())
	{
		cout << "\nError. Please enter a valid choice below" << endl;
		cout << "1. Statue\n";
		cout << "2. Switch 1\n";
		cout << "3. Switch 2\n";
		cout << "4. Switch 3\n";
		cout << "5. Switch 4" << endl;

		cin.clear();
		cin.ignore(10000, '\n');
		cin >> choice;
	}

	switch (choice)
	{
		case 1: //User chooses to interact with statue
			if (key && !lev1 && lev2 && !lev3 && lev4)
			//Switches are  Off -  On -  Off - On (Key solution)
			{
				cout << "\nA shiny golden key lays in the statue's";
				cout << " open mouth. Take it(Y/N)?" << endl;
				
				cin.ignore(10000, '\n');
				cin >> opt;

				//input validation
				while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
				{
					cout << "Error. Please enter Y or N" << endl;
	
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> opt;
				}

				if (opt == 'y' || opt == 'Y') //User says yes, add key to bag
				{
					cout << "\nYou add the key to your bag" << endl;
					player.addItem("key");
					key = false;

					//If both solutions have been found, statue is complete
					if (!potion)
					{
						statue = true;
					}
				}
				else //Leave key in statue's mouth
				{
					cout << "\nYou leave the key in place" << endl;
				}
			}
			else if (potion && lev1 && !lev2 && lev3 && !lev4)
			//Switches are On - Off - On - Off (Potion solution)
			{
				cout << "\nA juicy potion lays in the statue's ";
				cout << "open mouth. Take it(Y/N)?" << endl;
				
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> opt;

				//Input validation
				while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
				{
					cout << "Error. Please enter Y or N" << endl;
	
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> opt;
				}

				if (opt == 'y' || opt == 'Y') //User says yes, add potion to bag
				{
					cout << "\nYou add the potion to your bag" << endl;
					player.addItem("hpot");
					potion = false;

					//If both solutions have been found, statue is complete
					if (!key)
					{
						statue = true;
					}
				}
				else // Leave the potion in statue's mouth
				{
					cout << "\nYou leave the potion in place" << endl;
				}
			}
			else if (!statue) //If statue is not complete, give hint to solutions
			{
				cout << "\nYou see shiny objects from ";
				cout << "within the statues 2 eyes. The ";
				cout << "first and third slot of its mask";
				cout << " are sealed shut." << endl;
			}
			else 	//Statue is complete, nothing left to get
			{
				cout << "\nYou see nothing left in the statue." << endl;
			}
			player.hurt(1);
			break;
		case 2: //User interacts with switch 1
			if (lev1) //Switch is currently on
			{
				cout <<"\nThis switch is currently on. Turn it off(Y/N)?" << endl;
				
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> opt;

				//Input validation
				while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
				{
					cout << "Error. Please enter Y or N" << endl;
	
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> opt;
				}

				if (opt == 'y' || opt == 'Y') 	//User changes switch direction
				{
					cout << "\nYou push the switch to off" << endl;
					lev1 = false;

					//If switch leads to a solution, let user know
					if (lev2 && !lev3 && lev4)	
					{
						cout << "\nA rumble comes from the statue" << endl;
					}
				}
				else 	//User doesn't change switch position
				{
					cout << "\nYou leave the switch in place" << endl;
				}
			}
			else	//Switch is currently off
			{
				cout <<"\nThis switch is currently off. Turn it on(Y/N)?" << endl;
				
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> opt;

				//Input validation
				while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
				{
					cout << "Error. Please enter Y or N" << endl;
	
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> opt;
				}

				if (opt == 'y' || opt == 'Y')	//User changes switch to off
				{
					cout << "\nYou push the switch to on" << endl;
					lev1 = true;

					//If switch leads to a solution, let user know
					if (!lev2 && lev3 && !lev4)
					{
						cout << "\nA rumble comes from the statue" << endl;
					}
				}
				else	//User doesn't change switch position
				{
					cout << "\nYou leave the switch in place" << endl;
				}
			}
			player.hurt(1);
			break;
		case 3:	//User interacts with Switch 2
			if (lev2)	//Switch is on
			{
				cout <<"\nThis switch is currently on. Turn it off(Y/N)?" << endl;
				
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> opt;

				//Input validation
				while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
				{
					cout << "Error. Please enter Y or N" << endl;
	
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> opt;
				}

				if (opt == 'y' || opt == 'Y') //If user says yes, move switch to off
				{
					cout << "\nYou push the switch to off" << endl;
					lev2 = false;

					//If switch leads to a solution, let user know
					if (lev1 && lev3 && !lev4)
					{
						cout << "\nA rumble comes from the statue" << endl;
					}
				}
				else	//User doesn't change switch position
				{
					cout << "\nYou leave the switch in place" << endl;
				}
			}
			else	//Switch is off
			{
				cout <<"\nThis switch is currently off. Turn it on(Y/N)?" << endl;
				
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> opt;

				//Input validation
				while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
				{
					cout << "Error. Please enter Y or N" << endl;
	
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> opt;
				}

				if (opt == 'y' || opt == 'Y') //user says yes, switch to on
				{
					cout << "\nYou push the switch to on" << endl;
					lev2 = true;

					//If switch leads to a solution, let user know
					if (!lev1 && !lev3 && lev4)
					{
						cout << "\nA rumble comes from the statue" << endl;
					}
				}
				else // Leave switch in place
				{
					cout << "\nYou leave the switch in place" << endl;
				}
			}
			player.hurt(1);
			break;
		case 4://User interacts with switch 3
			if (lev3)	//Switch is on
			{
				cout <<"\nThis switch is currently on. Turn it off(Y/N)?" << endl;
				
				cin.clear();	
				cin.ignore(10000, '\n');
				cin >> opt;

				//Input validation
				while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
				{
					cout << "Error. Please enter Y or N" << endl;
	
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> opt;
				}

				if (opt == 'y' || opt == 'Y') //User says yes, move switch to off
				{
					cout << "\nYou push the switch to off" << endl;
					lev3 = false;

					//If switch leads to a solution, let user know
					if (!lev1 && lev2 && lev4)
					{
						cout << "\nA rumble comes from the statue" << endl;
					}
				}
				else	//Leave switch in place
				{
					cout << "\nYou leave the switch in place" << endl;
				}
			}
			else	//Switch is off
			{
				cout <<"\nThis switch is currently off. Turn it on(Y/N)?" << endl;
				
				cin.clear();	
				cin.ignore(10000, '\n');
				cin >> opt;

				//Input validation
				while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
				{
					cout << "Error. Please enter Y or N" << endl;
	
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> opt;
				}

				if (opt == 'y' || opt == 'Y') //User says yes, move switch to on
				{
					cout << "\nYou push the switch to on" << endl;
					lev3 = true;

					//If switch leads to a solution, let user know.
					if (lev1 && !lev2 && !lev4)
					{
						cout << "\nA rumble comes from the statue" << endl;
					}
				}
				else	//Leave switch in place
				{
					cout << "\nYou leave the switch in place" << endl;
				}
			}
			player.hurt(1);
			break;

		case 5:	//User interacts with switch 4
			if (lev4)	//Switch is on
			{
				cout <<"\nThis switch is currently on. Turn it off(Y/N)?" << endl;
				
				cin.clear();	
				cin.ignore(10000, '\n');
				cin >> opt;

				//Input validation
				while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
				{
					cout << "Error. Please enter Y or N" << endl;
	
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> opt;
				}

				if (opt == 'y' || opt == 'Y')	//User says yes, move switch to off
				{
					cout << "\nYou push the switch to off" << endl;
					lev4 = false;

					//If switch leads to a solution, let user know
					if (lev1 && lev3 && !lev2)
					{
						cout << "\nA rumble comes from the statue" << endl;
					}
				}
				else	//Leave switch in place
				{
					cout << "\nYou leave the switch in place" << endl;
				}
			}
			else	//Switch is off
			{
				cout <<"\nThis switch is currently off. Turn it on(Y/N)?" << endl;
			
				cin.clear();	
				cin.ignore(10000, '\n');
				cin >> opt;

				//Input validation
				while (opt != 'n' && opt != 'N' && opt != 'y' && opt != 'Y')
				{
					cout << "Error. Please enter Y or N" << endl;
	
					cin.clear();
					cin.ignore(10000, '\n');
					cin >> opt;
				}

				if (opt == 'y' || opt == 'Y')	//User says yes, move switch to on
				{
					cout << "\nYou push the switch to on" << endl;
					lev4 = true;

					//If switch leads to a solution, let user know.
					if (!lev1 && !lev3 && lev2)
					{
						cout << "\nA rumble comes from the statue" << endl;
					}
				}
				else	//Leave switch in place
				{
					cout << "\nYou leave the switch in place" << endl;
				}
			}
			player.hurt(1);
			break;
	}
}


//Function to let user move to other rooms
Space* Hallway::move(Space* pointer)
{
	int choice;

	//Prompt user for direction to go
	cout << "\nWhich direction would you like to go?" << endl;
	cout << "1. Right (Barracks)\n";
	cout << "2. Down (Kitchen)\n";	
	cin >> choice;

	//Input validation
	while (choice < 1 || choice > 2 || cin.fail())
	{
		cout << "\nError. Please select from below" << endl;
		cout << "1. Right (Barracks)\n";
		cout << "2. Down (Kitchen) \n";

		cin.clear();
		cin.ignore(10000, '\n');
		cin >> choice;
	}

	if (choice == 1)	//User selects east, print description and move east
	{	
		right->printDesc();
		return right;
	}
	else			//User selects south, move south
	{
		return down;
	}

}
