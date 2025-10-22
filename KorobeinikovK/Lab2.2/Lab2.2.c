#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define OUT 0
#define WORD 1
#define NUM 2

int main() {
	char c;
	int state, nw = 0, nn = 0;
	state = OUT;
	int letter, digit;
	while ((c = getchar()) != '\n') {
		letter = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
		digit = (c >= '0' && c <= '9');
		if (c == ' ' || c == '\t') {
			state = OUT;
		}
		else if (letter && (state != WORD)) {
			state = WORD;
			++nw;
		}
		else if (digit && (state != NUM)) {
			state = NUM;
			++nn;
		}
		else if (state != OUT) {
			state = OUT;
		}
	}
	printf("Result\n");
	printf("Word count: %d\n", nw);
	printf("Number count: %d\n", nn);
}
