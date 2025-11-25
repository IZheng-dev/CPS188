/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Student Number: 501263130
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: February 13, 2024
 * Description: Using Gay-Lussac's Law, calculate the maximum temperature
 * the cylinder can withstand before bursting and display the results in
 * a neatly organized table
 */

#include <stdio.h>

int
main(void)
{
	
	//Declare the variables
	double pressure1, pressure2, temp1, temp2;
	
	//Prompt the user to enter the initial pressure in atm
	printf("Enter the initial pressure in atm: ");
	scanf("%lf", &pressure1);
	//Prompt the user to enter the initial temp in K
	printf("Enter the initial temperature in K: ");
	scanf("%lf", &temp1);
	//Prompt the user to enter the maximum presssure in atm
	printf("Enter the maximum pressure the cylinder can withstand in atm: ");
	scanf("%lf", &pressure2);
	
	//a)
	//Calculate the max temperature
	temp2 = (temp1 * pressure2) / pressure1;
	
	//Print the results
	printf("The max temperature the cylinder can withstand is: %.2f K\n\n", temp2);
	
	//b)
	//Create the header and columns
	printf("Temperature (K)          Pressure (atm)\n");
	printf("~~~~~~~~~~~~~~~          ~~~~~~~~~~~~~~\n");
	
	//Initialize the temp to 0c or 273.15K
	temp1 = 273.15;
	
	//Increment the temperature by 100 until the pressure reaches its max
	while (pressure1 < pressure2){
		pressure1 = (temp1 * pressure2) / temp2;
		printf("%.2f                   %.2f\n", temp1, pressure1);
		temp1 += 100;
	}
	
	//Print the boom statement
	if (pressure1 > pressure2){
		printf("KABOOM");
	}
	
	return (0);
}
