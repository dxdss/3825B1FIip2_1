#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void main() {
    printf("enter the coordinates of the first and second circles. enter the radii of the first and second circles\n");
	double x1, y1, x2, y2, r1, r2;
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &r1, &r2);
	if ((r1 < 0) || (r2 < 0)) {
		printf("error");
	}
	else
	{
		double eps = 1e-10;
		double d = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
		double sumr = r1 + r2;
		double dif = fabs(r1 - r2);
        if (d <= eps && dif <= eps) {
            printf("sovpadaut ");
        }
        else if (fabs(d - sumr) <= eps || fabs(d - dif) <= eps) {
            printf("kasautsa ");
        }
        else if (d < sumr && d > dif) {
            printf("peresekautsa ");
        }
        else if (d < dif) {
            printf("odna vnutri drugoy, ne kasautsa ");
        }
        else {
            printf("ne peresekautsa ");
        }
	}
}