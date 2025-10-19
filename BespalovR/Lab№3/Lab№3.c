//Lib.
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void main() {


	//Input + check.
	char c = 0;
	int lngth = 0;
	printf("Input length of guessed number.(2-5)\n");
	while (scanf("%d", &lngth) != 1 || lngth > 5 || lngth < 2) {
		printf("Incorrect input. Please try again.\n");
		while ((c = getchar()) != '\n') {};
	}


	//Creating random 2-5 digit array with unique numbers.
	char i = 0;
	char t = 0;
	char num[10] = { 0 };
	char array[5] = { 0 };
	srand(time(NULL));
	while (i < lngth) {
		t = rand() % 10;
		if (num[t] == 0 && (t > 0 || i > 0)) {
			array[i] = t;
			num[array[i++]] += 1;
		}
	}


	//Game itself
	char oxen;
	char cows;
	do {

		cows = oxen = 0;
		while ((c = getchar()) != '\n') {};
		printf("Make a guess.\n");

		while (i != 0) {
			//There's some strange behaviour of endlines with getchar, dunno how to fix it

			if ((c = getchar()) > '9' || c < '0') {
				printf("Error.\n");
				break;
			}

			else if (c - '0' == array[lngth - i]) {
				++cows;
			}

			else if (num[c - '0'] != 0) {
				++oxen;
			}

			--i;
		}
		printf("There is %d cows and %d oxen.\n", cows, oxen);
		i = lngth;
	} while (cows != lngth);

	printf("You Won!\n");
}