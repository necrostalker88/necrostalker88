// Programmer:		Sir Andrew John Gonda
// Date:			Mar_17_2017
// Program Name:	MC Exam
// Chapter:			Chapter #5 - Arrarys
// Description:		This is a simple C program to grade a students multiple choice test.
//					It was programmmed by the most awesome guy ever.

#define _CRT_SECURE_NO_WARNINGS // Disable warnings (and errors) when using non-secure versions of printf, scanf, strcpy, etc.
#include <stdio.h> // Needed for working with printf and scanf
#include <conio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	// Constant and Variable Declarations
	const int SIZE = 21; // this number should be the number of questions on the exam PLUS 1//
	const int NAMESIZE = 30; // some names are bigger than other so a generous amount of space has been given//
	const int RESPONSE = 10; // either correct or incorrect//
	const double ONE_HUNDRED_PERCENT = 100.0;
	const int SEVENTY_FIVE = 75; //must achieve a grade higher than this to pass// 
	char studentAnswers[SIZE];
	char correctAnswers[SIZE];
	char studentName[NAMESIZE];
	char question[SIZE][RESPONSE];
	char answer = 'a';
	double finalGrade = 0.0;
	int correctQs = 0;
	int notCorrectQs = 0;
	int i = 1;
	int j = 0;

	correctAnswers[i] = 'B'; i++; correctAnswers[i] = 'D'; i++;
	correctAnswers[i] = 'A'; i++; correctAnswers[i] = 'A'; i++;
	correctAnswers[i] = 'C'; i++; correctAnswers[i] = 'A'; i++;
	correctAnswers[i] = 'B'; i++; correctAnswers[i] = 'A'; i++;
	correctAnswers[i] = 'C'; i++; correctAnswers[i] = 'D'; i++;
	correctAnswers[i] = 'B'; i++; correctAnswers[i] = 'C'; i++;
	correctAnswers[i] = 'D'; i++; correctAnswers[i] = 'A'; i++;
	correctAnswers[i] = 'D'; i++; correctAnswers[i] = 'C'; i++;
	correctAnswers[i] = 'C'; i++; correctAnswers[i] = 'B'; i++;
	correctAnswers[i] = 'D'; i++; correctAnswers[i] = 'A'; i++;

	i = 1;

	question[i][0] = '\0'; i++; question[i][0] = '\0'; i++;
	question[i][0] = '\0'; i++; question[i][0] = '\0'; i++;
	question[i][0] = '\0'; i++; question[i][0] = '\0'; i++;
	question[i][0] = '\0'; i++; question[i][0] = '\0'; i++;
	question[i][0] = '\0'; i++; question[i][0] = '\0'; i++;
	question[i][0] = '\0'; i++; question[i][0] = '\0'; i++;
	question[i][0] = '\0'; i++; question[i][0] = '\0'; i++;
	question[i][0] = '\0'; i++; question[i][0] = '\0'; i++;
	question[i][0] = '\0'; i++; question[i][0] = '\0'; i++;
	question[i][0] = '\0'; i++; question[i][0] = '\0'; i++;


	i = 1;

	//****Enter UserName****//
	printf("\nEnter the student's full name (enter nothing to end): ");
	//Loop continues until student name equals "enter"//
	fgets(studentName, NAMESIZE, stdin);
	while (studentName != '\0') {
		if (strncmp(studentName, "\n\0", 2) == 0) {
			break;
		}
		printf("Enter ");
		for (j = 0; (studentName[j] != '\n') && (studentName[j] != '\0'); ++j) {
			printf("%c", studentName[j]);
		}
		printf("'s 20 answers:\n", studentName);
		// get all of the answers//
		i = 1;
		while (i < SIZE) {
			printf("Enter answer #%d: ", i);
			scanf(" %c", &answer);
			answer = toupper(answer);
			if ((isalpha(answer)) && (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D')) {
				studentAnswers[i] = answer;
				i++;
			}
			else {
				//answer was not an 'A' 'B' 'C' or 'D'//
				while (1) {
					printf("The answer entered was not in the range of A - D.\n");
					printf("Please re-enter answer #%d: ", i);
					scanf(" %c", &answer);
					answer = toupper(answer);
					if ((isalpha(answer)) && (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D')) {
						studentAnswers[i] = answer;
						i++;
						break;
					}
				}
			}
		}

		printf("\n"); // a new line for formatting//

					  // compare answers of user to correct answers//
		for (i = 1; i < SIZE; i++) {
			if ((studentAnswers[i]) == (correctAnswers[i])) {
				strcpy(question[i], "correct\0");
				correctQs++;
			}
			else {
				strcpy(question[i], "incorrect\0");
				notCorrectQs++;
			}
		}
		for (i = 1; i < SIZE; i++) {
		printf("Question #%d - %s\n", i, question[i]);
		}
		printf("\n"); // blank line for formatting//
		for (j = 0; (studentName[j] != '\n') && (studentName[j] != '\0'); ++j) {
			printf("%c", studentName[j]);
		}
		printf(" had %d correct answers\n", correctQs);
		printf("and had %d incorrect answers.\n", notCorrectQs);

		finalGrade = (correctQs * ONE_HUNDRED_PERCENT) / (SIZE - 1);

		if (finalGrade < SEVENTY_FIVE) {
			printf("The student did not pass the exam.\nTheir score was %.0lf%%.\nA score of 75%% or better is required to pass.\n\n", finalGrade);
		}
		else {
			printf("The student passed the exam with a score of %.0lf%%%!\n\n", finalGrade);
		}

		correctQs = 0;
		notCorrectQs = 0;
		finalGrade = 0.0;
		for (i = 1; i < SIZE; i++) {
			question[i][0] = '\0';
		}


		printf("Enter the student's full name (enter nothing to end): "); 
		getchar();
		fgets(studentName, NAMESIZE, stdin);

	}
	return 0;
} // end main()
