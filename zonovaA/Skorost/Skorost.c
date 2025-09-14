#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdio.h>


void main() {
	double v1 = 0;
	double v2 = 0;
	double s = 0;
	double t = 0;
	double V = 0;
	double U = 0;
	double t1 = 0;
	double t2 = 0;
	printf("v1 = "); scanf("%lf", &v1);
	printf("v2 = "); scanf("%lf", &v2);
	printf("s = "); scanf("%lf", &s);
	printf("t = "); scanf("%lf", &t);
	printf("V = "); scanf("%lf", &V);
	printf("U:U<V = "); scanf("%lf", &U);
	printf("t1 = "); scanf("%lf", &t1);
	printf("t2 = "); scanf("%lf", &t2);
	printf("res = %lf\nres2 = %lf\nres3 = %lf", s + (v1 + v2) * t, fabs(s - (v1 + v2) * t), V * t1 + (V - U) * t2);

}