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


//======================================================================================================================
//THIS CODE WAS FOUND ANS WRITTEN BY ERIK ENGLISH CIS150-02.  
//Code found from cplusplus.com: SOURCE: http://www.cplusplus.com/forum/beginner/105484/ ; User: Giblit
enum COLOR
{
	black, blue,
	green, cyan,
	red, magenta,
	brown, normal,
	darkgrey, lightblue,
	lightgreen, lightcyan,
	lightred, lightmagenta,
	yellow, white
};


//Not entirely sure what this does but is necessary for coloring text.
ostream& operator<<(ostream &stm, const COLOR &c)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out_handle, c);
	return(stm);
}
//End of found code from cplusplus.com
//END OF ERIK'S CODE
//=============================================================================================================================



//Random edits throughout program written by Sebastian Newbold



string Armory(string &, bool, int, bool, bool, bool &, bool, bool);
string Hallway1(string &, bool, int, bool, bool, bool, bool, bool);
string LockedDoor(string &, bool &, bool &, int &, bool, bool, bool);
string Smith(string &, int &, bool &, bool &, bool &, bool &);
string Clothes(string &, int &, bool &, bool &, bool &, bool &);
string AlcShop(string &, int &, bool &, bool &, bool &, bool &);
string Inn(string &, int &, bool &, bool &, bool &, bool &, bool, bool);

void PlayerDeath();
void pressEnter();
void tempFunc(string &, bool &, int &, bool &, bool, bool); //This is a function for error checking
void townMap(string &, bool &, int &, bool &, bool, bool);

//Functions: Inn, Smith, Clothes, AlcShop, Prison Outlined by Joshua Salkeld

