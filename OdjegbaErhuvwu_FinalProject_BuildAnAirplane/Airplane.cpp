#define _USE_MATH_DEFINES //allows the use of math CONSTANTS, including PI.
//must be above all the include statements

#include <iostream> // adds the library to allow input and output
#include <math.h> //allows for additional math functions
#include <cmath> //ditto "     "       "      "
#include <string> //allows for string manipulation
#include <iomanip> //allows for manipulation of inputs and outputs
#include <fstream>
#include <fstream> //allows for input and output to/from files
#include <vector> //allows for vectors to be used
#include <cstdlib> //for rand()
#include "Airplane.h" //include the header file

using namespace std; //goes below include include statements; no more std typing
//Put all Function Prototypes here (function header), just above main, so the program can point to the method: 


//-------------------------------------------------GETTING STUFF
//GET USER INPUT
//return type, class name, scope resolution access operator, function name
void Airplane::getUserInput()
{
	char choice; //allows the user to say yes or no

	//prompt user for starting airport name
	cout << "Enter the name of your starting airport: " << endl;

	//validates airport name using function below
	while (true)
	{
		getline(cin, startingAirportName); //this is a string with spaces, which is why i am using getline
		if (isValidAirportName(startingAirportName))
		{
			break;
		}
	}
	//prompt user for ending airport name
	cout << "Enter the name of your ending airport: " << endl;

	while (true)
	{
		getline(cin, endingAirportName); //this is a string with spaces, which is why i am using getline
		if (isValidAirportName(endingAirportName))
		{
			break;
		}
	}
	//prompt user for crusing wind speed
	cout << "Enter your cruising speed in miles per hour: " << endl;
	while (!(cin >> cruisingSpeed) || cruisingSpeed <= 0)
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Please enter a positive cruising speed: " << endl;
	}

	//prompt user for wind speed
	cout << "Enter your wind speed in miles per hour: " << endl;
	while (!(cin >> windSpeed) || windSpeed < 0)
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Please enter a valid wind speed: " << endl;
	}

	//prompt user for wind direction and validate it using function below
	cout << "Enter your wind direction (N)(NW)(NE)(S)(SW)(SE)(E)(W): " << endl;
	while (true)
	{
		cin >> windDirection;
		if (isValidDirection(windDirection)) break;
		cout << "Invalid direction. Try again: " << endl;
	}

	//prompt user for crusing dircetion and validate it with function below
	//RESEARCH THIS
	cout << "Enter your cruising direction: North (N), South(S), East(E), West(W): " << endl;
	while (true)
	{
		cin >> cruisingDirection;
		if (isValidDirection(cruisingDirection)) break;
		cout << "Invalid direction. Try again: " << endl;
	}

	//prompt user for pilot weight and validate it
	cout << "Enter the weight of your pilot in pounds: " << endl;
	while (!(cin >> pilotWeight) || pilotWeight <= 0)
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Please enter a valid weight: " << endl;
	}

	//prompt user for front passenger weight
	cout << "Do you have a passenger? Y/N" << endl;
	cin >> choice;
	//if there is a passenger, the number of passengers is made equal to the max passenger
	if (choice == 'Y' || choice == 'y')
	{
		numPassengers = maxPassengersAllowed; //this stores one passenger, since that is the max allowed
		cout << "Enter the weight of your massenger in pounds (lbs): " << endl;
		cin >> weightOfPassenger;
		while (!(cin >> weightOfPassenger) || weightOfPassenger <= 0)
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Please enter a valid weight: " << endl;
		}
	}
	else //the weight of passengers is 0, since there are no passengers
		weightOfPassenger = 0;

	//prompt user for luggage weight
	cout << "Do you have luggage? Y/N " << endl;
	cin >> choice;
	//if the user chooses yes in these ways then ask for their luggage weight
	if (choice == 'Y' || choice == 'y')
	{
		cout << "Enter your luggage weight in pounds: " << endl;
		while (!(cin >> luggageWeight) || luggageWeight < 0)
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Please enter a valid weight: " << endl;
		}
	}
	if (luggageWeight > baggageWeightAllowance) //if the luggage weight exceeds 50, set it to 50 pounds
	{
		luggageWeight = baggageWeightAllowance;
	}

	else //if the user says no, then there is no luggage weight 
		luggageWeight = 0;

	//prompt user for crusing altitude
	cout << "Enter your cruising altitude in feet: " << endl;
	//make sure the user enters a positive number and the input is valid
	while (!(cin >> cruisingAltitude) || cruisingAltitude <= 0)
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Please enter a valid altitude: " << endl;
	}
	
	/*
•	Starting Airport
•	Ending Airport
•	Cruising windspeed (miles per hour)
•	Cruising direction (research)
•	Pilot Weight (in pounds)
•	Front passenger Weight (in pounds)
•	Luggage weight (rear seat in pounds)
•	Cruising Altitude (feet)
	*/


}//end get user input

