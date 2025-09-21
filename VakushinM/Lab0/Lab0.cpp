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

	printf("Enter the coordinates of the first circle to the third decimal place: x1, y1\nThe remaining decimal places will be discarded.\n");
	scanf("%f%f", &x1, &y1);
	x1 = (floor(x1 * 1000)) / 1000;	//ќкругеление x1 до третьего знака после зап€той
	y1 = (floor(y1 * 1000)) / 1000;	//ќкругеление y1 до третьего знака после зап€той

	printf("Enter the radius of the first circle to the third decimal place: r1\nThe remaining decimal places will be discarded.\n");
	scanf("%f", &r1);
	if (r1 <= 0) {
		printf("Incorrect input\n");
		return(-1);
	}
	r1 = (floor(r1 * 1000)) / 1000;	//ќкругеление r1 до третьего знака после зап€той

	printf("Enter the coordinates of the second circle to the third decimal place: x2, y2\nThe remaining decimal places will be discarded.\n");
	scanf("%f%f", &x2, &y2);
	x2 = (floor(x2 * 1000)) / 1000;	//ќкругеление x2 до третьего знака после зап€той
	y2 = (floor(y2 * 1000)) / 1000;	//ќкругеление y2 до третьего знака после зап€той

	printf("Enter the radius of the first circle to the third decimal place: r2\nThe remaining decimal places will be discarded.\n");
	scanf("%f", &r2);
	if (r2 <= 0) {
		printf("Incorrect input\n");
		return(-1);
	}
	r2 = (floor(r2 * 1000)) / 1000;	//ќкругеление r2 до третьего знака после зап€той

	L = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	//L = (round(L * 1000)) / 1000;	//ќкругеление L до третьего знака после зап€той
	
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