/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: March 12, 2024
 * Description: Print the original and normalized values as a table
 */

#include <stdio.h>

int
main(void)
{
	
	//Declare the variables
	FILE *dataFile;
	int numCount;
	double min, max, low, high;
	
	//Open the .txt data file 
	dataFile = fopen("Lab6_Problem1_DataFile.txt", "r");
	
	//Checks if the file is readable or exists
	if (dataFile == NULL){
		printf("Error cannot detect file.");
		return (0);
	}
	
	//Use a while loop to scan for the first 3 numbers in the data file
	while (fscanf(dataFile, "%d %lf %lf", &numCount, &min, &max) == 3){
		
		//Declare 2 arrays to the size of the number count
		double numX[numCount], numNorm[numCount];
		
		//Print the column headings
		printf("Original\tNormalized\n");
		
		//Append the original numbers into an array
		for (int i = 0; i < numCount; i++){
			fscanf(dataFile, "%lf", &numX[i]);
		}
		
		//Set the first number in the array as the temporary low and high value
		low = numX[0];
		high = numX[0];
		
		//Determine the lowest and highest number
		for (int i = 1; i < numCount; i++){
			
			if (numX[i] > high){
				high = numX[i];
			}
			
			if (numX[i] < low){
				low = numX[i];
			}
			
		}
		
		//Solve normalized for each value
		for (int i = 0; i < numCount; i++){
			
			//Append the normalized values into a second array
			numNorm[i] = min + (numX[i] - low) * (max - min) / (high - low);
			
			//Print the values
			printf("%.2f\t\t%.2f\n", numX[i], numNorm[i]);
			
		}
		
		//Print an extra line to separate the 3 number sets
		printf("\n");
		
	}
	
	//Close the file
	fclose(dataFile);
	
	return (0);
}

