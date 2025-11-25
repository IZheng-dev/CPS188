/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Student Number: 501263130
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: February 6, 2024
 * Description: Calculate the training heart rate (THR) given user inputted 
 * gender, age, resting heart rate, and fitness level
 */

#include <stdio.h>
#include <math.h>

//heartRate function
double
heartRate(char gender, int age, int restHR, char fitnessLvl)
{
	
	//Declare the variables
	double maximumHR, trainingHR, inten;
	
	//Determine if the gender is male or female
	//Calculate the maximum heart rate using the proper formula for each respective gender
	if (gender == 'M'){
		maximumHR = (203.7/(1+exp(0.033*(age - 104.3))));
	}
	else if (gender == 'F'){
		maximumHR = (190.2/(1+exp(0.0453*(age - 107.5))));
	}
	
	//Determine the fitness level and assign it to its number
	if (fitnessLvl == 'L'){
		inten = 0.55;
	}
	else if (fitnessLvl == 'M'){
		inten = 0.65;
	}
	else if (fitnessLvl == 'H'){
		inten = 0.8;
	}
	
	//Calculate the training heart rate
	trainingHR = (maximumHR - restHR) * inten + restHR;
	
	//Return the result
	return(trainingHR);
}

int
main(void)
{
	
	//Declare the variables
	int age, restHR;
	char gender, fitnessLvl;
	double trainingHR;
	
	
	//Prompt the user to enter their gender
	printf("What is your gender? Enter 'M' for male or 'F' for female: ");
	scanf("%c", &gender);
	
	//Prompt the user to enter their age
	printf("Enter your age: ");
	scanf("%d", &age);
	
	//Prompt the user to enter their resting heart rate
	printf("Enter your resting heart rate: ");
	scanf("%d", &restHR);
	
	//Prompt the user to enter their fitness level
	printf("What is your fitness level? Enter 'L' for low, 'M' for medium, or 'H' for high: ");
	scanf(" %c", &fitnessLvl);
	
	
	//Calculate the training heart rate by using the heartRate function
	trainingHR = heartRate(gender, age, restHR, fitnessLvl);
	
	
	//Print out the resulted training heart rate rounded to the nearest integer
	printf("Your training heart rate (THR) is: %.0f", trainingHR);
	

	return (0);
}
