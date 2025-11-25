/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Student Number: 501263130
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: March 19, 2024
 * Description: Store data on a txt file to create a GNUPlot
 */

#include <stdio.h>
#include <math.h>

#define C 3e8
#define H 6.626e-34
#define K 1.38e-23
#define MATH_PI 3.14159265

double
specEnerDens(double lambda, double temperature){
	
	//Formula for spectral energy density
	double r = (((2*MATH_PI*pow(C, 2))*H)/(pow(lambda, 5)))*((1)/((exp((H*C)/(lambda*K*temperature)))-1));
	
	//Returned the solve value, r
	return(r);
	
}

int
main(void)
{
	
	//Declare the variables
	FILE *dataFile;
	double r1, r2, r3, y = 0;
	
	//Open the file to be written on
	dataFile = fopen("Lab7_Problem2_DataFile.txt", "w");
	
	//Check if the file exists or is readable
	if (dataFile == NULL){
		printf("Error File Cannot Be Detected!\n");
		return(0);
	}
	
	//Create the headers for the file
	fprintf(dataFile, "Wavelength Temp1 Temp2 Temp3\n");
	
	//Calculate and store the spectral energy density for each temp
	for (double i = 0; i < 3e-6; i+=0.1e-6){
		
		r1 = specEnerDens(i, 3000.00);
		r2 = specEnerDens(i, 4000.00);
		r3 = specEnerDens(i, 5000.00);
		
		fprintf(dataFile, "%.2lf %.2lf %.2lf %.2lf\n", y, r1, r2, r3);
		
		y+=0.1;
		
	}
	
	//Close the file
	fclose(dataFile);
	
	return (0);
}
