#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

const double epsilon = 0.00001;

int isEqual(double a, double b)
{
    if (fabs(a - b) <= epsilon)
    {
        return 1;
    }

    return 0;
}


int main() 
{
    double x1, y1, r1;
    double x2, y2, r2;
    double distance, sumradius, diffrRadius;

    printf("Enter the coordinates of the center x1 and y1 and the radius of the circle\n");
    scanf("%lf%lf%lf", &x1, &y1, &r1);

    printf("Enter the coordinates of the center x2 and y2 and the radius of the circle\n");
    scanf("%lf%lf%lf", &x2, &y2, &r2);

    if (r1 <= 0 || r2 <= 0) 
    {
        printf("The radius cannot be negative or equal to 0\n");
        return 1;
    }

    distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    sumradius = r1 + r2;
    diffrRadius = fabs(r1 - r2);

    if (distance > sumradius)
    {
        printf("The circles do not intersect (they are located outside of each other)");
    }
    else if (isEqual(distance, sumradius))
    {
        printf("The circles touch externally");
    }
    else if (distance < diffrRadius)
    {
        printf("The circles do not intersect (one is inside the other)");
    }
    else if (isEqual(distance, diffrRadius))
    {
        printf("The circles are touching internally");
    }
    else
    {
        printf("The circles intersect");
    }
    
    return 0;
}


