#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearInput() {
	char ch = '\0';
	while ((ch = getchar()) != '\n' && ch != EOF);
}

char compareNumbers(unsigned short num1, unsigned short num2) {
	if (num1 == num2) {
		return '=';
	}
	else if (num1 > num2) {
		return '>';
	}
	else return '<';
}

void firstMode() {
	unsigned short rand_number = 1 + rand() % 1000;
	unsigned short user_ans = 0;
	unsigned short tries_count = 0;

	while (rand_number != user_ans) {
		printf("Enter you answer: ");
		while (scanf("%hd", &user_ans) != 1 || user_ans < 1 || user_ans > 1000) {
			printf("Encorrect enter or number not in range 1-1000\n");
			clearInput();
			printf("Enter you answer: ");
		}
		clearInput();

		++tries_count;
		char compare_result = compareNumbers(user_ans, rand_number);
		if (compare_result != '=') {
			printf("You number %c Hidden number\n", compare_result);
		}
	}
	printf("You're damn right. Tries count: %hd", tries_count);
}

void secondMode() {
	unsigned short bot_number = 0;
	unsigned short max = 1000;
	unsigned short min = 1;
	unsigned short tries_count = 0;
	char number_status = ' ';

	while (number_status != '=') {
		bot_number = min + (max - min) / 2;
		++tries_count;
		printf("Bot number: %hd\n", bot_number);

		printf("Enter status (<, =, >): ");
		while (scanf("%c", &number_status) != 1 || number_status != '<' && number_status != '=' && number_status != '>') {
			printf("Encorrect enter\n");
			clearInput();
			printf("Enter status (<, =, >): ");
		}
		clearInput();

		if (number_status == '>') {
			max = bot_number - 1;
		}
		else if (number_status == '<') {
			min = bot_number + 1;
		}
	}
	printf("Your number is %hd. Tries count: %hd", bot_number, tries_count);
}

void main() {
	srand(time(0));
	unsigned int mode = 0;
	printf("Select mode (1, 2): ");
	while (scanf("%d", &mode) != 1 || mode < 1 || mode > 2) {
		printf("Encorrect enter\n");
		clearInput();
		printf("Select mode (1, 2): ");
	}
	clearInput();

	switch (mode) {
	case 1:
		firstMode();
		break;
	case 2:
		secondMode();
		break;
	}
}