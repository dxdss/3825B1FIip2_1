#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Density in kg/m3
const int densityDsp = 680;
const int densityDvp = 820;
const int densityTree = 740;

//Thickness in m
const double thicknessDvp = 0.005;
const double thicknessDsp = 0.015;
const double thicknessTree = 0.001;
const double thicknessShelf = 0.005;

const double maxHeight = 220;
const double minHeight = 180;
const double maxDepth = 90;
const double minDepth = 50;
const double maxWidth = 120;
const double minWidth = 80;


int validateValue(double value, double min, double max) {
    if (value < min || value > max) {
        printf("Error: the value should be between %.0f and %.0f cm\n", min, max);
        return -1;
    }
    return 0;
}


int main() {
    double h, d, w;
    double totalMass = 0;

    printf("Enter the height h (%.0f-%.0f cm):\n", minHeight, maxHeight);
    scanf("%lf", &h);
    if (validateValue(h, minHeight, maxHeight) < 0)
    {
        return 1;
    }

    printf("Enter the depth d (%.0f-%.0f cm):\n", minDepth, maxDepth);
    scanf("%lf", &d);
    if (validateValue(d, minDepth, maxDepth) < 0)
    {
        return 1;
    }

    printf("Enter the width w (%.0f-%.0f cm):\n", minWidth, maxWidth);
    scanf("%lf", &w);
    if (validateValue(w, minWidth, maxWidth) < 0)
    {
        return 1;
    }

    h /= 100;
    d /= 100;
    w /= 100;

    //The masses
    //The back wall is made of DVP
    double backMass = h * thicknessDvp * w * densityDvp;
    totalMass += backMass;
    //Two sidewalls made of DSP
    double sidewallsMass = (h * d * thicknessDsp * densityDsp) * 2;
    totalMass += sidewallsMass;
    //Top and lower caps made of DSP
    double topLowerMass = (thicknessDsp * d * w * densityDsp) * 2;
    totalMass += topLowerMass;
    //two doors made of tree
    double doorsMass = h * thicknessTree * w * densityTree;
    totalMass += doorsMass;
    //internal shelves made of DSP
    int shelfCount = (h / 0.4) - 1;
    double shelvesMass = (d * thicknessShelf * w * densityDsp) * shelfCount;
    totalMass += shelvesMass;

    printf("Back wall: %.2f kg\n", backMass);
    printf("Sidewalls: %.2f kg\n", sidewallsMass);
    printf("Top and lower covers: %.2f kg\n", topLowerMass);
    printf("Doors: %.2f kg\n", doorsMass);
    printf("Shelves: %.2f kg\n", shelvesMass);
    printf("Total weight of the cabinet: %.2f kg\n", totalMass);
    return 0;
}