//Map written by Joshua Salkeld, Everything else by Dan Curley
string Inn(string &Location, int &PlayerHealth, bool &Sword, bool &SwordLv2, bool &Clothes, bool &CaptainDead, bool WarStory5, bool WarStory10)
{
	int i = 0;
	int x = 0;
	bool test = true;
	char PlayerIcon = 'P';
	char move;
	char talk;
	static int playerVert = 18;
	static int PlayerHoriz = 9;
	int PlayerTempVert;
	int PlayerTempHoriz;
	int Check;
	string getChoice;
	bool badInput = true;

	const int ROWS = 21, COLS = 20;

	char ClothesMap[ROWS][COLS] = {
		{ 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W', 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , 'I' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , '=' , '=' , '=' , '=' , ' ' , '-' , '-' , '-' , '/', '-' , '-' , ' ' , '=' , '=' , '=' , '=' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , '=' , '=' , '=' , '=' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '=' , '=' , '=' , '=' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , '=' , '=' , '=' , '=' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '=' , '=' , '=' , '=' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , '=' , '=' , '=' , '=' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '=' , '=' , '=' , '=' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'V' , 'V', 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' }
	};

	ClothesMap[playerVert][PlayerHoriz] = 'P';

	while (test)
	{
		while (x < 20)
		{
			if (i == 0 && x == 0)
			{
				system("cls");
			}
			cout << ClothesMap[x][i];
			i++;
			if (i == 20)
			{
				cout << endl;
				x++;
				i = 0;
			}

		}
		i = 0;
		x = 0;
		PlayerTempHoriz = PlayerHoriz;
		PlayerTempVert = playerVert;

		cout << "W, A, S, or D: ";
		cin >> move;

		if (move == 'w')
		{
			Check = playerVert - 1;

			if (ClothesMap[Check][PlayerHoriz] == 'W' || ClothesMap[Check][PlayerHoriz] == '|' || ClothesMap[Check][PlayerHoriz] == '-' || ClothesMap[Check][PlayerHoriz] == '/' || ClothesMap[Check][PlayerHoriz] == '=')
			{

			}
			else if (ClothesMap[5][9] == 'P')
			{
				cout << endl << "Would you like to talk to the Innkeep? (Y/N)";
				cin >> talk;
				if (talk == 'y' || talk == 'Y')
				{
					
				}
				else
				{
					ClothesMap[playerVert][PlayerHoriz] = ' ';
					playerVert = 6;
					PlayerHoriz = 9;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
				}
			}
			else
			{

				PlayerTempVert = playerVert;
				PlayerTempHoriz = PlayerHoriz;
				playerVert = playerVert - 1;
			}
		}
		else if (move == 'a')
		{
			Check = PlayerHoriz - 1;
			if (ClothesMap[Check][PlayerHoriz] == 'W' || ClothesMap[Check][PlayerHoriz] == '|' || ClothesMap[Check][PlayerHoriz] == '-' || ClothesMap[Check][PlayerHoriz] == '/' || ClothesMap[Check][PlayerHoriz] == '=')
			{

			}
			else if (ClothesMap[5][9] == 'P')
			{
				cout << endl << "Would you like to talk to the Innkeep? (Y/N)";
				cin >> talk;
				if (talk == 'y' || talk == 'Y')
				{
					while (badInput)
					{
						cout << "You approach the bar." << endl;
						Sleep(300);
						cout << "You are surprised to find the innkeeper up at this hour, though grateful nonetheless." << endl;
						Sleep(300);
						cout << " 'A pint of ale, please,' you request, your voice barely above a whisper. It seems rude to defile the silence of the Inn." << endl;
						Sleep(300);
						cout << "As the innkeeper turns to gather a glass, you spot a massive scar on the running along the back of his neck." << endl;
						Sleep(300);
						cout << "1. Remain Silent." << endl;
						cout << "2. 'What's the story behind that scar?'" << endl;

						getline(cin, getChoice);
						//Where ever the dialogue tree ends just make sure to put badinput = false; in it. That will break out of the loop and allow the game to continue.
						//Also this part is important! to simplify things for the player whenever the loop ends with badInput = false; you NEED to put tempFunc(Location, Sword, PlayerHealth, CaptainDead);
						//That will respawn the player outside the Inn. 
						if (getChoice.at(0) == '1')
						{
							cout << "You remain silent as the Innkeeper slides the Pint down the tabletop to your waiting hand." << endl;
							Sleep(300);
							badInput = false;
						}

						else if (getChoice.at(0) == '2')
						{
							cout << "Curiousity gets the better of you. 'Lose a fight with a wolf?' The innkeeper looks at you with a mildly amused smirk." << endl;
							Sleep(250);
							cout << "'No, actually. During the war all of those years ago, one of the King's thugs took a blade to my throat." << endl;
							Sleep(250);
							cout << "I managed to turn away just in time to save my own hide, but I took the brunt of the blow right there.' " << endl;
							Sleep(250);
							cout << "He turns again to show you the battlescar, more up close and personal." << endl;
						}
						else
						{
							badInput = true;
						}
					}
				}
				else
				{
					ClothesMap[playerVert][PlayerHoriz] = ' ';
					playerVert = 6;
					PlayerHoriz = 9;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
				}
			}
			else
			{
				PlayerTempHoriz = PlayerHoriz;
				PlayerTempVert = playerVert;
				PlayerHoriz = PlayerHoriz - 1;
			}
		}
		else if (move == 's')
		{
			Check = playerVert + 1;

			if (ClothesMap[Check][PlayerHoriz] == 'W' || ClothesMap[Check][PlayerHoriz] == '|' || ClothesMap[Check][PlayerHoriz] == '-' || ClothesMap[Check][PlayerHoriz] == '/' || ClothesMap[Check][PlayerHoriz] == '=')
			{

			}
			else if (ClothesMap[5][9] == 'P')
			{
				cout << endl << "Would you like to talk to the Innkeep? (Y/N)";
				cin >> talk;
				if (talk == 'y' || talk == 'Y')
				{
					while (badInput)
					{
						cout << "You approach the bar." << endl;
						Sleep(300);
						cout << "You are surprised to find the innkeeper up at this hour, though grateful nonetheless." << endl;
						Sleep(300);
						cout << " 'A pint of ale, please,' you request, your voice barely above a whisper. It seems rude to defile the silence of the Inn." << endl;
						Sleep(300);
						cout << "As the innkeeper turns to gather a glass, you spot a massive scar on the running along the back of his neck." << endl;
						Sleep(300);
						cout << "1. Remain Silent." << endl;
						cout << "2. 'What's the story behind that scar?'" << endl;

						getline(cin, getChoice);
						//Where ever the dialogue tree ends just make sure to put badinput = false; in it. That will break out of the loop and allow the game to continue.
						//Also this part is important! to simplify things for the player whenever the loop ends with badInput = false; you NEED to put tempFunc(Location, Sword, PlayerHealth, CaptainDead);
						//That will respawn the player outside the Inn. 
						if (getChoice.at(0) == '1')
						{
							cout << "You remain silent as the Innkeeper slides the Pint down the tabletop to your waiting hand." << endl;
							Sleep(300);
							badInput = false;
						}

						else if (getChoice.at(0) == '2')
						{
							cout << "Curiousity gets the better of you. 'Lose a fight with a wolf?' The innkeeper looks at you with a mildly amused smirk." << endl;
							Sleep(250);
							cout << "'No, actually. During the war all of those years ago, one of the King's thugs took a blade to my throat." << endl;
							Sleep(250);
							cout << "I managed to turn away just in time to save my own hide, but I took the brunt of the blow right there.' " << endl;
							Sleep(250);
							cout << "He turns again to show you the battlescar, more up close and personal." << endl;
						}
						else
						{
							badInput = true;
						}
					}
				}
				else
				{
					ClothesMap[playerVert][PlayerHoriz] = ' ';
					playerVert = 6;
					PlayerHoriz = 9;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
				}
			}
			else
			{

				PlayerTempVert = playerVert;
				PlayerTempHoriz = PlayerHoriz;
				playerVert = playerVert + 1;
			}

		}
		else if (move == 'd')
		{
			Check = PlayerHoriz + 1;
			if (ClothesMap[Check][PlayerHoriz] == 'W' || ClothesMap[Check][PlayerHoriz] == '|' || ClothesMap[Check][PlayerHoriz] == '-' || ClothesMap[Check][PlayerHoriz] == '/' || ClothesMap[Check][PlayerHoriz] == '=')
			{

			}
			else if (ClothesMap[5][9] == 'P')
			{
				cout << endl << "Would you like to talk to the Innkeep? (Y/N)";
				cin >> talk;
				if (talk == 'y' || talk == 'Y')
				{
					while (badInput)
					{
						cout << "You approach the bar." << endl;
						Sleep(300);
						cout << "You are surprised to find the innkeeper up at this hour, though grateful nonetheless." << endl;
						Sleep(300);
						cout << " 'A pint of ale, please,' you request, your voice barely above a whisper. It seems rude to defile the silence of the Inn." << endl;
						Sleep(300);
						cout << "As the innkeeper turns to gather a glass, you spot a massive scar on the running along the back of his neck." << endl;
						Sleep(300);
						cout << "1. Remain Silent." << endl;
						cout << "2. 'What's the story behind that scar?'" << endl;

						getline(cin, getChoice);
						//Where ever the dialogue tree ends just make sure to put badinput = false; in it. That will break out of the loop and allow the game to continue.
						//Also this part is important! to simplify things for the player whenever the loop ends with badInput = false; you NEED to put tempFunc(Location, Sword, PlayerHealth, CaptainDead);
						//That will respawn the player outside the Inn. 
						if (getChoice.at(0) == '1')
						{
							cout << "You remain silent as the Innkeeper slides the Pint down the tabletop to your waiting hand." << endl;
							Sleep(300);
							badInput = false;
						}

						else if (getChoice.at(0) == '2')
						{
							cout << "Curiousity gets the better of you. 'Lose a fight with a wolf?' The innkeeper looks at you with a mildly amused smirk." << endl;
							Sleep(250);
							cout << "'No, actually. During the war all of those years ago, one of the King's thugs took a blade to my throat." << endl;
							Sleep(250);
							cout << "I managed to turn away just in time to save my own hide, but I took the brunt of the blow right there.' " << endl;
							Sleep(250);
							cout << "He turns again to show you the battlescar, more up close and personal." << endl;
						}
						else
						{
							badInput = true;
						}
					}
				}
				else
				{
					ClothesMap[playerVert][PlayerHoriz] = ' ';
					playerVert = 6;
					PlayerHoriz = 9;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
				}
			}
			else
			{
				PlayerTempHoriz = PlayerHoriz;
				PlayerTempVert = playerVert;
				PlayerHoriz = PlayerHoriz + 1;
			}
		}
		else
		{

		}

		ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
		ClothesMap[playerVert][PlayerHoriz] = 'P';

	}

	return Location;
}
//End JS and DC


string Smith(string &Location, int &PlayerHealth, bool &Sword, bool &SwordLv2, bool &Clothes, bool &CaptainDead)
{

	return Location;
}


string Clothes(string &Location, int &PlayerHealth, bool &Sword, bool &SwordLv2, bool &Clothes, bool &CaptainDead)
{

	return Location;
}


