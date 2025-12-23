// OdjegbaErhuvwu_FinalProject_BuildAnAirplane.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Erhuvwu Odjegba
// Date: 28 October 2024
// Purpose: Build an airplane and make sure it flies. if not, it crashes

#define _USE_MATH_DEFINES //allows the use of math CONSTANTS, including PI.
//must be above all the include statements

#include <iostream> // adds the library to allow input and output
#include <math.h> //allows for additional math functions
#include <cmath> //ditto "     "       "      "
#include <string> //allows for string manipulation
#include <iomanip> //allows for manipulation of inputs and outputs
#include <fstream> //allows for input and output to/from files
#include <vector> //allows for vectors to be used
#include <cstdlib> //for rand()
#include "Airplane.h" //include the header file


using namespace std; //goes below include include statements; no more std typing
//Put all Function Prototypes here (function header), just above main, so the program can point to the method: 

int main()
{
	//instantiate/make an object instance
	Airplane myAirplane;
	
	//call each function in order
	myAirplane.getUserInput();	
	myAirplane.printAircraftSpecifications(cout);
	myAirplane.printUserInput(cout);
	myAirplane.printCalculatedFields(cout);
	myAirplane.writeResultsToFile();


	cin.get(); //this keeps the program window open
	return 0; //return this when it runs properly
}


