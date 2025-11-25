/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Student Number: 501263130
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: March 12, 2024
 * Description: Use the push and pop function on a stack
 */

#include <stdio.h>
#define STACK_EMPTY '0'
#define STACK_SIZE 20

void
push(char stack[],    /* input/output - the stack */
     char item,       /* input - data being pushed onto the stack */
     int  *top,       /* input/output - pointer to top of stack */
     int  max_size)   /* input - maximum size of stack */
{
     if (*top < max_size-1) {
         ++(*top);
         stack[*top] = item;
     }
}

char
pop (char stack[],    /* input/output - the stack */
    int *top)        /* input/output - pointer to top of stack */
{
    char item;       /* value popped off the stack */

    if (*top >= 0) {
        item = stack[*top];
        --(*top);
    } else {
         item = STACK_EMPTY;
    }

    return (item);
}

int
main(void)
{
	
	char s [STACK_SIZE];
	int s_top = -1; // stack is empty

	/* complete the program here */
	
	//Calls the push function on the stack 3 times
	push(s, 'J', &s_top, STACK_SIZE);
	push(s, 'O', &s_top, STACK_SIZE);
	push(s, 'E', &s_top, STACK_SIZE);
	
	//Print the updated stack
	printf("Updated Stack (push 3x): ");
	for (int i = 0; i <= s_top; i ++){
		printf("%c", s[i]);
	}
	
	//Print a line to separate the results
	printf("\n");
	
	//Calls the pop out function once
	pop(s, &s_top);
	
	//Print the updated stack
	printf("Updated stack (pop x1): ");
	for (int i = 0; i <= s_top; i ++){
		printf("%c", s[i]);
	}
	
	return (0);
}
