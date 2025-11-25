/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: February 27, 2024
 * Description: Display 3 user inputted integer numbers in ascending order
 */

#include <stdio.h>

//Sort function that determines the biggest number from 2
void
numSort(int *smallestNum, int *largestNum){
	
	//Declare a temporary value
	int temp;
	
	//Determine the largest number
	if (*smallestNum > *largestNum){
		temp = *smallestNum;
		*smallestNum = *largestNum;
		*largestNum = temp;
	}

}

int
main(void)
{
	
	//Declare the variables
	int num1, num2, num3;
	
	//Prompt the user to enter 3 integer values
	printf("Enter 3 integer numbers with a space between each: ");
	scanf("%d %d %d", &num1, &num2, &num3);
	
	//Use the sort function to sort the 3 numbers in ascending order
	numSort(&num1, &num2);
	numSort(&num1, &num3);
	numSort(&num2, &num3);
	
	printf("The numbers from smallest to largest is: %d %d %d", num1, num2, num3);
	
	return (0);
}