//this makes sure that the airport names are real and not random special characters or numbers
bool Airplane::isValidAirportName(const string& name)
{
	if (name.empty()) 
	{
		cout << "Please enter an airport name." << endl;
		return false;
	}

	for (char c : name)
	{
		if (!isalpha(c) && c != ' ' && c != '-') 
		{
			cout << "Please enter a VALID airport name." << endl;
			return false;
		}
	}
	return true;
}
//this makes sure that the direction are these valid characters
bool Airplane::isValidDirection(const string& dir)
{
	return dir == "N" || dir == "S" || dir == "E" || dir == "W" ||
		dir == "NE" || dir == "NW" || dir == "SE" || dir == "SW" 
		|| dir == "n" || dir == "s" || dir == "e" || dir == "w" ||
		dir == "ne" || dir == "nw" || dir == "se" || dir == "sw";
}
//makes sure that values input are positive numbers
bool Airplane::isPositiveValue(double value)
{
	return value > 0;
}



//*************************************GETTERS AND SETTERS *********************************

//this reads/accesses the private field, maxAltitude and returns it
//return type, class name, scope resolution access operator, function name
double Airplane::getMaxAltitudeOfAircraft() const // 
{
	return maxAltitudeOfAircraft; 
}

//this reads/accesses the private field, fuel capacity and returns it
//return type, class name, scope resolution access operator, function name
double Airplane::getFuelCapacity() const
{
	return totalFuelCapacity;
}

//this reads/accesses the private field, number of passengers and returns it
//return type, class name, scope resolution access operator, function name

double Airplane::getNumPassengers() const
{
	return numPassengers;
}

//this reads/accesses the private field, length of aircraft and returns it
//return type, class name, scope resolution access operator, function name

double Airplane::getLengthOfAircraft()
{
	return lengthOfAircraft;
}
//this reads/accesses the private field, height of aircraft and returns it
//return type, class name, scope resolution access operator, function name
double Airplane::getHeightOfAircraft()
{
	return heightOfAircraft;
}

//this reads/accesses the private field, wing span and returns it
//return type, class name, scope resolution access operator, function name

double Airplane::getWingspanOfAircraft()
{
	return wingspanOfAircraft;
}

//this reads/accesses the private field, wing area and returns it
//return type, class name, scope resolution access operator, function name

double Airplane::getWingAreaOfAircraft()
{
	return wingAreaOfAircraft;
}

//this reads/accesses the private field, oil capacity and returns it
//return type, class name, scope resolution access operator, function name
double Airplane::getOilCapacityOfAircraft()
{
	return oilCapacityOfAircraft;
}


//FUNCTIONS THAT CALCULATE SHIT

//------------------------------------WEIGHT-RELATED FUNCTIONS------------------------------------------
					
//this function calculates Gross Weight and Takeoff weight
//return type, class name, scope resolution access operator, function name and parameters

