// CIS150_Final Project_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "windows.h"
#include <ctime>
#include <mmsystem.h>

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

//All sounds done by everyone
//Sounds found on https://freesound.org

//Random edits throughout program written by Sebastian Newbold

//Change Function calls in lv 3

bool PlayerDeadEndRoyal = false;
bool PlayerDeadEndCap = false;
bool CaptainDeadEnd = false;
bool RoyalGuardDeadEnd = false;

string Armory(string &, bool, int, bool, bool, bool &, bool, bool, string [], bool, bool);
string Hallway1(string &, bool, int, bool, bool, bool, bool, bool, string [], bool, bool);
string LockedDoor(string &, bool &, bool &, int &, bool, bool, bool, string[], bool, bool);
string Smith(string &, int &, bool &, bool &, bool, bool, string [], bool, bool);
string ClothesFunc(string &, int &, bool &, bool &, bool, bool, string [], bool, bool);
string AlcShop(string &, int &, bool &, bool &, bool, bool, string[], bool, bool);
string Inn(string &, int &, bool &, bool &, bool, bool, string [], bool, bool);

void PlayerDeath();
void tempFunc(string &, bool &, int &, bool &, bool, bool, string [], bool, bool); //This is a function for error checking
void townMap(string &, bool &, int &, bool &, bool, bool, string [], bool, bool);

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

//Written by Sebastian Newbold
void TheEndDisplay()
{
	
	system("cls");
	Sleep(1200);
	cout << magenta;
	cout << "..........................................................................................................................." << endl;
	Sleep(200);
	system("cls");

	cout << "........................................................................................................................" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;//
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "IMMM" << magenta << "......................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "...." << lightblue << "MMMO" << magenta << "...." << lightblue << "?MMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "$MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "IMMM" << magenta << "......................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "...." << lightblue << "MMMO" << magenta << "...." << lightblue << "?MMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "$MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMM" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << ",MMM" << magenta << "......." << lightblue << "MMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "IMMM" << magenta << "......................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "...." << lightblue << "MMMO" << magenta << "...." << lightblue << "?MMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "ZMM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMM" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << ",MMM" << magenta << "......." << lightblue << "MMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "IMMM" << magenta << "......................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "...." << lightblue << "MMMO" << magenta << "...." << lightblue << "?MMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "ZMM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMI" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM," << magenta << "......." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMM" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << ",MMM" << magenta << "......." << lightblue << "MMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "IMMM" << magenta << "......................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "...." << lightblue << "MMMO" << magenta << "...." << lightblue << "?MMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "ZMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "." << lightblue << "$MMMMN" << magenta << ".........." << lightblue << "=MMMMMM" << magenta << "................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << ".." << lightblue << "8MMMMO" << magenta << ".........." << lightblue << "MMMMM=" << magenta << "." << lightblue << "OMM" << magenta << "........" << endl << endl << endl << endl << endl << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMI" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM," << magenta << "......." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMM" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << ",MMM" << magenta << "......." << lightblue << "MMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "IMMM" << magenta << "......................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "...." << lightblue << "MMMO" << magenta << "...." << lightblue << "?MMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "ZMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "." << lightblue << "$MMMMN" << magenta << ".........." << lightblue << "=MMMMMM" << magenta << "................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << ".." << lightblue << "8MMMMO" << magenta << ".........." << lightblue << "MMMMM=" << magenta << "." << lightblue << "OMM" << magenta << "........" << endl << endl << endl << endl << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMDNNNNNNNMMM" << magenta << "............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM" << magenta << "........" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMI" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM," << magenta << "......." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMM" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << ",MMM" << magenta << "......." << lightblue << "MMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "IMMM" << magenta << "......................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "...." << lightblue << "MMMO" << magenta << "...." << lightblue << "?MMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "ZMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "." << lightblue << "$MMMMN" << magenta << ".........." << lightblue << "=MMMMMM" << magenta << "................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << ".." << lightblue << "8MMMMO" << magenta << ".........." << lightblue << "MMMMM=" << magenta << "." << lightblue << "OMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM?MMMMMMMM=" << magenta << "......" << lightblue << "?MMMNODMMMM" << magenta << ".............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMMDMMMMMMMM" << magenta << "......." << lightblue << "MMMMMMMMM8MM" << magenta << "........" << endl << endl << endl << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMDNNNNNNNMMM" << magenta << "............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM" << magenta << "........" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMI" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM," << magenta << "......." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMM" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << ",MMM" << magenta << "......." << lightblue << "MMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "IMMM" << magenta << "......................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "...." << lightblue << "MMMO" << magenta << "...." << lightblue << "?MMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "ZMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "." << lightblue << "$MMMMN" << magenta << ".........." << lightblue << "=MMMMMM" << magenta << "................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << ".." << lightblue << "8MMMMO" << magenta << ".........." << lightblue << "MMMMM=" << magenta << "." << lightblue << "OMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM?MMMMMMMM=" << magenta << "......" << lightblue << "?MMMNODMMMM" << magenta << ".............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMMDMMMMMMMM" << magenta << "......." << lightblue << "MMMMMMMMM8MM" << magenta << "........" << endl << endl << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMDNNNNNNNMMM" << magenta << "............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM" << magenta << "........" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMDNNNNNNNMMM" << magenta << "............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM" << magenta << "........" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMI" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM," << magenta << "......." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMM" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << ",MMM" << magenta << "......." << lightblue << "MMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "IMMM" << magenta << "......................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "...." << lightblue << "MMMO" << magenta << "...." << lightblue << "?MMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "ZMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "." << lightblue << "$MMMMN" << magenta << ".........." << lightblue << "=MMMMMM" << magenta << "................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << ".." << lightblue << "8MMMMO" << magenta << ".........." << lightblue << "MMMMM=" << magenta << "." << lightblue << "OMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM?MMMMMMMM=" << magenta << "......" << lightblue << "?MMMNODMMMM" << magenta << ".............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMMDMMMMMMMM" << magenta << "......." << lightblue << "MMMMMMMMM8MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MMM8" << magenta << "...." << lightblue << ".MMM" << magenta << "....." << lightblue << "$MM?" << magenta << "......" << lightblue << "MMM" << magenta << "............." << lightblue << "MMMZZ$$$$$" << magenta << "......" << lightblue << "MMMM?" << magenta << "....." << lightblue << "MMM" << magenta << "....." << lightblue << "MMM?" << magenta << "....." << lightblue << "NMMM" << magenta << "........" << endl << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMDNNNNNNNMMM" << magenta << "............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM" << magenta << "........" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMDNNNNNNNMMM" << magenta << "............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM" << magenta << "........" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMI" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM," << magenta << "......." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMM" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << ",MMM" << magenta << "......." << lightblue << "MMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "IMMM" << magenta << "......................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "...." << lightblue << "MMMO" << magenta << "...." << lightblue << "?MMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Sleep(200);
	system("cls");

	cout << "..........................................................................................................................." << endl;
	cout << "....." << lightblue << "MMMMMMMMMMMMMMMMZ" << magenta << ".." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMMMMMMMMMMM" << magenta << "................................" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "........................................" << lightblue << "MMD" << magenta << "........................................." << lightblue << "ZMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM:" << magenta << "." << lightblue << "$MMMMN" << magenta << ".........." << lightblue << "=MMMMMM" << magenta << "................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << ".." << lightblue << "8MMMMO" << magenta << ".........." << lightblue << "MMMMM=" << magenta << "." << lightblue << "OMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM?MMMMMMMM=" << magenta << "......" << lightblue << "?MMMNODMMMM" << magenta << ".............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMMDMMMMMMMM" << magenta << "......." << lightblue << "MMMMMMMMM8MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MMM8" << magenta << "...." << lightblue << ".MMM" << magenta << "....." << lightblue << "$MM?" << magenta << "......" << lightblue << "MMM" << magenta << "............." << lightblue << "MMMZZ$$$$$" << magenta << "......" << lightblue << "MMMM?" << magenta << "....." << lightblue << "MMM" << magenta << "....." << lightblue << "MMM?" << magenta << "....." << lightblue << "NMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM~" << magenta << "......" << lightblue << "+MMZ" << magenta << "...." << lightblue << "MMN" << magenta << "......." << lightblue << "7MM" << magenta << "............." << lightblue << "MMMMMMMMMM" << magenta << "......" << lightblue << "MMM" << magenta << "......." << lightblue << "DMM," << magenta << "..." << lightblue << "IMM" << magenta << "........" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMDNNNNNNNMMM" << magenta << "............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM" << magenta << "........" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMDNNNNNNNMMM" << magenta << "............." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM" << magenta << "........" << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMI" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << "IMM," << magenta << "......." << lightblue << "$MM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "MMM" << magenta << "......................." << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "..." << lightblue << ",MMM" << magenta << "......." << lightblue << "MMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "...." << lightblue << "IMMM" << magenta << "......................" << lightblue << "MMD" << magenta << "............." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "...." << lightblue << "MMMO" << magenta << "...." << lightblue << "?MMMM" << magenta << "........" << endl;
	cout << magenta << "............" << lightblue << "MMM" << magenta << "........." << lightblue << "7MM," << magenta << "......." << lightblue << "MMD" << magenta << "....." << lightblue << "=MMMMMMMMMMM" << magenta << "............." << lightblue << "MMMMMMMMMMMM" << magenta << "...." << lightblue << "MMM" << magenta << "......." << lightblue << "?MM~" << magenta << "....." << lightblue << "MMMMMMMMM" << magenta << "." << lightblue << "MM" << magenta << "........" << endl;

	Sleep(1200);
	cout << magenta << "...........................................................................................................................\n";
	Sleep(300);
	cout << magenta << "......................................." << lightblue << "............................................." << magenta << ".......................................\n";
	Sleep(300);
	cout << magenta << "......................................." << lightblue << "." << magenta << "." << lightblue << "Group" << magenta << "." << lightblue << "project" << magenta << "." << lightblue << "by:" << magenta << "........................." << lightblue << "." << magenta << ".......................................\n";
	Sleep(300);
	cout << magenta << "......................................." << lightblue << "." << magenta << "................." << lightblue << "Dan" << magenta << "." << lightblue << "Curley," << magenta << "..............." << lightblue << "." << magenta << ".......................................\n";
	Sleep(300);
	cout << magenta << "......................................." << lightblue << "." << magenta << "..................." << lightblue << "Joshua" << magenta << "." << lightblue << "Salkeld," << magenta << "........." << lightblue << "." << magenta << ".......................................\n";
	Sleep(300);
	cout << magenta << "......................................." << lightblue << "." << magenta << "....................." << lightblue << "and" << magenta << "." << lightblue << "Sebastian" << magenta << "." << lightblue << "Newbold" << magenta << "." << lightblue << "." << magenta << ".......................................\n";
	Sleep(300);
	cout << magenta << "......................................." << lightblue << "............................................." << magenta << ".......................................\n";
	Sleep(300);
	cout << magenta << "...........................................................................................................................\n";
	string input;

	getline(cin, input);
	for (int i = -1; i < input.length(); i++)
		cin.ignore();

	exit(0);
}
//End SN

void Ending(string &Location, int &PlayerHealth, bool &Sword, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	if (PlayerDeadEndRoyal)
	{
		system("cls");
		cout << lightred;
		cout << "Player, you have died. You fought well, but it wasn't enough. To make an example of you, your corpse is paraded through the city on a pike." << endl;
		PlaySound(TEXT("Royal_Kills.wav"), NULL, SND_SYNC);
		Sleep(300);
		cout << "The King makes an appearance at your punishment. To his subjects he shouts 'This is what happens when you defy the crown!' " << endl;
		Sleep(300);
		cout << "The Royal guard that slew you has been promoted to a Knight Grand Officer, and lives a cushy life." << normal << endl << endl;
		pressEnter();
		TheEndDisplay();
	}
	else if (PlayerDeadEndCap)
	{
		cout << lightred;
		cout << "Player, you have died. You fought well, but it wasn't enough." << endl;
		Sleep(400);
		cout << "The Captain looks down on your pale and lifeless form, and lets loose a grunt of disgust. He hefts you over his shoulder and carries you into the woods." << endl;
		Sleep(400);
		cout << "There he digs a shallow grave for you, and tosses your body in. Your story ends here. The Captain stumbles back to the Dungeon to sleep the rest of the night." << endl;
		PlaySound(TEXT("Captain_Kills.wav"), NULL, SND_SYNC);
		Sleep(400);
		cout << "Your fellow prisoners know nothing of your demise, though it is doubtful they would care either way." << normal << endl << endl;
		pressEnter();
		TheEndDisplay();
	}
	else if (CaptainDeadEnd)
	{
		system("cls");
		PlaySound(TEXT("Kills_Boss.wav"), NULL, SND_SYNC);
		cout << lightgreen;
		cout << "You finally reach the horse. It's a chestnut mare, sturdy but lean enough for the speed you need." << endl;
		Sleep(400);
		cout << "You give a last glance back at the dead Captain, the gates to the town, and the looming dungeon tower in the distance." << endl;
		cout << "With a disgusted grunt at your experience, you give the horse a firm smack and a 'Let's go' as you ride off into the dark." << normal << endl << endl;
		PlaySound(TEXT("Sneak_End.wav"), NULL, SND_SYNC);
		pressEnter();
		TheEndDisplay();
	}
	else if (RoyalGuardDeadEnd)
	{
		system("cls");
		PlaySound(TEXT("Kills_Boss.wav"), NULL, SND_SYNC);
		cout << lightgreen;
		cout << "You finally reach the horse. It's a chestnut mare, sturdy but lean enough for the speed you need." << endl;
		Sleep(400);
		cout << "You give a last glance back at the Royal Guard, the gates to the town, and the looming dungeon tower in the distance." << endl;
		Sleep(400); // Add ASCII art of horse riding into sunset here? In another function.
		cout << "With a disgusted grunt at your experience, you give the horse a firm smack and a 'Let's go' as you ride off into the dark." << normal << endl << endl;
		PlaySound(TEXT("Sneak_End.wav"), NULL, SND_SYNC);
		pressEnter();
		TheEndDisplay();
	}
	else
	{
		system("cls");
		cout << "You cannot believe the luck you have struck. You managed to reach the horse undetected and unharmed." << endl;
		Sleep(400);
		cout << "You give a last glance back at the town, and the looming dungeon tower in the distance." << endl;
		Sleep(400);
		cout << "With a disgusted grunt at your experience, you give the horse a firm smack and a 'Let's go, Roach' as your ride off into the dark." << normal << endl << endl;
		PlaySound(TEXT("Sneak_End.wav"), NULL, SND_SYNC);
		pressEnter();
		TheEndDisplay();
	}
}

