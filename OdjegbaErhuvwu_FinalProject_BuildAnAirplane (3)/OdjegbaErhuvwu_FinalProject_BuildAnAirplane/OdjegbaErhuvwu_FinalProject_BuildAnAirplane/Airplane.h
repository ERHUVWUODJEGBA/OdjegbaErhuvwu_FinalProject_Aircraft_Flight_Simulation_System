#pragma once
#include <string> //allows for string manipulation

using namespace std; //goes below include include statements; no more std typing
//Put all Function Prototypes here (function header), just above main, so the program can point to the method: 

//declare the class Airplane
class Airplane
{
private: //declare private fields
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

	//speed
	double speedOfAircraft = 120; //measured in miles per hour

	//distance stuff
	double distanceBetweenAirports = 255; //this is the distance between BFD and CMH in miles, according to an air travel calculator

	//physical attributes
	string aircraftName = "Cessna Skyhawk II 1976 Model 172M"; //might need to get this
	string colorOfAircraft = "White"; //might need to get this

public: //declare public fields

	Airplane() {}; //this is the default constructor that initalizes the airplane object in main

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
	const double STANDARD_EMPTY_WEIGHT = 1412; //empty weight of this specific plane, according to the manual
	const double MAXIMUM_GROSS_WEIGHT  = 2300; // pounds, according to the manual
	const double MAXIMUM_TAKEOFF_WEIGHT  = 2300; //pounds, according to the manual
	const double MAX_LANDING_WEIGHT  = 2300; //pounds, according to the manual
	const double BAGGAGE_WEIGHT_ALLOWANCE = 50; //50 pounds of baggage is allowed in thisc ase
	
	//time
	const double TAKEOFF_TIME = (5.0 / 60.0); //this is measured in hours, since it takes 5 minutes
	const double TAXING_AND_LANDING = (1.0 / 6.0); //measured in hours, since it takes 10 minutes

	//fuel
	//speed 
	const double TAKE0FF_SPEED_SOFT_FIELD  = 70; //60 KIAS converted to miles per hour, accordig to the plane website
	const double HEADWIND_SPEED = 20; //miles per hour

	//FUNCTIONS: getters and setters
	
	//ask Keeney do i need getters and setters for the fields that I am not gonna change

	double getMaxAltitudeOfAircraft() const;
	double getFuelCapacity() const;
	double getNumPassengers() const;
	double getSpeedOfAircraft();
	void setSpeedOfAircraft(double speed);

	//GETS THE USER INPUT
	void getUserInput();

	//weight realted functions
	double calculateGrossWeight(double standardEmptyWeight, double weightOfPassenger, double pilotWeight, double luggageWeight);
	double calculateTakeoffWeight(); //shouldnt gross weight equal takeoff weight? YES
	double calculateLandingWeight();


	//speed functions
	double calculateTakeoffSpeedOfSoftField(); 

	//double calculateTakeoffSpeedSoftField(); //this might turn into a constant later on
	double calculateGroundSpeed(double *, double *);
	double calculateTotalTimeForTravel(); //double takeoffTime, double landingTimeAndTaxing, double cruisingAltitude
	double calculateHeading(); //(0-360 from BFD to CMH)

	//fuel-related functions
	double calculateWeightOfTotalFuel();
	double calculateWeightOfBurnedFuel(); 
	double calculateFuelBurnedDuringTakeoff();
	double calculateFuelBurnedDuringLanding();
	double calculateWeightOfFuelBurnedDuringTakeoff();
	double calculateFuelBurnedDuringCruise();
	double calculateTotalFuelBurned();
	double calculateGallonsOfReservedFuel();
	double calculateWeightOfBurnedFuelDuringCruise();
	double calculateWeightOfFuelBurnedDuringLanding();

	//time related functions
	double calculateCruiseTime();
	void convertTravelTimeToMinutesAndHours();
	void convertCruiseTimeToMinutesAndHours();

	//physical flying related functions
	void flyPlane();
	void isReadyForTakeoff();
	void landPlane();

	//print stuff
	void printUserInput();
	void printAircraftSpecifications();
	void printCalculatedFields(); //this prints out information about flight, which includes all the calculated fields
};