string AlcShop(string &Location, int &PlayerHealth, bool &Sword, bool &SwordLv2, bool &Clothes, bool &CaptainDead)
{
	const int ROWS = 14, COLS = 13;

	char AlcMap[ROWS][COLS] = {
		{ 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' },
		{ 'W' , '=' , '=' , 'W' , '=' , '=' , '|' , '=' , '=' , '=' , '=' , ' ' , 'W' },//'='s are shelves
		{ 'W' , '=' , '=' , 'W' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , ']' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , '=' , 'W' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , '(' },
		{ 'W' , ' ' , '=' , 'W' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , '(' },
		{ 'W' , ' ' , 'W' , 'W' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },
		{ 'W' , ' ' , ' ' , 'W' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , '(' },
		{ 'W' , ' ' , ' ' , ']' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , '(' },
		{ 'W' , ' ' , ' ' , 'W' , ' ' , ' ' , '}' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },//'}'s would allow you to cross over to the other side (or deny the player if thats what we decide)
		{ 'W' , 'B' , 'B' , 'W' , ' ' , ' ' , '}' , ' ' , ' ' , ' ' , ' ' , ' ' , 'W' },//B stands for bed.
		{ 'W' , 'B' , 'B' , 'W' , '=' , '=' , '|' , '=' , '=' , '=' , '=' , ' ' , 'W' },
		{ 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
	};

	return Location;
}

// Witten by Joshua Salkeld
string PrisonDoors(string &Location, int &PlayerHealth, bool &Sword, bool &SwordLv2, bool &Clothes, bool &CaptainDead, bool WarStory5, bool WarStory10)
{
	Location = "Prison Door";

	system("cls");
	Sleep(300);
	cout << "This door leads back into the prison." << endl << endl;
	Sleep(300);
	cout << "It'd be stupid to go back into the place you're trying to escape from." << endl << endl;
	Sleep(300);
	cout << "It's best to be going now." << endl << endl;
	Sleep(300);
	pressEnter();

	townMap(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);

	return Location;
}
//End JS


// Written by Joshua Salkeld
void townMap(string &Location, bool &Sword, int &PlayerHealth, bool &CaptainDead, bool WarStory5, bool WarStory10)
{
	int i = 0;
	int x = 0;
	bool test = true;
	char PlayerIcon = 'P';
	char move;
	static int playerVert = 21; //The two static variables is the initial spawn point.
	static int PlayerHoriz = 14;
	int PlayerTempVert;
	int PlayerTempHoriz;
	int Check;
	string GetChoice;
	bool BadInput = true;
	Location = "Town";

	//These ones are transfered between functions
	bool SwordLv2 = false;
	bool clothes = false;
	//==========================================

	const int ROWS = 25, COLS = 21;
	//Key for the map is as follows
	//B = wall of building
	// (, ), {, [, ], are all doors to the buildings
	// | these are vertical road markers
	// - these are horizontal road markers


	char townArray[ROWS][COLS] = {
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , '^' , '^', '^' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , 'B' , 'B' , 'B' , 'B' , '-' , '-' , ' ' , ' ', ' ' , '-' , '-' , 'B' , 'B' , 'B' , 'B' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ')' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '[' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ')' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '[' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , 'B' , 'B' , 'B' , 'B' , '-' , '-' , ' ' , ' ', ' ' , '-' , '-' , 'B' , 'B' , 'B' , 'B' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , 'B' , 'B' , 'B' , 'B' , 'B' , 'B' , ' ' , '|' , ' ' , ' ', ' ' , '|' , ' ' , 'B' , 'B' , 'B' , 'B' , 'B' , ' ' , ' ' },
		{ ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , 'B' , '-' , '-' , ' ' , ' ', ' ' , '-' , '-' , 'B' , ' ' , ' ' , ' ' , 'B' , ' ' , ' ' },
		{ ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , ']' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '(' , ' ' , ' ' , ' ' , 'B' , ' ' , ' ' },
		{ ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , ']' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '(' , ' ' , ' ' , ' ' , 'B' , ' ' , ' ' },
		{ ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , 'B' , '-' , '-' , ' ' , ' ', ' ' , '-' , '-' , 'B' , ' ' , ' ' , ' ' , 'B' , ' ' , ' ' },
		{ ' ' , 'B' , 'B' , 'B' , 'B' , 'B' , 'B' , ' ' , '|' , ' ' , ' ', ' ' , '|' , ' ' , 'B' , 'B' , 'B' , 'B' , 'B' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , 'B' , 'B' , 'B' , 'B' , 'B' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , '|' , ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , '|' , '-' , '-' , '-' , 'B' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , '{' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , '{' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , '-' , '-', '-' , '-' , '-' , '-' , '-' , 'B' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' }
	};

	townArray[playerVert][PlayerHoriz] = 'P'; //sets the player character to 'P'
	

	while (test) //This while loop is what draws the map
	{
		while (x < 24)
		{
			if (i == 0)
			{
				system("cls");
				cout << " " << " " << " " << " " << " " << " " << " " << " ";
			}
			cout << townArray[x][i];

			if (i == 21)
			{
				cout << endl;
				x++;
				i = 0;
				cout << " " << " " << " " << " " << " " << " " << " " << " " << " ";
			}
			else
			{

			}
			i++;
		}
		i = 0;
		x = 0;
		PlayerTempHoriz = PlayerHoriz;
		PlayerTempVert = playerVert;

		cout << "W, A, S, or D: "; // W moves up, A moves left, S moves down, D moves right. Must hit enter after every one.
		cin >> move;

		//Inside the following if statements it checks for first the button pushed and then checks the location of the player. If they are at a door asks them if they want to enter.

		if (move == 'w')
		{
			Check = playerVert - 1;

			if (townArray[Check][PlayerHoriz] == '-' || townArray[Check][PlayerHoriz] == '|')
			{

			}
			else if (townArray[10][13] == 'P' || townArray[11][13] == 'P') 
			{
				break;
			}
			else if (townArray[3][13] == 'P' || townArray[4][13] == 'P')
			{
				break;
			}
			else if (townArray[21][15] == 'P' || townArray[22][15] == 'P')
			{
				break;
			}
			else if (townArray[10][7] == 'P' || townArray[11][7] == 'P')
			{
				break;
			}
			else if (townArray[3][7] == 'P' || townArray[4][7] == 'P')
			{
				break;
			}
			else if (townArray[1][9] == 'P' || townArray[1][10] == 'P'|| townArray[1][11] == 'P')
			{
				break;
			}
			else
			{

				PlayerTempVert = playerVert;
				PlayerTempHoriz = PlayerHoriz;
				playerVert = playerVert - 1;
			}
		}
		else if (move == 'a')
		{
			Check = PlayerHoriz - 1;
			if (townArray[playerVert][Check] == '-' || townArray[playerVert][Check] == '|')
			{

			}
			else if (townArray[10][13] == 'P' || townArray[11][13] == 'P')
			{
				break;
			}
			else if (townArray[3][13] == 'P' || townArray[4][13] == 'P')
			{
				break;
			}
			else if (townArray[21][15] == 'P' || townArray[22][15] == 'P')
			{
				break;
			}
			else if (townArray[10][7] == 'P' || townArray[11][7] == 'P')
			{
				break;
			}
			else if (townArray[3][7] == 'P' || townArray[4][7] == 'P')
			{
				break;
			}
			else if (townArray[1][9] == 'P' || townArray[1][10] == 'P' || townArray[1][11] == 'P')
			{
				break;
			}

			else
			{
				PlayerTempHoriz = PlayerHoriz;
				PlayerTempVert = playerVert;
				PlayerHoriz = PlayerHoriz - 1;
			}
		}
		else if (move == 's')
		{
			Check = playerVert + 1;

			if (townArray[Check][PlayerHoriz] == '-' || townArray[Check][PlayerHoriz] == '|')
			{

			}
			else if (townArray[10][13] == 'P' || townArray[11][13] == 'P')
			{
				break;
			}
			else if (townArray[3][13] == 'P' || townArray[4][13] == 'P')
			{
				break;
			}
			else if (townArray[21][15] == 'P' || townArray[22][15] == 'P')
			{
				break;
			}
			else if (townArray[10][7] == 'P' || townArray[11][7] == 'P')
			{
				break;
			}
			else if (townArray[3][7] == 'P' || townArray[4][7] == 'P')
			{
				break;
			}
			else if (townArray[1][9] == 'P' || townArray[1][10] == 'P' || townArray[1][11] == 'P')
			{
				break;
			}
			else
			{

				PlayerTempVert = playerVert;
				PlayerTempHoriz = PlayerHoriz;
				playerVert = playerVert + 1;
			}

		}
		else if (move == 'd')
		{
			Check = PlayerHoriz + 1;
			if (townArray[playerVert][Check] == '-' || townArray[playerVert][Check] == '|')
			{

			}
			else if (townArray[10][13] == 'P' || townArray[11][13] == 'P')
			{
				break;
			}
			else if (townArray[3][13] == 'P' || townArray[4][13] == 'P')
			{
				break;
			}
			else if (townArray[21][15] == 'P' || townArray[22][15] == 'P')
			{
				break;
			}
			else if (townArray[10][7] == 'P' || townArray[11][7] == 'P')
			{
				break;
			}
			else if (townArray[3][7] == 'P' || townArray[4][7] == 'P')
			{
				break;
			}
			else if (townArray[1][9] == 'P' || townArray[1][10] == 'P' || townArray[1][11] == 'P')
			{
				break;
			}
			else
			{
				PlayerTempHoriz = PlayerHoriz;
				PlayerTempVert = playerVert;
				PlayerHoriz = PlayerHoriz + 1;
			}
		}
		else
		{

		}

		townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
		townArray[playerVert][PlayerHoriz] = 'P';


	}

	BadInput = true;

	// These If statements check again the location of the player and then ask the proper question to them. These lead to the functions for lv2
	//Inside each of them it sets the spawn point to back outside the door so the player returns there when they leave the building.

	if (townArray[1][9] == 'P' || townArray[1][10] == 'P' || townArray[1][11] == 'P')
	{
		cout << endl << "Do you want to go to the stables to escape this town? (Once this is done there is no going back). (Y/N)";
		BadInput = true;
		while (BadInput == true)
		{
			getline(cin, GetChoice);
			if (GetChoice.at(0) == 'y' || GetChoice.at(0) == 'Y')
			{
				BadInput = false;
				//This Goes to Lv3
			}
			else if (GetChoice.at(0) == 'n' || GetChoice.at(0) == 'N')
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 2;
				PlayerHoriz = 10;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);
			}
			else
			{
				BadInput = true;
			}
		}
	}
	else if (townArray[3][7] == 'P' || townArray[4][7] == 'P')
	{
		cout << endl << "Do you want to go to the Alchemist Shop?. (Y/N)";
		BadInput = true;
		//Sebastian writing Alchemist shop. Remember Bool check for if you have armor. IF yes, up health to 20. If no, up health to 10. 
		while (BadInput == true)
		{
			getline(cin, GetChoice);
			if (GetChoice.at(0) == 'y' || GetChoice.at(0) == 'Y')
			{
				BadInput = false;
				playerVert = 3;
				PlayerHoriz = 8;
				townArray[playerVert][PlayerHoriz] = 'P';
				AlcShop(Location, PlayerHealth, Sword, SwordLv2, clothes, CaptainDead);
			}
			else if (GetChoice.at(0) == 'n' || GetChoice.at(0) == 'N')
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 3;
				PlayerHoriz = 8;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);
			}
			else
			{
				BadInput = true;
			}
		}
	}
	else if (townArray[10][7] == 'P' || townArray[11][7] == 'P')
	{
		cout << endl << "Do you want to go to the Inn?. (Y/N)";
		BadInput = true;
		//Dan writing Inn. Story check: If you get Innkeeper's war story, add another 5 top health from buff. 
		while (BadInput == true)
		{
			getline(cin, GetChoice);
			if (GetChoice.at(0) == 'y' || GetChoice.at(0) == 'Y')
			{
				BadInput = false;
				playerVert = 10;
				PlayerHoriz = 8;
				townArray[playerVert][PlayerHoriz] = 'P';
				Inn(Location, PlayerHealth, Sword, SwordLv2, clothes, CaptainDead, WarStory5, WarStory10);
			}
			else if (GetChoice.at(0) == 'n' || GetChoice.at(0) == 'N')
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 10;
				PlayerHoriz = 8;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);
			}
			else
			{
				BadInput = true;
			}
		}
	}
	else if (townArray[3][13] == 'P' || townArray[4][13] == 'P')
	{
		cout << endl << "Do you want to go to the Clothing Shop?. (Y/N)"; 
		BadInput = true;
		//Cowriting by Sebastian and Dan
		while (BadInput == true)
		{
			getline(cin, GetChoice);
			if (GetChoice.at(0) == 'y' || GetChoice.at(0) == 'Y')
			{
				BadInput = false;
				playerVert = 3;
				PlayerHoriz = 12;
				townArray[playerVert][PlayerHoriz] = 'P';
				Clothes(Location, PlayerHealth, Sword, SwordLv2, clothes, CaptainDead);
			}
			else if (GetChoice.at(0) == 'n' || GetChoice.at(0) == 'N')
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 3;
				PlayerHoriz = 12;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);
			}
			else
			{
				BadInput = true;
			}
		}
	}
	else if (townArray[10][13] == 'P' || townArray[11][13] == 'P')
	{
		cout << endl << "Do you want to go to the blacksmith?. (Y/N)";
		BadInput = true;
		//Only other battle in town is the Smithy if you wake him up (RNG Chance). Josh is writing that. Josh writing Smithy.
		while (BadInput == true)
		{
			getline(cin, GetChoice);
			if (GetChoice.at(0) == 'y' || GetChoice.at(0) == 'Y')
			{
				BadInput = false;
				playerVert = 10;
				PlayerHoriz = 12;
				townArray[playerVert][PlayerHoriz] = 'P';
				Smith(Location, PlayerHealth, Sword, SwordLv2, clothes, CaptainDead);
			}
			else if (GetChoice.at(0) == 'n' || GetChoice.at(0) == 'N')
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 10;
				PlayerHoriz = 12;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory5);
			}
			else
			{
				BadInput = true;
			}
		}
	}
	else if (townArray[21][15] == 'P' || townArray[22][15] == 'P')
	{
		cout << endl << "Do you want to go to the Prison?. (Y/N)";
		BadInput = true;
		while (BadInput == true)
		{
			getline(cin, GetChoice);
			if (GetChoice.at(0) == 'y' || GetChoice.at(0) == 'Y')
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 21;
				PlayerHoriz = 14;
				townArray[playerVert][PlayerHoriz] = 'P';
				PrisonDoors(Location, PlayerHealth, Sword, SwordLv2, clothes, CaptainDead, WarStory5, WarStory10);
			}
			else if (GetChoice.at(0) == 'n' || GetChoice.at(0) == 'N')
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 21;
				PlayerHoriz = 14;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);
			}
			else
			{
				BadInput = true;
			}
		}
	}
	else
	{

	}

}

