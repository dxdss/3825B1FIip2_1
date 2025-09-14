#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdio.h>

void main() {
	double x, y, r, X, Y, R = 0;
	printf("x1 = "); scanf("%lf", &x);
	printf("y1 = "); scanf("%lf", &y);
	printf("r1 = "); scanf("%lf", &r);
	printf("x2 = "); scanf("%lf", &X);
	printf("y2 = "); scanf("%lf", &Y);
	printf("r2 = "); scanf("%lf", &R);
	double dist = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
	if (dist > r + R) {
		printf("This circles do not intersect %lf", dist);
	}
	else if (dist == r + R) {
		printf("This circles touch %lf", dist);
	}
	else {
		printf("This circles intersect %lf", dist);
	}

}