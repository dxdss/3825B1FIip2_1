#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int gm;
	int num = 0;
	int guess = 0;
	int guess_q = 1;
	char c;

	printf("Select the game mode. Enter 1 if you want to guess the number. Enter 2 if you want the program to guess your number.\n");
	scanf("%d", &gm);

	while (gm != 1 && gm != 2) {
		printf("Error, try again\n");
		while ((c = getchar()) != '\n' && c != EOF) {};
		scanf("%d", &gm);
	}

	switch (gm) {
	case 1:
		srand(time(NULL));
		num = rand() % 1000 + 1;
		for (guess_q; num != guess; guess_q++) {
			printf("Guess the number from 1 to 1000\n");

			while (scanf("%d", &guess) != 1) {
				printf("Error, try again\n");
				while ((c = getchar()) != '\n' && c != EOF) {};
			}

			if (guess > num) {
				printf("Your number is larger then hidden number\n");
			}

			if (guess < num) {
				printf("Your number is smaller then hidden number\n");
			}

			if (guess == num) {
				printf("You guessed the number! Number of attempts: %d\n", guess_q);
			}
		}
		break;
	
	case 2:
		int a = 1;
		int b = 1000;

		printf("Come up with the number from 1 to 1000\n");
		while (scanf("%d", &num) != 1 || num < 1 || num > 1000) {
			printf("Error, try again\t");
			while ((c = getchar()) != '\n' && c != EOF) {};
		}
		srand(time(NULL));

		for (guess_q; num != guess; guess_q++) {
			if (a > b || a == b) {
				printf("Error, no numbers left in range");
			}

			guess = a + rand() % (b - a + 1);
			printf("Maybe it is %d? Print </=/>\t", guess);
			
			while ((c = getchar()) != '<' && c != '=' && c != '>') {
				if (c != '\n') {
					printf("Please enter only <, = or >:\t");
				}
			}
			if (c == '<' && guess < b) {
				b = guess - 1;
			}
			if (c == '>' && guess > a) {
				a = guess + 1;
			}
			if (c == '=' && guess == num) {
				printf("I guessed your number! Number of attempts: %d", guess_q);
				break;
			}
			if (a > b) {
				printf("You gave erroneous hints. The number cannot exist.\n");
				break;
			}
			
		}
	}
}
