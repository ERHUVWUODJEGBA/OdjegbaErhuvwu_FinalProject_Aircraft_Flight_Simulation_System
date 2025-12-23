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

//-------------------------------------------------GETTING STUFF
//GET USER INPUT
//return type, class name, scope resolution access operator, function name
void Airplane::getUserInput()
{
	char choice; //allows the user to say yes or no

	//prompt user for starting airport name
	cout << "Enter the name of your starting airport: " << endl;
	getline(cin, startingAirportName); //this is a string with spaces, which is why i am using getline
	cin.clear(); //clear bullshit
	cin.ignore(200, '\n');//clear bullshit

	//prompt user for ending airport name
	cout << "Enter the name of your ending airport: " << endl;
	getline(cin, endingAirportName); //this is a string with spaces, which is why i am using getline
	cin.clear(); //clear bullshit
	cin.ignore(200, '\n'); //clear bullshit

	//prompt user for crusing wind speed
	cout << "Enter your cruising speed in miles per hour: " << endl;
	cin >> cruisingSpeed; //store it
	cin.clear(); //clear bullshit
	cin.ignore(200, '\n'); //clear bullshit

	//prompt user for wind speed
	cout << "Enter your wind speed in miles per hour: " << endl;
	cin >> windSpeed; //store it
	cin.clear(); //clear bullshit
	cin.ignore(200, '\n'); //clear bullshit

	//prompt user for wind direction
	cout << "Enter your wind direction (N)(NW)(NE)(S)(SW)(SE)(E)(W): " << endl;
	cin >> windDirection; //store it
	cin.clear(); //clear bullshit
	cin.ignore(200, '\n'); //clear bullshit

	//prompt user for crusing dircetion
	//RESEARCH THIS
	cout << "Enter your cruising direction: North (N), South(S), East(E), West(W): " << endl;
	cin >> cruisingDirection; //store it
	cin.clear(); //clear bullshit
	cin.ignore(200, '\n'); //clear bullshit

	//prompt user for pilot weight
	cout << "Enter the weight of your pilot in pounds: " << endl;
	cin >> pilotWeight;
	cin.clear();
	cin.ignore(200, '\n');
	//makes sure that the pilot weight is a realistic number
	if (pilotWeight < 100 || pilotWeight > 300)
	{
		cout << "Please enter a valid weight between 100 and 300 pounds " << endl;
	}

	//prompt user for front passenger weight
	cout << "Do you have a passenger? Y/N" << endl;
	cin >> choice;
	//if there is a passenger, the number of passengers is made equal to the max passenger
	if (choice == 'Y' || choice == 'y')
	{
		numPassengers = maxPassengersAllowed; //this stores one passenger, since that is the max allowed
		cout << "Enter the weight of your massenger in pounds: " << endl;
		cin >> weightOfPassenger;
		cin.clear();
		cin.ignore(200, '\n');
		//makes sure that the passenger weight is a realistic number
		if (weightOfPassenger < 100 || weightOfPassenger > 300)
		{
			cout << "Please enter a valid weight between 100 and 300 pounds " << endl;
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
		cout << "Enter your luggage weight in pounds that ranges from 0-50 pounds: " << endl;
		cin >> luggageWeight;
		cin.clear();
		cin.ignore(200, '\n');

		//make sure the user enters a positive number
		if (luggageWeight < 0)
		{
			cout << "Please enter a valid luggage weight." << endl;
			luggageWeight = 0;
		}
		else if (luggageWeight > BAGGAGE_WEIGHT_ALLOWANCE) //if the luggage weight exceeds 50, set it to 50 pounds
		{
			//communicate why the luggage weight changed
			cout << "This exceeds the baggage limit. Because of this, your luggage is 50 pounds." << endl;
			luggageWeight = BAGGAGE_WEIGHT_ALLOWANCE;
		}

	}
	else //if the user says no, then there is no luggage weight 
		luggageWeight = 0;

	//prompt user for crusing altitude
	cout << "Enter your cruising altitude in feet: " << endl;
	cin >> cruisingAltitude;
	cin.clear();
	cin.ignore(200, '\n'); //make sure the user enters a positive number
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

////this reads/accesses the private field, oil capacity and returns it
////return type, class name, scope resolution access operator, function name
double Airplane::getSpeedOfAircraft()
{
	return speedOfAircraft;

}//end getter for speed

////this reads/accesses the private field, oil capacity and returns it
////return type, class name, scope resolution access operator, function name

void Airplane::setSpeedOfAircraft(double speed)
{
	speedOfAircraft = speed;

}//end setter for speed

//FUNCTIONS THAT CALCULATE SHIT

//------------------------------------WEIGHT-RELATED FUNCTIONS------------------------------------------
					
//this function calculates Gross Weight and Takeoff weight
//return type, class name, scope resolution access operator, function name and parameters

double Airplane::calculateGrossWeight(double standardEmptyWeight, double weightOfPassenger, double pilotWeight, double luggageWeight)
{
	//declare variables
	double grossWeight = 0;
	double weightOfAllFuel = 0;

	//calculate weight of fuel and store it here
	weightOfAllFuel = calculateWeightOfTotalFuel();
	//double takeoffWeight = 0;
	//standardEmptyWeight = STANDARD_EMPTY_WEIGHT;
	//add up standadrd empty weight, weight of passenger if there is one, pilot weight, weight of all fuel on board, and luggage weight if theres one
	grossWeight = standardEmptyWeight + weightOfPassenger + pilotWeight + luggageWeight + weightOfAllFuel;

	return grossWeight;
}//end calculate gross weight

//this calculates the takeoff weight
double Airplane::calculateTakeoffWeight()
{
	double takeoffWeight = 0;
	double grossWeight = 0;
	/*double *grossWeightAddress;
	grossWeightAddress = &grossWeight;*/
	//because gross weight is equal to takeoff weight, use the function calculateGrossWeight and store it into takeoff weight
	grossWeight = calculateGrossWeight(STANDARD_EMPTY_WEIGHT, weightOfPassenger, pilotWeight, luggageWeight);
	takeoffWeight = grossWeight;

	//return that shit
	return takeoffWeight;

}//end takeoff weight

//this calculates landing weight
double Airplane::calculateLandingWeight()
{
	//declare variables
	double landingWeight = 0;
	double takeoffWeight = 0;
	double weightOfBurnedFuel = 0;

	//calculate and store takeoff weight and weight of burned fuel
	takeoffWeight = calculateTakeoffWeight();
	weightOfBurnedFuel = calculateWeightOfBurnedFuel();

	//calculate landing weight
	landingWeight = takeoffWeight - weightOfBurnedFuel;


	//return it
	return landingWeight;
}//end calculate landing weight

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

//this calculates the takeoff speed of a soft field
double Airplane::calculateTakeoffSpeedOfSoftField()
{
	double takeoffSpeedSoftField = 0; 
	takeoffSpeedSoftField = TAKE0FF_SPEED_SOFT_FIELD; 

	return takeoffSpeedSoftField;
} //end calculateTakeoffSpeedOfSoftField

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

	groundSpeed = calculateGroundSpeed(trueAirSpeedAddress, windSpeedAddress); //calculate groundspeed and store it here

	//avoid embedding functions in each other when calculating something
	//add landing and takeoff time
	//convert into hours and minutes
	totalTravelTime = (distanceBetweenAirports / groundSpeed) + TAKEOFF_TIME + TAXING_AND_LANDING; //don't divide by function; use a pointer
	
	return totalTravelTime;
} //end function calculateTimeForTravel

//return type, class name, scope resolution access operator, function name
//this calculates the weight of all the fuel on the plane
//this is supposed to convert the fractional hour (2.8) into real time by multiplying the 0.8 by 60 minutes and adding it to 2
void Airplane::convertTravelTimeToMinutesAndHours()
{
	//declare variables
	double totalTimeForTravel = 0;
	double totalMinutesForTravel = 0;
	double hoursForTravel;
	double fractionalMinutesForTravel;
	double realMinutesForTravel;
	double realTimeForTravel;

	//this calculates the time for travel in hours and minutes
	totalTimeForTravel = calculateTotalTimeForTravel(); //2.8 hours
	hoursForTravel = static_cast<int>(totalTimeForTravel);//this makes the decimal hours, 2.8 into a 2 since it is converting it into an integer
	fractionalMinutesForTravel = totalTimeForTravel - hoursForTravel; //2.8-2 = 0.8
	realMinutesForTravel = fractionalMinutesForTravel * 60; //multiply fractional hours by 60 to get real minutes

	//calculate the total minutes for travel so that it can be used for cruise time (multiply hours by 60 and add the remaining minutes)
	totalMinutesForTravel = (hoursForTravel * 60) + realMinutesForTravel;

	//display the time in real time
	cout << "This flight will take " << hoursForTravel << " hours and " << realMinutesForTravel << " minutes." << endl;
	cout << "This flight is a total of " << totalMinutesForTravel << " minutes." << endl;
}//end convert time function

//TAKEOFF DISTANCE AND LANDING DISTANCE: 
/*
	BFD EVELATION CONSTANT : 2,143 feet (TAKEOFF POINT)
	CMH EVELATION CONSTANT: 815 FEET (LANDING)
	TAKEOFF DISTANCE (IN MILES): 500 FEET PER MINUTE TO GET TO 4500 FROM 2143 FEET
	LANDING DISTANCE (IN MILES): 200 FEET PER MINUTE TO GET FROM 4500 TO 815 FEET
	COMPUTE FINAL CRUISE DISTANCE BY SUBTRACTING TAKEOFF AND LANDING DISTANCE FROM TOTAL DISTANCE
	CRUISE TIME: FINAL CRUISE DISTANCE / CRUISING SPEED (IF NUMBER IS TOO BIG IT IS WRONG OR TOO SMALL) MPH

	*/

	//this function calculates the cruise time
double Airplane::calculateCruiseTime() //FIX THIS TELL KEENEY I AM STRUGGLING WITH THIS
{
	//declare variables and constants
	double cruiseTime = 0;
	double cruiseSpeed = 0;
	const double TAKEOFF_CLIMB_RATE = 500.00; //feet per minute given
	const double LANDING_DESCENT_RATE = 200.00; //feet per minute
	const double BFD_ELEVATION = 2143.00; //feet given above
	const double CMH_ELEVATION = 815.00;  //feet given aobe
	const double FEET_PER_MILE = 5280.00; //this will be used to convert the feet to miles above. 5280 feet are in one mile

	//Calculate takeoff and landing distances in miles; the feet must be converted
	double takeoffDistance = (cruisingAltitude - BFD_ELEVATION) / FEET_PER_MILE;
	double landingDistance = (cruisingAltitude - CMH_ELEVATION) /FEET_PER_MILE; 

	//calculate the cruise distance
	double cruiseDistance = distanceBetweenAirports - (takeoffDistance + landingDistance);

	//cruise speed is the same as true air speed
	cruiseSpeed = trueAirSpeedOfAircraft;

	//calculate cruise time
	cruiseTime = cruiseDistance / cruiseSpeed;

	//return that shit
	return cruiseTime;
}//end calcualate cruise time

void Airplane::convertCruiseTimeToMinutesAndHours()
{

	//declare variables
	double cruiseTime = 0;
	double totalMinutesForTravel = 0;
	double hoursForTravel;
	double fractionalMinutesForTravel;
	double realMinutesForTravel;
	double realTimeForTravel;

	//this calculates the time for travel in hours and minutes
	cruiseTime = calculateCruiseTime(); //2.8 hours
	hoursForTravel = static_cast<int>(cruiseTime);//this makes the decimal hours, 2. something into a 2 since it is converting it into an integer
	fractionalMinutesForTravel = cruiseTime - hoursForTravel;
	realMinutesForTravel = fractionalMinutesForTravel * 60; //multiply fractional hours by 60 to get real minutes

	//calculate the total minutes for travel so that it can be used for cruise time (multiply hours by 60 and add the remaining minutes)
	totalMinutesForTravel = (hoursForTravel * 60) + realMinutesForTravel;

	//display the time in real time
	cout << "This flight cruise time will take " << hoursForTravel << " hours and " << realMinutesForTravel << " minutes." << endl;
}


//---------------------------------DIRECTION-RELATED FUNCTION(S)-------------------------------------------------
//this calculates the heading of the plane (a diagonal line from BFD airport to CMD)
double Airplane::calculateHeading()
{
	//declare variables and constants
	double planeHeading = 0;
	double differenceInLatitude = 0;
	double differenceInLongtitude = 0;
	double latRadians = 0;
	double longRadians = 0;

	const double PI = 3.141592653589793;
	const double LATITUDE_BFD_AIRPORT_IN_DEGREES = 41.7993; //latitude of bdf airport according to research
	const double LONGITUDE_BFD_AIRPORT_IN_DEGREES = 78.6396;//longtitide of bfd airport according to research

	const double LATITUDE_CMH_AIRPORT_IN_DEGREES = 39.9999; //latitude of bdf airport according to research
	const double LONGITUDE_CMH_AIRPORT_IN_DEGREES = 82.8872;//LONGITIUDE of bdf airport according to research

	//calculate difference in latitude
	differenceInLatitude = LATITUDE_CMH_AIRPORT_IN_DEGREES - LATITUDE_BFD_AIRPORT_IN_DEGREES;

	//calculate difference in longitude
	differenceInLongtitude = LONGITUDE_CMH_AIRPORT_IN_DEGREES - LONGITUDE_BFD_AIRPORT_IN_DEGREES;

	//convert longituge and latitide to radians so that i can get the arctan/inverse tangent function
	latRadians = differenceInLatitude * (PI / 180); 
	longRadians = differenceInLongtitude * (PI / 180);

	//find the arc tangent of longtitude and latitude (shaped like this \)
	planeHeading = atan(longRadians/latRadians);

	//convert it back to degrees

	planeHeading *= planeHeading * (180 / PI);

	return planeHeading;

}//end calculate heading function


//---------------------------------FUEL-RELATED FUNCTION(S)-------------------------------------------------
//return type, class name, scope resolution access operator, function name
//"calculates" total fuel during takeoff
double Airplane::calculateFuelBurnedDuringTakeoff()
{
	//declare variable and store a value
	double totalFuelBurnedDuringTakeoff = 1.5; //1.5 gallons, as given by Keeney

	//return that shit
	return totalFuelBurnedDuringTakeoff;
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

	//calculate total weight by multipltyng the weight by the fuel burned during takeoff (6 pounds)
	totalWeightOfFuelBurnedDuringTakeoff = totalFuelBurnedDuringTakeoff * weightOfFuel;

	//display the amount of fuel burned during takeoff

	//return that shit
	return totalWeightOfFuelBurnedDuringTakeoff;
}//end calculate weight of fuel during takeoff


//return type, class name, scope resolution access operator, function name
//calculates fuel burned during cruise
double Airplane::calculateFuelBurnedDuringCruise()
{
	//declare variable to store fuel burned during cruise and actual cruise time
	double totalFuelBurnedDuringCruise = 0;
	double actualCruiseTime;

	//calculate the cruise time and store it in this variable
	actualCruiseTime = calculateCruiseTime();

	//calculate total fuel burned during cruise
	totalFuelBurnedDuringCruise = actualCruiseTime * fuelBurnRate;

	//return that shit
	return totalFuelBurnedDuringCruise;
}//end calculate fuel burned during cruise

double Airplane::calculateWeightOfBurnedFuelDuringCruise()
{
	//declare variables and constants
	double weightOfFuelBurned = 0;
	double totalFuelBurnedDuringCruise = 0;

	//call the calculate fuel burned during cruise function and store it
	totalFuelBurnedDuringCruise = calculateFuelBurnedDuringCruise();

	//calculate it
	weightOfFuelBurned = totalFuelBurnedDuringCruise * weightOfFuel;

	//return it
	return weightOfFuelBurned;


}//end calculate weight of burned fuel during cruise

//return type, class name, scope resolution access operator, function name
//"calculates" the total fuel burned during landing
double Airplane::calculateFuelBurnedDuringLanding()
{
	double totalBurnedFuelDuringLanding = 2; //2 gallons, according to Keeney

	//return it
	return totalBurnedFuelDuringLanding;
}//end calculate fuel during landing

double Airplane::calculateWeightOfFuelBurnedDuringLanding()
{
	//declare variables
	double weightOfFuelBurnedDuringLanding = 0;
	double fuelBurnedDuringLanding = 0;

	fuelBurnedDuringLanding = calculateFuelBurnedDuringLanding();
	weightOfFuelBurnedDuringLanding = fuelBurnedDuringLanding * weightOfFuel;

	return weightOfFuelBurnedDuringLanding;

}//end weight of fuel burned during landing

//this calculates the weight of the fuel burned during all three parts of a flight
 double Airplane::calculateWeightOfBurnedFuel()
{
	//burned fuel during takeoff, cruise, and landing combined and multiply 6 
	 double weightOfFuelBurnedDuringLanding = 0;
	 double weightOfFuelBurnedDuringCruise = 0;
	 double weightOfFuelBurnedDuringTakeoff = 0;
	 double totalWeightOfFuelBurned = 0;

	 //call each function and store it here
	 weightOfFuelBurnedDuringTakeoff = calculateWeightOfFuelBurnedDuringTakeoff(); 
	 weightOfFuelBurnedDuringCruise = calculateWeightOfBurnedFuelDuringCruise();
	 weightOfFuelBurnedDuringLanding = calculateWeightOfFuelBurnedDuringLanding();

	 //calculate total fuel burned
	 totalWeightOfFuelBurned = weightOfFuelBurnedDuringLanding + weightOfFuelBurnedDuringCruise + weightOfFuelBurnedDuringTakeoff;

	 return totalWeightOfFuelBurned;
}//end calculate weight of burned fuel


double Airplane::calculateTotalFuelBurned()
{
	double fuelUsedDuringTakeoff = 0;
	double fuelUsedDuringCruise = 0;
	double fuelUsedDuringLanding = 0;
	double totalFuelUsed;

	fuelUsedDuringTakeoff = calculateFuelBurnedDuringTakeoff();
	fuelUsedDuringCruise = calculateFuelBurnedDuringCruise();
	fuelUsedDuringLanding = calculateFuelBurnedDuringLanding();

	totalFuelUsed = fuelUsedDuringTakeoff + fuelUsedDuringCruise + fuelUsedDuringLanding;

	return totalFuelUsed;
}//end calculate total fuel used

 
 double Airplane::calculateGallonsOfReservedFuel()
{
	 //declare variables
	 double reservedFuel = 0;

	 //store reserved fuel as unusable fuel
	 reservedFuel = unusableFuel;

	 return reservedFuel;

}//end gallons of reserved fuel

 //return type, class name, scope resolution access operator, function name
//this calculates the weight of all the fuel on the plane
 double Airplane::calculateWeightOfTotalFuel()
 {
	 double weightOfTotalFuel = 0;

	 weightOfTotalFuel = weightOfFuel * totalFuelCapacity; //this includes usable and unusbale fuel

	 return weightOfTotalFuel;
 }//end calculate weight of total fuel

//physical flying related functions
 void Airplane::flyPlane()
 {
	 cout << "This plane is flying. Hooray!" << endl;
 }
 void Airplane::isReadyForTakeoff()
 {
	 if (usableFuelCapacity = 38)
	 {
		 cout << "This flight is ready for takeoff!" << endl;
	 }
	 else
		 cout << "This plane is not ready for takeoff" << endl;

 }
 void Airplane::landPlane()
 {
	 cout << "This plane is landing" << endl;

 }


//---------------------------------OUTPUT-RELATED FUNCTION(S)-------------------------------------------------
//PRINTING SHIT
// //return type, class name, scope resolution access operator, function name
//this prints out the specifications of the aircraft, according to research and the actual manual
void Airplane::printAircraftSpecifications()
{
	cout << "\nAircraft Specifications" << endl;
	cout << "The name of the aircraft is: " << aircraftName << endl;
	cout << "The color of the aircraft is: " << colorOfAircraft << endl;
	cout << "This aircraft has " << numEngines << " engine." << endl;
	cout << "The length of the aircraft is: " << lengthOfAircraft << " feet." << endl;
	cout << "The height of the aircraft is: " << heightOfAircraft << " feet." << endl;
	cout << "The wingspan of the aircraft is: " << wingspanOfAircraft << " feet." << endl;
	cout << "The wing area of the aircraft is: " << wingAreaOfAircraft << " square feet." << endl;
	cout << "The max altitude of the aircraft is: " << maxAltitudeOfAircraft << " feet." <<  endl;
	cout << "The oil capacity of the aircraft is: " << oilCapacityOfAircraft << " gallons." << endl;
	cout << "The total fuel of the aircraft is: " << totalFuelCapacity << " gallons." << endl;
	cout << "The usable fuel of the aircraft is: " << usableFuelCapacity << " gallons." << endl;
	cout << "The unusable fuel of the aircraft is: " << unusableFuelCapacity << " gallons." << endl;
	cout << "The standard empty weight is: " << STANDARD_EMPTY_WEIGHT << " pounds." << endl;
	cout << "The maximum gross weight is: " << MAXIMUM_GROSS_WEIGHT << " pounds." << endl;
	cout << "The maximum takeoff weight is: " << MAXIMUM_TAKEOFF_WEIGHT << " pounds." << endl;
	cout << "The maximum landing weight is: " << MAX_LANDING_WEIGHT << " pounds." << endl;
	cout << "The baggage allowance is: " << BAGGAGE_WEIGHT_ALLOWANCE << " pounds." << endl;
}//end function print specifications

//print user input
//return type, class name, scope resolution access operator, function name
void Airplane::printUserInput()
{
	cout << "\nUser Output:" << endl;
	cout << "The starting airport is: " << startingAirportName << endl;
	cout << "The ending airport is: " << endingAirportName << endl;
	cout << "The crusing speed is: " << cruisingSpeed << " miles per hour." << endl;
	cout << "The wind speed is: " << windSpeed << " miles per hour." << endl;
	cout << "The wind direction is: " << windDirection << endl;
	cout << "The crusing direction is: " << cruisingDirection << endl;
	cout << "The pilot weight is: " << pilotWeight << " pounds." << endl;
	cout << "The passenger weight is: " << weightOfPassenger << " pounds" << endl;
	cout << "The luggage weight is: " << luggageWeight << " pounds." << endl;
	cout << "The cruising altitude is: " << cruisingAltitude << " feet." << endl;
}//end print user input

//print calculated fields at once, instead of calling them individually
//return type, class name, scope resolution access operator, function name
void Airplane::printCalculatedFields()
{
	cout << "\nFlight Specifications:" << endl;

	//declare variables 
	double grossWeight = 0;
	double takeoffWeight = 0;
	double landingWeight = 0;
	double groundSpeed = 0;
	double takeoffSpeed = 0;
	double planeHeading = 0;
	double totalTimeForTravel = 0;
	double cruiseTime = 0;
	double totalFuelBurnedDuringTakeoff = 0;
	double weightOfFuelBurnedDuringTakeoff = 0;
	double totalFuelBurnedDuringCruise = 0;
	double weightOfFuelBurnedDuringCruise = 0;
	double totalFuelBurnedDuringLanding = 0;
	double weightOfFuelBurnedDuringLanding = 0;
	double totalFuelBurned = 0;
	double weightOfBurnedFuel = 0;
	double weightOfTotalFuel = 0;
	double reservedFuel = 0;


	//weight related functions
	//print gross weight
	grossWeight = calculateGrossWeight(STANDARD_EMPTY_WEIGHT, weightOfPassenger, pilotWeight, luggageWeight);
	cout << "The gross weight of this aircraft is: " << grossWeight << " pounds." << endl;

	//print takeoff weight
	takeoffWeight = calculateTakeoffWeight();
	cout << "The takeoff weight of this aircraft is: " << takeoffWeight << " pounds. This is equal to the gross weight." << endl;
	
	//print landing weight
	landingWeight = calculateLandingWeight();
	cout << "The landing weight is: " << landingWeight << " pounds." << endl;
	
	//speed related functions
	//print ground speed
	groundSpeed = calculateGroundSpeed(&trueAirSpeedOfAircraft, &windSpeedOfAircraft);
	cout << "The ground speed of this aircraft is: " << groundSpeed << " miles per hour." << endl;

	//print takeoff speed
	takeoffSpeed = calculateTakeoffSpeedOfSoftField();
	cout << "The takeoff speed off this softfield on 60 degree weather and 40% humidty is: " << takeoffSpeed << " miles per hour." << endl;


	//direction related functions
	planeHeading = calculateHeading();
	cout << "The plane is heading " << planeHeading << " degrees north" << endl;

	//time related functions
	totalTimeForTravel = calculateTotalTimeForTravel();
	cout << "The total time for travel, in decimal format, is: " << totalTimeForTravel << " hours." << endl;

	//print real time for travel
	convertTravelTimeToMinutesAndHours();
	
	//print cruise time
	convertCruiseTimeToMinutesAndHours();

	//fuel related functions
	
	//print total fuel burned during takeoff
	totalFuelBurnedDuringTakeoff = calculateFuelBurnedDuringTakeoff();
	cout << "The total burned fuel during takeoff is: " << totalFuelBurnedDuringTakeoff << " gallons." << endl;
	
	//print weight of fuel burned during takeoff
	weightOfFuelBurnedDuringTakeoff = calculateWeightOfFuelBurnedDuringTakeoff();
	cout << "The weight of fuel burned during takeoff is: " << weightOfFuelBurnedDuringTakeoff << " pounds." << endl;

	//print fuel burned during cruise
	totalFuelBurnedDuringCruise = calculateFuelBurnedDuringCruise();
	cout << "The total fuel burned during cruise is: " << totalFuelBurnedDuringCruise << " gallons." << endl;

	//print weight of fuel burned duriing cruise
	weightOfFuelBurnedDuringCruise = calculateWeightOfBurnedFuelDuringCruise();
	cout << "The weight of fuel burned during cruise is: " << weightOfFuelBurnedDuringCruise << " pounds." << endl;

	//print fuel burned during landing
	totalFuelBurnedDuringLanding = calculateFuelBurnedDuringLanding();
	cout << "The total fuel burned during landing is: " << totalFuelBurnedDuringLanding << " gallons." << endl;

	//print weight of fuel burned during landing
	weightOfFuelBurnedDuringLanding = calculateWeightOfFuelBurnedDuringLanding();
	cout << "The weight of fuel burned during landing is: " << weightOfFuelBurnedDuringLanding << " pounds." << endl;
	
	//print total fuel burned
	totalFuelBurned = calculateTotalFuelBurned();
	cout << "The total fuel burned during this trip is: " << totalFuelBurned << " gallons." << endl;
	
	//print of weight of burned fuel
	weightOfBurnedFuel = calculateWeightOfBurnedFuel();
	cout << "The weight of burned fuel is: " << weightOfBurnedFuel << " pounds." << endl;

	//print weight of total fuel
	weightOfTotalFuel = calculateWeightOfTotalFuel();
	cout << "The weight of all fuel is: " << weightOfTotalFuel << " pounds." << endl;

	//print gallons of reserved fuel
	reservedFuel = calculateGallonsOfReservedFuel(); 
	cout << "The total gallons of reserved fuel on this aircraft is: " << reservedFuel << endl;

	flyPlane();
	isReadyForTakeoff();
	landPlane();
}//end print calculated fields

