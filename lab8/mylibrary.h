/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Student Number: 501263130
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: April 2, 2024
 * Description: mylibrary.h file for CPS188 Lab 8 Problem 2
 */
 
#define MAX_ROWS 10
#define MAX_COLS 10

//Function to find the sum of the diagonal
double sumdiag (double numArray[MAX_ROWS][MAX_COLS]){
	
	double sumDiag = 0.0;
	
	for (int i = 0; i < MAX_ROWS; i++){
		sumDiag += numArray[i][i]; //If row = col, then it is the diag
	}
	
	return sumDiag;
	
}

//Function that sums all the nunmbers in the array
double sumall (double numArray[MAX_ROWS][MAX_COLS]){
	
	double totalSum = 0.0;
	
	for (int row = 0; row < MAX_ROWS; row++){
		for (int col = 0; col < MAX_COLS; col++){
			totalSum += numArray[row][col];
		}
	}
	
	return totalSum;
	
}

//Function that calculates the average of the last column of the array
double avright (double numArray[MAX_ROWS][MAX_COLS]){
	
	double sum = 0.0, averRight = 0.0;
	
	for (int i = 0; i < MAX_ROWS; i++){
		sum += numArray[i][MAX_ROWS-1]; //Subtract 1 to account for index 0
	}
	
	averRight = sum / MAX_ROWS;
	
	return averRight;
	
}

//Function that sums all four corners of the array
double corners (double numArray[MAX_ROWS][MAX_COLS]){
	
	double sumCorners = 0.0;
	
	sumCorners = numArray[0][0] + numArray[0][MAX_COLS-1] + numArray[MAX_ROWS-1][0] + numArray[MAX_ROWS-1][MAX_COLS-1];
	
	return sumCorners;
	
}

//Function that is found in the antidiagonal of the array
double largeanti (double numArray[MAX_ROWS][MAX_COLS]){
	
	//Set the first number as the temporary largest number
	double largestNum = numArray[0][MAX_COLS-1];
	
	for (int row = 1; row < MAX_ROWS; row++){
		int col = (MAX_ROWS - 1) - row;
		
		if (numArray[row][col] > largestNum){
			largestNum = numArray[row][col];
		}
	}
	
	return largestNum;
	
}
