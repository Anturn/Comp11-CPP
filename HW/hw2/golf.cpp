//
// golf.cpp
// 		purpose: practice using booleans and constants
// 	modified by: Rui Qin    
// 		 on:2/3/2016
//
#include <iostream>
#include <iomanip>
using namespace std;

// days of the week
const int SUN = 0, MON = 1, TUE = 2, WED = 3, THR = 4, FRI = 5, SAT = 6;

// constants for rules
const double 	BASE_PRICE 		= 9.0;
const int 	HIGH_TEMP_CUTOFF 	= 80;
const int 	LOW_TEMP_CUTOFF 	= 65;
const double 	PER_DEGREE_PENALTY 	= 0.10;
const int 	EVENING_START 		= 17;
const double 	WEEKEND_EVE_SURCHARGE 	= 1.00;
const double 	RAIN_PENALTY 		= 2.00;
const int 	WIND_GRANULARITY 	= 15;
const double 	WIND_PENALTY 		= 1.50;

// main function here
int main()
{
	// -- define vars for input and a value used in the tests below
	int tempF, dayOweek, hour, rainP, windMPH;
	double price;
	
	// -- set the precision
	cout << setiosflags(ios::fixed) << setprecision(2);
	
	// -- Get data from user
	cout << "Temperature (fahrenheit)? ";
	cin >> tempF;
	
	cout << "Day of week (0 = Sun, 1 = Mon, ..., 6 = Sat)? " ;
	cin >> dayOweek;
	
	cout << "Hour of day (0..23)? ";
	cin >> hour;
	
	cout << "Is it raining (0 = no, 1 = yes)? ";
	cin >> rainP;
	
	cout << "Wind speed (MPH)? ";
	cin >> windMPH;
	
	// -- compute price based on these values
	
	price = BASE_PRICE; 

        if (tempF > HIGH_TEMP_CUTOFF){
                price = BASE_PRICE-PER_DEGREE_PENALTY*(tempF-HIGH_TEMP_CUTOFF);
        }
                else if (tempF < LOW_TEMP_CUTOFF){
                        price = BASE_PRICE-PER_DEGREE_PENALTY*(LOW_TEMP_CUTOFF-tempF);
                }

        if (dayOweek > 6){
                cout << "There is an error"<<endl;
        }        

        if ((dayOweek == SUN || dayOweek == SAT) || (hour>=EVENING_START)){
                price = price + WEEKEND_EVE_SURCHARGE;
        }

        if (rainP == 1){
                price = price - RAIN_PENALTY;
        }

        price = price -  (windMPH / WIND_GRANULARITY)*WIND_PENALTY;






                                         // start here then adjust
					// ADD YOUR CODE IN THIS PART
					// ADD ONE CONDITION AT A TIME
					// THEN TEST, THEN ADD THE NEXT ...
				// -- USE CONSTANTS NOT RAW NUMBERS
	// -- report price to user
	
	cout << "Price: " << price << endl;
	return 0;
}
