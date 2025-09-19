#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	double a;
	printf("Input first triangle's side.\n");
	if (scanf("%lf", &a) != 1 || a <= 0) {
		printf("Incorrect input.\n");
	}

	double b;
	printf("Input second triangle's side.\n");
	if (scanf("%lf", &b) != 1 || b <= 0) {
		printf("Incorrect input.\n");
	}

	double c;
	printf("Input third(largest) triangle's side.\n");
	if (scanf("%lf", &c) != 1 || c <= 0 || a > c || b > c) {
		printf("Incorrect input.\n");
	}

	double sum = a * a + b * b;
	double EPS = 1e-9;

	if (a + b <= c) {
		printf("Triangle does not exist.\n");
	}
	else if (abs(sum - c * c) < EPS) {
		printf("Right triangle.\n");
	}
	else if (sum - c * c > EPS) {
		printf("sharp-angled triangle.\n");

	}
	else if (c*c - sum > EPS) {
		printf("blunt-angled triangle.\n");

	}
}