double Airplane::calculateGrossAndTakeoffWeight(double standardEmptyWeight, double weightOfPassenger, double pilotWeight, double luggageWeight)
{
	double grossWeight = 0;
	double takeoffWeight = 0;
	//add up standadrd empty weight, weight of passenger if there is one, pilot weight, and luggage weight if theres one
	grossWeight = standardEmptyWeight + weightOfPassenger + pilotWeight + luggageWeight;
	takeoffWeight = grossWeight; //made them equal since they are equal technically

	//display it
	cout << "Gross Weight: " << grossWeight << " pounds." << endl;
	cout << "Takeoff weight: " << takeoffWeight << " pounds." << endl;
	return grossWeight;
}//end calculate gross weight

//this calculates the takeoff weight
//double Airplane::calculateTakeoffWeight()
//{
//	//because gross weight is equal to takeoff weight, use the function calculateGrossWeight and store it into takeoff weight
//	takeoffWeight = calculateGrossWeight (standardEmptyWeight, weightOfPassenger, pilotWeight, luggageWeight);
//
//	//print takeoff Weight
//	cout << "Takeoff Weight: " << takeoffWeight << " pounds." << endl;
//
//	//return that shit
//	return takeoffWeight;
//
//}//end takeoff weight


//---------------------------------SPEED-RELATED FUNCTION(S)-------------------------------------------------
//return type, class name, scope resolution access operator, function name
//this function calculates ground speed using true air speed (TAS) and wind speed
double Airplane::calculateGroundSpeed(double *TAS, double *wSA)
{
	//declare variables
	double groundSpeed = 0;

	//subtract the pointers since they hold the values
	groundSpeed = *TAS - *wSA;

	return groundSpeed;

}//end calculateGroundSpeed

//---------------------------------TIME-RELATED FUNCTION(S)-------------------------------------------------
//return type, class name, scope resolution access operator, function name
//this calculates the time for travel for this aircraft by dividing the distance between the airports by the ground speed calculated above
double Airplane::calculateTotalTimeForTravel() //may need parameter list
{
	//declare variables and pointers
	double* trueAirSpeedAddress, * windSpeedAddress, groundSpeed;
	trueAirSpeedAddress = &trueAirSpeedOfAircraft; //stores the address of TAS
	windSpeedAddress = &windSpeedOfAircraft; //stores address of Wind speed
	double totalTravelTime = 0;
	//time
	const double takeoffTime = (5.0 / 60.0); //this is measured in hours, since it takes 5 minutes
	const double landingTimeAndTaxing = (1.0 / 6.0); //measured in hours, since it takes 10 minutes


	groundSpeed = calculateGroundSpeed(trueAirSpeedAddress, windSpeedAddress); //calculate groundspeed and store it here


	//avoid embedding functions in each other when calculating something
	//add landing and takeoff time
	//convert into hours and minutes
	totalTravelTime = (distanceBetweenAirports / groundSpeed) + takeoffTime + landingTimeAndTaxing; //don't divide by function; use a pointer
	
	cout << "Ground Speed: " << groundSpeed << " miles per hour." << endl;
	cout << "Time for Travel: " << totalTravelTime << " hours." << endl;
	return totalTravelTime;
} //end function calculateTimeForTravel


//---------------------------------DIRECTION-RELATED FUNCTION(S)-------------------------------------------------




//---------------------------------FUEL-RELATED FUNCTION(S)-------------------------------------------------
//return type, class name, scope resolution access operator, function name
//"calculates" total fuel during takeoff
double Airplane::calculateFuelBurnedDuringTakeoff()
{
	//declare variable and store a value
	double totalBurnedFuelDuringTakeoff = 1.5; //1.5 gallons, as given by Keeney

	//return that shit
	return totalBurnedFuelDuringTakeoff;
}//end calculate fuel burned during takeoff

//return type, class name, scope resolution access operator, function name
//calculaes weight of fuel burned during takeoff
double Airplane::calculateWeightOfFuelBurnedDuringTakeoff()
{
	//declare variables 
	double totalWeightOfFuelBurnedDuringTakeoff = 0;
	double totalFuelBurnedDuringTakeoff;

	//store fuel during takeoff into this variable
	totalFuelBurnedDuringTakeoff = calculateFuelBurnedDuringTakeoff();

	//calculate total weight by multipltyng the weight by the fuel burned during takeoff
	totalWeightOfFuelBurnedDuringTakeoff = totalFuelBurnedDuringTakeoff * weightOfFuel;

	//return that shit
	return totalWeightOfFuelBurnedDuringTakeoff;
}//end calculate weight of fuel during takeoff

