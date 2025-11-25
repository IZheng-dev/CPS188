/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Student Number: 501263130
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: February 6, 2024
 * Description: Calculate the overall course grade given the grades of 
 * 10 quizzes, a midterm, and a final exam
 */

#include <stdio.h>

int
main(void)
{
	
	//Declare the variables
	double quizGrades[10], midtermGrade, finalGrade;
	double lowestQuiz, totalQuizzes, quizAverage, midtermWeight, finalWeight;
	double courseGrade;
	
	
	//Set a for loop that repeats 10 times for 10 quizzes
	for (int i = 0; i < 10; i++){
		//Prompt the user to enter their quiz grade
		printf("Enter your grade for quiz %d: ", i+1);
		scanf("%lf", &quizGrades[i]);
		totalQuizzes += quizGrades[i];
	}
	
	//Prompt the user to enter their midterm and final exam grades
	printf("Enter your midterm grade: ");
	scanf("%lf", &midtermGrade);
	
	printf("Enter your final exam grade: ");
	scanf("%lf", &finalGrade);
	
	
	//Determining the lowest mark between the first and last quiz
	if (quizGrades[0] >= quizGrades[9]){
		lowestQuiz = quizGrades[9];
	}
	else{
		lowestQuiz = quizGrades[0];
	}
	
	
	//Calculating the average of the 9 remaining quizzes
	quizAverage = ((totalQuizzes - lowestQuiz)/9)*10;
	
	
	//Assgining the weight values to the midterm and final exam based on the higher mark
	//Assign a higher % if the midterm is greater than or equal to the final exam mark
	if(midtermGrade >= finalGrade){
		midtermWeight = 0.35;
		finalWeight = 0.40;
	}
	//Else if the final exam mark is greater assign a greater weight to the final exam
	else{
		midtermWeight = 0.25;
		finalWeight = 0.50;
	}
	
	
	//Determine the course average by adding up all the grades with proper weighting
	courseGrade = (quizAverage * 0.25) + (midtermGrade * midtermWeight) + (finalGrade * finalWeight);
	
	
	//Print the resulted course grade
	printf("Your final grade is %.2f percent", courseGrade);
	
	
	return (0);
}
