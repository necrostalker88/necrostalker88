// Programmer:		Sir Andrew John Gonda
// Date:			Mar_14_2017
// Program Name:	Payroll
// Chapter:			Chapter #4
// Description:		
//			
#define SIZE 7
#define _CRT_SECURE_NO_WARNINGS // Disable warnings (and errors) when using non-secure versions of printf, scanf, strcpy, etc.
#include <stdio.h> // Needed for working with printf and scanf
#include <string.h>

int main(void)
{
	// Constant and Variable Declarations
	int i = 0;
	char idArray[9];
	double hoursArrary[SIZE];
	double rateArray[SIZE];
	double payArrary[SIZE];

	strcpy(idArray[i], "00013570"); i++;
	strcpy(idArray[i], "00101020"); i++;
	strcpy(idArray[i], "00097536"); i++;
	strcpy(idArray[i], "00110111"); i++;
	strcpy(idArray[i], "00104562"); i++;
	strcpy(idArray[i], "00109512"); i++;
	strcpy(idArray[i], "00102468"); i++;

	/*for (i = 0; i < SIZE; i++) {
		printf("Enter the number of hours worked for employee ID T%s : ", idArray[i]);
		scanf("%lf", &hoursArrary[i]);
		printf("Enter the pay rate for employee ID T%s : $", idArray[i]);
		scanf("%lf", &rateArray);
	}*/

	/*for (i = 0; i < SIZE; i++) {
		payArrary[i] = (hoursArrary[i]) * (rateArray[i]);
	}*/


	/*for (i = 0; i < SIZE; i++) {
		printf("Enployee ID T%s earned $%.2lf.\n", idArray[i], payArrary[i]);
	}*/

	
	
	// *** Your program goes here ***

	printf("End\n");
	return 0;
} // end main()
