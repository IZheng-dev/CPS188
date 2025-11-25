/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: January 30, 2024
 * Description: Calculate the speed of sound in air using
 * a given temperature in degrees celsius
 */
 
#include <stdio.h>
#include <math.h>

double
spsound(double tempC)
{
	//Declare a variable for the temp in fahrenheit
	double tempF;
	//Declare a variable for the speed of sound
	double a;
	
	//Convert temp in celsius to fahrenheit
	tempF = ((tempC * (9.0/5.0)) + 32);
	
	//Solve for the speed of sound
	a = 1086 * (sqrt((5 * tempF + 297) / 247));
	
	//Return the value for speed of sound
	return (a);
}


int
main (void)
{
	double temp, result;

	printf ("Enter a temperature in degrees celsius: ");
	scanf ("%lf", &temp);

	result = spsound(temp);
	
	printf ("The speed of sound in air is %.2f km/h", result);
	
	return (0);
}