double Airplane::calculateCruiseTime()
{
	//declare variable and constants
	double cruiseTime, takeoffFuelBurnedCapacity, landingFuelBurnedCapacity;
	
	takeoffFuelBurnedCapacity = calculateFuelBurnedDuringTakeoff();
	landingFuelBurnedCapacity = calculateFuelBurnedDuringLanding();

	//calculate cruise time by subtracting fuel burned during takeoff and landing from the total usbale fuel and divide by the burn rate
	cruiseTime = (usableFuelCapacity - takeoffFuelBurnedCapacity - landingFuelBurnedCapacity) / fuelBurnRate;

	//return that shit
	return cruiseTime;
}//end calcualate cruise time

//return type, class name, scope resolution access operator, function name
//calculates fuel burned during cruise
double Airplane::calculateFuelBurnedDuringCruise()
{
	double totalFuelBurnedDuringCruise = 0;
	double actualCruiseTime;

	//calculate the cruise time and store it in this variable
	actualCruiseTime = calculateCruiseTime();

	//calculate total fuel burned during cruise
	totalFuelBurnedDuringCruise = actualCruiseTime * fuelBurnRate ;

	cout << "The total fuel burned during cruise is: " << totalFuelBurnedDuringCruise << " gallons." << endl;
	//return that shit
	return totalFuelBurnedDuringCruise;
}//end calculate fuel burned during cruise

//return type, class name, scope resolution access operator, function name
//"calculates" the total fuel burned during landing
double Airplane::calculateFuelBurnedDuringLanding()
{
	double totalBurnedFuelDuringLanding = 2; //2 gallons, according to Keeney

	return totalBurnedFuelDuringLanding;
}//end calculate fuel during landing

//return type, class name, scope resolution access operator, function name
//this calculates the weight of all the fuel on the plane
double Airplane::calculateWeightOfTotalFuel()
{
	double weightOfTotalFuel = 0;

	weightOfTotalFuel = weightOfFuel * totalFuelCapacity;

	cout << "Weight of Total Fuel: " << weightOfTotalFuel << " pounds." << endl;

	return weightOfTotalFuel;
}//end calculate weight of total fuel

double Airplane::convertTravelTimeToMinutesAndHours()
{
	double totalTimeForTravel = calculateTotalTimeForTravel(); 

	int hours = static_cast<int>(totalTimeForTravel);  
	double fractionalPart = totalTimeForTravel - hours;       
	double minutes = fractionalPart * 60;                     

	//print time

	return totalTimeForTravel; //
}

//double Airplane::calculateWeightOfBurnedFuel()
//{
// //burned fuel during takeoff, cruise, and landing combined and multiply 6 
//
//
//}//end calculate weight of burned fuel
//double Airplane::calculateWeightOfBurnedFuelDuringCruise()
//{
//
//
//
//}//end calculate weight of burned fuel during cruise
//
//
//
//double Airplane::calculateTotalFuelUsed()
//{
//
//
//}//end calculate total fuel used
//
//
//
//double Airplane::calculateGallonsOfReservedFuel()
//{
//
//}//end gallons of reserved fuel


