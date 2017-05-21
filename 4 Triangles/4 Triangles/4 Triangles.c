// Programmer:		Sir Andrew John Gonda
// Date:			Mar_5_2017
// Program Name:	4 Triangles
// Chapter:			Chapter #4 - Repetition
// Description:		This is a simple C program to use loops to create four different trangles from a single user number. 
//					Its was programmed by the most awesome guy ever.

#define _CRT_SECURE_NO_WARNINGS // Disable warnings (and errors) when using non-secure versions of printf, scanf, strcpy, etc.
#include <stdio.h> // Needed for working with printf and scanf

int main(void)
{
	// Constant and Variable Declarations
	int userNum        = 0;
	int triangleHeight = 0;
	int columnNum      = 0;
	int triangleBase   = 0;
	int numberOfSpaces = 0;
	int spaceCounter   = 0;
	char triangleShape = '*';

	// ***Input User NUm***//

	printf("Enter the size of the base for the triangles (1-15): ");
	scanf("%d", &userNum);

	//***Verify UserNUm***//

	while ( (userNum <= 0) || (userNum >=16) ) {
		printf("The base of the triangles must be between 1 and 15 – Please re-enter.\n");
		printf("Enter the size of the base for the triangles (1–15): ");
		scanf("%d", &userNum);
	}

	//Enter character to make triangle out of//

	printf("Enter a character to use to draw the triangles: ");
	scanf(" %c", &triangleShape);
	printf("\n");

	//***First triangle**//

	printf("Pattern A\n");
	printf("Base at bottom - Hypotenuse on right");


	while (triangleHeight <= userNum){
		
		while (columnNum < triangleHeight){
			printf("%c", triangleShape);
			columnNum += 1;
		}
		columnNum = 0;
		printf("\n");
		triangleHeight += 1;
	}

	printf("\n");

	//***Second triangle**//

	printf("Pattern B\n");
	printf("Base at top - Hypotenuse on right\n");

	triangleHeight = userNum;

	while (triangleHeight >= 0 ) {

		while (columnNum < triangleHeight) {
			printf("%c", triangleShape);
			columnNum += 1;
		}
		columnNum = 0;
		printf("\n");
		triangleHeight -= 1;
	}

	//***Third triangle**//

	printf("Pattern C\n");
	printf("Base at top - Hypotenuse on left\n");

	triangleHeight = userNum;

	while (triangleHeight >= 0) {

		while (columnNum < triangleHeight) {
			printf("%c", triangleShape);
			columnNum += 1;
			}
		
		columnNum = 0;
		printf("\n");
		triangleHeight -= 1;

		while (numberOfSpaces <= spaceCounter) {
			printf(" ");
			numberOfSpaces += 1;
			}
		numberOfSpaces = 0;
		spaceCounter += 1;
	}

	//***Fourth triangle**//

	printf("Pattern D\n");
	printf("Base at bottom - Hypotenuse on left");

	spaceCounter = userNum;
	numberOfSpaces = 0;

	while (triangleHeight <= userNum) {

		while (numberOfSpaces <= spaceCounter) {
			printf(" ");
			numberOfSpaces += 1;
		}
		numberOfSpaces = 0;
		spaceCounter -= 1;
		while (columnNum < triangleHeight) {
			printf("%c", triangleShape);
			columnNum += 1;
		}
		columnNum = 0;
		printf("\n");
		triangleHeight += 1;
	}

	printf("\n");
	return 0;
} // end main()
