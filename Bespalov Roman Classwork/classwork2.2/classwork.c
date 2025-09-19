#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main() {
	unsigned int a;
	scanf("%u", &a);
	unsigned int b = a & 2;
	unsigned int c = a & 4;
	unsigned int d = 6;

	if ((b != 0 && c == 0) || (b == 0 && c != 0)) {

		printf("%u", a ^ d);

	}
	else {
		printf("%u", a);
	}
}