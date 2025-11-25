/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Student Number: 501263130
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: February 6, 2024
 * Description: Calculate the BMI of a person and determine their
 * classification based on their height in m and weight in kg
 */

#include <stdio.h>
#include <math.h>

int
main(void)
{
	
	//Declare the variables
	double height, weight, bmi;
	
	//Prompt the user to enter their height in m
	printf("Enter your height in metres: ");
	scanf("%lf", &height);
	
	//Prompt the user to enter their weight in kg
	printf("Enter your weight in kilograms: ");
	scanf("%lf", &weight);
	
	//Calculate the BMI
	bmi = weight/(pow(height, 2));
	
	//Determine the classification and print out the results
	if (bmi < 18.5){
		printf("Your BMI value is %.1f, which classifies you as underweight", bmi);
	}	
	else if (bmi >= 18.5 && bmi <= 24.9){
		printf("Your BMI value is %.1f, which classifies you as normal", bmi);
	}
	else if (bmi >= 25 && bmi <= 29.9){
		printf("Your BMI value is %.1f, which classifies you as overweight", bmi);
	}
	else{
		printf("Your BMI value is %.1f, which classifies you as obese", bmi);
	}
	
	return (0);
}
