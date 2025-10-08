#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


void main() {
	printf("Hello, it is a cabinet Weight Calculator \n");
	float h, w, d;
	float tol_stenki = 0.5f;
	float tol_bok = 1.5f;
	float tol_dveri = 1.0f;
	float tol_polk = 0.5f;
	float plotnost_dsp = 0.55f;
	float plotnost_dvp = 0.95f;
	float plotnost_dereva = 0.54f;

	do {
		printf("Enter h (180-220):\n");
		scanf("%f", &h);

		printf("Enter w (80-120):\n");
		scanf("%f", &w);

		printf("Enter d (50-90):\n");
		scanf("%f", &d);
	} while (h < 180 || h > 220 || w < 80 || w > 120 || d < 50 || d > 90);
	
	double mas_zad = plotnost_dvp * h * w * tol_stenki;
	double mas_bok=2 * plotnost_dsp*d * tol_bok;
	double mas_nakl = 2 * plotnost_dsp * w * d * tol_bok;
	double mas_dveri = plotnost_dereva * h * w * tol_dveri;

	int count_polk = floor(h / 40.5);
	double mas_polk = count_polk * plotnost_dsp * tol_polk * w * d;
	double ms = mas_bok + mas_dveri + mas_nakl + mas_polk + mas_zad;
	printf("Finish massa: %lf kg", ms / 1000.0);

}