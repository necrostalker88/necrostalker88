//#define _CRT_SECURE_NO_WARNINGS // Disable warnings (and errors) when using non-secure versions of printf, scanf, strcpy, etc.
#include<stdio.h>
#include <string.h>
#include <ctype.h>

//********Function Prototypes Defined here*****************//
char PrintMenu(char userStr[]);
int GetNumOfNonWSCharacters(char userString[]);
int GetNumOfWords(char userString[]);
void FixCapitalization(char toUpperStr[]);
void ReplaceExclamation(char replaceStr[]);
void ShortenSpace(char userString[],char shortedStr[]);

//**********Star of Main*********************************//
int main(void) {
	const int SIZE = 2000;
	char userString[SIZE];
	char toUpperStr[SIZE];
	char replaceStr[SIZE];
	char shortedStr[SIZE];
	char userChar = 'x';
	int nonWSpaceChars = 0;
	int numberOfWords = 0;
	int i = 0;

	printf("Enter a sample text:\n");
	printf("\n");
	fgets(userString, SIZE, stdin);

	printf("You entered: %s\n", userString);
	
	strcpy(toUpperStr, userString);
	strcpy(replaceStr, userString);
	

	while (userChar != 'q') {
		userChar = PrintMenu(userString);

		switch (userChar) {
		case 'c':
			nonWSpaceChars = GetNumOfNonWSCharacters(userString);
			printf("Number of non-whitespace characters: %d\n", nonWSpaceChars);
			printf("\n");
			break;
		case 'w':
			numberOfWords = GetNumOfWords(userString);
			printf("Number of words: %d\n", numberOfWords);
			break;
		case 'f':
			FixCapitalization(toUpperStr);
			printf("%s\n", toUpperStr);
			break;
		case 'r':
			ReplaceExclamation(replaceStr);
			printf("%s\n", replaceStr);

			break;
		case 's':
			ShortenSpace(userString,shortedStr);
			printf("%s\n", userString); //FIXME
			break;
		case 'q':
			break;
		}

	}
	return 0;
}

//*********Function Definations Start Here************//
char PrintMenu(char userStr[]) {
	char userChar = 'x';

	printf("MENU\n");
	printf("c - Number of non-whitespace characters\n");
	printf("w - Number of words\n");
	printf("f - Fix capitalization\n");
	printf("r - Replace all !'s\n");
	printf("s - Shorten spaces\n");
	printf("q - Quit\n");
	printf("\n");
	printf("Choose an option:\n");
	scanf(" %c", &userChar);

	return userChar;
}

int GetNumOfNonWSCharacters(char userString[]) {
	int nonWSpaceChars = 0;
	int i = 0;
	for (i = 0; userString[i] != '\0'; i++) {
		if (userString[i] != ' ') {
			nonWSpaceChars += 1;
		}
	}
	return (nonWSpaceChars);
}

int GetNumOfWords(char userString[]) {
	int numberOfWords = 0;
	int i = 0;

	for (i = 0; userString[i] != '\0'; i++) {
		if ((userString[i] == ' ') || (userString[i] == '\n')) { /*if char is a space or a new line the execute nested while*/
			while(userString[i] == ' ' || userString[i] == '\n'){ /*if char is space or new line move too next char and skip over them*/
				i++;
			}
			numberOfWords++; //a space or new line has occured and we have also skipped over any extra spaces or new line chars//
		}
	}
	return numberOfWords;
}

void FixCapitalization(char toUpperStr[]) {
	int i = 0;

	toUpperStr[0] = toupper(toUpperStr[0]); //uppercase the first element, if it is not a letter then it doesnt matter.

	for (i = 0; toUpperStr[i] != '\0'; i++) {
		
		if ((toUpperStr[i] == '.') || (toUpperStr[i] == '!') || (toUpperStr[i] == '?') ) { /*if at the end of a sentence then execute nested while*/
			i++;
			while (toUpperStr[i] == ' ' || toUpperStr[i] == '\n') { /*if char is space or new line move too next char and skip over them*/
				i++;
			}
			toUpperStr[i] = toupper( (toUpperStr[i]) );
		}
	}
	

	return;
}

void ReplaceExclamation(char replaceStr[]) {
	int i = 0;
	
	while (replaceStr[i] != '\0') {
		if (replaceStr[i] == '!') {
			replaceStr[i] = '.';
		}
		i++;
	}
	
	return;
}

void ShortenSpace(char userString[], char shortedStr[]) {
	int i = 0;
	int j = 0;
	//while (userString[i] != '\0') { /*until the end of the string*/
	//	if(userString[i] == ' ') { /*When char encounters a Space*/
	//		while(userString[i + 1] == ' ') { /*when a char is a space followed by another space i++ into next element*/
	//			i++;

	//		}
	//	shortedStr[j] = userString[i];
	//	i++;
	//	j++;
	//	}//end of if statment checking for space
	//} //End of while loop that will run until userString


	shortedStr[j] = '\0'; /*adds the End-Of-File char to end to shorted string*/


	return;
}