void tempFunc(string &Location, bool &Sword, int &PlayerHealth, bool &CaptainDead, bool WarStory5, bool WarStory10) //This function serves as the respawn function if the player chooses the no option.
{
	system("cls");
	Sleep(900);

	townMap(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);
}

void Level_2_Begin(string &Location, bool &Sword, int &PlayerHealth, bool &CaptainDead, bool WarStory5, bool WarStory10)
{
	system("cls");
	cout << "You walk out of the prison's main door and end up in a small town." << endl << endl;
	Sleep(300);
	cout << "There isn't much here of use. You do know that there is a stables to the north that might have a horse." << endl << endl;
	Sleep(300);
	cout << "The guards here will all be looking for an escaped prisoner. A horse would definitly help escape." << endl << endl;
	Sleep(300);
	cout << "Other than the horse there is also a smith to the east, a clothes store to the north-east, an inn to the west," << endl << endl;
	Sleep(300);
	cout << "and an alchemist shop to the north-west. They might have something useful inside if I check quietly." << endl << endl;
	pressEnter();
	townMap(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);
}

//End JS





//Written By Sebastian Newbold
void pressEnter()//Press enter to continue
{
	Sleep(300);//CHANGE TO 1000 WHEN DONE//
	string input;
	cout << "Press ENTER to continue.\n";
	getline(cin, input);
	//Ignores everything the user puts in. (cin.ignore alone only works with 1 character and screws up when more are entered.)

	for (int i = -1; i < input.length(); i++)
		cin.ignore();
}
//End SN

