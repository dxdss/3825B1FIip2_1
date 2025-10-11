#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    const double plDSP = 650.0;
    const double plDVP = 1000.0;
    const double plwood = 520.0;
    double h, d, w;

    printf("Enter height h (cm): ");
    scanf("%lf", &h);
    while (h < 180 || h > 220) {
        printf("Height must be 180 - 220 cm. Please try again.\n");
        printf("Enter height h (cm): ");
        scanf("%lf", &h);
    }

    printf("Enter depth d (cm): ");
    scanf("%lf", &d);
    while (d < 50 || d > 90) {
        printf("Depth must be 50 - 90 cm. Please try again.\n");
        printf("Enter depth d (cm): ");
        scanf("%lf", &d);
    }

    printf("Enter width w (cm): ");
    scanf("%lf", &w);
    while (w < 80 || w > 120) {
        printf("Error: Width must be between 80 - 120 cm. Please try again.\n");
        printf("Enter width w (cm): ");
        scanf("%lf", &w);
    }

    h = h / 100.0;
    d = d / 100.0;
    w = w / 100.0;

    double dvpwall = h * w * 0.005 * plDVP;

    double bok = h * d * 0.015 * plDSP * 2;

    double verh = w * d * 0.015 * plDSP * 2;

    double doors = h * (w / 2.0) * 0.01 * plwood * 2;

    int count = (int)(h / 0.4);
    double polki = w * d * 0.005 * plDSP * count;

    double mass = dvpwall + bok + verh + doors + polki;
    printf("Wardrobe mass is %f kg\n", mass);
}