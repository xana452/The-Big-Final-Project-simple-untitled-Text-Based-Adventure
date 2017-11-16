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
//http://blockofcodes.blogspot.com/2013/06/how-to-change-text-color-of-cc-console.html											  //
//																																  //
//																																  //
//================================================================================================================================//																																																							

//Updated input checks written by Sebastian Newbold + small edits


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
			else if (getChoice.at(0) == '2')
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
					CaptainQuarters(Location, Sword);
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
				Armory(Location, Sword); //paths continues in Armory function
				check2 = 1; //these stop the while loops and let the program continue once the player is on the right path
				check = 1;
			}
			//End JS 
			else
			{
				badInput = 1;
				system("cls");
				Sleep(650);
			}
		}
		
	}//While check = 0 end
	return Location;
}

//"First level" functions outlined by Dan Curley. 
string StartingCell(string &Location, bool Sword)
{
	const int ROWS = 1, COLS = 1;
	int playerAt[ROWS][COLS];
	string getChoice = "1";
	bool badInput = 1;
	Location == "StartingCell";


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
			Location == "Hallway1";
			Hallway1(Location, Sword);

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

