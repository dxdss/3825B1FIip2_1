#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
	double a = 0;
	double b = 0;
	double c = 0;
	printf("a = "); scanf("%lf", &a);
	printf("b = "); scanf("%lf", &b);
	printf("c = "); scanf("%lf", &c);
	if (a + b > c && a + c > b && b + c > a) {
		if (c > b && c > a){
			if (c * c == a * a + b * b) {
				printf("90");
		}
			else if (c * c < a * a + b * b) {
				printf("<90");
			}
			else if (c*c > a*a + b*b) {
				printf(">90");
			}
			else {
				printf("error");
			}
		}
		else if (b > c && b > a) {
			if (b * b == a * a + c * c) {
				printf("90");
			}
			else if (b * b < a * a + c * c) {
				printf("<90");
			}
			else if (b * b > a * a + c * c) {
				printf(">90");
			}
			else {
				printf("error");
			}

		}
		else if (a > c && a > b) {
			if (a * a == b * b + c * c) {
				printf("90");
			}
			else if (a * a < b * b + c * c) {
				printf("<90");
			}
			else if (a * a > b * b + c * c) {
				printf(">90");
			}
			else {
				printf("error");
			}

		}
		else {
			printf("60");
		}
	}
	else {
		printf("error");
	}

}