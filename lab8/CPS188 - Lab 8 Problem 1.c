/*
 * Institute: Toronto Metropolitan University
 * Course: CPS188-052
 * Name: Isaac Zheng
 * Professor: Dr. Denis Hamelin
 * TA: Austin Vuong
 * Date: April 2, 2024
 * Description: Analyze a data file and print the servers on the same local network
 */

#include <stdio.h>

#define MAX_NAME_CHAR 14
#define MAX_ADDRESS 300
#define MAX_CHAR 1000

//Address structure
typedef struct{
		
	int num1;
	int num2;
	int num3;
	int num4;
	char nickname[MAX_NAME_CHAR];
		
}address_t; 

//Function that identifies the first 2 component of 2 addresses
int
localnet(const address_t *address1, const address_t *address2){
	
	return (address1->num1 == address2->num1 && address1->num2 == address2->num2);
	
}

int
main(void)
{
	
	//Declare the variables
	FILE *dataFile;
	address_t addressArr[MAX_ADDRESS];
	char rowLine[MAX_CHAR];
	int index = 0; 
	
	//Open the file
	dataFile = fopen("L8_ip.txt", "r");
	
	//Determines if the file is readable or exists
	if (dataFile == NULL){
		printf("Error File Cannot Be Read or Detected!\n");
		return (0);
	}
	
	//While loop that reads each row of the file
	while (fgets(rowLine, sizeof(rowLine), dataFile) != NULL && index < MAX_ADDRESS){
		
		if (sscanf(rowLine, "%d.%d.%d.%d %s", &addressArr[index].num1, &addressArr[index].num2, 
		&addressArr[index].num3, &addressArr[index].num4, addressArr[index].nickname) == 5){
			index++;
		}
		
	}
	
	//Print out the servers on the same local network
	for (int i = 0; i < index; i++){
		
		for (int j = i+1; j < index; j++){
			
			if (localnet(&addressArr[i], &addressArr[j])){
				
				printf("Servers %s and %s are on the same local network.\n", addressArr[i].nickname, addressArr[j].nickname);
				
			}
			
		}
		
	}
	
	//Print a to go to next line
	printf("\n");
	
	//Print out the full list of addresses and nicknames
	for (int i = 0; i < index; i++){
		printf("%d.%d.%d.%d %s\n", addressArr[i].num1, addressArr[i].num2, 
		addressArr[i].num3, addressArr[i].num4, addressArr[i].nickname);
	}
	
	//Close the file
	fclose(dataFile);
	
	return (0);
}

