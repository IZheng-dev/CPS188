/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: January 23, 2024
 * Description: Calculating the hypotenuse, perimeter, 
 * and the surface area of a right triangle 
 * using the length of the 2 shortest sides
 */

#include <stdio.h>
#include <math.h>

int
main (void)
{

	//Defining the variables as double
	double a, b, c, perimeter, area;
	
	//Prompt the user to enter a value for the first side
	printf("Enter a value for the base of the right triangle, a: ");
	//Assign the inputted value to variable "a"
	scanf("%lf", &a);
	
	//Prompt the user to enter a value for the second side
	printf("Enter a value for the height of the right triangle, b: ");
	//Assign the inputted value to variable "b"
	scanf("%lf", &b);
	
	//Calculate the hypotenuse using pythagorean theorem
	c = sqrt(pow(a, 2) + pow(b,2));
	
	//Calculate the perimeter by adding up the 2 sides and hypotenuse
	perimeter = a + b + c;
	
	//Calculate the surface area
	area = (a * b)/2;
	
	//Print out the resulted hypotenuse, perimeter, and area
	printf("The hypotenuse of the triangle is %.2f units\n", c);
	printf("The perimeter of the triangle is %.2f units\n", perimeter);
	printf("The area of the triangle is %.2f units^2", area);
	
	return (0); 
}

