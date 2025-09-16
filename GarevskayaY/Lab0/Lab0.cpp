#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, r1, r2 = 0;
    printf("X1 Y1: ");
    scanf("%lf%lf", &x1, &y1);
    printf("X2 Y2: ");
    scanf("%lf%lf", &x2, &y2);
    printf("R1 R2: ");
    scanf("%lf%lf", &r1, &r2);
    double xx = pow(x1 - x2, 2);
    double yy = pow(y1 - y2, 2);
    double d = pow(xx + yy, 0.5);
    if (d > r1 + r2) {
        printf("Okruzhnosti ne peresekayutsa");
    }
    else if (d < r1 + r2) {
        printf("Okruzhnosti peresekayutsa");
    }
    else if (d = r1 + r2) {
        printf("Okruzhnosti kasayutsa");
    }
 
}