// Death System coded by Joshua Salkeld
void PlayerDeath()
{
	system("cls");
	Sleep(650);
	cout << "The last thing you feel is your body hit the floor before your vision goes black." << endl << endl;
	Sleep(1600);
	system("cls");
	Sleep(650);
	//ascii art was made using a generator from this website http://www.glassgiant.com/ascii/
	cout << red;
	cout << "..........~~.....~~..~~...~~...~~~~....~~~~......~~~~~~....~~~~~~..~~~~~~~....~~~~~~................" << endl;
	cout << "...........~~...~~..~~.....~~....~.......~.......~~.....~~...~~....~~.........~~....~~.............." << endl;
	cout << "............~...~..~~.......~~...~.......~.......~~......~~..~~....~~.........~~.....~~............." << endl;
	cout << ".............~.~...~~........~~..~.......~.......~~......~~..~~....~~.........~~......~~............" << endl;
	cout << "..............~....~~........~~..~.......~.......~~......~~..~~....~~~~~~.....~~.......~~..........." << endl;
	cout << "..............~....~~........~~..~.......~.......~~......~~..~~....~~.........~~.......~~..........." << endl;
	cout << "..............~....~~.......~~...~.......~.......~~.....~~...~~....~~.........~~......~~............" << endl;
	cout << "..............~.....~~.....~~....~~....~~........~~....~~....~~....~~.........~~.....~~............." << endl;
	cout << "..............~........~~..........~~~~..........~~~~~~....~~~~~~..~~~~~~~....~~~~~~~..............." << endl;
	cout << endl << endl << endl << endl << endl << endl;
	Sleep(4000);
	exit(0);
}
// End JS\1

// Battle System Written by Joshua  Salkeld
bool battleGuard(string &Location, bool Sword, int PlayerHealth, bool guardFight, bool Key, bool CaptainDead, bool WarStory5, bool WarStory10)
{
	int GuardHealth = 5;
	const int maxDamage = 3;
	int MissChance = 100;
	int playerMiss;
	int guardMiss;
	string getChoice;
	int Damage;

	cout << "You draw your sword and face the guard." << endl << endl;
	pressEnter();
	while (PlayerHealth > 0)
	{
		while (GuardHealth > 0) 
		{
			system("cls");
			Sleep(650);
			cout << "You have " << PlayerHealth << " health remaining." << endl << endl;
			Sleep(300);
			cout << "Press 1 to swing at the guard." << endl;
			Sleep(300);
			cout << "Press 2 to Defend." << endl;
			getline(cin, getChoice);
			system("cls");

			if (getChoice.at(0) == '1')
			{
				cout << "You swing your sword at the guard." << endl << endl;
				Sleep(300);
				MissChance = 100;
				Damage = (rand() % maxDamage) + 1;
				playerMiss = (rand() % MissChance);
				if (playerMiss < 25) //25% chance to miss
				{
					cout << red << "Your sword collides with the guards armor dealing no damage. You missed." << normal << endl << endl;
					Sleep(300);
				}
				else
				{
					cout << lightcyan << "Your sword collides with the guard. You deal " << Damage << " damage." << normal << endl << endl;
					Sleep(300);
					GuardHealth = GuardHealth - Damage; //calc guard health

					if (GuardHealth <= 0)
					{
						break;
					}
				}
			} 
			else if (getChoice.at(0) == '2')
			{
				cout << cyan << "You bring your sword up and get ready for the guards attack." << normal << endl << endl;
				Sleep(300);
				MissChance = 50;
			}
			else
			{
				system("cls");
				Sleep(650);
			}

			cout << "The guard swings at you." << endl << endl;
			Sleep(300);
			Damage = (rand() % maxDamage) + 1; //Damage is between 1 and 4
			guardMiss = (rand() % MissChance);
			if (guardMiss < 25)
			{
				cout << lightgreen << "The guard swings wide and misses you." << normal << endl << endl;
				pressEnter();
			}
			else 
			{
				cout << lightred << "The guard's sword collides with your chest dealing " << Damage << " damage." << normal << endl << endl;
				pressEnter();
				PlayerHealth = PlayerHealth - Damage; //calculate player health

				if (PlayerHealth <= 0)
				{
					break;
				}
			}

		}
		if (GuardHealth <= 0)
		{
			cout << "You watch as the guard's body goes limp and hits the floor." << endl << endl;
			pressEnter();
		}
		break;
	}
	if (PlayerHealth <= 0)
	{
		PlayerDeath();
	}
	else
	{
		guardFight = true;
		Hallway1(Location, Sword, PlayerHealth, guardFight, Key, CaptainDead, WarStory5, WarStory10);
	}
	return guardFight;
}
// End JS