//---------------------------------OUTPUT-RELATED FUNCTION(S)-------------------------------------------------
//PRINTING
// //return type, class name, scope resolution access operator, function name
//this prints out the specifications of the aircraft, according to research and the actual manual
void Airplane::printAircraftSpecifications(ostream& out)
{
	out << "\nAircraft Specifications" << endl;
	out << "The name of the aircraft is: " << aircraftName << endl;
	out << "The color of the aircraft is: " << colorOfAircraft << endl;
	out << "This aircraft has " << numEngines << " engine." << endl;
	out << "The length of the aircraft is: " << lengthOfAircraft << " feet." << endl;
	out << "The height of the aircraft is: " << heightOfAircraft << " feet." << endl;
	out << "The wingspan of the aircraft is: " << wingspanOfAircraft << " feet." << endl;
	out << "The wing area of the aircraft is: " << wingAreaOfAircraft << " square feet." << endl;
	out << "The max altitude of the aircraft is: " << maxAltitudeOfAircraft << " feet." <<  endl;
	out << "The oil capacity of the aircraft is: " << oilCapacityOfAircraft << " gallons." << endl;
	out << "The total fuel of the aircraft is: " << totalFuelCapacity << " gallons." << endl;
	out << "The usable fuel of the aircraft is: " << usableFuelCapacity << " gallons." << endl;
	out << "The unusable fuel of the aircraft is: " << unusableFuelCapacity << " gallons." << endl;
	out << "The standard empty weight is: " << standardEmptyWeight << " pounds." << endl;
	out << "The maximum gross weight is: " << maximumGrossWeight << " pounds." << endl;
	out << "The maximum takeoff weight is: " << maxTakeoffWeight << " pounds." << endl;
	out << "The maximum landing weight is: " << maxLandingWeight << " pounds." << endl;
	out << "The baggage allowance is: " << baggageWeightAllowance << " pounds." << endl;
}//end function print specifications

//print user input
//return type, class name, scope resolution access operator, function name
void Airplane::printUserInput(ostream& out)
{
	out << "\nUser Output:" << endl;
	out << "The starting airport is: " << startingAirportName << endl;
	out << "The ending airport is: " << endingAirportName << endl;
	out << "The crusing speed is: " << cruisingSpeed << " miles per hour." << endl;
	out << "The wind speed is: " << windSpeed << " miles per hour." << endl;
	out << "The wind direction is: " << windDirection << endl;
	out << "The crusing direction is: " << cruisingDirection << endl;
	out << "The pilot weight is: " << pilotWeight << " pounds." << endl;
	out << "The passenger weight is: " << weightOfPassenger << " pounds" << endl;
	out << "The luggage weight is: " << luggageWeight << " pounds." << endl;
	out << "The cruising altitude is: " << cruisingAltitude << " feet." << endl;
}//end print user input

//print calculated fields at once, instead of calling them individually
//decided to print these to the file
//return type, class name, scope resolution access operator, function name
void Airplane::printCalculatedFields(ostream& out)
{
	double grossAndTakeoffWeight, groundSpeed, totalTimeForTravel, realTravelTime;
	out << "\nFlight Specifications:" << endl;

	//write/print gross weight and takeoff Weight to the file
	grossAndTakeoffWeight = calculateGrossAndTakeoffWeight(standardEmptyWeight, weightOfPassenger, pilotWeight, luggageWeight);
	out << "Gross / Takeoff Weight: " << grossAndTakeoffWeight << " lbs" << endl;

	//write/print ground speed to the file
	groundSpeed = calculateGroundSpeed(&trueAirSpeedOfAircraft, &windSpeedOfAircraft);
	out << "Ground Speed: " << groundSpeed << " mph" << endl;

	//write/print total time for travel to the file
	totalTimeForTravel = calculateTotalTimeForTravel();
	out << "Total Travel Time: " << totalTimeForTravel << " hours" << endl;

	//write/print total real time for travel to the file
	realTravelTime = convertTravelTimeToMinutesAndHours();
	out << "Real Travel Time: " << realTravelTime << " minutes" << endl;
}//end print calculated fields

//write these results to the file
int Airplane::writeResultsToFile()
{
	cout << "DEBUG: writeResultsToFile() EXECUTED" << endl;

	outFile.open("output.txt");

	if (!outFile.is_open())
	{
		cerr << "Error opening one file." << endl;
		return 1; // Exit program with an error code
	}

	printAircraftSpecifications(outFile);
	printUserInput(outFile);
	printCalculatedFields(outFile);

	outFile.close();
	return 0;
}

