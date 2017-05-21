#define XSIZE 25
#define YSIZE 100
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

struct Body {
	boolean alive;
	int bodyX;
	int bodyY;
};

void growBody(struct Body *myBody, int charX2, int charY2);
void drawBody(struct Body *myBody, char(*myArray)[100]);
void moveBody(struct Body *myBody, int deltaX, int deltaY);
char testBounds(char input, int charX, int charY);

int main()
{
	char myArray[XSIZE][YSIZE];
	char input;
	int charX = 12;
	int charY = 50;
	int charX2 = 12;
	int charY2 = 50;
	int foodX = 10;
	int foodY = 45;
	int score = 0;
	boolean esc = 1;
	struct Body myBody[100];
	char lastInput = 'd';

	for (int i = 0; i < 100; i++) {
		myBody[i].alive = 0;
		myBody[i].bodyX = 0;
		myBody[i].bodyY = 0;
	}

	while (esc) {
		system("CLS");
		printf("Your score is: %d\n", score);
		printf(" ");
		for (int i = 0; i < YSIZE; i++) { printf("_"); if (i == (YSIZE - 1)) { printf("\n"); } }
		for (int i = 0; i < XSIZE; i++) {
			for (int j = 0; j < YSIZE; j++) {
				myArray[i][j] = ' ';
			}
		}

		if (charX == foodX && charY == foodY) {
			foodX = rand() % 25;
			foodY = rand() % 100;
			score++;
			growBody(&myBody, charX2, charY2);
		}

		drawBody(&myBody, &myArray);
		
		myArray[charX][charY] = 'H';
		myArray[foodX][foodY] = 'O';

		for (int i = 0; i < XSIZE; i++) {
			printf("|");
			for (int j = 0; j < YSIZE; j++) {
				printf("%c", myArray[i][j]);
			}
			printf("|\n");
		}
		printf(" ");
		for (int i = 0; i < YSIZE; i++) { printf("_"); if (i == (YSIZE - 1)) { printf("\n"); } }
	
		Sleep(50);
		
		if (kbhit()) {
			input = getch();
		}
		else {
			input = lastInput;
		}

		input = testBounds(input, charX, charY);
		
		switch (input) {
		case 'w':
			lastInput = 'w';
			charY2 = charY;
			charX2 = charX;
			charX -= 1;
			moveBody(&myBody, charX2, charY2);
			break;
		case 's':
			lastInput = 's';
			charY2 = charY;
			charX2 = charX;
			charX += 1;
			moveBody(&myBody, charX2, charY2);
			break;
		case 'a':
			lastInput = 'a';
			charX2 = charX;
			charY2 = charY;
			charY -= 1;
			moveBody(&myBody, charX2, charY2);
			break;
		case 'd':
			lastInput = 'd';
			charX2 = charX;
			charY2 = charY;
			charY += 1;
			moveBody(&myBody, charX2, charY2);
			break;
		case 27:
			esc = 0;
			break;
		}
	}
	return(0);
}

void growBody(struct Body *myBody, int charX2, int charY2) {
	for (int i = 0; i < 100; i++) {
		if (myBody[i].alive == 0) {
			myBody[i].alive = 1;
			myBody[i].bodyX = charX2;
			myBody[i].bodyY = charY2;
			return;
		}
	}
}

void drawBody(struct Body *myBody, char(*myArray)[100]) {
	for (int i = 0; i < 100; i++) {
		if (myBody[i].alive == 1) {
			int x = myBody[i].bodyX;
			int y = myBody[i].bodyY;
			myArray[x][y] = 'X';
		}
	}
}

void moveBody(struct Body *myBody, int charX2, int charY2) {
	for (int i = 99; i > 0; i--) {
		if (myBody[i].alive == 1) {
			myBody[i].bodyX = myBody[i - 1].bodyX;
			myBody[i].bodyY = myBody[i - 1].bodyY;
		}
	}
	if (myBody[0].alive == 1) {
		myBody[0].bodyX = charX2;
		myBody[0].bodyY = charY2;
	}
}

char testBounds(char input, int charX, int charY) {
	if (input == 'w' && charX == 0) {
		input = 'z';
	}
	if (input == 's' && charX == 24) {
		input = 'z';
	}
	if (input == 'a' && charY == 0) {
		input = 'z';
	}
	if (input == 'd' && charY == 99) {
		input = 'z';
	}
	return input;
}
