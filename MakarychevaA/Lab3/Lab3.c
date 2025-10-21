#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int lengthCorrect(int number, int size) {
	int i = 0;
	while (number != 0) {
		number /= 10;
		i++;
	}
	if (i == size) {
		return 1;
	}
	else {
		return 0;
	}
}

int differentDigitsCorrect(int number, int size) {
	int userNumber[5];
	for (int i = size - 1; i >= 0; i--) {
		userNumber[i] = number % 10;
		number /= 10;
	}
	for (int i = 0; i < size - 1; i++) {
		int j = i + 1;
		while (j < size) {
			if (userNumber[j] == userNumber[i]) {
				return 0;
			}
			++j;
		}
	}
	return 1;
}

int inputCorrect(int size) {
	int number;
	printf("Try to guess the number, the digits should not be repeated\n");
	while (1) {
		clearInputBuffer();
		scanf("%d", &number);
		if (number < 0) {
			printf("The number must be positive\n");
		}
		else if (lengthCorrect(number, size) == 0) {
			printf("The length should be the size %d\n", size);
		}
		else if (differentDigitsCorrect(number, size) == 0) {
			printf("The number must not contain repeated digits.\n");
		}	
		else {
			return number;
		}
	}
}

int main() {
		srand(time(NULL));
		int number; int size;
		int arr[5];
		int bulls = 0; int cows = 0;
		int userNumber[5];
		printf("Enter the length of the number you are trying to guess (from 2 to 5)\n");
		scanf("%d", &size);
		while (size > 5 || size < 2) {
			printf("Error. Length must be between 2 and 5. Please enter the size again.\n");
			clearInputBuffer();
			scanf("%d", &size);
		}

		arr[0] = rand() % 9 + 1;
		for (int i = 1; i < size; i++) {
			int generated = rand() % 10;
			int j = 0;
			while (j < i) {
				if (arr[j] == generated) {
					generated = rand() % 10;
					j = 0;
				}
				else {
					j++;
				}
			}
			arr[i] = generated;
		}

	while (bulls != size) {
		bulls = 0;
		cows = 0;
		number = inputCorrect(size);

		for (int i = size - 1; i >= 0; i--) {
			userNumber[i] = number % 10;
			number /= 10;
		}

		for (int i = 0; i < size; i++) {
			if (userNumber[i] == arr[i]) {
				bulls++;
			}
			else {
				for (int j = 0; j < size; j++) {
					if (userNumber[j] == arr[i]) {
						cows++;
					}
				}
			}
		}

		if (bulls == size) {
			printf("Congratulations! You guessed the number.\n");
		}
		printf("Number of cows = %d, number of bulls = %d.\n", cows, bulls);
	}
}

	






