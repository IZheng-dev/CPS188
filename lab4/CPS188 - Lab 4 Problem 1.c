/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: February 13, 2024
 * Description: Calculate and display Pascal's Triangle to 9 rows
 */

#include <stdio.h>

int
main(void)
{
	
	//Declare the variables
	int nSequences, num;
	
	//Prompt the user to enter the number of sequences
	printf("Enter the number of sequences for Pascal's Triangle: ");
	scanf("%d", &nSequences);
	
	//Initialize a for loop for the rows of the triangle
	for (int i = 0; i < nSequences; i++){
		
		//For loop that calculates each individual value in the row
		for (int j = 0; j <= i; j++){
			
			if (j == 0){
				num = 1;
			}
			
			else{
				num = (num * ((i - j) + 1)) / j;
			}
			
			//Print the resulted number with a space in front
			printf("%d ", num);
		}
		//Prints to next line
		printf("\n");
	}
	
	return (0);
}

