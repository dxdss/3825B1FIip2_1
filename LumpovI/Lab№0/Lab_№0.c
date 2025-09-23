#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	double r1 = 0, r2 = 0, x1 = 0, y1 = 0, x2 = 0 , y2 = 0;
	while (scanf("%lf%lf%lf%lf%lf%lf", &r1, &r2, &x1, &y1, &x2, &y2) != 6 || r1 < 0 || r2 < 0) {
		printf("Incorrect input!!!");
		return -1;
	}
	double xy = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	double rast = pow(xy, 0.5);
	double sum_rad = r1 + r2;
	int x = 0;
	if (rast < r1 || rast < r2) {
		x = 2;
	}
	else {
		x = 1;
	}
	if (r1 == r2 && x1 == x2 && y1 == y2) {
		printf("The circles coincide");
		return -1;
	}
	else {

		switch (x) {
		case(1):
			if (rast < sum_rad) {
				printf("Circles externally intersect");
			}
			else if (rast > sum_rad) {
				printf("Circles externally not intersect");
			}
			else if (rast == sum_rad) {
				printf("Circles externally touch");
			}
			break;
		case(2):
			if (rast == fabs(r1 - r2)) {
				printf("Circles touch internally");
			}
			else if (rast < fabs(r1 - r2)) {
				printf("Circles not intersect internally");
			}
			else if (rast > fabs(r1 - r2)) {
				printf("Circles intersect internally");
			}
			break;
		}
	}
}