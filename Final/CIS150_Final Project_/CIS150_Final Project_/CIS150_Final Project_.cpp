// CIS150_Final Project_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "windows.h"
#include <ctime>

using namespace std;

//Dan Curley
//Sebastian Newbold
//Joshua Salkeld

//                                                            NOTES									        				      //
//================================================================================================================================//
//																																  //
//																																  //
//================================================================================================================================//

//Updated input checks written by Sebastian Newbold

string Armory(string &, bool, int);

void PlayerDeath()
{

}

// Battle System Written by Joshua  Salkeld
void battleGuard(string &Location, bool Sword, int PlayerHealth)
{
	int GuardHealth = 5;
	const int maxDamage = 3;
	int MissChance = 100;
	int playerMiss;
	int guardMiss;
	string getChoice;
	int Damage;
	cout << "You draw your sword and face the guard." << endl << endl;
	Sleep(5000);
	while (PlayerHealth > 0)
	{
		while (GuardHealth > 0) 
		{
			system("cls");
			Sleep(650);
			cout << "You have " << PlayerHealth << " health remaining." << endl << endl;
			Sleep(2000);
			cout << "Press 1 to swing at the guard." << endl << endl;
			Sleep(900);
			cout << "Press 2 to Defend." << endl << endl;
			Sleep(900);
			getline(cin, getChoice);

			if (getChoice.at(0) == '1')
			{
				cout << "You swing you sword at the guard." << endl << endl;
				Sleep(2000);
				MissChance = 100;
				Damage = (rand() % maxDamage) + 1;
				playerMiss = (rand() % MissChance);
				if (playerMiss < 25) //25% chance to miss
				{
					cout << "Your sword collides with the guards armor dealing no damage. You missed." << endl << endl;
					Sleep(2000);
				}
				else
				{
					cout << "Your sword collides with the guard. You deal " << Damage << " damage." << endl << endl;
					Sleep(2000);
					GuardHealth = GuardHealth - Damage; //calc guard health

					if (GuardHealth <= 0)
					{
						break;
					}
				}
			} 
			else if (getChoice.at(0) == '2')
			{
				cout << "You bring your sword up and get ready for the guards attack." << endl << endl;
				Sleep(2000);
				MissChance = 50;
			}
			else
			{
				system("cls");
				Sleep(650);
			}

			cout << "The guard swings at you." << endl << endl;
			Sleep(2000);
			Damage = (rand() % maxDamage) + 1; //Damage is between 1 and 4
			guardMiss = (rand() % MissChance);
			if (guardMiss < 25)
			{
				cout << "The guard swings wide and misses you." << endl << endl;
				Sleep(2000);
			}
			else 
			{
				cout << "The guards sword collides with your chest dealing " << Damage << " damage." << endl << endl;
				Sleep(2000);
				PlayerHealth = PlayerHealth - Damage; //calculate player health
			}

		}
		cout << "You watch as the guards body goes limp and hits the floor." << endl << endl;
		break;
	}
	if (PlayerHealth <= 0)
	{
		PlayerDeath();
	}
	else
	{
		//change up hallway 1 to include going back after fight
	}
}
// End JS

string CaptainQuarters(string &location, bool Sword, int PlayerHealth)
{
	return "Temp";//Replace later
}




string LockedDoor(string &Location)
{
	return "Temp";//Replace later
}


string Hallway1(string &Location, bool Sword, int PlayerHealth)
{
	string getChoice;
	int check = 0;
	int check2 = 0;
	bool badInput = 1;

	system("cls");

	while (check == 0)
	{//While check = 0 start

		while (badInput == 1)
		{
			//Intro written by Dan Curley.
			cout << "You take a tentative step into the dark, dank hallway." << endl << endl;
			Sleep(1300);
			cout << "Torches line the overhead trim, singeing what little moss and mold has grown around the crown. " << endl << endl;
			Sleep(1800);
			cout << "Cells of your fellow inmates, deserving or not, line the hall on either side of you. It is cold here. You look around." << endl << endl;
			Sleep(2000);
			cout << "On your left you see a wall. To your right, the hallway stretches on a short length." << endl << endl;
			Sleep(1700);


			cout << "Press 1 to go left. " << endl;
			Sleep(900);
			cout << "Press 2 to go right. " << endl;
			Sleep(900);
			badInput = 0;
			getline(cin, getChoice);

			if (getChoice.at(0) == '1')
			{
				cout << "That's a dead end! ";
				Sleep(1300);
				badInput = 1;//Puts it in the same loop as badInput.
				system("cls");
			}
			else if (getChoice.at(0) == '2') {
			}
			else
			{
				badInput = 1;
				system("cls");
				Sleep(650);
			}
		}

		//End DC
		badInput = 1;
		//Written By Joshua Salkeld 
		while (check2 == 0 || badInput == 1)
		{
			system("cls");
			cout << "You come upon a three-way split in your path." << endl << endl;
			Sleep(1300);
			cout << "On your left is the Quarters to the Captain of the Guard." << endl << endl; //describe Captain after you get into the room. 
			Sleep(1500);
			cout << "On your right lay the armory. You may need to get in there." << endl << endl;
			Sleep(1540);
			cout << "Straight ahead of you is your first step to freedom. It is also your first obstacle. The thick oaken door is locked tight." << endl << endl;
			Sleep(2250);

			cout << "Press 1 to sneak into the Captain's quarters." << endl;
			Sleep(900);
			cout << "Press 2 to try the LOCKED door." << endl;
			Sleep(900);
			cout << "Press 3 to sneak into the Armory." << endl;
			Sleep(900);


			badInput = 0;
			getline(cin, getChoice);

			if (getChoice.at(0) == '1')
			{
				if (Sword) //if player has a sword go to Captain quarters function
				{
					system("cls");
					CaptainQuarters(Location, Sword, PlayerHealth);
				}
				else
				{
					system("cls");
					cout << "It might not be the best idea to test the captian. He may be sleeping, but having a weapon would definitely help." << endl << endl;
					Sleep(2300);
				}
			}
			else if (getChoice.at(0) == '2')
			{
				system("cls");
				cout << "The door leading out of the prison appears to be LOCKED. Maybe the captain will have a key to unlock it." << endl << endl;
				Sleep(2150);
			}
			else if (getChoice.at(0) == '3')
			{
				check2 = 1; //these stop the while loops and let the program continue once the player is on the right path
				check = 1;
				Armory(Location, Sword, PlayerHealth); //paths continues in Armory function
			}
			//End JS 
			else
			{
				badInput = 1;
				system("cls");
				Sleep(650);
			}
		}

	}
	//While check = 0 end
	return Location;
}

