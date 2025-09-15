//0.1 Рациональное число
//Определить, каково взаимное расположение двух окружностей(пересекаются, касаются, не пересекаются)
//по их заданным координатам центров и радиусам.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void main() {
	float x1, y1, r1, x2, y2, r2, L;

	printf("Enter the coordinates of the first circle: x1, y1\n");
	scanf("%f%f", &x1, &y1);
	printf("Enter the radius of the first circle: r1\n");
	scanf("%f", &r1);
	printf("Enter the coordinates of the second circle: x2, y2\n");
	scanf("%f%f", &x2, &y2);
	printf("Enter the radius of the second circle: r2\n");
	scanf("%f", &r2);

	L = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	
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