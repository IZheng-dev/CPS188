/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: April 2, 2024
 * Description: Use a personal library to solve the questions and write the results in a binary file
 */

#include <stdio.h>
#include "mylibrary.h"

#define MAX_ROWS 10
#define MAX_COLS 10

int
main(void)
{
	
	//Declare the variables
	FILE *dataFile;
	FILE *binFile;
	double num, numArray[MAX_ROWS][MAX_COLS];	
	
	//Open the data file
	dataFile = fopen("L8_real.txt", "r");
	
	//Determines of the file is readable or exists
	if (dataFile == NULL){
		printf("Error File Cannot Be Read or Detected!\n");
		return (0);
	}
	
	//Scan and append each number from the file into the 2D array
	for (int row = 0; row < MAX_ROWS; row++){
		
		for (int col = 0; col < MAX_COLS; col++){
			
			if (fscanf(dataFile, "%lf", &num) == 1){
				
				numArray[row][col] = num;
				
			}
			
		}
		
	}
	
	//Open the bin file to write
	binFile = fopen("results.bin", "wb");
	
	//Call the functions from mylibrary.h to get the results
	double sumDiag = sumdiag(numArray);
	double totalSum = sumall(numArray);
	double averRight = avright(numArray);
	double sumCorners = corners(numArray);
	double largestNum = largeanti(numArray);
	
	//Write the results into the binary file
	fwrite(&sumDiag, sizeof(double), 1, binFile);
	fwrite(&totalSum, sizeof(double), 1, binFile);
	fwrite(&averRight, sizeof(double), 1, binFile);
	fwrite(&sumCorners, sizeof(double), 1, binFile);
	fwrite(&largestNum, sizeof(double), 1, binFile);
	
	//Print the results
	printf("These values were read directly from the variables in the C program:\n");
	printf("Sum diag: %.1f\n", sumDiag);
	printf("Sum all: %.1f\n", totalSum);
	printf("Average right: %.1f\n", averRight);
	printf("Corners: %.1f\n", sumCorners);
	printf("Largest Anti: %.1f\n\n", largestNum);
	
	//Close the files
	fclose(dataFile);
	fclose(binFile);
	
	//Print the results from the bin file
	double results, binResults[4];
	int count = 0;
	
	//Open the bin file to read
	binFile = fopen("results.bin", "rb");
	
	//Append the values from the bin file into an array
	while (fread(&results, sizeof(double), 1, binFile) == 1){
		binResults[count] = results;
		count++;
	}
	
	//Print the results
	printf("These are the values read from the bin file:\n");
	printf("The sum of all the numbers in the main diagonal is: %.1f\n", binResults[0]);
	printf("The sum of all the numbers is: %.1f\n", binResults[1]);
	printf("The average of the last (right-most) column: %.1f\n", binResults[2]);
	printf("The sum of the four corners is: %.1f\n", binResults[3]);
	printf("The largest number in the antidiagonal is: %.1f\n", binResults[4]);
	
	//Close the bin file
	fclose(binFile);
	
	return (0);
}

