#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {

	double v;
	printf("Input boat's speed.\n");
	if (scanf("%lf", &v) != 1 || v<=0 ) {
		printf("Incorrect input.\n");
	}

	double u;
	printf("Input river's speed.\n");
	if (scanf("%lf", &u) != 1 || u<=0 || u >= v ) {
		printf("Incorrect input.\n");
	}

	double t1;
	printf("Input first time.\n");
	if (scanf("%lf", &t1) != 1 || t1<=0 ) {
		printf("Incorrect input.\n");
	}

	double t2;
	printf("Input second time.\n");
	if (scanf("%lf", &t2) != 1 || t2<=0 ) {
		printf("Incorrect input.\n");

	}

	double s = v * t1 + (v - u) * t2;
	printf("%lf", s);


}