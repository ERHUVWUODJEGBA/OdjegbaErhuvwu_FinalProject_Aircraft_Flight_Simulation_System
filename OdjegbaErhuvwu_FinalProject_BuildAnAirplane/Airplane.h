#pragma once
#include <string> //allows for string manipulation

using namespace std; //goes below include include statements; no more std typing
//Put all Function Prototypes here (function header), just above main, so the program can point to the method: 

//declare the class Airplane
class Airplane
{
private: //declare private fields
	//declare stream variables
	ofstream outFile;

	int numEngines  = 1; // this is the number of engines. this plane uses 1
	//these are the specifications of a Cessna 172 Class M Skywalk, converted to decimal form
	double lengthOfAircraft  = 27.167; //Length: 27 ft 2 in; do 2/12 or 1/6 and add it to 27 //MEASURED IN FEET
	double heightOfAircraft  = 8.917; //Height: 8 ft 11 in; do 11/12 and add it to 8 //MEASURED IN FEET
	double wingspanOfAircraft  = 36.083; //Wingspan: 36 ft 1 in; do 1/12 and add it to 36 //MEASURED IN FEET
	double wingAreaOfAircraft  = 174.000; // straight off the website //MEASURED IN FEET
	double maxAltitudeOfAircraft = 12000; //max altitude, according to Keeney

	//needed fluids in aircraft
	double oilCapacityOfAircraft  = 2.25; //9 quarts of oil, according to manual specifications; 4 quarts are in a gallon, so two and some change gallons //MEASURED IN GALLONS
	double usableFuelCapacity = 38; //38; this is the usable fuel capacity before burning it, measured in gallons
	double totalFuelCapacity = 42; //42; this is the total amount of fuel, including unusable fuel
	double unusableFuelCapacity = 6; //this is unsuable fuel
	double weightOfFuel = 6; //the weight of the fuel is 6 pounds per gallon
	double unusableFuel = 6.0;
	double fuelBurnRate = 8; //burns at 8 gallons per hour

	//passenger
	int numPassengers; //might need to get and set this but idk (update: not needed)
	int maxPassengersAllowed = 1; // this is the maximum number of passengers allowed. make sure to check for tgis
	double weightOfPassenger; //might need to get and set this (update: not needed)


	double speedOfAircraft = 120; //measured in miles per hour

	//distance stuff
	double distanceBetweenAirports = 255; //this is the distance between BFD and CMH in miles, according to an air travel calculator

	string aircraftName = "Cessna Skyhawk II 1976 Model 172M"; //might need to get this
	string colorOfAircraft = "White"; //might need to get this

public: //declare public fields
	//variables the user will need
	string startingAirportName;	
	string endingAirportName;
	double cruisingSpeed;
	string windDirection;
	double windSpeed;
	double pilotWeight; // = 170; //this is the weight of the pilot in pounds
	double luggageWeight;
	string cruisingDirection;
	
	//speed and altitude
	double cruisingAltitude; //= 4500; //measured in feet
	double trueAirSpeedOfAircraft = 120; //this is in miles per hour
	double windSpeedOfAircraft = 20;


	//weight variables and constants
	double const standardEmptyWeight = 1412; //empty weight of this specific plane, according to the manual
	double const maximumGrossWeight  = 2300; // pounds, according to the manual
	double const maxTakeoffWeight  = 2300; //pounds, according to the manual
	double const maxLandingWeight  = 2300; //pounds, according to the manual
	double const baggageWeightAllowance  = 50; //50 pounds of baggage is allowed in thisc ase

	//fuel
	//speed 
	double const takeoffSpeedSoftField  = 70; //60 KIAS converted to miles per hour
	double const headWindSpeed  = 20; //miles per hour




	//FUNCTIONS: that get input and validate it
	void getUserInput(); 
	bool isValidAirportName(const string& name);
	bool isValidDirection(const string& dir);
	bool isPositiveValue(double value);


	//dont need getters and setters for this shit apparently

	double getMaxAltitudeOfAircraft() const;
	double getFuelCapacity() const;
	double getNumPassengers() const;
	//double getSpeedOfAircraft() const;
	//double setSpeedOfAircraft();
	double getLengthOfAircraft(); //Length: 27 ft 2 in; do 2/12 or 1/6 and add it to 27 //MEASURED IN FEET
	double getHeightOfAircraft(); //Height: 8 ft 11 in; do 11/12 and add it to 8 //MEASURED IN FEET
	double getWingspanOfAircraft(); //Wingspan: 36 ft 1 in; do 1/12 and add it to 36 //MEASURED IN FEET
	double getWingAreaOfAircraft(); // straight off the website //MEASURED IN FEET
	double getOilCapacityOfAircraft(); //8 quarts of oil, according to manual specifications; 4 quarts are in a gallon, so two gallons //MEASURED IN GALLONS


	//there can be either zero or one passanger
	//double calculateEmptyWeight(); already gives this
	double calculateGrossAndTakeoffWeight(double standardEmptyWeight, double weightOfPassenger, double pilotWeight, double luggageWeight);
	//double calculateTakeoffWeight(); //shouldnt gross weight equal takeoff weight? YES
	//double calculateTakeoffSpeedSoftField(); //this might turn into a constant later on
	double calculateGroundSpeed(double *, double *);
	double calculateTotalTimeForTravel(); //double takeoffTime, double landingTimeAndTaxing, double cruisingAltitude
	//double calculateHeading(); //(0-360 from P15 to CMH)

	//fuel-related functions
	double calculateWeightOfTotalFuel();
	//double calculateWeightOfBurnedFuel(); //
	double calculateFuelBurnedDuringTakeoff();
	double calculateCruiseTime();
	double calculateFuelBurnedDuringLanding();
	double convertTravelTimeToMinutesAndHours();
	double calculateWeightOfFuelBurnedDuringTakeoff();
	double calculateFuelBurnedDuringCruise(); 
	/*double calculateTotalFuelUsed();
	double calculateGallonsOfReservedFuel();
	double calculateWeightOfBurnedFuelDuringCruise();*/

	//double calculateLandingWeight();

	//physical flying related functions
	//void flyPlane();
	//bool isReadyForTakeoff();
	//void landPlane();

	//print stuff
	void printUserInput(ostream& out);
	void printAircraftSpecifications(ostream& out);
	void printCalculatedFields(ostream& out); //this prints out information about flight, which includes all the calculated fields
	int writeResultsToFile(); //this writes all the printed fields into a file
};