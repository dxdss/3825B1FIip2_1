#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	double r1, r2, x1, y1, x2, y2 = 0;
	while (scanf("%lf%lf%lf%lf%lf%lf", &r1, &r2, &x1, &y1, &x2, &y2) != 6 || r1 < 0 || r2 < 0) {
		printf("Incorrect input!!!");
		return -1;
	}
	double rast = pow(((x1 - x2) * (x1 - x2) - (y1 - y2) * (y1 - y2)), 0.5);
	double sum_rad = r1 + r2;
	if (rast < sum_rad) {
		printf("Okruzh. peresek");
	} else if (rast > sum_rad) {
		printf("Okruzh. ne peresek");
	}
	else if (rast == sum_rad) {
		printf("Okruzh. kasautsya");
	}
	else if (r1 == r2 && x1 == x2 && y1 == y2) {
		printf("Okruzh. sovpadaut")
	}
}