//All of us wrote this
void RoyalBattle(string &Location, int &PlayerHealth, bool &Sword, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	string GetChoice;
	bool BadInput = true;
	bool BadInput2 = true;
	static bool SmithDeadOrIntim = false;
	int SmithHealth = 20;
	const int maxDamage = 4;
	int MissChance = 100;
	int playerMiss;
	int SmithMiss;
	string getChoice;
	int Damage;

	

	if (SmithDeadOrIntim == true)
	{
		Smith(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
	}
	else
	{

	}

	
	while (BadInput == true)
	{
		BadInput = false;
		system("cls");
		Sleep(300);
		cout << "With the Stable Master taken care of, you sit for a rest to regather your thoughts. " << endl << endl;
		Sleep(3000);
		cout << "With the Captain dead, you would think your worries to be over, your escape totally guaranteed." << endl;
		Sleep(300);
		cout << "Unfortunately, life rarely follows logic. As you rest among the hay piles, you hear the clank of gilded boots on the cobble." << endl; 
		PlaySound(TEXT("Guard_Footstep.wav"), NULL, SND_SYNC);
		Sleep(300);
		cout << "You look around the corner to see a member of the Royal Guard in your pursuit. He must have noticed the dead Guard Captain." << endl;
		Sleep(300);
		cout << "Without a word, he takes a fighting stance and takes a charge at you." << endl << endl;
		Sleep(300);
		cout << "Press 1 to attack him." << endl;

		getline(cin, GetChoice);
		if (GetChoice.at(0) == '1')
		{
			while (PlayerHealth > 0)
			{
				while (SmithHealth > 0)
				{
					system("cls");
					BadInput2 = true;
					MissChance = 100;
					cout << "Your health is " << PlayerHealth << "." << endl << endl;
					Sleep(300);
					cout << "Press 1 to hit the Royal Guard." << endl;
					Sleep(300);
					cout << "Press 2 to defend." << endl;
					Sleep(300);
					cout << "Selection: ";
					getline(cin, GetChoice);
					system("cls");
					if (GetChoice == "1")
					{
						playerMiss = (rand() % MissChance) + 1;
						if (playerMiss > 20)
						{
							if (SwordLv2 == true)
							{
								Damage = (rand() % maxDamage) + 3; //Sword Lv2 Damage between 3 and 6
								cout << endl << endl << lightcyan << "You swing at the Royal Guard dealing " << Damage << " damage." << normal << endl << endl;
								PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
								Sleep(300);
								SmithHealth -= Damage;
								if (SmithHealth <= 0)
								{
									break;
								}
							}
							else
							{
								Damage = (rand() % maxDamage) + 1; // Sword Lv1 damage between 1 and 4
								cout << endl << endl << lightcyan << "You swing at the Royal Guard dealing " << Damage << " damage." << normal << endl << endl;
								PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
								Sleep(300);
								SmithHealth -= Damage;
								if (SmithHealth <= 0)
								{
									break;
								}
							}
						}
						else
						{
							cout << endl << endl << red << "You swing at the Royal Guard dealing no damage. You missed." << endl << normal << endl;
							PlaySound(TEXT("Sword_Armor.wav"), NULL, SND_SYNC);
							Sleep(300);
						}
					}
					else if (GetChoice == "2")
					{
						cout << cyan << endl << endl << "You bring your sword up and get ready for the Royal Guard's attack." << normal << endl << endl;
						Sleep(300);
						MissChance = 50;
					}
					else
					{
						BadInput2 = true;
					}


					if (Armor == true)
					{
						MissChance -= 25;

						SmithMiss = (rand() % MissChance) + 1;

						Damage = (rand() % maxDamage) + 3;

						if (SmithMiss < 25)
						{
							cout << lightgreen << "The Royal Guard swings his axe towards you and it glances off your armor." << normal << endl << endl;
							PlaySound(TEXT("Sword_Armor.wav"), NULL, SND_SYNC);
							pressEnter();
						}
						else
						{
							cout << lightred << "The Royal Guard's axe connects with you dealing " << Damage << " damage." << normal << endl << endl;
							PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
							pressEnter();
							PlayerHealth -= Damage;
							if (PlayerHealth <= 0)
							{
								break;
							}
						}
					}
					else
					{
						Damage = (rand() % maxDamage) + 3;

						SmithMiss = (rand() % MissChance) + 1;

						if (SmithMiss < 25)
						{
							cout << lightgreen << "The Royal Guard swings his axe towards you and it misses." << normal << endl << endl;
							PlaySound(TEXT("Sword_Air.wav"), NULL, SND_SYNC);
							pressEnter();
						}
						else
						{
							cout << lightred << "The Royal Guard's axe connects with you dealing " << Damage << " damage." << normal << endl << endl;
							PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
							pressEnter();
							PlayerHealth -= Damage;
							if (PlayerHealth <= 0)
							{
								break;
							}
						}
					}
				}
				if (SmithHealth <= 0)
				{
					pressEnter();
					system("cls");
					cout << normal << "This Royal Guard was ruthless and a true challenge. His gilded armor is slick with ichor from both you and he. " << endl;
					cout << "He falls to the ground, cursing your name to the heavens as he draws his last breath. Your hardship is over. You can escape now." << endl << endl;
					PlaySound(TEXT("Uncon_Body.wav"), NULL, SND_SYNC);
					pressEnter();
					break;
				}
			}
			if (PlayerHealth <= 0)
			{
				PlayerDeadEndRoyal = true;
				Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
			else
			{
				RoyalGuardDeadEnd = true;
				Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
		}
		else
		{
			BadInput = true;
		}
	}
}
void CaptainBattle(string &Location, int &PlayerHealth, bool &Sword, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	string GetChoice;
	bool BadInput = true;
	bool BadInput2 = true;
	int SmithHealth = 16;
	const int maxDamage = 4;
	int MissChance = 100;
	int playerMiss;
	int SmithMiss;
	string getChoice;
	int Damage;
	bool boolean1 = false;
	
	while (BadInput == true)
	{
		BadInput = false;
		system("cls");
		cout << "With the Stable Master dealt with, you take momentary rest to regather your thoughts." << endl << endl;
		Sleep(3000);
		cout << "You hear footsteps on the cobblestone leading up to the Stables. You peak around the corner of the building " << endl;
		PlaySound(TEXT("Guard_Footstep.wav"), NULL, SND_SYNC);
		Sleep(300);
		cout << "to see a very angry-looking Captain of the Guard. You knew you should have killed him when you had the chance." << endl;
		Sleep(300);

		cout << lightred << "Stop! You have committed crimes against the land and are a fugitive from the law!" << endl << endl;
		Sleep(300);
		cout << normal << "He stands ready for battle." << endl << endl;
		Sleep(300);
		cout << "Press 1 to attack him." << endl;
		boolean1 = false;
		cin >> GetChoice;
		if (GetChoice == "1")
		{
			while (PlayerHealth > 0)
			{
				while (SmithHealth > 0)
				{
					if (boolean1 == true)
						cin.ignore();

					boolean1 = true;
					system("cls");
					MissChance = 100;
					BadInput2 = true;
					cout << "Your health is " << PlayerHealth << "." << endl << endl;
					Sleep(300);
					cout << "Press 1 to hit the captain." << endl;
					Sleep(300);
					cout << "Press 2 to defend." << endl;
					Sleep(300);
					cout << "Selection: ";
					cin >> GetChoice;
					system("cls");
					if (GetChoice == "1")
					{
						playerMiss = (rand() % MissChance) + 1;
						if (playerMiss > 20)
						{
							if (SwordLv2 == true)
							{
								Damage = (rand() % maxDamage) + 3; //Sword Lv2 Damage between 3 and 6
								cout << endl << endl << lightcyan << "You swing at the captain dealing " << Damage << " damage." << normal << endl << endl;
								PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
								Sleep(300);
								SmithHealth -= Damage;
								if (SmithHealth <= 0)
								{
									break;
								}
							}
							else
							{
								Damage = (rand() % maxDamage) + 1; // Sword Lv1 damage between 1 and 4
								cout << endl << endl << lightcyan << "You swing at the captain dealing " << Damage << " damage." << normal << endl << endl;
								PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
								Sleep(300);
								SmithHealth -= Damage;
								if (SmithHealth <= 0)
								{
									break;
								}
							}
						}
						else
						{
							cout << endl << endl << red << "You swing at the captain dealing no damage. You missed." << endl << normal << endl;
							PlaySound(TEXT("Sword_Armor.wav"), NULL, SND_SYNC);
							Sleep(300);
						}
					}
					else if (GetChoice == "2")
					{
						cout << cyan << endl << endl << "You bring your sword up and get ready for the captain's attack." << normal << endl << endl;
						Sleep(300);
						MissChance = 50;
					}
					else
					{
						BadInput2 = true;
					}


					if (Armor == true)
					{
						MissChance -= 25;

						SmithMiss = (rand() % MissChance) + 1;

						Damage = (rand() % maxDamage) + 2;

						if (SmithMiss < 25)
						{
							cout << lightgreen << "The captain swings his sword towards you and it glances off your armor." << normal << endl << endl;
							PlaySound(TEXT("Sword_Armor.wav"), NULL, SND_SYNC);
							pressEnter();
							Sleep(300);
						}
						else
						{
							cout << lightred << "The captain's sword connects with you dealing " << Damage << " damage." << normal << endl << endl;
							PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
							pressEnter();
							Sleep(300);
							PlayerHealth -= Damage;
							if (PlayerHealth <= 0)
							{
								break;
							}
						}
					}
					else
					{
						Damage = (rand() % maxDamage) + 1;

						SmithMiss = (rand() % MissChance) + 1;

						if (SmithMiss < 25)
						{
							cout << lightgreen << "The captain swings his sword towards you and it misses." << normal << endl << endl;
							PlaySound(TEXT("Sword_Air.wav"), NULL, SND_SYNC);
							pressEnter();
							Sleep(300);
						}
						else
						{
							cout << lightred << "The captain's sword connects with you dealing " << Damage << " damage." << normal << endl << endl;
							PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
							pressEnter();
							Sleep(300);
							PlayerHealth -= Damage;
							if (PlayerHealth <= 0)
							{
								break;
							}
						}
					}
				}
				if (SmithHealth <= 0)
				{
					cin.ignore();
					pressEnter();
					system("cls");
					cout << normal << "The Captain sways in place, woozy from his blood loss. You kick your oppressor in the knee, snapping his meaty femur. " << endl;
					PlaySound(TEXT("Bone_Snap.wav"), NULL, SND_SYNC);
					Sleep(300);
					cout << "You can't help but swagger and gloat a little bit as you stand over him, taunting his dying form." << endl;
					Sleep(300);
					cout << "As a send-off, you skewer his torso with your sword and watch the life drain from his eyes." << endl << endl;
					Sleep(300);
					pressEnter();
					Sleep(300);
					break;
				}
			}
			if (PlayerHealth <= 0)
			{
				PlayerDeadEndCap = true;
				Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
			else
			{
				CaptainDeadEnd = true;
				Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
		}
		else
		{
			BadInput = true;
		}
	}
}

void StableMasterBattle(string &Location, int &PlayerHealth, bool &Sword, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	string GetChoice;
	bool BadInput = true;
	bool BadInput2 = true;
	int IntimChance = 100;
	int DidIntim;
	static bool SmithDeadOrIntim = false;
	int SmithHealth = 3;
	const int maxDamage = 4;
	int MissChance = 100;
	int playerMiss;
	int SmithMiss;
	string getChoice;
	int Damage;
	bool boolean1 = false;

	
	while (BadInput == true)
	{
		BadInput = false;
		system("cls");
		Sleep(300);
		cout << "You turn and see the Stable Master coming out of the stables with a dagger drawn."<< endl << endl;
		Sleep(300);
		cout << "He walks towards you and shouts: " << lightred << "'Get the hell off of my property!' " << normal << endl;
		Sleep(300);
		cout <<  "He stands ready for battle." << endl << endl;
		Sleep(300);
		cout << "You can either attack now or attempt to intimidate him to go back upstairs." << endl << endl;
		Sleep(300);
		cout << "Press 1 to intimidate him." << endl;
		Sleep(300);
		cout << "Press 2 to attack him." << endl;
		boolean1 = false;
			
		cin >> GetChoice;
		if (GetChoice == "1")
		{
			DidIntim = (rand() % IntimChance);
			if (DidIntim <= 35)
			{
				system("cls");
				Sleep(300);
				cout << "You turn and draw your sword. 'Get back inside and nobody get's hurt'. The Stable Master's face drops as he slowly backs into the building." << endl << endl;
				Sleep(300);
				cout << "You hear a door close. You're safe for now but you better finish up here soon." << endl << endl;
				Sleep(300);
				cin.ignore();
				pressEnter();
				SmithDeadOrIntim = true;
				if (CaptainDead)
				{
					RoyalBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
				else
				{
					CaptainBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
			}
			else
			{
				system("cls");
				Sleep(300);
				cout << "You turn and draw your sword. 'Get back inside and nobody get's hurt'." << endl << endl;
				Sleep(300);
				cout << "He chuckles, " << lightred << "not a chance buddy." << normal << " He steps forward ready for a fight." << endl << endl;
				cin.ignore();
				pressEnter();
				system("cls");
				while (PlayerHealth > 0)
				{
					while (SmithHealth > 0)
					{
						//boolean1 makes sure cin.ignore(); is only missed the first time.
						if (boolean1 == true)
							cin.ignore();

						boolean1 = true;
						system("cls");
						BadInput2 = true;
						MissChance = 100;
						cout << "Your health is " << PlayerHealth << "." << endl << endl;
						Sleep(300);
						cout << "Press 1 to hit the Stable Master." << endl;
						Sleep(300);
						cout << "Press 2 to defend." << endl;
						Sleep(300);
						cout << "Selection: ";
						cin >> GetChoice;
						
						system("cls");
						if (GetChoice == "1")
						{
							playerMiss = (rand() % MissChance) + 1;
							if (playerMiss > 20)
							{
								if (SwordLv2 == true)
								{
									Damage = (rand() % maxDamage) + 3; //Sword Lv2 Damage between 3 and 6
									cout << endl << endl << lightcyan << "You swing at the Stable Master dealing " << Damage << " damage." << normal << endl << endl;
									PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
									Sleep(300);
									SmithHealth -= Damage;
									if (SmithHealth <= 0)
									{
										break;
									}
								}
								else
								{
									Damage = (rand() % maxDamage) + 1; // Sword Lv1 damage between 1 and 4
									cout << endl << endl << lightcyan << "You swing at the Stable Master dealing " << Damage << " damage." << normal << endl << endl;
									PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
									Sleep(300);
									SmithHealth -= Damage;
									if (SmithHealth <= 0)
									{
										break;
									}
								}
							}
							else
							{
								system("cls");
								cout << endl << endl << red << "You swing at the Stable Master dealing no damage. You missed." << endl << normal << endl;
								PlaySound(TEXT("Sword_Air.wav"), NULL, SND_SYNC);
								Sleep(300);
							}
						}
						else if (GetChoice == "2")
						{
							system("cls");
							cout << cyan << endl << endl << "You bring your sword up and get ready for the Stable Master's attack." << normal << endl << endl;
							Sleep(300);
							MissChance = 50;
						}
						else
						{
							BadInput2 = true;
						}


						if (Armor == true)
						{
							MissChance -= 25;

							SmithMiss = (rand() % MissChance) + 1;

							Damage = (rand() % maxDamage) + 1;

							if (SmithMiss < 25)
							{
								cout << lightgreen << "The Stable Master thrusts his dagger at you and it glances off your armor." << normal << endl << endl;
								PlaySound(TEXT("Sword_Armor.wav"), NULL, SND_SYNC);
								pressEnter();
							}
							else
							{
								cout << lightred << "The Stable Master's dagger connects with you dealing " << Damage << " damage." << normal << endl << endl;
								PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
								pressEnter();
								PlayerHealth -= Damage;
								if (PlayerHealth <= 0)
								{
									break;
								}
							}
						}
						else
						{
							Damage = (rand() % maxDamage) + 1;

							SmithMiss = (rand() % MissChance) + 1;

							if (SmithMiss < 25)
							{
								cout << lightgreen << "The Stable Master thrusts his dagger at you but it misses." << normal << endl << endl;
								PlaySound(TEXT("Sword_Air.wav"), NULL, SND_SYNC);
								pressEnter();
							}
							else
							{
								cout << lightred << "The Stable Master's dagger connects with you dealing " << Damage << " damage." << normal << endl << endl;
								PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
								pressEnter();
								PlayerHealth -= Damage;
								if (PlayerHealth <= 0)
								{
									break;
								}
							}
						}
					}
					if (SmithHealth <= 0)
					{
						cout << normal << "You hit the Stable Master with the hilt of your sword and he falls to the ground unconscious." << endl << endl;
						PlaySound(TEXT("Uncon_Body.wav"), NULL, SND_SYNC);
						cin.ignore();
						pressEnter();
						break;
					}
				}
				if (PlayerHealth <= 0)
				{
					PlayerDeath();
				}
				else
				{
					SmithDeadOrIntim = true;
					if (CaptainDead)
					{
						RoyalBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						CaptainBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
				}
			}
		}
		else if (GetChoice == "2")
		{
			while (PlayerHealth > 0)
			{
				while (SmithHealth > 0)
				{
					if (boolean1 == true)
						cin.ignore();

					boolean1 = true;
					system("cls");
					BadInput2 = true;
					MissChance = 100;
					cout << "Your health is " << PlayerHealth << "." << endl << endl;
					Sleep(300);
					cout << "Press 1 to hit the Stable Master." << endl;
					Sleep(300);
					cout << "Press 2 to defend." << endl;
					Sleep(300); 
					cout << "Selection: ";
					cin >> GetChoice;
					system("cls");
					if (GetChoice == "1")
					{
						playerMiss = (rand() % MissChance) + 1;
						if (playerMiss > 20)
						{
							if (SwordLv2 == true)
							{
								Damage = (rand() % maxDamage) + 3; //Sword Lv2 Damage between 3 and 6
								cout << endl << endl << lightcyan << "You swing at the Stable Master dealing " << Damage << " damage." << normal << endl << endl;
								PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
								Sleep(300);
								SmithHealth -= Damage;
								if (SmithHealth <= 0)
								{
									break;
								}
							}
							else
							{
								Damage = (rand() % maxDamage) + 1; // Sword Lv1 damage between 1 and 4
								cout << endl << endl << lightcyan << "You swing at the Stable Master dealing " << Damage << " damage." << normal << endl << endl;
								PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
								Sleep(300);
								SmithHealth -= Damage;
								if (SmithHealth <= 0)
								{
									break;
								}
							}
						}
						else
						{
							cout << endl << endl << red << "You swing at the Stable Master dealing no damage. You missed." << endl << normal << endl;
							PlaySound(TEXT("Sword_Air.wav"), NULL, SND_SYNC);
							Sleep(300);
						}
					}
					else if (GetChoice == "2")
					{
						cout << cyan << endl << endl << "You bring your sword up and get ready for the Stable Master's attack." << normal << endl << endl;
						Sleep(300);
						MissChance = 50;
					}
					else
					{
						BadInput2 = true;
					}


					if (Armor == true)
					{
						MissChance -= 25;

						SmithMiss = (rand() % MissChance) + 1;

						Damage = (rand() % maxDamage) + 1;

						if (SmithMiss < 25)
						{
							cout << lightgreen << "The Stable Master thrusts his dagger at you and it glances off your armor." << normal << endl << endl;
							PlaySound(TEXT("Sword_Armor.wav"), NULL, SND_SYNC);
							pressEnter();
						}
						else
						{
							cout << lightred << "The Stable Master's dagger connects with you dealing " << Damage << " damage." << normal << endl << endl;
							PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
							pressEnter();
							PlayerHealth -= Damage;
							if (PlayerHealth <= 0)
							{
								break;
							}
						}
					}
					else
					{
						Damage = (rand() % maxDamage) + 1;

						SmithMiss = (rand() % MissChance) + 1;

						if (SmithMiss < 25)
						{
							cout << lightgreen << "The Stable Master thrusts his dagger at you and it misses you." << normal << endl << endl;
							PlaySound(TEXT("Sword_Air.wav"), NULL, SND_SYNC);
							pressEnter();
						}
						else
						{
							cout << lightred << "The Stable Master's dagger connects with you dealing " << Damage << " damage." << normal << endl << endl;
							PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
							pressEnter();
							PlayerHealth -= Damage;
							if (PlayerHealth <= 0)
							{
								break;
							}
						}
					}
				}
				if (SmithHealth <= 0)
				{
					cout << normal << "You hit the Stable Master with the hilt of your sword and he falls to the ground unconscious." << normal << endl << endl;
					PlaySound(TEXT("Uncon_Body.wav"), NULL, SND_SYNC);
					cin.ignore();
					pressEnter();
					break;
				}
			}
			if (PlayerHealth <= 0)
			{
				PlayerDeath();
			}
			else
			{
				SmithDeadOrIntim = true;
				if (CaptainDead)
				{
					RoyalBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
				else
				{
					CaptainBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
			}
		}
		else
		{
			BadInput = true;
		}
	}
}
//End all

void Stables(string &Location, int &PlayerHealth, bool &Sword, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	int i = 0;
	int x = 0;
	bool test = true;
	char PlayerIcon = 'P';
	char move;
	static int playerVert = 22; //The two static variables is the initial spawn point.
	static int PlayerHoriz = 3;
	int PlayerTempVert;
	int PlayerTempHoriz;
	int Check;
	string GetChoice;
	bool BadInput = true;
	bool Lock = false;
	int SneakChance = 100;
	int Caught;

	const int ROWS = 25, COLS = 21;


	char StableMap[ROWS][COLS] = {
		{ ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' },
		{ ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' },
		{ ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' },
		{ ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' },
		{ ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'B' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' },
		{ ' ' , ' ' , ' ' , 'B' , 'B' , 'B' , 'B' , 'B' , 'V' , 'V' , 'B', 'B' , 'B' , 'B' , 'B' , '-' , '-' , ' ' , '-' , '-' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , '|', ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , '|' , ' ' , ' ' },
		{ ' ' , '|' , '-' , '-' , '-' , '-' , '-' , '-' , ' ' , ' ' , '-', '-' , '-' , '-' , '-' , '-' , '|' , ' ' , '|' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , '-' , '-' , '-' , '-' , '-', '-' , '-' , '-' , '-' , '-' , '-' , '-' , '|' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , '|' , 'V' , 'V' , 'V' , '|' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' }
	};

	StableMap[playerVert][PlayerHoriz] = 'P'; //sets the player character to 'P'


	while (test) //This while loop is what draws the map
	{
		while (x < 24)
		{
			if (i == 0)
			{
				system("cls");
				cout << " " << " " << " " << " " << " " << " " << " " << " ";
			}
			cout << StableMap[x][i];

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

		Caught = (rand() % SneakChance);

		cout << "W, A, S, or D: "; // W moves up, A moves left, S moves down, D moves right. Must hit enter after every one.
		cin >> move;

		if (move == 'w')
		{
			if (Armor)
			{
				if (Caught <= 20)
				{
					Check = playerVert - 1;

					if (StableMap[Check][PlayerHoriz] == 'B' || StableMap[Check][PlayerHoriz] == '-' || StableMap[Check][PlayerHoriz] == '|' || StableMap[Check][PlayerHoriz] == 'V')
					{

					}
					else if (StableMap[6][17] == 'P')
					{
						Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						PlayerTempVert = playerVert;
						PlayerTempHoriz = PlayerHoriz;
						playerVert = playerVert - 1;
						PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
					}
				}
				else
				{
					StableMasterBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
			}
			else if (!Armor)
			{
				if (Caught <= 80)
				{
					Check = playerVert - 1;

					if (StableMap[Check][PlayerHoriz] == 'B' || StableMap[Check][PlayerHoriz] == '-' || StableMap[Check][PlayerHoriz] == '|' || StableMap[Check][PlayerHoriz] == 'V')
					{

					}
					else if (StableMap[6][17] == 'P')
					{
						Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						PlayerTempVert = playerVert;
						PlayerTempHoriz = PlayerHoriz;
						playerVert = playerVert - 1;
						PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
					}
				}
				else
				{
					StableMasterBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
			}
			else
			{
				Check = playerVert - 1;

				if (StableMap[Check][PlayerHoriz] == 'B' || StableMap[Check][PlayerHoriz] == '-' || StableMap[Check][PlayerHoriz] == '|' || StableMap[Check][PlayerHoriz] == 'V')
				{

				}
				else if (StableMap[6][17] == 'P')
				{
					Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
				else
				{
					PlayerTempVert = playerVert;
					PlayerTempHoriz = PlayerHoriz;
					playerVert = playerVert - 1;
					PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
				}
			}
		}
		else if (move == 'a')
		{
			if (Armor)
			{
				if (Caught <= 20)
				{
					Check = PlayerHoriz - 1;
					if (StableMap[playerVert][Check] == '|')
					{

					}
					else if (StableMap[6][17] == 'P')
					{
						Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						PlayerTempVert = playerVert;
						PlayerTempHoriz = PlayerHoriz;
						PlayerHoriz = PlayerHoriz - 1;
						PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
					}
				}
				else
				{
					StableMasterBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
			}
			else if (!Armor)
			{
				if (Caught <= 80)
				{
					Check = PlayerHoriz - 1;
					if (StableMap[playerVert][Check] == '|')
					{

					}
					else if (StableMap[6][17] == 'P')
					{
						Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						PlayerTempVert = playerVert;
						PlayerTempHoriz = PlayerHoriz;
						PlayerHoriz = PlayerHoriz - 1;
						PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
					}
				}
				else
				{
					StableMasterBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
			}
			else
			{
				Check = PlayerHoriz - 1;
				if (StableMap[playerVert][Check] == '|')
				{

				}
				else if (StableMap[6][17] == 'P')
				{
					Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
				else
				{
					PlayerTempVert = playerVert;
					PlayerTempHoriz = PlayerHoriz;
					PlayerHoriz = PlayerHoriz - 1;
					PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
				}
			}
		}
		else if (move == 's')
		{
			if (Armor)
			{
				if (Caught <= 20)
				{
					Check = playerVert + 1;

					if (StableMap[Check][PlayerHoriz] == 'B' || StableMap[Check][PlayerHoriz] == '-' || StableMap[Check][PlayerHoriz] == '|')
					{

					}
					else if (StableMap[6][17] == 'P')
					{
						Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						PlayerTempVert = playerVert;
						PlayerTempHoriz = PlayerHoriz;
						playerVert = playerVert + 1;
						PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
					}
				}
				else
				{
					StableMasterBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
			}
			else if (!Armor)
			{
				if (Caught <= 80)
				{
					Check = playerVert + 1;

					if (StableMap[Check][PlayerHoriz] == 'B' || StableMap[Check][PlayerHoriz] == '-' || StableMap[Check][PlayerHoriz] == '|')
					{

					}
					else if (StableMap[6][17] == 'P')
					{
						Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						PlayerTempVert = playerVert;
						PlayerTempHoriz = PlayerHoriz;
						playerVert = playerVert + 1;
						PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
					}
				}
				else
				{
					StableMasterBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
			}
			else
			{
				Check = playerVert + 1;

				if (StableMap[Check][PlayerHoriz] == 'B' || StableMap[Check][PlayerHoriz] == '-' || StableMap[Check][PlayerHoriz] == '|')
				{

				}
				else if (StableMap[6][17] == 'P')
				{
					Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
				else
				{
					PlayerTempVert = playerVert;
					PlayerTempHoriz = PlayerHoriz;
					playerVert = playerVert + 1;
					PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
				}
			}
		}
		else if (move == 'd')
		{
			if (Armor)
			{
				if (Caught <= 20)
				{
					Check = PlayerHoriz + 1;
					if (StableMap[playerVert][Check] == '|')
					{

					}
					else if (StableMap[6][17] == 'P')
					{
						Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						PlayerTempVert = playerVert;
						PlayerTempHoriz = PlayerHoriz;
						PlayerHoriz = PlayerHoriz + 1;
						PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
					}
				}
				else
				{
					StableMasterBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
			}
			else if (!Armor)
			{
				if (Caught <= 80)
				{
					Check = PlayerHoriz + 1;
					if (StableMap[playerVert][Check] == '|')
					{

					}
					else if (StableMap[6][17] == 'P')
					{
						Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						PlayerTempVert = playerVert;
						PlayerTempHoriz = PlayerHoriz;
						PlayerHoriz = PlayerHoriz + 1;
						PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
					}
				}
				else
				{
					StableMasterBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
			}
			else
			{
				Check = PlayerHoriz + 1;
				if (StableMap[playerVert][Check] == '|')
				{

				}
				else if (StableMap[6][17] == 'P')
				{
					Ending(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
				else
				{
					PlayerTempVert = playerVert;
					PlayerTempHoriz = PlayerHoriz;
					PlayerHoriz = PlayerHoriz + 1;
					PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
				}
			}
		}
		else
		{

		}

		StableMap[PlayerTempVert][PlayerTempHoriz] = ' ';
		StableMap[playerVert][PlayerHoriz] = 'P';


	}
}

//Functions: Inn, Smith, Clothes, AlcShop, Prison Outlined by Joshua Salkeld

//Map and movement written by Joshua Salkeld, Everything else by Dan Curley
string Inn(string &Location, int &PlayerHealth, bool &Sword, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	static bool Lock = false;
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

	if (Lock == true)
	{
		system("cls");
		cout << "The door is locked. You cannot enter." << endl;
		pressEnter();
		tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
	}
	else
	{

	}
	Lock = true;
	
	Sleep(900);

	PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);

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
					while (badInput)
					{
						system("cls");
						cout << "You approach the bar." << endl << endl;
						Sleep(300);
						cout << "You are surprised to find the Innkeeper up at this hour, though grateful nonetheless." << endl << endl;
						Sleep(300);
						cout << " 'A pint of ale, please,' you request, your voice barely above a whisper. It seems rude to defile the silence of the Inn." << endl << endl;
						Sleep(300);
						cout << "As the Innkeeper turns to gather a glass, you spot a massive scar on the running along the back of his neck." << endl << endl;
						Sleep(300);
						cout << "1. Remain Silent." << endl;
						cout << "2. 'What's the story behind that scar?'" << endl;
						

						getline(cin, getChoice);
						system("cls");
						//Where ever the dialogue tree ends just make sure to put badinput = false; in it. That will break out of the loop and allow the game to continue.
						//Also this part is important! to simplify things for the player whenever the loop ends with badInput = false; you NEED to put tempFunc(Location, Sword, PlayerHealth, CaptainDead);
						//That will respawn the player outside the Inn. 
						if (getChoice == "1")
						{
							cout << "You remain silent as the Innkeeper slides the Pint down the tabletop to your waiting hand." << endl << endl;
							pressEnter();
							Sleep(300);
							badInput = false;
							Lock = true;
							PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
							tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
						}

						else if (getChoice == "2")
						{
							cout << "Curiousity gets the better of you. 'Lose a fight with a wolf?' The Innkeeper looks at you with a mildly amused smirk." << endl << endl;
							Sleep(250);
							cout << "'No, actually. During the war all of those years ago, one of the King's thugs took a blade to my throat." << endl << endl;
							Sleep(250);
							cout << "I managed to turn away just in time to save my own hide, but I took the brunt of the blow right there.' " << endl << endl;
							Sleep(250);
							cout << "He turns again to show you the battlescar, more up close and personal." << endl << endl;
							Sleep(300);
							cout << "1. 'Not a fan of the King, I see. I can't blame you. That rat had me imprisoned for 'treason.' " << endl;
							cout << "2. 'I take it you weren't exactly on the King's side, then?' " << endl;
							Sleep(250);

							getline(cin, getChoice);
							system("cls");

							if (getChoice == "1")
							{
								cout << "'Treason? Really?' He seems not to believe your tale." << endl << endl;
								Sleep(250);
								cout << "You explain to him that your only crime was petty theft from the Castle grounds. You were only desperate for your next meal." << endl << endl;
								Sleep(250);
								cout << "Unfortunately for you, the King decided it was good day to make an example out his subject. At least you weren't put to the Gallows." << endl << endl;
								Sleep(250);
								cout << "'That sounds like him, alright. When I met his knights on the field of battle, he was completely ruthless in his command as well." << endl << endl;
								Sleep(250);
								cout << "His men spared nobody their life. He brought terrible weapons of fire against even his own villages, on the mere suspicion that " << endl << endl;
								cout << "one of us may be hiding there. In fact, that's where I was found. I was run out of a burning house only to be attacked in my retreat." << endl << endl;
								Sleep(100);
								cout << "He was the size of a tree, it seemed. He took a swing at me with his blade. I jumped out of the way just in time to not be knicked.'" << endl << endl;
								Sleep(100);
								cout << "The Innkeeper continues his recounting of his battle with the King's forces. In the process, he shares with you some techniques that " << endl << endl;
								cout << "he and his shield-brothers learned during battle. You are enthralled by his magnificent struggle and close shave with death. " << endl << endl;
								Sleep(300);
								cout << "The Innkeeper wraps up his story. You thank him for the drink, and ask that a bar tab be opened under your name. To your pleasant surprise, " << endl << endl;
								cout << "he tells you it was 'on the house.' You thank him for his generosity, and leave the Inn." << endl << endl;
								pressEnter();
								system("cls");
								PlaySound(TEXT("Inn_Upgrade.wav"), NULL, SND_SYNC);
								WarStory10 = true;
								badInput = false;
								Lock = true;
								PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
								tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
							}

							else if (getChoice == "2")
							{
								cout << "'Of course not! Who could support a tyrant like him? No, I wanted nothing less than his head on a pike.'" << endl << endl;
								Sleep(250);
								cout << "As it turns out, he got part of his wish in the form of the King's soldier's head on a pike. The one that gave him that battlescar." << endl << endl;
								Sleep(250);
								cout << "While you are happy to know of his triumph, you can't help but grow more and more uncomfortable over the story he seems to be lost in." << endl << endl;
								Sleep(250);
								cout << "He recounts a bloody, overblown tale of violence and battle. Even through your unease at the story, you do manage to pick up some rather uncouth battle techniques." << endl << endl;
								Sleep(250);
								cout << "As he takes your glass to be cleaned, you awkwardly shuffle out of the Inn and avoid the payment for the drink. Anything to get out of there!" << endl << endl;
								pressEnter();
								system("cls");

								PlaySound(TEXT("Inn_Upgrade.wav"), NULL, SND_SYNC);
								WarStory5 = true;
								badInput = false;
								Lock = true;
								PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
								tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);

							}

							else
							{
								badInput = true;
							}


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
				PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
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
						system("cls");
						cout << "You approach the bar." << endl << endl;
						Sleep(300);
						cout << "You are surprised to find the Innkeeper up at this hour, though grateful nonetheless." << endl << endl;
						Sleep(300);
						cout << " 'A pint of ale, please,' you request, your voice barely above a whisper. It seems rude to defile the silence of the Inn." << endl << endl;
						Sleep(300);
						cout << "As the Innkeeper turns to gather a glass, you spot a massive scar on the running along the back of his neck." << endl << endl;
						Sleep(300);
						cout << "1. Remain Silent." << endl;
						cout << "2. 'What's the story behind that scar?'" << endl;
						

						getline(cin, getChoice);
						system("cls");
						//Where ever the dialogue tree ends just make sure to put badinput = false; in it. That will break out of the loop and allow the game to continue.
						//Also this part is important! to simplify things for the player whenever the loop ends with badInput = false; you NEED to put tempFunc(Location, Sword, PlayerHealth, CaptainDead);
						//That will respawn the player outside the Inn. 
						if (getChoice == "1")
						{
							cout << "You remain silent as the Innkeeper slides the Pint down the tabletop to your waiting hand." << endl << endl;
							pressEnter();
							Sleep(300);
							badInput = false;
							Lock = true;
							PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
							tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
						}

						else if (getChoice == "2")
						{
							cout << "Curiousity gets the better of you. 'Lose a fight with a wolf?' The Innkeeper looks at you with a mildly amused smirk." << endl << endl;
							Sleep(250);
							cout << "'No, actually. During the war all of those years ago, one of the King's thugs took a blade to my throat." << endl << endl;
							Sleep(250);
							cout << "I managed to turn away just in time to save my own hide, but I took the brunt of the blow right there.' " << endl << endl;
							Sleep(250);
							cout << "He turns again to show you the battlescar, more up close and personal." << endl << endl;
							Sleep(300);
							cout << "1. 'Not a fan of the King, I see. I can't blame you. That rat had me imprisoned for 'treason.' " << endl;
							cout << "2. 'I take it you weren't exactly on the King's side, then?' " << endl;
							Sleep(250);

							getline(cin, getChoice);
							system("cls");

							if (getChoice == "1")
							{
								cout << "'Treason? Really?' He seems not to believe your tale." << endl << endl;
								Sleep(250);
								cout << "You explain to him that your only crime was petty theft from the Castle grounds. You were only desperate for your next meal." << endl << endl;
								Sleep(250);
								cout << "Unfortunately for you, the King decided it was good day to make an example out his subject. At least you weren't put to the Gallows." << endl << endl;
								Sleep(250);
								cout << "'That sounds like him, alright. When I met his knights on the field of battle, he was completely ruthless in his command as well." << endl << endl;
								Sleep(250);
								cout << "His men spared nobody their life. He brought terrible weapons of fire against even his own villages, on the mere suspicion that " << endl << endl;
								cout << "one of us may be hiding there. In fact, that's where I was found. I was run out of a burning house only to be attacked in my retreat." << endl << endl;
								Sleep(100);
								cout << "He was the size of a tree, it seemed. He took a swing at me with his blade. I jumped out of the way just in time to not be knicked.'" << endl << endl;
								Sleep(100);
								cout << "The Innkeeper continues his recounting of his battle with the King's forces. In the process, he shares with you some techniques that " << endl << endl;
								cout << "he and his shield-brothers learned during battle. You are enthralled by his magnificent struggle and close shave with death. " << endl << endl;
								Sleep(300);
								cout << "The Innkeeper wraps up his story. You thank him for the drink, and ask that a bar tab be opened under your name. To your pleasant surprise, " << endl << endl;
								cout << "he tells you it was 'on the house.' You thank him for his generosity, and leave the Inn." << endl << endl;
								pressEnter();
								system("cls");

								PlaySound(TEXT("Inn_Upgrade.wav"), NULL, SND_SYNC);
								WarStory10 = true;
								badInput = false;
								Lock = true;
								PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
								tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
							}

							else if (getChoice == "2")
							{
								cout << "'Of course not! Who could support a tyrant like him? No, I wanted nothing less than his head on a pike.'" << endl << endl;
								Sleep(250);
								cout << "As it turns out, he got part of his wish in the form of the King's soldier's head on a pike. The one that gave him that battlescar." << endl << endl;
								Sleep(250);
								cout << "While you are happy to know of his triumph, you can't help but grow more and more uncomfortable over the story he seems to be lost in." << endl << endl;
								Sleep(250);
								cout << "He recounts a bloody, overblown tale of violence and battle. Even through your unease at the story, you do manage to pick up some rather uncouth battle techniques." << endl << endl;
								Sleep(250);
								cout << "As he takes your glass to be cleaned, you awkwardly shuffle out of the Inn and avoid the payment for the drink. Anything to get out of there!" << endl << endl;
								pressEnter();
								system("cls");

								PlaySound(TEXT("Inn_Upgrade.wav"), NULL, SND_SYNC);
								WarStory5 = true;
								badInput = false;
								Lock = true;
								PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
								tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
							}

							else
							{
								badInput = true;
							}


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
				PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
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
						system("cls");
						cout << "You approach the bar." << endl << endl;
						Sleep(300);
						cout << "You are surprised to find the Innkeeper up at this hour, though grateful nonetheless." << endl << endl;
						Sleep(300);
						cout << " 'A pint of ale, please,' you request, your voice barely above a whisper. It seems rude to defile the silence of the Inn." << endl << endl;
						Sleep(300);
						cout << "As the Innkeeper turns to gather a glass, you spot a massive scar on the running along the back of his neck." << endl << endl;
						Sleep(300);
						cout << "1. Remain Silent." << endl;
						cout << "2. 'What's the story behind that scar?'" << endl;


						getline(cin, getChoice);
						system("cls");
						//Where ever the dialogue tree ends just make sure to put badinput = false; in it. That will break out of the loop and allow the game to continue.
						//Also this part is important! to simplify things for the player whenever the loop ends with badInput = false; you NEED to put tempFunc(Location, Sword, PlayerHealth, CaptainDead);
						//That will respawn the player outside the Inn. 
						if (getChoice == "1")
						{
							cout << "You remain silent as the Innkeeper slides the Pint down the tabletop to your waiting hand." << endl << endl;
							pressEnter();
							Sleep(300);
							badInput = false;
							Lock = true;
							PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
							tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
						}

						else if (getChoice == "2")
						{
							cout << "Curiousity gets the better of you. 'Lose a fight with a wolf?' The Innkeeper looks at you with a mildly amused smirk." << endl << endl;
							Sleep(250);
							cout << "'No, actually. During the war all of those years ago, one of the King's thugs took a blade to my throat." << endl << endl;
							Sleep(250);
							cout << "I managed to turn away just in time to save my own hide, but I took the brunt of the blow right there.' " << endl << endl;
							Sleep(250);
							cout << "He turns again to show you the battlescar, more up close and personal." << endl << endl;
							Sleep(300);
							cout << "1. 'Not a fan of the King, I see. I can't blame you. That rat had me imprisoned for 'treason.' " << endl;
							cout << "2. 'I take it you weren't exactly on the King's side, then?' " << endl;
							Sleep(250);

							getline(cin, getChoice);
							system("cls");

							if (getChoice == "1")
							{
								cout << "'Treason? Really?' He seems not to believe your tale." << endl << endl;
								Sleep(250);
								cout << "You explain to him that your only crime was petty theft from the Castle grounds. You were only desperate for your next meal." << endl << endl;
								Sleep(250);
								cout << "Unfortunately for you, the King decided it was good day to make an example out his subject. At least you weren't put to the Gallows." << endl << endl;
								Sleep(250);
								cout << "'That sounds like him, alright. When I met his knights on the field of battle, he was completely ruthless in his command as well." << endl << endl;
								Sleep(250);
								cout << "His men spared nobody their life. He brought terrible weapons of fire against even his own villages, on the mere suspicion that " << endl << endl;
								cout << "one of us may be hiding there. In fact, that's where I was found. I was run out of a burning house only to be attacked in my retreat." << endl << endl;
								Sleep(100);
								cout << "He was the size of a tree, it seemed. He took a swing at me with his blade. I jumped out of the way just in time to not be knicked.'" << endl << endl;
								Sleep(100);
								cout << "The Innkeeper continues his recounting of his battle with the King's forces. In the process, he shares with you some techniques that " << endl << endl;
								cout << "he and his shield-brothers learned during battle. You are enthralled by his magnificent struggle and close shave with death. " << endl << endl;
								Sleep(300);
								cout << "The Innkeeper wraps up his story. You thank him for the drink, and ask that a bar tab be opened under your name. To your pleasant surprise, " << endl << endl;
								cout << "he tells you it was 'on the house.' You thank him for his generosity, and leave the Inn." << endl << endl;
								pressEnter();
								system("cls");

								PlaySound(TEXT("Inn_Upgrade.wav"), NULL, SND_SYNC);
								WarStory10 = true;
								badInput = false;
								Lock = true;
								PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
								tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
							}

							else if (getChoice == "2")
							{
								cout << "'Of course not! Who could support a tyrant like him? No, I wanted nothing less than his head on a pike.'" << endl << endl;
								Sleep(250);
								cout << "As it turns out, he got part of his wish in the form of the King's soldier's head on a pike. The one that gave him that battlescar." << endl << endl;
								Sleep(250);
								cout << "While you are happy to know of his triumph, you can't help but grow more and more uncomfortable over the story he seems to be lost in." << endl << endl;
								Sleep(250);
								cout << "He recounts a bloody, overblown tale of violence and battle. Even through your unease at the story, you do manage to pick up some rather uncouth battle techniques." << endl << endl;
								Sleep(250);
								cout << "As he takes your glass to be cleaned, you awkwardly shuffle out of the Inn and avoid the payment for the drink. Anything to get out of there!" << endl << endl;
								pressEnter();
								system("cls");

								PlaySound(TEXT("Inn_Upgrade.wav"), NULL, SND_SYNC);
								WarStory5 = true;
								badInput = false;
								Lock = true;
								PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
								tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);

							}

							else
							{
								badInput = true;
							}


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
				PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
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
						system("cls");
						cout << "You approach the bar." << endl << endl;
						Sleep(300);
						cout << "You are surprised to find the Innkeeper up at this hour, though grateful nonetheless." << endl << endl;
						Sleep(300);
						cout << " 'A pint of ale, please,' you request, your voice barely above a whisper. It seems rude to defile the silence of the Inn." << endl << endl;
						Sleep(300);
						cout << "As the Innkeeper turns to gather a glass, you spot a massive scar on the running along the back of his neck." << endl << endl;
						Sleep(300);
						cout << "1. Remain Silent." << endl;
						cout << "2. 'What's the story behind that scar?'" << endl;


						getline(cin, getChoice);
						system("cls");
						//Where ever the dialogue tree ends just make sure to put badinput = false; in it. That will break out of the loop and allow the game to continue.
						//Also this part is important! to simplify things for the player whenever the loop ends with badInput = false; you NEED to put tempFunc(Location, Sword, PlayerHealth, CaptainDead);
						//That will respawn the player outside the Inn. 
						if (getChoice == "1")
						{
							cout << "You remain silent as the Innkeeper slides the Pint down the tabletop to your waiting hand." << endl << endl;
							pressEnter();
							Sleep(300);
							badInput = false;
							Lock = true;
							PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
							tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
						}

						else if (getChoice == "2")
						{
							cout << "Curiousity gets the better of you. 'Lose a fight with a wolf?' The Innkeeper looks at you with a mildly amused smirk." << endl << endl;
							Sleep(250);
							cout << "'No, actually. During the war all of those years ago, one of the King's thugs took a blade to my throat." << endl << endl;
							Sleep(250);
							cout << "I managed to turn away just in time to save my own hide, but I took the brunt of the blow right there.' " << endl << endl;
							Sleep(250);
							cout << "He turns again to show you the battlescar, more up close and personal." << endl << endl;
							Sleep(300);
							cout << "1. 'Not a fan of the King, I see. I can't blame you. That rat had me imprisoned for 'treason.' " << endl;
							cout << "2. 'I take it you weren't exactly on the King's side, then?' " << endl;
							Sleep(250);

							getline(cin, getChoice);
							system("cls");

							if (getChoice == "1")
							{
								cout << "'Treason? Really?' He seems not to believe your tale." << endl << endl;
								Sleep(250);
								cout << "You explain to him that your only crime was petty theft from the Castle grounds. You were only desperate for your next meal." << endl << endl;
								Sleep(250);
								cout << "Unfortunately for you, the King decided it was good day to make an example out his subject. At least you weren't put to the Gallows." << endl << endl;
								Sleep(250);
								cout << "'That sounds like him, alright. When I met his knights on the field of battle, he was completely ruthless in his command as well." << endl << endl;
								Sleep(250);
								cout << "His men spared nobody their life. He brought terrible weapons of fire against even his own villages, on the mere suspicion that " << endl << endl;
								cout << "one of us may be hiding there. In fact, that's where I was found. I was run out of a burning house only to be attacked in my retreat." << endl << endl;
								Sleep(100);
								cout << "He was the size of a tree, it seemed. He took a swing at me with his blade. I jumped out of the way just in time to not be knicked.'" << endl << endl;
								Sleep(100);
								cout << "The Innkeeper continues his recounting of his battle with the King's forces. In the process, he shares with you some techniques that " << endl << endl;
								cout << "he and his shield-brothers learned during battle. You are enthralled by his magnificent struggle and close shave with death. " << endl << endl;
								Sleep(300);
								cout << "The Innkeeper wraps up his story. You thank him for the drink, and ask that a bar tab be opened under your name. To your pleasant surprise, " << endl << endl;
								cout << "he tells you it was 'on the house.' You thank him for his generosity, and leave the Inn." << endl << endl;
								pressEnter();
								system("cls");

								PlaySound(TEXT("Inn_Upgrade.wav"), NULL, SND_SYNC);
								WarStory10 = true;
								badInput = false;
								Lock = true;
								PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
								tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
							}

							else if (getChoice == "2")
							{
								cout << "'Of course not! Who could support a tyrant like him? No, I wanted nothing less than his head on a pike.'" << endl << endl;
								Sleep(250);
								cout << "As it turns out, he got part of his wish in the form of the King's soldier's head on a pike. The one that gave him that battlescar." << endl << endl;
								Sleep(250);
								cout << "While you are happy to know of his triumph, you can't help but grow more and more uncomfortable over the story he seems to be lost in." << endl << endl;
								Sleep(250);
								cout << "He recounts a bloody, overblown tale of violence and battle. Even through your unease at the story, you do manage to pick up some rather uncouth battle techniques." << endl << endl;
								Sleep(250);
								cout << "As he takes your glass to be cleaned, you awkwardly shuffle out of the Inn and avoid the payment for the drink. Anything to get out of there!" << endl << endl;
								pressEnter();
								system("cls");

								PlaySound(TEXT("Inn_Upgrade.wav"), NULL, SND_SYNC);
								WarStory5 = true;
								badInput = false;
								Lock = true;
								PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
								tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);

							}

							else
							{
								badInput = true;
							}


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
				PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
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

//Written by Joshua Salkeld
void SmithBattle(string &Location, int &PlayerHealth, bool &Sword, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	string GetChoice;
	bool BadInput = true;
	bool BadInput2 = true;
	int IntimChance = 100;
	int DidIntim;
	static bool SmithDeadOrIntim = false;
	int SmithHealth = 3;
	const int maxDamage = 4;
	int MissChance = 100;
	int playerMiss;
	int SmithMiss;
	string getChoice;
	int Damage;
	bool boolean1 = false;

	

	if (SmithDeadOrIntim == true)
	{
		Smith(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
	}
	else
	{

	}

	
	while (BadInput == true)
	{
		BadInput = false;
		system("cls");
		cout << "You turn and see the blacksmith coming down the stairs with an axe drawn. He walks towards you and shouts " << lightred << endl << endl;
		Sleep(300);
		cout << "Hey you, get out of my shop! " << normal << "He stands ready for battle." << endl << endl;
		Sleep(300);
		cout << "You can either attack now or attempt to intimidate him to go back upstairs." << endl << endl;
		Sleep(300);
		cout << "Press 1 to intimidate him." << endl;
		Sleep(300);
		cout << "Press 2 to attack him." << endl;
		cin >> GetChoice;
		if (GetChoice == "1")
		{
			DidIntim = (rand() % IntimChance);
			if (DidIntim < 20)
			{
				cout << "You turn and draw your sword. 'Get back upstairs and nobody get's hurt'. The blacksmith's face drops as he slowly backs up the stairs and " << endl << endl;
				cout << "you hear a door close. You're safe for now but you better finish up here soon." << endl << endl;
				SmithDeadOrIntim = true;
				Smith(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
			else
			{
				cout << "You turn and draw your sword. 'Get back upstairs and nobody get's hurt'. He chuckles, " << lightred << "not a chance buddy." << normal << "He steps forward ready for a fight." << endl << endl;

				while (PlayerHealth > 0)
				{
					while (SmithHealth > 0)
					{
						if (boolean1 == true)
							cin.ignore();

						boolean1 = true;
						system("cls");
						BadInput2 = true;
						MissChance = 100;
						cout << "Your health is " << PlayerHealth << "." << endl << endl;
						Sleep(300);
						cout << "Press 1 to hit the smith." << endl;
						cout << "Press 2 to defend." << endl;
						cout << "Selection: ";
						cin >> GetChoice;
						system("cls");

							if (GetChoice == "1")
							{
								playerMiss = (rand() % MissChance) + 1;
								if (playerMiss > 20)
								{
									if (SwordLv2 == true)
									{
										Damage = (rand() % maxDamage) + 3; //Sword Lv2 Damage between 3 and 6
										cout << endl << endl << lightcyan << "You swing at the smith dealing " << Damage << " damage." << normal << endl << endl;
										PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
										Sleep(300);
										SmithHealth -= Damage;
										if (SmithHealth <= 0)
										{
											break;
										}
									}
									else
									{
										Damage = (rand() % maxDamage) + 1; // Sword Lv1 damage between 1 and 4
										cout << endl << endl << lightcyan << "You swing at the smith dealing " << Damage << " damage." << normal << endl << endl;
										PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
										Sleep(300);
										SmithHealth -= Damage;
										if (SmithHealth <= 0)
										{
											break;
										}
									}
								}
								else
								{
									cout << endl << endl << red << "You swing at the smith dealing no damage. You missed." << endl << normal << endl;
									PlaySound(TEXT("Sword_Air.wav"), NULL, SND_SYNC);
									Sleep(300);
								}
							}
							else if (GetChoice == "2")
							{
								cout << cyan << "You bring your sword up and get ready for the smith's attack." << normal << endl << endl;
								Sleep(300);
								MissChance = 50;
							}
							else
							{
								BadInput2 = true;
							}


							if (Armor == true)
							{
								MissChance -= 25;

								SmithMiss = (rand() % MissChance) + 1;

								Damage = (rand() % maxDamage) + 1;

								if (SmithMiss < 25)
								{
									cout << lightgreen << "The smith swings his axe towards you and it glances off your armor." << normal << endl << endl;
									PlaySound(TEXT("Sword_Armor.wav"), NULL, SND_SYNC);
									Sleep(300);
								}
								else
								{
									cout << lightred << "The smiths axe connects with you dealing " << Damage << " damage." << normal << endl << endl;
									PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
									Sleep(300);
									PlayerHealth -= Damage;
									if (PlayerHealth <= 0)
									{
										break;
									}
								}
							}
							else
							{
								Damage = (rand() % maxDamage) + 1;

								SmithMiss = (rand() % MissChance) + 1;

								if (SmithMiss < 25)
								{
									cout << lightgreen << "The smith swings his axe towards you and misses you." << normal << endl << endl;
									PlaySound(TEXT("Sword_Air.wav"), NULL, SND_SYNC);
									Sleep(300);
								}
								else
								{
									cout << lightred << "The smiths axe connects with you dealing " << Damage << " damage." << normal << endl << endl;
									PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
									Sleep(300);
									PlayerHealth -= Damage;
									if (PlayerHealth <= 0)
									{
										break;
									}
								}
							}
					}
					if (SmithHealth <= 0)
					{
						cout << normal << "You hit the smith with the hilt of your sword and he falls to the ground unconscious." << endl << endl;
						Sleep(300);
						break;
					}
				}
				if (PlayerHealth <= 0)
				{
					PlayerDeath();
				}
				else
				{
					SmithDeadOrIntim = true;
					Smith(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
				}
			}
		}
		else if (GetChoice == "2")
		{
			while (PlayerHealth > 0)
			{
				while (SmithHealth > 0)
				{
					if (boolean1 == true)
						cin.ignore();

					boolean1 = true;
					system("cls");
					BadInput2 = true;
					MissChance = 100;
					cout << "Your health is " << PlayerHealth << "." << endl << endl;
					Sleep(300);
					cout << "Press 1 to hit the smith." << endl;
					Sleep(300);
					cout << "Press 2 to defend." << endl;
					Sleep(300);
					cout << "Selection: ";
					cin >> GetChoice;

					if (GetChoice == "1")
					{
						playerMiss = (rand() % MissChance) + 1;
						if (playerMiss > 20)
						{
							if (SwordLv2 == true)
							{
								Damage = (rand() % maxDamage) + 3; //Sword Lv2 Damage between 3 and 6
								cout << endl << endl << lightcyan << "You swing at the smith dealing " << Damage << " damage." << normal << endl << endl;
								PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
								Sleep(300);
								SmithHealth -= Damage;
								if (SmithHealth <= 0)
								{
									break;
								}
							}
							else
							{
								Damage = (rand() % maxDamage) + 1; // Sword Lv1 damage between 1 and 4
								cout << endl << endl << lightcyan << "You swing at the smith dealing " << Damage << " damage." << normal << endl << endl;
								PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
								Sleep(300);
								SmithHealth -= Damage;
								if (SmithHealth <= 0)
								{
									break;
								}
							}
						}
						else
						{
							cout << endl << endl << red << "You swing at the smith dealing no damage. You missed." << endl << normal << endl;
							PlaySound(TEXT("Sword_Air.wav"), NULL, SND_SYNC);
							Sleep(300);
						}
					}
					else if (GetChoice == "2")
					{
						cout << cyan << "You bring your sword up and get ready for the smith's attack." << normal << endl << endl;
						Sleep(300);
						MissChance = 50;
					}
					else
					{
						BadInput2 = true;
					}


					if (Armor == true)
					{
						MissChance -= 25;

						SmithMiss = (rand() % MissChance) + 1;

						Damage = (rand() % maxDamage) + 1;

						if (SmithMiss < 25)
						{
							cout << lightgreen << "The smith swings his axe towards you and it glances off your armor." << normal << endl << endl;
							PlaySound(TEXT("Sword_Armor.wav"), NULL, SND_SYNC);
							pressEnter();
							Sleep(300);
						}
						else
						{
							cout << lightred << "The smiths axe connects with you dealing " << Damage << " damage." << normal << endl << endl;
							PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
							pressEnter();
							Sleep(300);
							PlayerHealth -= Damage;
							if (PlayerHealth <= 0)
							{
								break;
							}
						}
					}
					else
					{
						Damage = (rand() % maxDamage) + 1;

						SmithMiss = (rand() % MissChance) + 1;

						if (SmithMiss < 25)
						{
							cout << lightgreen << "The smith swings his axe towards you and misses you." << normal << endl << endl;
							PlaySound(TEXT("Sword_Air.wav"), NULL, SND_SYNC);
							pressEnter();
							Sleep(300);
						}
						else
						{
							cout << lightred << "The smiths axe connects with you dealing " << Damage << " damage." << normal << endl << endl;
							PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
							pressEnter();
							Sleep(300);
							PlayerHealth -= Damage;
							if (PlayerHealth <= 0)
							{
								break;
							}
						}
					}
				}
				if (SmithHealth <= 0)
				{
					system("cls");
					cout << normal << "You hit the smith with the hilt of your sword and he falls to the ground unconscious." << endl << endl;
					PlaySound(TEXT("Uncon_Body.wav"), NULL, SND_SYNC);
					cin.ignore();
					pressEnter();
					break;
				}
			}
			if (PlayerHealth <= 0)
			{
				PlayerDeath();
			}
			else
			{
				SmithDeadOrIntim = true;
				Smith(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
		}
		else
		{
			BadInput = true;
		}
	}

}
//End JS

//Written by Joshua Salkeld
string Smith(string &Location, int &PlayerHealth, bool &Sword, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	int i = 0;
	int x = 0;
	bool test = true;
	char PlayerIcon = 'P';
	char move;
	int playerVert = 4; //The two static variables is the initial spawn point.
	int PlayerHoriz = 4;
	int PlayerTempVert;
	int PlayerTempHoriz;
	int Check;
	string GetChoice;
	bool BadInput = true;
	bool Lock = false;
	int IsCaught;
	int CatchChance = 100;

	if (Lock == true)
	{
		system("cls");
		cout << "The door is locked. You cannot enter." << endl;
		pressEnter();
		tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
	}
	else
	{

	}

	const int ROWS = 25, COLS = 21;

	char SmithMap[ROWS][COLS] = {
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W', 'W' , 'W' , 'W' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , 'W' , '=' , '=' , '=', '=' , '=' , 'W' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , '(' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , '(' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , 'W' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , 'W' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , '(' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , '(' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , 'W' , '=' , '=' , '=', '=' , '=' , 'W' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W', 'W' , 'W' , 'W' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' }
	};

	SmithMap[playerVert][PlayerHoriz] = 'P'; //sets the player character to 'P'


	while (test) //This while loop is what draws the map
	{
		if (SwordLv2 == true && Armor == true)
		{
			system("cls");
			cout << "You have all the things that this blacksmith can provide for you and decide to get out before anyone sees you." << endl << endl;
			Sleep(2000);
			Lock = true;
			PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
			tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
		}
		else
		{
			IsCaught = (rand() % CatchChance);

			BadInput = true;

			while (x < 24)
			{
				if (i == 0)
				{
					system("cls");
					cout << " " << " " << " " << " " << " " << " " << " " << " ";
				}
				cout << SmithMap[x][i];

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

			if (move == 'w')
			{
				Check = playerVert - 1;

				if (SmithMap[Check][PlayerHoriz] == 'W' || SmithMap[Check][PlayerHoriz] == '(' || SmithMap[Check][PlayerHoriz] == '|')
				{

				}
				else if (SmithMap[3][8] == 'P' || SmithMap[3][9] == 'P' || SmithMap[3][10] == 'P' || SmithMap[3][11] == 'P' || SmithMap[3][12] == 'P' || SmithMap[4][12] == 'P' || SmithMap[5][12] == 'P')
				{
					SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 4;
					PlayerHoriz = 11;
					SmithMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput == true)
					{
						cout << "There is a table with sets of armor. Would you like to steal one? (Y/N) ";
						cin >> GetChoice;
						if (GetChoice == "y" || GetChoice == "Y")
						{
							BadInput = false;
							if (Armor == true)
							{
								cout << "You already have armor, better move on." << endl << endl;
								Sleep(5000);
							}
							else
							{
								if (IsCaught < 25)
								{
									cout << "You see a set of chain armor and put it on quickly but make some noise. You hear foot steps coming down the stairs." << endl << endl;
									PlaySound(TEXT("Smith_Armor.wav"), NULL, SND_SYNC);
									Armor = true;
									Sleep(4000);
									SmithBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
								else
								{
									cout << "You see a well made set a chain armor. Quietly putting it on you are slowed and make more noise but better defended." << endl << endl;
									Armor = true;
									Sleep(5000);
								}
							}
						}
						else if (GetChoice == "n" || GetChoice == "N")
						{
							BadInput = false;
						}
						else
						{
							BadInput = true;
						}
					}
				}
				else if (SmithMap[17][8] == 'P' || SmithMap[17][9] == 'P' || SmithMap[17][10] == 'P' || SmithMap[17][11] == 'P' || SmithMap[17][12] == 'P' || SmithMap[16][12] == 'P' || SmithMap[15][12] == 'P')
				{
					SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 16;
					PlayerHoriz = 11;
					SmithMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput == true)
					{
						cout << "You see a table full of better weapons. Would you like to steal one? (Y/N) ";
						cin >> GetChoice;

						if (GetChoice == "Y" || GetChoice == "y")
						{
							BadInput = false;
							if (SwordLv2 == true)
							{
								cout << "You already have a better sword, better move on." << endl << endl;
								Sleep(5000);
							}
							else
							{
								if (IsCaught < 15)
								{
									cout << "Picking up a sharp longsword you notice it's better than your current one and lay it on the table. It hits a hammer and makes a sound." << endl << endl;
									PlaySound(TEXT("Smith_Sword.wav"), NULL, SND_SYNC);
									cout << "You hear footsteps coming down the stairs." << endl << endl;
									Sleep(4000);
									SwordLv2 = true;
									SmithBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
								else
								{
									cout << "You approach the counter and see a sharp longsword laying there next to some blacksmith tools. Quickly looking between your sword and" << endl;
									cout << "this one you realize that this is much better. You pick it up and leave you old sword behind." << endl << endl;
									SwordLv2 = true;
									Sleep(5000);
								}
							}
						}
						else if (GetChoice == "N" || GetChoice == "n")
						{
							BadInput = false;
						}
						else
						{
							BadInput = true;
						}
					}
				}
				else if (SmithMap[3][3] == 'P' || SmithMap[4][3] == 'P' || SmithMap[16][3] == 'P' || SmithMap[17][3] == 'P')
				{
					cout << "Would you like to leave the smith? (Y/N)" << endl;
					cin >> GetChoice;

					if (GetChoice == "Y" || GetChoice == "y")
					{
						PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
						tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else 
					{
						SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
						playerVert = 4;
						PlayerHoriz = 4;
						SmithMap[playerVert][PlayerHoriz] = 'P';
					}
				}
				else
				{
					PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
					PlayerTempVert = playerVert;
					PlayerTempHoriz = PlayerHoriz;
					playerVert = playerVert - 1;
				}
			}
			else if (move == 'a')
			{
				Check = PlayerHoriz - 1;
				if (SmithMap[playerVert][Check] == 'W' || SmithMap[playerVert][Check] == ')' || SmithMap[Check][PlayerHoriz] == '|')
				{

				}
				else if (SmithMap[3][8] == 'P' || SmithMap[3][9] == 'P' || SmithMap[3][10] == 'P' || SmithMap[3][11] == 'P' || SmithMap[3][12] == 'P' || SmithMap[4][12] == 'P' || SmithMap[5][12] == 'P')
				{
					SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 4;
					PlayerHoriz = 11;
					SmithMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput == true)
					{
						cout << "There is a table with sets of armor. Would you like to steal one? (Y/N) ";
						cin >> GetChoice;
						if (GetChoice == "y" || GetChoice == "Y")
						{
							BadInput = false;
							if (Armor == true)
							{
								cout << "You already have armor, better move on." << endl << endl;
								Sleep(5000);
							}
							else
							{
								if (IsCaught < 25)
								{
									cout << "You see a set of chain armor and put it on quickly but make some noise. You hear foot steps coming down the stairs." << endl << endl;
									PlaySound(TEXT("Smith_Armor.wav"), NULL, SND_SYNC);
									Armor = true;
									Sleep(4000);
									SmithBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
								else
								{
									cout << "You see a well made set a chain armor. Quietly putting it on you are slowed and make more noise but better defended." << endl << endl;
									Armor = true;
									Sleep(5000);
								}
							}
						}
						else if (GetChoice == "n" || GetChoice == "N")
						{
							BadInput = false;
						}
						else
						{
							BadInput = true;
						}
					}
				}
				else if (SmithMap[17][8] == 'P' || SmithMap[17][9] == 'P' || SmithMap[17][10] == 'P' || SmithMap[17][11] == 'P' || SmithMap[17][12] == 'P' || SmithMap[16][12] == 'P' || SmithMap[15][12] == 'P')
				{
					SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 16;
					PlayerHoriz = 11;
					SmithMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput == true)
					{
						cout << "You see a table full of better weapons. Would you like to steal one? (Y/N) ";
						cin >> GetChoice;

						if (GetChoice == "Y" || GetChoice == "y")
						{
							BadInput = false;
							if (SwordLv2 == true)
							{
								cout << "You already have a better sword, better move on." << endl << endl;
								Sleep(5000);
							}
							else
							{
								if (IsCaught < 15)
								{
									cout << "Picking up a sharp longsword you notice it's better than your current one and lay it on the table. It hits a hammer and makes a sound." << endl << endl;
									PlaySound(TEXT("Smith_Sword.wav"), NULL, SND_SYNC);
									cout << "You hear footsteps coming down the stairs." << endl << endl;
									Sleep(4000);
									SwordLv2 = true;
									SmithBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
								else
								{
									cout << "You approach the counter and see a sharp longsword laying there next to some blacksmith tools. Quickly looking between your sword and" << endl;
									cout << "this one you realize that this is much better. You pick it up and leave you old sword behind." << endl << endl;
									SwordLv2 = true;
									Sleep(5000);
								}
							}
						}
						else if (GetChoice == "N" || GetChoice == "n")
						{
							BadInput = false;
						}
						else
						{
							BadInput = true;
						}
					}
				}
				else if (SmithMap[3][3] == 'P' || SmithMap[4][3] == 'P' || SmithMap[16][3] == 'P' || SmithMap[17][3] == 'P')
				{
					cout << "Would you like to leave the smith? (Y/N)" << endl;
					cin >> GetChoice;

					if (GetChoice == "Y" || GetChoice == "y")
					{
						PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
						tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
						playerVert = 4;
						PlayerHoriz = 4;
						SmithMap[playerVert][PlayerHoriz] = 'P';
					}
				}
				else
				{
					PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
					PlayerTempHoriz = PlayerHoriz;
					PlayerTempVert = playerVert;
					PlayerHoriz = PlayerHoriz - 1;
				}
			}
			else if (move == 's')
			{
				Check = playerVert + 1;

				if (SmithMap[Check][PlayerHoriz] == 'W' || SmithMap[Check][PlayerHoriz] == ')' || SmithMap[Check][PlayerHoriz] == '|')
				{

				}
				else if (SmithMap[3][8] == 'P' || SmithMap[3][9] == 'P' || SmithMap[3][10] == 'P' || SmithMap[3][11] == 'P' || SmithMap[3][12] == 'P' || SmithMap[4][12] == 'P' || SmithMap[5][12] == 'P')
				{
					SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 4;
					PlayerHoriz = 11;
					SmithMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput == true)
					{
						cout << "There is a table with sets of armor. Would you like to steal one? (Y/N) ";
						cin >> GetChoice;
						if (GetChoice == "y" || GetChoice == "Y")
						{
							BadInput = false;
							if (Armor == true)
							{
								cout << "You already have armor, better move on." << endl << endl;
								Sleep(5000);
							}
							else
							{
								if (IsCaught < 25)
								{
									cout << "You see a set of chain armor and put it on quickly but make some noise. You hear foot steps coming down the stairs." << endl << endl;
									PlaySound(TEXT("Smith_Armor.wav"), NULL, SND_SYNC);
									Armor = true;
									Sleep(4000);
									SmithBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
								else
								{
									cout << "You see a well made set a chain armor. Quietly putting it on you are slowed and make more noise but better defended." << endl << endl;
									Armor = true;
									Sleep(5000);
								}
							}
						}
						else if (GetChoice == "n" || GetChoice == "N")
						{
							BadInput = false;
						}
						else
						{
							BadInput = true;
						}
					}
				}
				else if (SmithMap[17][8] == 'P' || SmithMap[17][9] == 'P' || SmithMap[17][10] == 'P' || SmithMap[17][11] == 'P' || SmithMap[17][12] == 'P' || SmithMap[16][12] == 'P' || SmithMap[15][12] == 'P')
				{
					SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 16;
					PlayerHoriz = 11;
					SmithMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput == true)
					{
						cout << "You see a table full of better weapons. Would you like to steal one? (Y/N) ";
						cin >> GetChoice;

						if (GetChoice == "Y" || GetChoice == "y")
						{
							BadInput = false;
							if (SwordLv2 == true)
							{
								cout << "You already have a better sword, better move on." << endl << endl;
								Sleep(5000);
							}
							else
							{
								if (IsCaught < 15)
								{
									cout << "Picking up a sharp longsword you notice it's better than your current one and lay it on the table. It hits a hammer and makes a sound." << endl << endl;
									PlaySound(TEXT("Smith_Sword.wav"), NULL, SND_SYNC);
									cout << "You hear footsteps coming down the stairs." << endl << endl;
									Sleep(4000);
									SwordLv2 = true;
									SmithBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
								else
								{
									cout << "You approach the counter and see a sharp longsword laying there next to some blacksmith tools. Quickly looking between your sword and" << endl;
									cout << "this one you realize that this is much better. You pick it up and leave you old sword behind." << endl << endl;
									Sleep(5000);
									SwordLv2 = true;
								}
							}
						}
						else if (GetChoice == "N" || GetChoice == "n")
						{
							BadInput = false;
						}
						else
						{
							BadInput = true;
						}
					}
				}
				else if (SmithMap[3][3] == 'P' || SmithMap[4][3] == 'P' || SmithMap[16][3] == 'P' || SmithMap[17][3] == 'P')
				{
					cout << "Would you like to leave the smith? (Y/N)" << endl;
					cin >> GetChoice;

					if (GetChoice == "Y" || GetChoice == "y")
					{
						PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
						tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
						playerVert = 4;
						PlayerHoriz = 4;
						SmithMap[playerVert][PlayerHoriz] = 'P';
					}
				}
				else
				{
					PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
					PlayerTempVert = playerVert;
					PlayerTempHoriz = PlayerHoriz;
					playerVert = playerVert + 1;
				}

			}
			else if (move == 'd')
			{
				Check = PlayerHoriz + 1;
				if (SmithMap[playerVert][Check] == 'W' || SmithMap[playerVert][Check] == ')' || SmithMap[Check][PlayerHoriz] == '|')
				{

				}
				else if (SmithMap[3][8] == 'P' || SmithMap[3][9] == 'P' || SmithMap[3][10] == 'P' || SmithMap[3][11] == 'P' || SmithMap[3][12] == 'P' || SmithMap[4][12] == 'P' || SmithMap[5][12] == 'P')
				{
					SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 4;
					PlayerHoriz = 11;
					SmithMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput == true)
					{
						cout << "There is a table with sets of armor. Would you like to steal one? (Y/N) ";
						cin >> GetChoice;
						if (GetChoice == "y" || GetChoice == "Y")
						{
							BadInput = false;
							if (Armor == true)
							{
								cout << "You already have armor, better move on." << endl << endl;
								Sleep(5000);
							}
							else
							{
								if (IsCaught < 25)
								{
									cout << "You see a set of chain armor and put it on quickly but make some noise. You hear foot steps coming down the stairs." << endl << endl;
									PlaySound(TEXT("Smith_Armor.wav"), NULL, SND_SYNC);
									Armor = true;
									Sleep(4000);
									SmithBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
								else
								{
									cout << "You see a well made set a chain armor. Quietly putting it on you are slowed and make more noise but better defended." << endl << endl;
									Armor = true;
									Sleep(5000);
								}
							}
						}
						else if (GetChoice == "n" || GetChoice == "N")
						{
							BadInput = false;
						}
						else
						{
							BadInput = true;
						}
					}
				}
				else if (SmithMap[17][8] == 'P' || SmithMap[17][9] == 'P' || SmithMap[17][10] == 'P' || SmithMap[17][11] == 'P' || SmithMap[17][12] == 'P' || SmithMap[16][12] == 'P' || SmithMap[15][12] == 'P')
				{
					SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 16;
					PlayerHoriz = 11;
					SmithMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput == true)
					{
						cout << "You see a table full of better weapons. Would you like to steal one? (Y/N) ";
						cin >> GetChoice;

						if (GetChoice == "Y" || GetChoice == "y")
						{
							BadInput = false;
							if (SwordLv2 == true)
							{
								cout << "You already have a better sword, better move on." << endl << endl;
								Sleep(5000);
							}
							else
							{
								if (IsCaught < 15)
								{
									cout << "Picking up a sharp longsword you notice it's better than your current one and lay it on the table. It hits a hammer and makes a sound." << endl << endl;
									PlaySound(TEXT("Smith_Sowrd.wav"), NULL, SND_SYNC);
									cout << "You hear footsteps coming down the stairs." << endl << endl;
									Sleep(4000);
									SwordLv2 = true;
									SmithBattle(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
								else
								{
									cout << "You approach the counter and see a sharp longsword laying there next to some blacksmith tools. Quickly looking between your sword and" << endl;
									cout << "this one you realize that this is much better. You pick it up and leave you old sword behind." << endl << endl;
									SwordLv2 = true;
									Sleep(5000);
								}
							}
						}
						else if (GetChoice == "N" || GetChoice == "n")
						{
							BadInput = false;
						}
						else
						{
							BadInput = true;
						}
					}
				}
				else if (SmithMap[3][3] == 'P' || SmithMap[4][3] == 'P' || SmithMap[16][3] == 'P' || SmithMap[17][3] == 'P')
				{
					cout << "Would you like to leave the smith? (Y/N)" << endl;
					cin >> GetChoice;

					if (GetChoice == "Y" || GetChoice == "y")
					{
						PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
						tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					}
					else
					{
						SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
						playerVert = 4;
						PlayerHoriz = 4;
						SmithMap[playerVert][PlayerHoriz] = 'P';
					}
				}
				else
				{
					PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
					PlayerTempHoriz = PlayerHoriz;
					PlayerTempVert = playerVert;
					PlayerHoriz = PlayerHoriz + 1;
				}
			}
			else
			{

			}

			SmithMap[PlayerTempVert][PlayerTempHoriz] = ' ';
			SmithMap[playerVert][PlayerHoriz] = 'P';


		}
	}


	return Location;
}
//End JS

//Array and outline doen by Joshua Salkeld. The rest done by Dan Curley and Sebastian Newbold
string ClothesFunc(string &Location, int &PlayerHealth, bool &Sword, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	int i = 0;
	int x = 0;
	bool test = true;
	static bool Lock = false;
	char PlayerIcon = 'P';
	char move;
	static int playerVert = 4; //The two static variables is the initial spawn point.
	static int PlayerHoriz = 4;
	int PlayerTempVert;
	int PlayerTempHoriz;
	int Check;
	string GetChoice;
	bool BadInput = true;
	bool ShirtSel = false;
	bool PantSel = false;
	bool ShoeSel = false;
	int IsCaught;
	int CatchChance = 100;

	if (Lock == true)
	{
		system("cls");
		cout << "The door is locked. You cannot enter." << endl;
		pressEnter();
		tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
	}
	else
	{

	}

	const int ROWS = 25, COLS = 21;

	PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);

	char ClothesMap[ROWS][COLS] = {
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W', 'W' , 'W' , 'W' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , 'W' , '=' , '=' , 'W' , '=' , '=' , '=', 'W' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ')' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ')' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '[' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '[' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ')' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ')' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , 'W' , '=' , '=' , 'W' , '=' , '=' , '=', 'W' , ' ' , '|' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W', 'W' , 'W' , 'W' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' }
	};

	ClothesMap[playerVert][PlayerHoriz] = 'P'; //sets the player character to 'P'


	while (test) //This while loop is what draws the map
	{
		if (Clothes[1] == " " || Clothes[2] == " " || Clothes[3] == " ")
		{
			BadInput = true;
			while (x < 24)
			{
				if (i == 0)
				{
					system("cls");
					cout << " " << " " << " " << " " << " " << " " << " " << " ";
				}
				cout << ClothesMap[x][i];

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

			IsCaught = (rand() % CatchChance);
			//Separates verticle and horizontal movement (W and S from A and D)
			if (move == 'w' || move == 's')
			{
				if (move == 'w')
					Check = playerVert - 1;
				else if (move == 's')
					Check = playerVert + 1;
				else {}

				if (ClothesMap[Check][PlayerHoriz] == 'W' || ClothesMap[Check][PlayerHoriz] == ')' || ClothesMap[Check][PlayerHoriz] == '|')
				{

				}
				else if (ClothesMap[5][12] == 'P')
				{
					//Shirt 1
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 5;
					PlayerHoriz = 11;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShirtSel == true)
						{
							cout << "You already have a shirt." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "This shirt is made of fine blue silk, with long sleeves." << endl << endl;
							cout << "Do you want to steal the blue silk shirt? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the shirt and quickly put it on." << endl;
									Sleep(1500);
									BadInput = false;
									ShirtSel = true;
									Clothes[3] = "Shirt 1";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else if (ClothesMap[8][12] == 'P')
				{
					//Shirt 2
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 6;
					PlayerHoriz = 11;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShirtSel == true)
						{
							cout << "You already have a shirt." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "The shirt is green, crafted of the finest cotton in the land." << endl << endl;
							cout << "Do you want to steal the green shirt? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the shirt and quickly put it on." << endl;
									Sleep(1500);
									BadInput = false;
									ShirtSel = true;
									Clothes[3] = "Shirt 2";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else if (ClothesMap[3][5] == 'P' || ClothesMap[3][6] == 'P')
				{
					//Shoe 1
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 4;
					PlayerHoriz = 5;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShoeSel == true)
						{
							cout << "You already have shoes." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "You eye some shoes made of leather. They don't look very comfortable, but they are just your size." << endl << endl;
							cout << "Do you want to steal the leather shoes? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the shoes and quickly put them on." << endl;
									Sleep(1500);
									BadInput = false;
									ShoeSel = true;
									Clothes[1] = "Shoes 1";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else if (ClothesMap[10][5] == 'P' || ClothesMap[10][6] == 'P')
				{
					//Shoe 2
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 9;
					PlayerHoriz = 5;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShoeSel == true)
						{
							cout << "You already have shoes." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "You eye some sandals made of a sort of light wood, held together by crude rope." << endl << endl;
							cout << "Do you want to steal the sandals? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the shoes and quickly put them on." << endl;
									Sleep(1500);
									BadInput = false;
									ShoeSel = true;
									Clothes[1] = "Shoes 2";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else if (ClothesMap[3][8] == 'P' || ClothesMap[3][9] == 'P' || ClothesMap[3][10] == 'P')
				{
					//Pants 1
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 4;
					PlayerHoriz = 8;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShoeSel == true)
						{
							cout << "You already have pants." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "On the table you see some trousers made of burlap. It's nothing fancy, but it covers the delicates." << endl << endl;
							cout << "Do you want to steal the burlap pants? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the pants and quickly put them on." << endl;
									Sleep(1500);
									BadInput = false;
									PantSel = true;
									Clothes[2] = "Pants 1";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else if (ClothesMap[10][8] == 'P' || ClothesMap[10][9] == 'P' || ClothesMap[10][10] == 'P')
				{
					//Pants 2
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 9;
					PlayerHoriz = 8;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShoeSel == true)
						{
							cout << "You already have pants." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "On the table are some trousers made of simple linen." << endl << endl;
							cout << "Do you want to steal the Linen trousers? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the pants and quickly put them on." << endl;
									Sleep(1500);
									BadInput = false;
									PantSel = true;
									Clothes[2] = "Pants 2";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else
				{
					PlayerTempVert = playerVert;
					PlayerTempHoriz = PlayerHoriz;
					if (move == 'w')
						playerVert = playerVert - 1;
					else if (move == 's')
						playerVert = playerVert + 1;
					else {}

				}
			}
			else if (move == 'a' || move == 'd')
			{
				if (move == 'a')
					Check = PlayerHoriz - 1;
				else if (move == 'd')
					Check = PlayerHoriz + 1;
				else {}

				if (ClothesMap[playerVert][Check] == 'W' || ClothesMap[playerVert][Check] == ')' || ClothesMap[Check][PlayerHoriz] == '|')
				{

				}

				else if (move == 'd' && (ClothesMap[2][12] == 'P' || ClothesMap[3][12] == 'P' || ClothesMap[4][12] == 'P' || ClothesMap[6][12] == 'P' || ClothesMap[7][12] == 'P' || ClothesMap[9][12] == 'P' || ClothesMap[10][12] == 'P' || ClothesMap[11][12] == 'P'))
				{
					cout << "Don't climb on the counters, just get the clothes and get out." << endl;
					Sleep(2000);
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 7;
					PlayerHoriz = 11;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
				}
				else if (ClothesMap[5][12] == 'P')
				{
					//Shirt 1
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 5;
					PlayerHoriz = 11;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShirtSel == true)
						{
							cout << "You already have a shirt." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "This shirt is made of fine blue silk, with long sleeves." << endl << endl;
							cout << "Do you want to steal the blue silk shirt? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the shirt and quickly put it on." << endl;
									Sleep(1500);
									BadInput = false;
									ShirtSel = true;
									Clothes[3] = "Shirt 1";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else if (ClothesMap[8][12] == 'P')
				{
					//Shirt 2
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 6;
					PlayerHoriz = 11;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShirtSel == true)
						{
							cout << "You already have a shirt." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "The shirt is green, crafted of the finest cotton in the land." << endl << endl;
							cout << "Do you want to steal the green shirt? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the shirt and quickly put it on." << endl;
									Sleep(1500);
									BadInput = false;
									ShirtSel = true;
									Clothes[3] = "Shirt 2";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else if (ClothesMap[3][5] == 'P' || ClothesMap[3][6] == 'P')
				{
					//Shoe 1
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 4;
					PlayerHoriz = 5;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShoeSel == true)
						{
							cout << "You already have shoes." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "You eye some shoes made of leather. They don't look very comfortable, but they are just your size." << endl << endl;
							cout << "Do you want to steal the leather shoes? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the shoes and quickly put them on." << endl;
									Sleep(1500);
									BadInput = false;
									ShoeSel = true;
									Clothes[1] = "Shoes 1";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else if (ClothesMap[10][5] == 'P' || ClothesMap[10][6] == 'P')
				{
					//Shoe 2
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 9;
					PlayerHoriz = 5;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShoeSel == true)
						{
							cout << "You already have shoes." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "You eye some sandals made of a sort of light wood, held together by crude rope." << endl << endl;
							cout << "Do you want to steal the sandals? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the shoes and quickly put them on." << endl;
									Sleep(1500);
									BadInput = false;
									ShoeSel = true;
									Clothes[1] = "Shoes 2";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else if (ClothesMap[3][8] == 'P' || ClothesMap[3][9] == 'P' || ClothesMap[3][10] == 'P')
				{
					//Pants 1
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 4;
					PlayerHoriz = 8;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShoeSel == true)
						{
							cout << "You already have pants." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "On the table you see some trousers made of burlap. It's nothing fancy, but it covers the delicates." << endl << endl;
							cout << "Do you want to steal the burlap pants? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the pants and quickly put them on." << endl;
									Sleep(1500);
									BadInput = false;
									PantSel = true;
									Clothes[2] = "Pants 1";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else if (ClothesMap[10][8] == 'P' || ClothesMap[10][9] == 'P' || ClothesMap[10][10] == 'P')
				{
					//Pants 2
					ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
					playerVert = 9;
					PlayerHoriz = 8;
					ClothesMap[playerVert][PlayerHoriz] = 'P';
					while (BadInput)
					{
						if (ShoeSel == true)
						{
							cout << "You already have pants." << endl << endl;
							BadInput = false;
						}
						else
						{
							cout << "On the table are some trousers made of simple linen." << endl << endl;
							cout << "Do you want to steal the Linen trousers? (Y/N)";
							cin >> GetChoice;
							if (GetChoice == "y" || GetChoice == "Y")
							{
								if (IsCaught > 10)
								{
									cout << "You pick up the pants and quickly put them on." << endl;
									Sleep(1500);
									BadInput = false;
									PantSel = true;
									Clothes[2] = "Pants 2";
								}
								else
								{
									cout << "The shop owner comes down the stairs just as you pick up the clothes. You run out of the store and hear a lock behind you." << endl << endl;
									Sleep(5000);
									Lock = true;
									tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
								}
							}
							else if (GetChoice == "N" || GetChoice == "n")
							{
								BadInput = false;
							}
							else
							{
								BadInput = true;
							}
						}
					}
				}
				else
				{
					PlayerTempHoriz = PlayerHoriz;
					PlayerTempVert = playerVert;
					if (move == 'a')
						PlayerHoriz = PlayerHoriz - 1;
					else if (move == 'd')
						PlayerHoriz = PlayerHoriz + 1;
					else {}

				}
			}
			else if (move == 'x')//UNSTUCK
			{
				playerVert = 6;
				PlayerHoriz = 8;
				ClothesMap[playerVert][PlayerHoriz] = 'P';
			}
			else {}
			ClothesMap[PlayerTempVert][PlayerTempHoriz] = ' ';
			ClothesMap[playerVert][PlayerHoriz] = 'P';
		}
		else
		{
			system("cls");
			cout << "Having all the clothes this store can provide you decide to leave before the owner wakes up." << endl << endl;
			Lock = true;
			tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
		}
	}
	return Location;
}
//End JS and DC and SN

//Array done by Joshua Salkeld, Other parts done by Sebastian Newbold
string AlcShop(string &Location, int &PlayerHealth, bool &Sword, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	int i = 0;
	int x = 0;
	bool test = true;
	char PlayerIcon = 'P';
	char move;
	static int playerVert = 4; //The two static variables is the initial spawn point.
	static int PlayerHoriz = 12;
	int PlayerTempVert;
	int PlayerTempHoriz;
	int Check;
	string GetChoice;
	bool BadInput = true;
	static bool Lock = false;
	int Caught;
	int CatchChance = 100;

	if (Lock == true)
	{
		system("cls");
		cout << "The door is locked. You cannot enter." << endl;
		pressEnter();
		tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
	}
	else
	{

	}

	const int ROWS = 25, COLS = 21;

	PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);

	char Alcmap[ROWS][COLS] = {
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W', 'W' , 'W' , 'W' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , '|' , 'W' , '=' , '=' , '=', '=' , 'W' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , '=' , '=' , ' ' , '|' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '(' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '(' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , '=' , '=' , ' ' , '|' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , '|' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , 'B' , 'B' , ' ' , '}' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '(' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , 'B' , 'B' , ' ' , '}' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '(' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , ' ' , ' ' , ' ' , '|' , 'W' , '=' , '=' , '=', '=' , 'W' , ' ' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W' , 'W', 'W' , 'W' , 'W' , 'W' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' }
	};

	Alcmap[playerVert][PlayerHoriz] = 'P'; //sets the player character to 'P'


	while (test) //This while loop is what draws the map
	{
		while (x < 24)
		{
			if (i == 0)
			{
				system("cls");
				cout << " " << " " << " " << " " << " " << " " << " " << " ";
			}
			cout << Alcmap[x][i];

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

		if (move == 'w')
		{
			Check = playerVert - 1;

			if (Alcmap[Check][PlayerHoriz] == 'W' || Alcmap[Check][PlayerHoriz] == '(' || Alcmap[Check][PlayerHoriz] == '|')
			{

			}
			else if (Alcmap[3][8] == 'P' || Alcmap[3][9] == 'P' || Alcmap[3][10] == 'P' || Alcmap[3][11] == 'P' || Alcmap[11][8] == 'P' || Alcmap[11][9] == 'P' || Alcmap[11][10] == 'P' || Alcmap[11][11] == 'P')
			{
				break;
			}
			else
			{

				PlayerTempVert = playerVert;
				PlayerTempHoriz = PlayerHoriz;
				playerVert = playerVert - 1;
				PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
			}
		}
		else if (move == 'a')
		{
			Check = PlayerHoriz - 1;
			if (Alcmap[playerVert][Check] == 'W' || Alcmap[playerVert][Check] == '(' || Alcmap[Check][PlayerHoriz] == '|')
			{

			}
			else if (Alcmap[2][7] == 'P' || Alcmap[3][7] == 'P' || Alcmap[4][7] == 'P' || Alcmap[4][7] == 'P' || Alcmap[5][7] == 'P' || Alcmap[6][7] == 'P' || Alcmap[7][7] == 'P' || Alcmap[8][7] == 'P' || Alcmap[9][7] == 'P' || Alcmap[10][7] == 'P' || Alcmap[11][7] == 'P' || Alcmap[12][7] == 'P')
			{
				cout << endl << "No need to go to the back room. You need to move quick, just get a potion and get out.";
				Sleep(3000);
			}
			else if (Alcmap[3][8] == 'P' || Alcmap[3][9] == 'P' || Alcmap[3][10] == 'P' || Alcmap[3][11] == 'P' || Alcmap[11][8] == 'P' || Alcmap[11][9] == 'P' || Alcmap[11][10] == 'P' || Alcmap[11][11] == 'P')
			{
				break;
			}
			else
			{
				PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
				PlayerTempHoriz = PlayerHoriz;
				PlayerTempVert = playerVert;
				PlayerHoriz = PlayerHoriz - 1;
			}
		}
		else if (move == 's')
		{
			Check = playerVert + 1;

			if (Alcmap[Check][PlayerHoriz] == 'W' || Alcmap[Check][PlayerHoriz] == '(' || Alcmap[Check][PlayerHoriz] == '|')
			{

			}
			else if (Alcmap[3][8] == 'P' || Alcmap[3][9] == 'P' || Alcmap[3][10] == 'P' || Alcmap[3][11] == 'P' || Alcmap[11][8] == 'P' || Alcmap[11][9] == 'P' || Alcmap[11][10] == 'P' || Alcmap[11][11] == 'P')
			{
				break;
			}
			else
			{
				PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
				PlayerTempVert = playerVert;
				PlayerTempHoriz = PlayerHoriz;
				playerVert = playerVert + 1;
			}

		}
		else if (move == 'd')
		{
			Check = PlayerHoriz + 1;
			if (Alcmap[playerVert][Check] == 'W' || Alcmap[playerVert][Check] == '(' || Alcmap[Check][PlayerHoriz] == '|')
			{

			}
			else if (Alcmap[3][8] == 'P' || Alcmap[3][9] == 'P' || Alcmap[3][10] == 'P' || Alcmap[3][11] == 'P' || Alcmap[11][8] == 'P' || Alcmap[11][9] == 'P' || Alcmap[11][10] == 'P' || Alcmap[11][11] == 'P')
			{
				break;
			}
			else
			{
				PlaySound(TEXT("Building_Floor.wav"), NULL, SND_SYNC);
				PlayerTempHoriz = PlayerHoriz;
				PlayerTempVert = playerVert;
				PlayerHoriz = PlayerHoriz + 1;
			}
		}
		else
		{

		}

		Alcmap[PlayerTempVert][PlayerTempHoriz] = ' ';
		Alcmap[playerVert][PlayerHoriz] = 'P';


	}

	Caught = (rand() % CatchChance);

	system("cls");

	if (Caught < 20)
	{
		Lock = true;
		cout << "You hear the owner of the shop come out from the back room. You manage to grab a potion and drink it before running out the door." << endl << endl;
		cout << "You hear a lock click behind you." << endl << endl;
		PlaySound(TEXT("Lock_Door.wav"), NULL, SND_SYNC);
	}
	else
	{
		cout << "You grab a vial of red liquid and drink it quickly. You feel any wounds you had going away soon after." << endl << endl;
		PlaySound(TEXT("Drink_Potion.wav"), NULL, SND_SYNC);
	}
	

	if (WarStory5 == true)
	{
		PlayerHealth = 15;
	}
	else if (WarStory10 == true)
	{
		PlayerHealth = 20;
	}
	else
	{
		PlayerHealth = 10;
	}
	cout << "Your health is now " << PlayerHealth << "." << endl;
	Sleep(4000);
	PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
	tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);

	return Location;
}
//End JS and SN

// Witten by Joshua Salkeld
string PrisonDoors(string &Location, int &PlayerHealth, bool &Sword, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes [], bool Armor, bool SwordLv2)
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

	townMap(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);

	return Location;
}
//End JS


// Written by Joshua Salkeld
void townMap(string &Location, bool &Sword, int &PlayerHealth, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
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
				PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
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
				PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
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
				PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
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
				PlaySound(TEXT("Walking.wav"), NULL, SND_SYNC);
			}
		}
		else if (move == '?')
		{

			cout << endl << "There isn't much here of use. You do know that there is a stables to the north that might have a horse." << endl << endl;
			Sleep(300);
			cout << "The guards here will all be looking for an escaped prisoner. A horse would definitely help escape." << endl << endl;
			Sleep(300);
			cout << "Other than the horse there is also a smith to the east, a clothes store to the north-east, an inn to the west," << endl << endl;
			Sleep(300);
			cout << "and an alchemist shop to the north-west. They might have something useful inside if I check quietly." << endl << endl;
			cin.ignore();
			pressEnter();
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
			if (GetChoice == "y" || GetChoice == "Y")
			{
				BadInput = false;
				Stables(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
			else if (GetChoice == "n" || GetChoice == "N")
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 2;
				PlayerHoriz = 10;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
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
			if (GetChoice == "y" || GetChoice == "Y")
			{
				BadInput = false;
				playerVert = 3;
				PlayerHoriz = 8;
				townArray[playerVert][PlayerHoriz] = 'P';
				AlcShop(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
			else if (GetChoice == "n" || GetChoice == "N")
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 3;
				PlayerHoriz = 8;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
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
			if (GetChoice == "y" || GetChoice == "Y")
			{
				BadInput = false;
				playerVert = 10;
				PlayerHoriz = 8;
				townArray[playerVert][PlayerHoriz] = 'P';
				Inn(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
			else if (GetChoice == "n" || GetChoice == "N")
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 10;
				PlayerHoriz = 8;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
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
			if (GetChoice == "y" || GetChoice == "Y")
			{
				BadInput = false;
				playerVert = 3;
				PlayerHoriz = 12;
				townArray[playerVert][PlayerHoriz] = 'P';
				ClothesFunc(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
			else if (GetChoice == "n" || GetChoice == "N")
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 3;
				PlayerHoriz = 12;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
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
			if (GetChoice == "y" || GetChoice == "Y")
			{
				BadInput = false;
				playerVert = 10;
				PlayerHoriz = 12;
				townArray[playerVert][PlayerHoriz] = 'P';
				PlaySound(TEXT("Town_Door.wav"), NULL, SND_SYNC);
				Smith(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
			else if (GetChoice == "n" || GetChoice == "N")
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 10;
				PlayerHoriz = 12;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
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
			if (GetChoice == "y" || GetChoice == "Y")
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 21;
				PlayerHoriz = 14;
				townArray[playerVert][PlayerHoriz] = 'P';
				PrisonDoors(Location, PlayerHealth, Sword, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
			else if (GetChoice == "n" || GetChoice == "N")
			{
				BadInput = false;
				townArray[PlayerTempVert][PlayerTempHoriz] = ' ';
				playerVert = 21;
				PlayerHoriz = 14;
				townArray[playerVert][PlayerHoriz] = 'P';
				tempFunc(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
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

void tempFunc(string &Location, bool &Sword, int &PlayerHealth, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2) //This function serves as the respawn function if the player chooses the no option.
{
	system("cls");
	Sleep(900);

	if (WarStory10 == true && PlayerHealth == 10)
	{
		PlayerHealth = 20;
	}

	//Fun times here. I realized that if every function in the town calls this one, the WarStory buffs will just infinitely stack each time they are seen. Instead, let the buffs set a new PlayerHealth
	//and use the Armor as a "miss chance" on the NPC that wants to fight you. (DC and SN)

	else if (WarStory5 == true && PlayerHealth == 10)
	{
		PlayerHealth = 15;
	}

	townMap(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
}

void Level_2_Begin(string &Location, bool &Sword, int &PlayerHealth, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	system("cls");
	PlaySound(TEXT("Prison_Door.wav"), NULL, SND_SYNC);
	cout << "You walk out of the prison's main door and end up in a small town." << endl << endl;
	Sleep(300);
	cout << "There isn't much here of use. You do know that there is a stables to the north that might have a horse." << endl << endl;
	Sleep(300);
	cout << "The guards here will all be looking for an escaped prisoner. A horse would definitely help escape." << endl << endl;
	Sleep(300);
	cout << "Other than the horse there is also a smith to the east, a clothes store to the north-east, an inn to the west," << endl << endl;
	Sleep(300);
	cout << "and an alchemist shop to the north-west. They might have something useful inside if I check quietly." << endl << endl;
	pressEnter();
	townMap(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
}

//End JS







// Death System coded by Joshua Salkeld
void PlayerDeath()
{
	system("cls");
	PlaySound(TEXT("Sword_Death.wav"), NULL, SND_SYNC);
	Sleep(650);
	cout << "The last thing you feel is your body hit the floor before your vision goes black." << endl << endl;
	Sleep(1600);
	system("cls");
	Sleep(650);
	//ascii art was made using a generator from this website http://www.glassgiant.com/ascii/
	//Additional color added by Sebastian Newbold
	cout << red;
	cout << ".........." << lightred << "~~" << red << "....." << lightred << "~~" << red << ".." << lightred << "~~" << red; 
	cout << "..." << lightred << "~~" << red << "..." << lightred << "~~~~" << red << "...." << lightred << "~~~~" << red; 
	cout << "......" << lightred << "~~~~~~" << red << "...." << lightred << "~~~~~~" << red << ".." << lightred << "~~~~~~~" << red;
	cout << "...." << lightred << "~~~~~~" << red << "................" << endl;
	cout << "..........." << lightred << "~~" << red << "..." << lightred << "~~" << red << ".." << lightred << "~~" << red; 
	cout << "....." << lightred << "~~" << red << "...." << lightred << "~" << red << "......." << lightred << "~" << red;
	cout << "......." << lightred << "~~" << red << "....." << lightred << "~~" << red << "..." << lightred << "~~" << red;
	cout << "...." << lightred << "~~" << red << "........." << lightred << "~~" << red << "...." << lightred << "~~" << red << ".............." << endl;
	cout << "............" << lightred << "~" << red << "..." << lightred << "~" << red << ".." << lightred << "~~" << red;
	cout << "......." << lightred << "~~" << red << "..." << lightred << "~" << red << "......." << lightred << "~" << red;
	cout << "......." << lightred << "~~" << red << "......" << lightred << "~~" << red << ".." << lightred << "~~" << red;
	cout << "...." << lightred << "~~" << red << "........." << lightred << "~~" << red << "....." << lightred << "~~" << red << "............." << endl;
	cout << "............." << lightred << "~" << red << "." << lightred << "~" << red << "..." << lightred << "~~" << red;
	cout << "........" << lightred << "~~" << red << ".." << lightred << "~" << red << "......." << lightred << "~" << red;
	cout << "......." << lightred << "~~" << red << "......" << lightred << "~~" << red << ".." << lightred << "~~" << red;
	cout << "...." << lightred << "~~" << red << "........." << lightred << "~~" << red << "......" << lightred << "~~" << red << "............" << endl;
	cout << ".............." << lightred << "~" << red << "...." << lightred << "~~" << red << "........" << lightred << "~~" << red;
	cout << ".." << lightred << "~" << red << "......." << lightred << "~" << red << "......." << lightred << "~~" << red;
	cout << "......" << lightred << "~~" << red << ".." << lightred << "~~" << red << "...." << lightred << "~~~~~~" << red;
	cout << "....." << lightred << "~~" << red << "......." << lightred << "~~" << red << "..........." << endl;
	cout << ".............." << lightred << "~" << red << "...." << lightred << "~~" << red << "........" << lightred << "~~" << red;
	cout << ".." << lightred << "~" << red << "......." << lightred << "~" << red << "......." << lightred << "~~" << red;
	cout << "......" << lightred << "~~" << red << ".." << lightred << "~~" << red << "...." << lightred << "~~" << red;
	cout << "........." << lightred << "~~" << red << "......." << lightred << "~~" << red << "..........." << endl;
	cout << ".............." << lightred << "~" << red << "...." << lightred << "~~" << red << "......." << lightred << "~~" << red;
	cout << "..." << lightred << "~" << red << "......." << lightred << "~" << red << "......." << lightred << "~~" << red;
	cout << "....." << lightred << "~~" << red << "..." << lightred << "~~" << red << "...." << lightred << "~~" << red;
	cout << "........." << lightred << "~~" << red << "......" << lightred << "~~" << red << "............" << endl;
	cout << ".............." << lightred << "~" << red << "....." << lightred << "~~" << red << "....." << lightred << "~~" << red;
	cout << "...." << lightred << "~~" << red << "...." << lightred << "~~" << red << "........" << lightred << "~~" << red;
	cout << "...." << lightred << "~~" << red << "...." << lightred << "~~" << red << "...." << lightred << "~~" << red;
	cout << "........." << lightred << "~~" << red << "....." << lightred << "~~" << red << "............." << endl;
	cout << ".............." << lightred << "~" << red << "........" << lightred << "~~" << red << ".........." << lightred << "~~~~" << red;
	cout << ".........." << lightred << "~~~~~~" << red << "...." << lightred << "~~~~~~" << red << ".." << lightred << "~~~~~~~" << red;
	cout << "...." << lightred << "~~~~~~~" << red << "..............." << endl;
	//End SN
	cout << endl << endl << endl << endl << endl << endl;
	Sleep(4500);
	exit(0);
}
// End JS\1

// Battle System Written by Joshua  Salkeld
bool battleGuard(string &Location, bool Sword, int PlayerHealth, bool guardFight, bool Key, bool CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
{
	int GuardHealth = 5;
	const int maxDamage = 4;
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
				playerMiss = (rand() % MissChance) + 1;
				if (playerMiss < 25) //25% chance to miss
				{
					cout << red << "Your sword collides with the guards armor dealing no damage. You missed." << normal << endl << endl;
					PlaySound(TEXT("Sword_Armor.wav"), NULL, SND_SYNC);
					Sleep(300);
				}
				else
				{
					cout << lightcyan << "Your sword collides with the guard. You deal " << Damage << " damage." << normal << endl << endl;
					PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
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
			else if (getChoice == "holy hand grenade" || getChoice == "hhg")//Type holy hand grenade or hhg to skip the guard fight
				GuardHealth = 0;
			else
			{
				system("cls");
				Sleep(650);
			}
			if (getChoice != "holy hand grenade" && getChoice != "hhg")
			{
				cout << "The guard swings at you." << endl << endl;
				Sleep(300);
				Damage = (rand() % maxDamage) + 1; //Damage is between 1 and 4
				guardMiss = (rand() % MissChance) + 1;
				if (guardMiss < 25)
				{
					cout << lightgreen << "The guard swings wide and misses you." << normal << endl << endl;
					PlaySound(TEXT("Sword_Air.wav"), NULL, SND_SYNC);
					pressEnter();
				}
				else
				{
					cout << lightred << "The guard's sword collides with your chest dealing " << Damage << " damage." << normal << endl << endl;
					PlaySound(TEXT("Sword_Flesh.wav"), NULL, SND_SYNC);
					pressEnter();
					PlayerHealth = PlayerHealth - Damage; //calculate player health

					if (PlayerHealth <= 0)
					{
						break;
					}
				}
			}
		}
		if (GuardHealth <= 0)
		{
			PlaySound(TEXT("Sword_Death.wav"), NULL, SND_SYNC);
			cout << "You watch as the guard's body goes limp and hits the floor." << endl << endl;
			PlaySound(TEXT("Uncon_Body.wav"), NULL, SND_SYNC);
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
		Hallway1(Location, Sword, PlayerHealth, guardFight, Key, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
	}
	return guardFight;
}
// End JS

string CaptainQuarters(string &Location, bool &Sword, int &PlayerHealth, bool &Key, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
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
	int maxLoc = 4;
	Location = "Captain's Quarters";
	int keyLocation = (rand() % maxLoc + 1); //sets key to either location 1, 2, 3, or 4.
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
							PlaySound(TEXT("Cap_Sleep.wav"), NULL, SND_SYNC);
							Sleep(300);
							cout << "The bastard has kept you locked up, tortured, beaten for the five longest years of your life. He must die." << endl << endl;
							Sleep(300);
							cout << "Press 1 to slit his throat like the pig he is." << endl;
							Sleep(300);
							cout << "Press 2 to have mercy for the time being." << endl;
							getline(cin, killCapChoice);

							if (killCapChoice.at(0) == '1')
							{
								system("cls");
								cout << "You slice your sword across the Captain's jugular, wetting it with his blood. Your captor is dead." << endl << endl;
								PlaySound(TEXT("Sword_Death.wav"), NULL, SND_SYNC);
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
								PlaySound(TEXT("Cap_Keys.wav"), NULL, SND_SYNC);
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
								PlaySound(TEXT("Cap_Keys.wav"), NULL, SND_SYNC);
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
								PlaySound(TEXT("Cap_Keys.wav"), NULL, SND_SYNC);
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
							cout << "You rifle through the contents of the desktop";
							if (keyLocation != 4)
								cout << ", but find nothing of interest to your goal." << endl << endl;
							else if (keyLocation == 4)
								cout << "..." << endl << endl;
							Sleep(300);
							if (keyLocation == 4)
							{
								PlaySound(TEXT("Cap_Keys.wav"), NULL, SND_SYNC);
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
		Level_2_Begin(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
	}

	else if (Key && !CaptainDead)
	{
		cout << "You have the key to your freedom, and you've taken mercy on the Captain. You need to get back out to the Door and move on from this place." << endl << endl;
		Sleep(300);
		pressEnter();
		Level_2_Begin(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
	}

	//====================================================================
	// THIS IS WHERE TO CONTINUE FOR LATER
	//====================================================================

	return Location;//Replace later
}




string LockedDoor(string &Location, bool &Key, bool &Sword, int &PlayerHealth, bool CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
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
		PlaySound(TEXT("Prison_Door.wav"), NULL, SND_SYNC);
		pressEnter();//To Level 2
		townMap(Location, Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
	}
	return Location;//Replace later
}


string Hallway1(string &Location, bool Sword, int PlayerHealth, bool guardFight, bool Key, bool CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
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
				cout << "Press 1 to sneak into the Captain's Quarters." << endl;
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
						CaptainQuarters(Location, Sword, PlayerHealth, Key, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
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
					LockedDoor(Location, Key,  Sword, PlayerHealth, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
					//Written By Sebastian Newbold
					//Examined the door and found that it is locked
					examinedDoor = " LOCKED";
					notFromCells = 1;
					system("cls");
					cout << "On your left is the Armory." << endl << endl;
					Sleep(300);
					cout << "On your right is the Captain's Quarters." << endl << endl;
					Sleep(300);
					cout << "Straight ahead is the hallway with your cell." << endl << endl;
					Sleep(300);
					//End SN
				}
				else if (getChoice.at(0) == '3')
				{
					Armory (Location, Sword, PlayerHealth, guardFight, Key, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2); //paths continues in Armory function
					//Written By Sebastian Newbold
					notFromCells = 1;
					system("cls");
					cout << "In front of you is the Captain's Quarters." << endl << endl;
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
				PlaySound(TEXT("Drink_Potion.wav"), NULL, SND_SYNC);
				Sleep(300);
				PlayerHealth = 10;
				cout << "Your health is now " << PlayerHealth << "." << endl << endl;
				pressEnter();
				break;
			}
			else if (getChoice.at(0) == '2')
			{
				system("cls");
				cout << "The battle was rough but you decide against taking it. You turn from the guard's body and advance quickly in hopes to avoid another battle." << endl << endl;
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
				CaptainQuarters(Location, Sword, PlayerHealth, Key, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
			}
			else if (getChoice.at(0) == '2')
			{
				system("cls");
				notFromArmory = 1;
				examinedDoor = " LOCKED";
				cout << "The door is " << red << "LOCKED" << normal << ". Best to check with the captain." << endl << endl;
				pressEnter();
				system("cls");
				cout << "Straight ahead is the hallway to your cell." << endl << endl;
				Sleep(300);
				cout << "On your right is the Captain's Quarters." << endl << endl;
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
string Armory(string &Location, bool Sword, int PlayerHealth, bool guardFight, bool Key, bool &CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
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
				PlaySound(TEXT("Armory_Sword.wav"), NULL, SND_SYNC);
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
				afterGuard = battleGuard(Location, Sword, PlayerHealth, guardFight, Key, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
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

string StartingCell(string &Location, bool Sword, int PlayerHealth, bool guardFight, bool Key, bool CaptainDead, bool WarStory5, bool WarStory10, string Clothes[], bool Armor, bool SwordLv2)
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
			PlaySound(TEXT("Player_Sleep.wav"), NULL, SND_SYNC);
			Sleep(1000);
			system("Color 07");//Normal screen color
		}
		else if (getChoice.at(0) == '2')
		{
			PlaySound(TEXT("Cell_Door.wav"), NULL, SND_SYNC);
			Location = "Hallway1";
			Hallway1(Location, Sword, PlayerHealth, guardFight, Key, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);

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
	const int Size = 3;
	string Clothes[Size] = { " ", " ", " " };
	bool Armor = false;
	bool SwordLv2 = false;
	srand(time(NULL));

	//Source - Zackary Moore
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	int fontSize = 22;
	font.dwFontSize.Y = fontSize;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &font);
	//Source - Zackary Moore END

	system("MODE 150,30");
	SetConsoleWindowInfo;

	//Start intro screen thing by: Dan Curley and Sebastian Newbold

	for (int i = 1; i < 8; i++)
	{
		cout << "=======================================================================" << endl;
		cout << "+                                                                     +" << endl;
		cout << "=                                                                     =" << endl;
		cout << "+                                                                     +" << endl;
		if (i == 1 || i == 3 || i == 5)
			cout << "=" << red << "                            DUNGEON ESCAPE                           " << normal << "=" << endl;
		if (i == 2 || i == 4 || i >= 6)
			cout << "=" << lightred << "                            DUNGEON ESCAPE                           " << normal << "=" << endl;
		cout << "+                                                                     +" << endl;
		if (i == 1 || i == 3 || i == 5)
			cout << "=" << red << "                          THE          GRUES                         " << normal << "=" << endl;
		if (i == 2 || i == 4 || i >= 6)
			cout << "=" << lightred << "                          THE          GRUES                         " << normal << "=" << endl;
		cout << "+                                                                     +" << endl;
		if (i < 6)
		{
			cout << "=                                                                     =" << endl;
			cout << "+                                                                     +" << endl;
			cout << "=                                                                     =" << endl;
			cout << "+                                                                     +" << endl;
		}
		if (i == 6)
		{
			cout << normal << "=" << magenta << "                         Press ENTER to start.                       " << normal << "=" << endl;
			cout << "+                                                                     +" << endl;
			cout << "=                                                                     =" << endl;
			cout << "+                                                                     +" << endl;
		}
		if (i == 7)
		{
			cout << normal << "=" << magenta << "                         Press ENTER to start.                       " << normal << "=" << endl;
			cout << "+                                                                     +" << endl;
			cout << normal << "=" << magenta << "                            Enter X to exit.                         " << normal << "=" << endl;
			cout << "+                                                                     +" << endl;
		}
			
		cout << "=                                                                     =" << endl;
		cout << "+                                                                     +" << endl;
		cout << "=======================================================================" << endl;
		for (int i = 0; i < 414; i++)
		{
			cout << "\b";
		}
		Sleep(500);
		
		if (i < 7)
			system("cls");
	}
	/*cout << "=======================================================================" << endl;
	cout << "=                                                                     =" << endl;
		cout << "=" << lightred << "                            DUNGEON ESCAPE                           " << normal << "=" << endl;
		cout << "=" << lightred << "                          THE          GRUES                         " << normal << "=" << endl;
	cout << "=                         Press ENTER to start.                       =" << endl;
	cout << "=                            Enter X to exit.                         =" << endl;
	cout << "=                                                                     =" << endl;
	cout << "=                                                                     =" << endl;
	cout << "=======================================================================" << endl;
	*/
	string input;
	
	getline(cin, input);
	for (int i = 0; i < input.length(); i++)
	{
		if (input.at(i) == 'x' || input.at(i) == 'X')
			exit(0);
	}
	for (int i = -1; i < input.length(); i++)
	{
			cin.ignore();
	}
	system("cls");

	//End DC
	/*
	string input1;
	cout << "Where do you want to start? Cell or Town? 1 or 2? ";
	getline(cin, input1);

	
	if (input1.at(0) == '2')
	{
		string Clothes[Size] = {"","",""};//TEMP
		CaptainDead = true;//TEMP
		townMap(Location, Sword, PlayerHealth, CaptainDead, false, false, Clothes, false, false);//TEMP
	}
	else
	{
		StartingCell(Location, Sword, PlayerHealth, guardFight, Key, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);
	}
	*/

	StartingCell(Location, Sword, PlayerHealth, guardFight, Key, CaptainDead, WarStory5, WarStory10, Clothes, Armor, SwordLv2);



	system("pause");
	return 0;
}