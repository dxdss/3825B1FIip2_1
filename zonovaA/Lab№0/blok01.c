#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdio.h>

void main() {
	double x, y, r, X, Y, R = 0;
	double EPS = 1e-6;
	printf("x1 = "); scanf("%lf", &x);
	printf("y1 = "); scanf("%lf", &y);
	printf("r1 = "); scanf("%lf", &r);
	printf("x2 = "); scanf("%lf", &X);
	printf("y2 = "); scanf("%lf", &Y);
	printf("r2 = "); scanf("%lf", &R);
	double dist = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
	while (r < 0 - EPS || R < 0 - EPS) {
		printf("Error, try again:\t");
		scanf("%lf%lf", &r, &R);
	}
	if (dist == 0) {
		printf("This centers of the circles coincide %lf", dist);
	}
	else if (dist > r + R) {
		printf("This circles do not intersect %lf", dist);
	}
	else if (r - R < dist < r + R) {
		printf("This circles intersect %lf", dist);
	}
	else if (dist == r + R) {
		printf("This circles externally touch %lf", dist);
	}
	else if (dist == r - R && dist > 0) {
		printf("This circles are internally tangent %lf", dist);
	}
	else if (d < r - R) {
		printf("One circle lies inside the other %lf", dist);
	}

}