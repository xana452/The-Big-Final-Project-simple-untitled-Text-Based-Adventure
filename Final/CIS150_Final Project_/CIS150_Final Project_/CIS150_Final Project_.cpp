// CIS150_Final Project_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

//Dan Curley
//Sebastian Newbold
//Joshua Salkeld

//                                                        NOTES																	  //
//================================================================================================================================//
//system("Color 4"); Example text color change.																				      //
//system("Color 4F"); Example background and text color change.																      //
//http://blockofcodes.blogspot.com/2013/06/how-to-change-text-color-of-cc-console.html										      //
//================================================================================================================================//																																																							


string CaptainQuarters(string &location, bool Sword)
{
	return "Temp";//Replace later
}

string Armory(string &Location, bool Sword)
{
	const int ROWS = 3, COLS = 3;
	int playerAt[1][1];

	return "Temp";//Replace later
}


string LockedDoor(string &Location)
{
	return "Temp";//Replace later
}


string Hallway1(string &Location, bool Sword)
{
	int getChoice;
	int check = 0;
	int check2 = 0;

	//Intro written by Dan Curley.
	cout << "You take a tentative step into the dark, dank hallway." << endl;
	cout << "Torches line the overhead trim, singing what little moss and mold has grown around the crown. " << endl << endl;
	cout << "Cells of your fellow inmates, deserving or not, line the hall on either side of you. It is cold here. You look around." << endl << endl;

	cout << "On your left you see a wall. To your right, the hallway stretches on a short length." << endl;



	while (check == 0)
	{
		cout << "Press 1 to go left. ";
		cout << "Press 2 to go right. ";
		cin >> getChoice;

		if (getChoice == 1)
		{
			cout << "That's a dead end! ";
			check == 0;
		}
		if (getChoice == 2)
		{
			cout << "You come upon a three-way split in your path." << endl << endl;
			cout << "On your left is the Quarters to the Captain of the Guard." << endl << endl; //describe Captain after you get into the room. 
			cout << "On your right lay the aromory. You may need to get in there." << endl << endl;
			cout << "Straight ahead of you is your first step to freedom. It is also your first obstacle. The thick oaken door is locked tight." << endl << endl;

			
			//End DC

			//Written By Joshua Salkeld 
			while (check2 == 0) {
				cout << "Press 1 to sneak into the Captain's quarters." << endl;
				cout << "Press 2 to try the LOCKED door." << endl;
				cout << "Press 3 to sneak into the Armory." << endl;
				cin >> getChoice;
				if (getChoice == 1)
				{
					if (Sword) //if player has a sword go to Captain quarters function
					{
						CaptainQuarters(Location, Sword); 
					}
					else
					{
						cout << "It might not be the best idea to test the captian. He may be sleeping, but having a weapon would definitly help." << endl << endl;
					}
				}
				if (getChoice == 2)
				{
					cout << "The door leading out of the prison appears to be LOCKED. Maybe the captain will have a key to unlock it." << endl << endl;
				}
				if (getChoice == 3) 
				{
					Armory(Location, Sword); //paths continues in Armory function
					check2 = 1; //these stop the while loops and let the program continue once the player is on the right path
					check = 1;
				}
			}
			//End JS 
		}
		
	}


	

	return Location;
}

//"First level" functions outlined by Dan Curley. 
string StartingCell(string &Location, bool Sword)
{
	const int ROWS = 1, COLS = 1;
	int playerAt[ROWS][COLS];
	int getChoice = 1;
	Location == "StartingCell";

	//If 
	while (getChoice == 1)
	{

		system("cls");
		cout << "You awaken in your dark cell, eager with the knowledge that today you break the chains of your bondage." << endl;
		cout << "Press 1 to go back to sleep. You don't have time to deal with this today." << endl;
		cout << "Press 2 to grab the lockpick from under your pillow and bust out." << endl;
		//Written by Sebastian Newbold

		cin >> getChoice;

		if (getChoice == 1)
		{
			system("cls");
			system("Color 80");//Gray screen color
			Sleep(2300);
			system("Color 07");//Normal screen color
		}
		else if (getChoice == 2)
		{
			Location == "Hallway1";
			Hallway1(Location, Sword);

			return Location;
		}
	}
	//End SN



}









int main()
{
	string Location = "StartingCell";
	static int PlayerHealth = 10;
	bool Sword = false;


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

	StartingCell(Location, Sword);




	system("pause");
	return 0;
}

