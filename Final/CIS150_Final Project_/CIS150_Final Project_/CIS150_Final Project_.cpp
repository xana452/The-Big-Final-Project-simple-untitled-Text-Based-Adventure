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



//"First level" functions outlined by Dan Curley. 
string StartingCell(string &Location)
{
	const int ROWS = 1, COLS = 1;
	int playerAt[ROWS][COLS];
	int getChoice = 1;


	
	while (getChoice == 1)
	{
		cout << "You awaken in your dark cell, eager with the knowledge that today you break the chains of your bondage." << endl;
		cout << "Press 1 to go back to sleep. You don't have time to deal with this today." << endl;
		cout << "Press 2 to grab the lockpick from under your pillow and bust out." << endl;

		cin >> getChoice;

		if (getChoice == 1)	{
			getChoice = 1;
		}
		else if (getChoice == 2)
		{
			Hallway1(Location);
		}
	}
	

	

}

string Hallway1(string &Location)
{

}

string CaptainQuarters(string &location)
{

}

string Armory(string &Location)
{
	const int ROWS = 3, COLS = 3;
	int playerAt[1][1];


}


string LockedDoor(string &Location)
{

}






















int main()
{
	string Location;
	static int PlayerHealth = 10;


	//Start intro screen thing by: Dan Curley
	cout << "=======================================================================" << endl;
	cout << "=                                                                      ="<< endl;
	cout << "=                                 PROJECT BY                           =" << endl;
	cout << "=                              THE         GRUES                       =" << endl;
	cout << "=                                                                      =" << endl; 
	cout << "=                                                                      =" << endl;
	cout << "=                                                                      =" << endl;
	cout << "=======================================================================" << endl;
	Sleep(6000);
	system("cls");
	//End DC
	
	StartingCell(Location);




	system("pause");
    return 0;
}

