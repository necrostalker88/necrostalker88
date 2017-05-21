// Programmer:		Sir Andrew John Gonda
// Date:			Jan_
// Program Name:	The name of the program
// Chapter:			Chapter #2 - Fundamentals
// Description:		This is a simple C program to ...
//					algorithm used, etc.

#define _CRT_SECURE_NO_WARNINGS // Disable warnings (and errors) when using non-secure versions of printf, scanf, strcpy, etc.
#include <stdio.h> // Needed for working with printf and scanf
#include <stdlib.h>

void MyFunction(char myArray[], int SIZE);

int main(void)
{
	// Constant and Variable Declarations
	const int SIZE = 54;
	const int FOUR = 4;
	char myArray[SIZE];
	int valueArray[FOUR];

	printf("enter four values between 1 and three: ");
	for (int i = 0; i < FOUR; i++) {
		scanf("%d", &valueArray[i]);

		if ((valueArray[i] <= 0) || (valueArray[i] > 3)) {
			
			while ( (valueArray[i] <= 0) || (valueArray[i] > 3) ){
			printf("not between 1 and 3, enter a new value\n");
			scanf("%d", &valueArray[i]);
			}
			printf("u entered ");
			for(i = 0; i < FOUR; i++)
			printf("%d ", valueArray[i]);
		}
	}

	while (myArray[0] != '\n') {
		printf("Enter sum values for the string\n");
		fgets(myArray, 54, stdin);
		MyFunction(myArray, SIZE);
		fflush(stdin);
	}


	// *** Your program goes here ***


	return 0;
} // end main()


void MyFunction(char myArray[], int SIZE) {

	printf("Enter function and display array\n");
	printf("%s", myArray);

	return;
}