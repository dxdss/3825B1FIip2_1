//Libraries
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//Input
void main() {
	printf("Input X coordinate of the FIRST centre.\n");
	double Centre1X;
	scanf("%lf", &Centre1X);

	printf("Input Y coordinate of the FIRST centre.\n");
	double Centre1Y;
	scanf("%lf", &Centre1Y);

	printf("Input RADIUS of the FIRST circle.\n");
	double Radius1;
	scanf("%lf", &Radius1);

	printf("Input X coordinate of the SECOND centre.\n");
	double Centre2X;
	scanf("%lf", &Centre2X);

	printf("Input Y coordinate of the SECOND centre.\n");
	double Centre2Y;
	scanf("%lf", &Centre2Y);

	printf("Input RADIUS of the SECOND circle.\n");
	double Radius2;
	scanf("%lf", &Radius2);





	//Math
	double Distance;
	Distance = sqrt((Centre1X - Centre2X) * (Centre1X - Centre2X) + (Centre1Y - Centre2Y) * (Centre1Y - Centre2Y));

	double RadiusSum;
	RadiusSum = Radius1 + Radius2;
	
	double MaxRadius;
	if (Radius1 > Radius2) { 
		MaxRadius = Radius1; 
	}
	else { 
		MaxRadius = Radius2;
	}




	//Connditions and output
	if ((Distance > RadiusSum)||(MaxRadius > Distance + (Radius1 + Radius2 - MaxRadius))) {
		printf("Circles don't intersect and don't touch.\n"); 
	}
	else if ((Distance == RadiusSum)||(MaxRadius == Distance + (Radius1 + Radius2 - MaxRadius))) {
		printf("Circles touch each other.\n");
	}
	else {
		printf("Circles intersect with each other.\n");
	}

}