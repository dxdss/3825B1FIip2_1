#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, r1, r2 = 0;
    double EPS = 1e-6;

    printf("X1 Y1: ");
    scanf("%lf%lf", &x1, &y1);
  
    printf("X2 Y2: ");
    scanf("%lf%lf", &x2, &y2);

    printf("R1 R2: ");
    scanf("%lf%lf", &r1, &r2);
    while (r1 < 0 - EPS || r2 < 0 - EPS ) {
        printf("Error, enter again:\t");
        scanf("%lf%lf", &r1, &r2);
    }
    double xx = (x1 - x2)*(x1 - x2);
    double yy = (y1 - y2)*(y1 - y2);
    double d = sqrt((xx + yy));

    if (d == 0) {
        printf("The centers of the circles coincide"); // Центры совпадают
    }
    else if (d > r1 + r2) {
        printf("The circles don't intersect"); // Не пересекаются
    }
    else if (r1 - r2 < d < r1 + r2) {
        printf("The circles intersect"); // Пересекаются
    }
    else if (d == r1 + r2) {
        printf("The circles externally touch"); // Касаются внешне
    }
    else if (d == r1 - r2 && d > 0) {
        printf("The circles are internally tangent"); // Касаются внутренне
    }
    else if (d < r1 - r2) {
        printf("One circle lies inside the other"); // Одна лежит внутри другой
    }
    
}