string Armory(string &Location, bool Sword, int PlayerHealth)
{
	system("cls");

	string getChoice;
	int check = 0;
	int check2 = 0;
	bool badInput = 1;
	Location = "Armory";

	while (check == 0)
	{
		while (badInput == 1)
		{
			//Armory written by Dan Curley
			const int ROWS = 3, COLS = 3;
			int playerAt[3][2];

			cout << "You creep into the Armory. Swords line the walls, gently reflecting the dull light of the torches." << endl << endl;
			Sleep(2300);
			cout << "You may need something to aid you in your escape. That something may need to be able to kill." << endl << endl;
			Sleep(900);

			cout << "Press 1 to take a sword from the wall." << endl << endl;
			Sleep(900);
			cout << "Press 2 to return to the hallway." << endl << endl;
			Sleep(900);

			badInput = 0;
			getline(cin, getChoice);
			// END DC

			//Second Part of Armory written by Joshua Salkeld
			if (getChoice.at(0) == '1')
			{
				system("cls");
				Sword = true;
				cout << "You make your way to the back wall and grab a sword off of it. It's nothing fancy but it will do for now." << endl << endl;
				Sleep(1200);
				cout << "Glanicing around, everything else in this room is too either too heavy or not useful enough to take with you in your escape." << endl << endl;
				Sleep(1200);
				cout << "You head out of the armory. Now to open that door." << endl << endl;
				Sleep(900);
				cout << "As you walk out of the armory you see a guard down the hall towards you. He sees you exit and draws his sword" << endl << endl;
				Sleep(1200);
				cout << "He yells over his shoulder: We have an escapped prison in the armory. You both walk towards each other, battle seems inevitable." << endl << endl;
				Sleep(1000);
				battleGuard(Location, Sword, PlayerHealth);
			}
			//end JS

			//Written by Dan Curley
			else if (getChoice.at(0) == '2')
			{
				Hallway1(Location, Sword, PlayerHealth);
			}
			else
			{
				badInput = 1;
				system("cls");
				Sleep(650);
			}
			//End DC

			//Written by Joshua Salkeld

			/// Continue after Battle
		}
	}

	return Location;
}
//End DC
//"First level" functions outlined by Dan Curley. 
string StartingCell(string &Location, bool Sword, int PlayerHealth)
{
	const int ROWS = 1, COLS = 1;
	int playerAt[ROWS][COLS];
	string getChoice = "1";
	bool badInput = 1;
	Location = "StartingCell";


	while (getChoice.at(0) == '1' || badInput == 1)
	{
		badInput = 0;
		system("cls");
		cout << "You awaken in your dark cell, eager with the knowledge that today you break the chains of your bondage." << endl << endl;
		Sleep(1900);
		cout << "Press 1 to go back to sleep. You don't have time to deal with this today." << endl;
		Sleep(900);
		cout << "Press 2 to grab the lockpick from under your pillow and bust out." << endl;
		Sleep(900);

		//Written by Sebastian Newbold
		getline(cin, getChoice);

		if (getChoice.at(0) == '1')
		{
			system("cls");
			system("Color 80");//Gray screen color
			Sleep(2300);
			system("Color 07");//Normal screen color
		}
		else if (getChoice.at(0) == '2')
		{
			Location = "Hallway1";
			Hallway1(Location, Sword, PlayerHealth);

			return Location;
		}
		else
		{
			badInput = 1;
			system("cls");
			Sleep(650);
		}

	}
	//End SN



}





int main()
{
	string Location = "StartingCell";
	static int PlayerHealth = 10;
	bool Sword = false;
	srand(time(NULL));

	//Start intro screen thing by: Dan Curley
	cout << "=======================================================================" << endl;
	cout << "=                                                                     =" << endl;
	cout << "=                              PROJECT BY                             =" << endl;
	cout << "=                           THE         GRUES                         =" << endl;
	cout << "=                                                                     =" << endl;
	cout << "=                                                                     =" << endl;
	cout << "=                                                                     =" << endl;
	cout << "=======================================================================" << endl;
	Sleep(6000);
	system("cls");
	//End DC
	StartingCell(Location, Sword, PlayerHealth);




	system("pause");
	return 0;
}