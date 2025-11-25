/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: March 12, 2024
 * Description: Use the qsort function to sort the given arrays
 */

#include <stdio.h>
#include <stdlib.h>
#define size 8

//Integer ascending
int comp1 (const void * a, const void * b){
	return ( *(int*)a - *(int*)b);
}

//Double asscending
int comp2 (const void * a, const void * b){
	return ( *(double*)b - *(double*)a);
}

//Char ascending
int comp3 (const void * a, const void * b){
	return ( *(char*)a - *(char*)b);
}

int
main(void)
{
	
	//Declare the arrays
	int array1[8] = {67, 98, 23, 11, 47, 13, 94, 58};
    double array2[8] = {-6.4, 2.65, 32.745, -3.9, 2.2, 11.742, -23.523, 0.0};
    char array3[8] = {'a', 'G', '?', 'm', '#', 'B', 'n', '%'};
    
	//Sort array1 in ascending order and print the resulting array.
	qsort(array1, size, sizeof(int), comp1);
	printf("Sorted Array1: ");
	for (int i = 0; i < size; i ++){
		printf("%d ", array1[i]);
	}

	//Sort array2 in descending order and print the resulting array.
	qsort(array2, size, sizeof(double), comp2);
	printf("\nSorted Array2: ");
	for (int i = 0; i < size; i ++){
		printf("%.3f ", array2[i]);
	}

	//Sort array3 in ascending order and print the resulting array.
	qsort(array3, size, sizeof(char), comp3);
	printf("\nSorted Array3: ");
	for (int i = 0; i < size; i ++){
		printf("%c ", array3[i]);
	}
	
	return (0);
}