string CaptainQuarters(string &Location, bool &Sword, int &PlayerHealth, bool &Key, bool &CaptainDead, bool WarStory5, bool WarStory10)
{
	//Start DC (with the help of SB. He lined up the while loop after I had troubles with it. Joshua set up the randomly spawned Key, and I think some part of the loop.)
	string getChoice;
	string killCapChoice; //Choice to kill the Captain. Can rename if needed.
	string KeySearch; //Where to search for the key.
	bool badInput1 = 1;
	bool badInput2 = 1;
	bool badInput3 = 1;
	bool breakLoop = 0;
	bool addSleep = 0;
	int maxLoc = 3;
	Location = "Captain's Quarters";
	int keyLocation = (rand() % maxLoc) + 1; //sets key to either location 1, 2, 3, or 4.
	const int ROWS = 3, COLS = 3;
	int playerAt[3][2];

	while (breakLoop == 0)//breakLoop start
	{
		if (Sword)
		{
			while (badInput1 == 1)
			{
				badInput1 = 0;
				system("cls");
				if (CaptainDead == false)
				{
					playerAt[3][2];
					cout << "The Captain of the Guard is sleeping peacefully in his Queen-sized cot." << endl << endl;
					Sleep(300);
					cout << "You look around the room. His cot is against the right wall, with an endtable holding an Oil lamp, an open book, and a helmet." << endl << endl;
					Sleep(300);
				}
				else if (CaptainDead == true)
				{
					playerAt[3][2];
					cout << "You look around the room. The Captain's bloody cot is against the right wall, with an endtable holding an oil lamp, an open book, and a helmet." << endl << endl;
					Sleep(300);
				}
				cout << "The left wall is mostly bare, save a long desk holding some of his personal effects. There are drawers along the face. " << endl << endl;
				Sleep(300);
				cout << "Press 1 to creep up to the Captain's bed." << endl;
				Sleep(300);
				cout << "Press 2 to search the desk on the left wall." << endl;
				getline(cin, getChoice);

				if (getChoice.at(0) == '1')
				{
					if (CaptainDead == false)
					{
						while (badInput2 == 1)
						{
							playerAt[2][3];
							badInput2 = 0;
							system("cls");
							cout << "The Captain continues to snooze away peacefully. His ugly face contorts with each breath, deep in dreaming." << endl << endl;
							Sleep(200);
							cout << "The bastard has kept you locked up, tortured, beaten for the five longest years of your life. He must die." << endl << endl;
							Sleep(200);
							cout << "Press 1 to slit his throat like the pig he is." << endl;
							Sleep(200);
							cout << "Press 2 to have mercy for the time being." << endl;
							getline(cin, killCapChoice);

							if (killCapChoice.at(0) == '1')
							{
								system("cls");
								cout << "You slice your sword across the Captain's jugular, wetting it with his blood. Your captor is dead." << endl << endl;
								CaptainDead = true;
								pressEnter();
							}

							else if (killCapChoice.at(0) == '2')
							{
								system("cls");
								cout << "You decide to leave him sleep for now. You have bigger problems than revenge." << endl << endl;
								pressEnter();
							}
							else
							{
								badInput2 = 1;
								system("cls");
								Sleep(650);
							}
						}
						
					}
					else if (CaptainDead == true)
					{
						system("cls");
						cout << "The Captain bleeds like a stuck pig. He is no threat to you anymore." << endl << endl;
						pressEnter();
					}
				}
				else if (getChoice.at(0) == '2')
				{
					while (badInput3 == 1)
					{
						playerAt[2][1];
						badInput3 = 0;
						system("cls");
						if (addSleep == 1)
						{
							Sleep(650);
							addSleep = 0;
						}
						cout << "You approach the desk. There are three drawers of unknown content; the top of the desk is littered with various papers and ";
						cout << "ledgers." << endl << endl;
						Sleep(300);
						cout << "Select a drawer to search (1-3), or press 4 to rummage the desktop. You need to find that key!" << endl;

						//Key spawns in random locations. This is set upon entering the captains quarters.
						//Key randomization and associated if statments written by Joshua Salkeld
						getline(cin, KeySearch);
						if (KeySearch.at(0) == '1')
						{
							system("cls");
							cout << "The drawer is piled heavy with knick knacks and personal effects." << endl << endl;
							Sleep(300);
							if (keyLocation == 1)
							{
								cout << "You find the key at the bottom of the drawer. Finally a way out of here." << endl << endl;
								Key = true;
								pressEnter();
								breakLoop = 1;
							}
							else
							{
								cout << "The key isn't here. It must be somewhere in here though." << endl << endl;
								badInput3 = 1;
								addSleep = 1;
								pressEnter();
							}
						}
						else if (KeySearch.at(0) == '2')
						{
							system("cls");
							cout << "The drawer is stacked tight with papers pertaining to the operations and happenings of the Dungeon." << endl << endl;
							Sleep(300);
							if (keyLocation == 2)
							{
								cout << "You find the key at the bottom of the drawer. Finally a way out of here." << endl << endl;
								Key = true;
								pressEnter();
								breakLoop = 1;
							}
							else
							{
								cout << "The key isn't here. It must be somewhere in here though." << endl << endl;
								badInput3 = 1;
								addSleep = 1;
								pressEnter();
							}
						}
						else if (KeySearch.at(0) == '3')
						{
							system("cls");
							cout << "The drawer holds the undergarments belonging to the Captain. You shiver in disugst, but rummage through looking for your freedom." << endl << endl;
							Sleep(300);
							if (keyLocation == 3)
							{
								cout << "You find the key at the bottom of the drawer. Finally a way out of here." << endl << endl;
								Key = true;
								pressEnter();
								breakLoop = 1;
							}
							else
							{
								cout << "The key isn't here. It must be somewhere in here though." << endl << endl;
								badInput3 = 1;
								addSleep = 1;
								pressEnter();
							}
						}

						else if (KeySearch.at(0) == '4')
						{
							system("cls");
							cout << "You rifle through the contents of the desktop, but find nothing of interest to your goal." << endl << endl;
							Sleep(300);
							if (keyLocation == 4)
							{
								cout << "You find the key on top of the desk. Finally a way out of here." << endl << endl;
								Key = true;
								pressEnter();
								breakLoop = 1;
							}
							else
							{
								cout << "The key isn't here. It must be somewhere in here though." << endl << endl;
								badInput3 = 1;
								addSleep = 1;
								pressEnter();
							}
						}
						else
						{
							badInput3 = 1;
							system("cls");
							Sleep(650);
						}
					}
				}
				else
				{
					badInput1 = 1;
					system("cls");
					Sleep(650);
				}
			}	
		}
		system("cls");
		badInput1 = 1;
		badInput2 = 1;
		badInput3 = 1;
	}//breakLoop end
	
	if (Key && CaptainDead)
	{
		cout << "You have the key to your freedom, and the Captain is dead. You need to get back out to the Door and move on from this place." << endl << endl;
		Sleep(300);
		pressEnter();
		Level_2_Begin(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);
	}

	else if (Key && !CaptainDead)
	{
		cout << "You have the key to your freedom, and you've taken mercy on the Captain. You need to get back out to the Door and move on from this place." << endl << endl;
		Sleep(300);
		pressEnter();
		Level_2_Begin(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);
	}

	//====================================================================
	// THIS IS WHERE TO CONTINUE FOR LATER
	//====================================================================

	return Location;//Replace later
}




