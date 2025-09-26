#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    double h, d, w1, w2 = 0;
    double pder, pdvp, pdsp = 0;
    double m1, m2, m3, m4, m5, mi = 0;
    double ch = 0; //Число полок
    const double t1 = 0.005;
    const double t2 = 0.015;
    const double t3 = 0.01;
    const double EPS = 1e-6;

    printf("Enter the Height of the back wall:\t"); //Высота задней стенки
    scanf("%lf", &h);
    while (h < 180 - EPS || h > 220 + EPS) {
        printf("Error, enter again:\t");
        scanf("%lf", &h);
    }
    
    printf("Enter the Width of the back wall:\t"); //Ширина задней стенки
    scanf("%lf", &w1);
    while (w1 < 80 - EPS || w1 > 120 + EPS) {
        printf("Error, enter again:\t");
        scanf("%lf", &w1);
    } 

    printf("Enter the Depth of the sidewall:\t"); //Глубина боковины
    scanf("%lf", &d);
    while (d < 50 - EPS || d > 90 + EPS) {
        printf("Error, enter again:\t");
        scanf("%lf", &d);
    } 
   
    printf("Enter the tree density:\t"); //Плотность дерева 
    scanf("%lf", &pder);
    while (pder < 0) {
        printf("Error, enter again:\t");
        scanf("%lf", &pder);
    } 

    printf("Enter the DSP density:\t"); //Плотность ДСП
    scanf("%lf", &pdsp);
    while (pdsp < 0) {
        printf("Error, enter again:\t");
        scanf("%lf", &pdsp);
    } 

    printf("Enter the DVP density:\t"); //Плотность ДВП
    scanf("%lf", &pdvp);
    while (pdvp < 0) {
        printf("Error, enter again:\t");
        scanf("%lf", &pdvp);
    } 

    ch = (int)(h / (40+t1*100)); //Вычисление числа полок в шкафу
    w2 = w1 * 0.5; // Ширина двери

    h = h / 100; //Перевод в метры 
    d = d / 100;
    w1 = w1 / 100;
    w2 = w2 / 100;
   
    m1 = h * w1 * t1 * pdvp;
    m2 = h * d * t2 * pdsp * 2;
    m3 = w1 * d * t2 * pdsp * 2;
    m4 = h * w2 * t3 * pder * 2;
    m5 = d * w1 * t1 * pdsp * ch;
    mi = m1 + m2 + m3 + m4 + m5;

    printf("Weight in kg:\t %lf", mi);
}

