/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: February 13, 2024
 * Description: Calculate the gross pay of each employee given a .txt file
 */
 
#include <stdio.h>

int
main(void)
{
	
	//Declare the variables
	FILE *dataFile;
	int employeeNum, numShifts;
	double baseWage, shiftHours[50], totalHours, grossPay, premium;
	
	//Opens the file
	dataFile = fopen ("L4_data.txt", "r");
	
	//Checks if the file is readable/exists
	if (dataFile == NULL){
		printf("Error cannot detect file.");
		return (0);
	}
		
	//Use a while loop to scan and verify for 3 values in the data file
	while (fscanf(dataFile, "%d %d %lf", &employeeNum, &numShifts, &baseWage) == 3){
		
		//Initialize the total hours to 0 at the beginning of each while loop
		totalHours = 0;
		
		//Increment each hour to the total hours worked for the singular employee
		for (int i = 0; i < numShifts; i++){
			fscanf(dataFile, "%lf", &shiftHours[i]);
			totalHours += shiftHours[i];
		}
		
		//If statement to determine the premium based on total hours
		if (totalHours <= 15){
			premium = 1;
		}
		else if (totalHours > 15 && totalHours <= 25){
			premium = 1.05;
		}
		else{
			premium = 1.10;
		}
		
		//Calculate the gross pay
		grossPay = totalHours * baseWage * premium;
		
		//Display the resulted gross pay for the worker
		printf("Employee Number: %d \nNumber of shifts: %d \nBase Wage: %.2f \nGross Pay: %.2f \n\n", employeeNum, numShifts, baseWage, grossPay);
		
	}
	
	//Close the file
	fclose (dataFile);
	
	return (0);
}

