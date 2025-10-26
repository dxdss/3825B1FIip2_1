#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int unique_dig(int num, int len) {
	int digits[10] = { 0 };
	for (int i = 0; i < len; i++) {
		int dig = num % 10;
		if (digits[dig]) {
			return 0; // ��� ���� �����
		}
		digits[dig] = 1;
		num /= 10;
	}
	return 1;
}
int gen_num(int n) {
	int num;
	int pos_dig[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int c = 10;
	//������ �����
	int first_dig = rand() % 9 + 1;
	num = pos_dig[first_dig];

	for (int i = first_dig; i < c - 1; i++) {
		pos_dig[i] == pos_dig[i + 1];
	}
	c--;
	for (int i = 1; i < n; i++) {
		int ind = rand() % c;
		num = num * 10 + pos_dig[ind];
		for (int j = ind; j < c - 1; j++) {
			pos_dig[j] = pos_dig[j + 1];
		}
		c--;
	}
	return num;
}
void bulls_and_cows(int secret, int guess, int n, int* cows, int* bulls) {
	*bulls = 0;
	*cows = 0;
	int sec_num[5], guess_num[5];
	for (int i = n - 1; i >= 0; i--) {
		sec_num[i] = secret % 10;
		secret /= 10;
		guess_num[i] = guess % 10;
		guess /= 10;
	}
	//����
	for (int i = 0; i < n; i++) {
		if (sec_num[i] == guess_num[i]) {
			(*bulls)++;
		}
	}
	//������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && sec_num[i] == guess_num[j]) {
				(*cows)++;
			}
		}
	}
}
int main() {
	srand(time(NULL));
	int n;
	printf("Enter number(2-5):");
	scanf("%d", &n);
	if (n < 2 || n>5) {
		printf("Incorrect");
	}
	int sec = gen_num(n);
	printf("Guess number\n");
	while (1) {
		int guess;
		printf("Your option:");
		scanf("%d", &guess);
		int min = 1;
		for (int i = 1; i < n; i++) {
			min *= 10;
		}
		if (guess < min || guess >= min * 10 || !unique_dig(guess, n)) {
			printf("Incorrect\n");
			continue;
		}
		int bull, cow;
		bulls_and_cows(sec, guess, n, &cow, &bull);
		printf("Cows: %d, Bulls: %d\n", &cow, &bull);
		if (bull == n) {
			printf("You Won! Number is %d", sec);
			break;
		}
	}
}