string LockedDoor(string &Location, bool &Key, bool &Sword, int &PlayerHealth, bool CaptainDead, bool WarStory5, bool WarStory10)
{
	Location = "Locked Door";
	if (!Key)
	{
		system("cls");
		cout << "The door leading out of the prison appears to be " << red << "LOCKED" << normal << ". Maybe the captain will have a key to unlock it." << endl << endl;
		pressEnter();
	}
	else 
	{
		cout << "Finally, you have your freedom. You only need to unlock the door and your imprisonment will be a memory." << endl << endl;
		Sleep(300);
		cout << "Hands trembling, you slot the key into the heavy lock and twist." << endl << endl;
		pressEnter();//To Level 2
		townMap(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);
	}
	return Location;//Replace later
}


string Hallway1(string &Location, bool Sword, int PlayerHealth, bool guardFight, bool Key, bool CaptainDead, bool WarStory5, bool WarStory10)
{
	string getChoice;
	int check = 0;
	int check2 = 0;
	bool badInput = 1;
	bool notFromCells = 0;
	bool notFromArmory = 0;
	bool deadEnd = 0;
	static string examinedDoor = "";
	const int ROWS = 1, COLS = 5;
	int playerAt[1][2];
	
	//Trainhead option: Code entire first level "dynamc hard." Movement will go on set numbers of cells in array. EX: Left option in hallway will set one cell left, display "Dead end!" 


	//Trainhead Option coordinates written by Dan. 
	system("cls");
	if (!guardFight)
	{

		while (check == 0)
		{//While check = 0 start

			while (badInput == 1)
			{
				//Intro written by Dan Curley.
				if (deadEnd == 1)
				{
					Sleep(650);
					deadEnd = 0;
				}
				cout << "You take a tentative step into the dark, dank hallway." << endl << endl;
				Sleep(300);
				cout << "Torches line the overhead trim, singeing what little moss and mold has grown around the crown. " << endl << endl;
				Sleep(300);
				cout << "Cells of your fellow prisoners line the hall on either side of you. It is cold here. You look around." << endl << endl;
				Sleep(300);
				cout << "On your left you see a wall. To your right, the hallway stretches on a short length." << endl << endl;
				Sleep(300);

				cout << "Press 1 to go left. " << endl;
				Sleep(300);
				cout << "Press 2 to go right. " << endl;
				badInput = 0;
				getline(cin, getChoice);

				if (getChoice.at(0) == '1')
				{
					deadEnd = 1;
					playerAt[1][1];
					cout << brown << "\nThat's a dead end! " << normal;
					Sleep(1300);
					badInput = 1;//Puts it in the same loop as badInput.
					system("cls");
				}
				else if (getChoice.at(0) == '2')
				{
					//Wait why is this here?
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
				if (notFromCells == 0)
				{
					playerAt[1][5];
					system("cls");
					cout << "You come upon a three-way split in your path." << endl << endl;
					Sleep(300);
					cout << "On your left is the Quarters to the Captain of the Guard." << endl << endl; //describe Captain after you get into the room. 
					Sleep(300);
					cout << "On your right lay the armory. You may need to get in there." << endl << endl;
					Sleep(300);
					//Edited to assume the character doesn't know the door is locked yet.
					cout << "Straight ahead of you is a thick oaken door. Past the door is the first step to freedom." << endl << endl;
					Sleep(300);
				}
				badInput = 0;
				cout << "Press 1 to sneak into the Captain's quarters." << endl;
				Sleep(300);
				//If examinedDoor is not set to " LOCKED" (already visited) it will just display "the door"
				cout << "Press 2 to try the" << red << examinedDoor << normal << " door";
				if (examinedDoor == " LOCKED")
				{
					cout << " again." << endl;
					Sleep(300);
				}
				else
				{
					cout << "." << endl;
					Sleep(300);
				}
			
				cout << "Press 3 to sneak into the Armory." << endl;
				
				getline(cin, getChoice);

				if (getChoice.at(0) == '1')
				{
					if (Sword) //if player has a sword go to Captain quarters function
					{
						system("cls");
						notFromCells = 1;
						CaptainQuarters(Location, Sword, PlayerHealth, Key, CaptainDead, WarStory5, WarStory10);
					}
					else
					{
						system("cls");
						cout << "It might not be the best idea to test the captian. He may be sleeping, but having a weapon would definitely help." << endl << endl;
						//Written By Sebastian Newbold
						pressEnter();
						system("cls");
						notFromCells = 1;
						cout << "In front of you is the armory." << endl << endl;
						Sleep(300);
						cout << "On your left is the" << examinedDoor << " door." << endl << endl;
						Sleep(300);
						cout << "On your right is the hallway with your cell." << endl << endl;
						Sleep(300);
						//End SN
					}
				}
				else if (getChoice.at(0) == '2')
				{
					LockedDoor(Location, Key,  Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10);
					//Written By Sebastian Newbold
					//Examined the door and found that it is locked
					examinedDoor = " LOCKED";
					notFromCells = 1;
					system("cls");
					cout << "On your left is the Armory." << endl << endl;
					Sleep(300);
					cout << "On your right is the Captain's quarters." << endl << endl;
					Sleep(300);
					cout << "Straight ahead is the hallway with your cell." << endl << endl;
					Sleep(300);
					//End SN
				}
				else if (getChoice.at(0) == '3')
				{
					Armory (Location, Sword, PlayerHealth, guardFight, Key, CaptainDead, WarStory5, WarStory10); //paths continues in Armory function
					//Written By Sebastian Newbold
					notFromCells = 1;
					system("cls");
					cout << "In front of you is the Captain's quarters." << endl << endl;
					Sleep(300);
					cout << "On your right is the" << red << examinedDoor << normal << " door." << endl << endl;
					Sleep(300);
					cout << "On your left is the hallway to your cell." << endl << endl;
					Sleep(300);
					//End SN
				}
				else
				{
					badInput = 1;
					system("cls");
					Sleep(650);
				}
			}

		}//While check = 0 end
	}
	else
	{
		system("cls");
		badInput = 1;
		cout << "You sheath your sword and look over the guards body. On him he has a single healing potion." << endl << endl;
		Sleep(300);
		cout << "Your health is currently " << PlayerHealth << " would you like to use it?" << endl << endl;
		Sleep(300);
		cout << "Press 1 to use the potion." << endl;
		Sleep(300);
		cout << "Press 2 to leave it there." << endl;

		getline(cin, getChoice);
		while (badInput == 1)
		{
			badInput = 0;
			if (getChoice.at(0) == '1')
			{
				system("cls");
				cout << "Feeling quite tired after that battle you decide to use it. As you drink it you feel your wounds vanish as your energy is restored." << endl << endl;
				Sleep(300);
				PlayerHealth = 10;
				cout << "Your health is now " << PlayerHealth << "." << endl << endl;
				pressEnter();
				break;
			}
			else if (getChoice.at(0) == '2')
			{
				system("cls");
				cout << "The battle was rough but you decide againt taking it. You turn from the guards body and advance quickly in hopes to avoid another battle" << endl << endl;
				pressEnter();
				break;
			}
			else
			{
				badInput = 1;
				system("cls");
				Sleep(650);
			}
		}
		badInput = 1;
		system("cls");
		while (badInput == 1)
		{
			if (notFromArmory == 0)
			{
				system("cls");
				cout << "You get back to the three-way intersection." << endl << endl;
				Sleep(300);
				cout << "Knowing that one way is the hallway with your cell you only have two real options." << endl << endl;
				Sleep(300);
				cout << "The Captian's Quarters lies down the hallway ahead of you." << endl << endl;
				Sleep(300);
				cout << "The" << red << examinedDoor << normal << " door, and your way out of the prison, lies to the right." << endl << endl;
				Sleep(300);
			}
			cout << "Press 1 to go to the Captian's Quarters." << endl;
			Sleep(300);
			cout << "Press 2 to try the" << red << examinedDoor << normal << " door";
			if (examinedDoor == " LOCKED")
				cout << " again." << endl;
			else
				cout << "." << endl;

			getline(cin, getChoice);

			if (getChoice.at(0) == '1')
			{
				badInput = 0;
				CaptainQuarters(Location, Sword, PlayerHealth, Key, CaptainDead, WarStory5, WarStory10);
			}
			else if (getChoice.at(0) == '2')
			{
				system("cls");
				notFromArmory = 1;
				examinedDoor = " LOCKED";
				cout << "The door is " << red << "LOCKED." << normal << " Best to check with the captain." << endl << endl;
				pressEnter();
				system("cls");
				cout << "Straight ahead is the hallway to your cell." << endl << endl;
				Sleep(300);
				cout << "On your right is the Captain's quarters." << endl << endl;
				Sleep(300);
				cout << "On your left is the Armory, but you've already been that way." << endl << endl;
				Sleep(300);
			}
			else{}
		}
	}
	
	return Location;
}
// End JS
string Armory(string &Location, bool Sword, int PlayerHealth, bool guardFight, bool Key, bool &CaptainDead, bool WarStory5, bool WarStory10)
{
	system("cls");

	string getChoice;
	int check = 0;
	int check2 = 0;
	bool badInput = 1;
	bool afterGuard = 0;
	Location = "Armory";
	

	while (check == 0)
	{
		while (badInput == 1)
		{
			//Armory written by Dan Curley
			const int ROWS = 3, COLS = 3;
			int playerAt[3][2];

			cout << "You creep into the Armory. Swords line the walls, gently reflecting the dull light of the torches." << endl << endl;
			Sleep(300);
			cout << "You may need something to aid you in your escape. That something may need to be able to kill." << endl << endl;
			Sleep(300);

			cout << "Press 1 to take a sword from the wall." << endl;
			Sleep(300);
			cout << "Press 2 to return to the hallway." << endl;
			Sleep(300);

			badInput = 0;
			getline(cin, getChoice);
			// END DC

			//Second Part of Armory written by Joshua Salkeld
			if (getChoice.at(0) == '1')
			{
				playerAt[1][2];
				system("cls");
				Sword = true;
				cout << "You make your way to the back wall and grab a sword off of it. It's nothing fancy but it will do for now." << endl << endl;
				Sleep(300);
				cout << "Glancing around, everything else in this room is too either too heavy or not useful enough to take with you in your escape." << endl << endl;
				pressEnter();
				system("cls");
				cout << "You head out of the armory. Now to open that door." << endl << endl;
				Sleep(300);
				cout << "As you walk out of the armory you see a guard down the hall towards you. He sees you exit and draws his sword" << endl << endl;
				Sleep(300);
				cout << "He yells over his shoulder: " << lightred << "We have an escaped prisoner in the armory!" << normal << endl << endl;
				Sleep(300);
				cout << "You both walk towards each other, battle seems inevitable." << endl << endl;
				Sleep(300);
				afterGuard = battleGuard(Location, Sword, PlayerHealth, guardFight, Key, CaptainDead, WarStory5, WarStory10);
			}
			//end JS

			//Written by Dan Curley
			else if (getChoice.at(0) == '2')
				check = 1;
			else
			{
				badInput = 1;
				system("cls");
				Sleep(650);
			}
			//End DC

			//Written by Joshua Salkeld
		}
	}

	return Location;
}
//End DC
//"First level" functions outlined by Dan Curley. 

string StartingCell(string &Location, bool Sword, int PlayerHealth, bool guardFight, bool Key, bool CaptainDead, bool WarStory5, bool WarStory10)
{
	const int ROWS = 1, COLS = 1;
	int playerAt[ROWS][COLS];
	string getChoice = "1";
	string getChoice1True = "Y";
	bool badInput = 1;
	Location = "StartingCell";


	while (getChoice.at(0) == '1' || badInput == 1)
	{
		badInput = 0;
		system("cls");
		cout << getChoice1True <<"ou awaken in your dark cell, eager with the knowledge that today you break the chains of your bondage." << endl << endl;
		Sleep(300);
		cout << "Press 1 to go back to sleep. You don't have time to deal with this today." << endl;
		Sleep(300);
		cout << "Press 2 to grab the lockpick from under your pillow and bust out." << endl;
		Sleep(300);

		//Written by Sebastian Newbold
		getline(cin, getChoice);

		if (getChoice.at(0) == '1')
		{
			system("cls");
			getChoice1True = "Again, y";
			system("Color 80");//Gray screen color
			Sleep(2300);
			system("Color 07");//Normal screen color
		}
		else if (getChoice.at(0) == '2')
		{
			Location = "Hallway1";
			Hallway1(Location, Sword, PlayerHealth, guardFight, Key, CaptainDead, WarStory5, WarStory10);

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
	bool guardFight = false;
	bool Key = false;
	bool CaptainDead = false;
	bool WarStory5 = false;
	bool WarStory10 = false; //5 or 10 refer to health buffs. Can only have one buff at a time. Conversation ends at end of dialouge tree.
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
	Sleep(600);//Change back later
	system("cls");
	//End DC
	StartingCell(Location, Sword, PlayerHealth, guardFight, Key, CaptainDead, WarStory5, WarStory10);




	system("pause");
	return 0;
}