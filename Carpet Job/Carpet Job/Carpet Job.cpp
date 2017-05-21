// Programmer:		Sir Andrew John Gonda
// Date:			Apr_9_2017
// Program Name:	Carpet Job
// Chapter:			Chapter #6 - Funtions
// Description:		This is a simple C program to estimate the cost of carpeting a space for the customer.
//					It was programmed by the most awesome guy ever.
//Developer Note:   Comments concerning functions are nested inside functions for readability.

#define _CRT_SECURE_NO_WARNINGS // Disable warnings (and errors) when using non-secure versions of printf, scanf, strcpy, etc.
#include <stdio.h> // Needed for working with printf and scanf

//*********Global CONSTANTS and Varibles*************//
const double PAYRATE = 25.00;
const int FOURHOURCARPET = 65;
const int FOURHOURS = 4;
const double MINCARPETPRICE = 1.00;
const double MAXCARPETPRICE = 10.00;
const int ONESQUAREFOOT = 144;
double roomLength = 0.0;
double roomWidth = 0.0;
double roomArea = 0.0;
double carpetPrice = 0.0;
double hoursOfWork = 0.0;
double subTotal = 0.0;
double laborCharges = 0.0;
double grandTotal = 0.0;

//**********Function Prototypes********//
void SquareFootage(double roomLength, double roomWidth, double* roomArea);
void NumberOfHours(double roomArea, int FOURHOURCARPET, int FOURHOURS, double* hoursOfWork);
void PriceOfCarpet(double roomArea, double carpetPrice, double* subTotal);
void LaborCharges(double PAYRATE, double hoursOfWork, double *laborCharges);
void TotalCost(double subTotal, double laborCharges, double* grandTotal);

//*********MAIN FUNCTION**************//

int main(void)
{
	// Constant and Variable Declarations
	
	//No varsibles used here all varibles are GLOBAL//

	// ********Get Input*******//

	printf("Enter the length of the room (in inches): ");
	scanf("%lf", &roomLength);
	//printf("\n"); //new line after inpute//
	//validate length//
	while (roomLength <= 0) {
		printf("   A positive value for the length must be entered.\n");
		printf("   Please re-enter the length of the room (in inches): ");
		scanf("%lf", &roomLength);
		printf("\n"); //new line after inpute//
	}

	printf("Enter the width of the room (in inches): ");
	scanf("%lf", &roomWidth);
	//validate roomWith//
	while (roomWidth <= 0) {
		printf("   A positive value for the width must be entered.\n");
		printf("   Please re-enter the width of the room (in inches): ");
		scanf("%lf", &roomWidth);
		printf("\n"); //new line after inpute//
	}

	printf("Enter the price per sq. ft. of the carpet: $");
	scanf("%lf", &carpetPrice);
	printf("\n"); //new line after inpute//
	//validate carpet price//
	while (carpetPrice < MINCARPETPRICE || carpetPrice > MAXCARPETPRICE) {
		printf("   The price of the carpet must be between $1.00 and $10.00 inclusive.\n");
		printf("   Please re-enter the price per sq. ft. of the carpet: $");
		scanf("%lf", &carpetPrice);
		printf("\n"); //new line after inpute//
	}

	SquareFootage(roomLength, roomWidth, &roomArea); //Note: only roomArea is pass by pointer. All other values are read only.//
	NumberOfHours(roomArea, FOURHOURCARPET, FOURHOURS, &hoursOfWork); //Note: only hoursOfWork is pass by pointer. All other values are read only.//
	PriceOfCarpet(roomArea, carpetPrice, &subTotal); //Note: only subTotal is pass by pointer. All other values are read only.//
	LaborCharges(PAYRATE, hoursOfWork, &laborCharges); //Note: only laborCharges is pass by pointer. All other values are read only.//
	TotalCost(subTotal, laborCharges, &grandTotal);


	return 0;
} // end main()

//********Functions Called or invoked in MAIN*******//

void SquareFootage(double roomLength, double roomWidth, double* roomArea) {

	*roomArea = (roomLength * roomWidth)/ ONESQUAREFOOT ;

	printf("The square footage of the room is: %.2lf sq. ft.\n", *roomArea);

	return;
} //calculate square feet of area to carpet.//

void NumberOfHours(double roomArea, int FOURHOURCARPET, int FOURHOURS, double* hoursOfWork){

	*hoursOfWork = roomArea / ( (double)FOURHOURCARPET / FOURHOURS);
	printf("The number of hours required to carpet %.2lf square feet is: %.2lf hours\n", roomArea, *hoursOfWork);

	return;
}//calculate numbers of hours required to carpet the given area//

void PriceOfCarpet(double roomArea, double carpetPrice, double* subTotal) {

	*subTotal = carpetPrice * roomArea;
	printf("The price for the carpet is: $%.2lf\n", *subTotal);

	return;
} //total cost of materials to carpet given area//

void LaborCharges(double PAYRATE, double hoursOfWork, double *laborCharges) {

	*laborCharges = PAYRATE * hoursOfWork;
	printf("The labor charges are: $%.2lf\n", *laborCharges);

	return;
} // Cost of hourly wages to pass to the customer. DOES NOT include cost of donuts and coffee for workers.

void TotalCost(double subTotal, double laborCharges, double* grandTotal) {

	*grandTotal = subTotal + laborCharges;
	printf("The total cost to carpet the room is: $%.2lf\n", *grandTotal);
	return;
}