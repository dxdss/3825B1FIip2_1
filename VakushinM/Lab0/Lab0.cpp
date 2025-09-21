/*
0.1 –ациональное число
ќпределить, каково взаимное расположение двух окружностей(пересекаютс€, касаютс€, не пересекаютс€)
по их заданным координатам центров и радиусам.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void main() {
	float x1, y1, r1, x2, y2, r2, L;

	printf("Enter the coordinates of the first circle: x1, y1\n");
	scanf("%f%f", &x1, &y1);

	printf("Enter the radius of the first circle: r1\n");
	scanf("%f", &r1);
	if (r1 <= 0) {
		printf("Incorrect input\n");
		return(-1);
	}
	r1 = (round(r1 * 1000)) / 1000;	//ќкругеление r1 до третьего знака после зап€той

	printf("Enter the coordinates of the second circle: x2, y2\n");
	scanf("%f%f", &x2, &y2);

	printf("Enter the radius of the second circle: r2\n");
	scanf("%f", &r2);
	if (r2 <= 0) {
		printf("Incorrect input\n");
		return(-1);
	}
	r2 = (round(r2 * 1000)) / 1000;	//ќкругеление r2 до третьего знака после зап€той

	L = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	L = (round(L * 1000)) / 1000;	//ќкругеление L до третьего знака после зап€той
	
	if (L > fmax(r1, r2)) {
		if ((r1 + r2) < L) {
			printf("Circles not intersect\n");
		}
		else if ((r1 + r2) > L) {
			printf("Circles intersect\n");
		}
		else {
			printf("Circles touch\n");
		}
	}
	else if ((L == 0) & (r1 == r2)) {
		printf("Circles match\n");
	}
	else if (L < fmax(r1, r2)) {
		if ((L + fmin(r1, r2)) < fmax(r1, r2)) {
			printf("Circles not intersect\n");
		}
		else if ((L + fmin(r1, r2)) > fmax(r1, r2)) {
			printf("Circles intersect\n");
		}
		else {
			printf("Circles touch\n");
		}
	}
}