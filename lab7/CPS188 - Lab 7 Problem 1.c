/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: March 19, 2024
 * Description: Determine if the user inputted text is a palindrome
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
clean(char strTextBefore[], char strTextAfter[]){
	
	//Determine the length of the string
	int length = strlen(strTextBefore);
	
	//Run through each character of the string
	for (int i = 0; i < length; i++){
		
		//Change the uppercase letter to lowercase
		strTextBefore[i] = tolower(strTextBefore[i]);
		
	}
	
	
	//Run through each character of the string again
	for (int i = 0; i < length; i++){
		
		//Remove non alphanumeric characters in the string
		if (isalnum(strTextBefore[i]) == 0){
			for (int j = i; j < length; j++){
				strTextBefore[j] = strTextBefore[j+1];
			}
		length--;	
		}
	}
	
	//Run through each character of the string again
	for (int i = 0; i < length; i++){
		
		//Remove spaces in the string
		if (strTextBefore[i] == ' '){
			for (int j = i; j < length; j++){
				strTextBefore[j] = strTextBefore[j+1];
			}
		length--;	
		}
	}
	
	//Set the new text as the original
	for (int i = 0; i <= length; i++){
		
		strTextAfter[i] = strTextBefore[i];
		
	}
	
}

void
reverse (char strTextBefore[], char strTextAfter[], int i, int j){
	
	//Swap the first char with the last char
	if (i < j){
		char temporary = strTextAfter[i];
		strTextAfter[i] = strTextAfter[j];
		strTextAfter[j] = temporary;
		
		reverse(strTextBefore, strTextAfter, ++i, --j);
	}
	
}

int
main(void)
{
	
	//Declare the variables
	char strTextBefore[1000];
	char strTextAfter[1000];
	
	//Prompt the user to enter a string
	printf("Enter a line of text: ");
	gets(strTextBefore);
	
	//Run the clean function
	clean(strTextBefore, strTextAfter);  
	
	//Run the reverse function
	reverse(strTextBefore, strTextAfter, 0, strlen(strTextAfter)-1);
	
	//Print the resulting strings
	printf("Original: %s\nReversed: %s\n", strTextBefore, strTextAfter);
	
	//Determine if the strings are palindromes
	if(strcmp(strTextBefore, strTextAfter) == 0){
		printf("The inputted text is a palindrome.");
	}
	else{
		printf("The inputted text is NOT a palindrome.");
	}
	
	return (0);
}

