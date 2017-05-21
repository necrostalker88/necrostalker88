// Programmer:		Sir Andrew John Gonda
// Date:			Feb_12_2017
// Program Name:	 Miles per Gallon (w/ validation)
// Chapter:			Chapter #3 - Desisions
// Description:		This is a simple C program to calculate miles per a gallon of gas from the odometer reading.
//					This program was written by the most awesome guy ever. 

#define _CRT_SECURE_NO_WARNINGS // Disable warnings (and errors) when using non-secure versions of printf, scanf, strcpy, etc.
#include <stdio.h> // Needed for working with printf and scanf

int main(void)
{
	// Constant and Variable Declarations
	int odometerReadOne   = 0;
	int odometerReadTwo   = 0;
	int milesDriven       = 0;
	double gallonsUsed    = 0.0;
	double milesPerGallon = 0.0;


	// ***Opening Input ***//

	printf("Enter the beginning odometer reading: ");
	scanf("%d", &odometerReadOne);

	//******Calculations Section**********//

	if ( (odometerReadOne > 0) && (odometerReadOne!= 0) ) {

		printf("Enter the ending odometer reading: ");
		scanf("%d", &odometerReadTwo);

		if (odometerReadOne == odometerReadTwo) {

			printf("The first and second odometer readings can not be the same.\n");
		}
		else if (odometerReadOne > odometerReadTwo ) {

			printf("The second odometer reading must be greater than the first odometer reading.\n");
		}
		else if (odometerReadTwo > odometerReadOne) {

			printf("Enter the number of gallons used: ");
			scanf("%lf", &gallonsUsed);
			
			if ( (gallonsUsed > 0) && (gallonsUsed < 30.1) ) {

				milesDriven = odometerReadTwo - odometerReadOne;
				milesPerGallon = milesDriven / gallonsUsed;

				printf("\n"); //blankline visual formatting
				printf("Your car gets %.1lf miles per gallon.\n\n", milesPerGallon);


			}
			else {
				printf("The gallons used must be greater than 0.0 and less than or equal to 30.0.\n\n");
			}
		}
		
		
	
	}
	else {
		printf("The beginning odometer reading must be a positive number.\n\n");
	}


	return 0;
} // end main()
