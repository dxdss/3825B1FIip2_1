#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
    double r1, r2, x1, x2, y1, y2 = 0;
    scanf("%lf%lf%lf%lf%lf%lf", &r1, &r2, &x1, &x2, &y1, &y2);
    double xx = (x1-x2)*(x1 - x2);
    double yy = (y1-y2)*(y1 - y2);
    double rast = pow(xx + yy, 0.5);
    if (r1 < 0 || r2 < 0 || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) {
        printf("Eror");
    }else if (rast < r1 + r2) {
        printf("the circles intersect");
    }else if (rast > r1 + r2) {
        printf("the circles not intersect");
    }else {
        printf("the circles touch");
    }

}