/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Student Number: 501263130
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: February 27, 2024
 * Description: Calculate the minimum and maximum travel time given 
 * the user chosen place and vehicle
 */

#include <stdio.h>
#include <stdlib.h>

//Distance to moon function
void
distMoon(double *speed, double *perigee, double *apogee){
	
	*perigee = 363104 / *speed;
	*apogee = 405696 / *speed;
	
}

//Distance to mars function
void
distMars(double *speed, double *perigee, double *apogee){
	
	*perigee = 54600000 / *speed;
	*apogee = 401000000 / *speed;
	
}

//Distance to venus function
void
distVenus(double *speed, double *perigee, double *apogee){
	
	*perigee = 38000000 / *speed;
	*apogee = 261000000 / *speed;
	
}

int
main(void)
{
	
	//Declare the variables
	int chosen = 1;
	int chosenPlace, chosenVehicle;
	double speed, perigee, apogee;
	
	//Keep the user on the menu page until a valid number is selected
	while (chosen == 1){
		printf("Type the number to choose:\n1. Traveling to the Moon\n2. Traveling to Mars\n3. Traveling to Venus\n4. Exit Program\n");
		scanf("%d", &chosenPlace);
		
		//Cloes program if user chooses 4
		if (chosenPlace == 4){
			printf("Exiting Program");
			chosen = 0;
			exit(0);
		}

		//Prompt the user to select a vehicle type
		printf("Type the number to choose a vehicle:\n1. Car (100km/h)\n2. Airplane (500km/h)\n3. Rocket (41000km/h)\n");
		scanf("%d", &chosenVehicle);
		
		//Determine the chosen vehicle's speed
		if (chosenVehicle == 1){
			speed = 100;
		}
		else if (chosenVehicle == 2){
			speed = 500;
		}
		else if (chosenVehicle == 3){
			speed = 41000;
		}
		
		//Calculate the perigee and apogee for chosen place and vehicle
		if (chosenPlace == 1){
			distMoon(&speed, &perigee, &apogee);
		}
		else if(chosenPlace == 2){
			distMars(&speed, &perigee, &apogee);
		}
		else if(chosenPlace == 3){
			distVenus(&speed, &perigee, &apogee);
		}
		
		//Print out the resulted min (perigee) and max (apogee) travel times
		printf("The minimum travel time is: %.2f hrs\nThe maximum travel time is: %.2f hrs\n\n", perigee, apogee);
		
	}
	
	return (0);
}
