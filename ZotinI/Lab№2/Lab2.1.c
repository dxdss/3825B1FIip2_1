#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void main() {
	srand(time(NULL));

	char v;
	int count = 0;
	char fl = '0';
	
	while (1) {
		printf("Select the mode(1 or 2)\n");
		scanf(" %c", &v);
		if (v == '1' || v == '2') {
			break;
		}
		fl = '1';
		if (fl == '1') {
			printf("Input error. Try again!");
		}
	}
	int pol;
	if (v == '1') {
		int ran = rand() % 1000 + 1;
		do {
			printf("Enter number: \n");
			scanf(" %d", &pol);
			if (ran < pol) {
				printf("Number is less \n");
			}
			else if (ran > pol) {
				printf("Number is greater \n");
			}
			count += 1;

		} while (pol != ran);
		printf("You guessed right \n");
	}
	else {
		printf("Enter number: \n");
		scanf(" %d", &pol);
		int prog;
		int left = 1;
		int right = 1000;
		char osenka;
		
		
		do {
			prog = rand() % right;
			while (left > prog) {
				prog = rand() % right;
			}
			printf("Number programm = %d \n", prog);
			printf("Rate number\n");

			while (1) {
				scanf(" %c", &osenka);
				if (osenka == '<' || osenka == '>' || osenka == '=') {
					fl = '0';
					break;
				}
				fl = '2';
				if (fl == '2') {
					printf("Input error. Try again!");
				}
			}
			
			if (osenka == '>') {
				left = prog;
			}
			else if (osenka == '<') {
				right = prog;
			}
			count += 1;

		} while (osenka != '=');
		printf("Programm guessed right \n");
		printf("Secret number = %d \n", prog);
	}
	printf("Number of attempts: %d", count);

}