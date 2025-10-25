#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    printf("select mode:\n");
    printf("mode 1: The program makes up a random number\n");
    printf("mode 2: The user guesses a number\n");
    char r;
    while (1)
    {
        scanf("%c", &r);
        if (r == '1' || r == '2')
        {
            break;
        }
        printf("incorrect\n");
        while (getchar() != '\n');
    }
    if (r == '1')
    {
        srand(time(NULL));
        int q = rand() % 1000 + 1;
        int k = 0;
        int g;
        printf("enter the guesses in the range from 1 to 1000\n");
        do {
            while (1)
            {
                if (scanf("%d", &g) == 1) {
                    if ((g >= 1) && (g <= 1000))
                    {
                        break;
                    }
                    printf("incorrect!\n");
                }
                else {
                    printf("incorrect!\n");
                    while (getchar() != '\n');
                }
            }
            if (g > q)
            {
                printf("the hidden number is smaller.\n");
                k = k + 1;
            }
            else if (g < q)
            {
                printf("the hidden number is bigger.\n");
                k = k + 1;
            }
        } while (q != g);
        printf("you found\n");
        printf("number of attempts = %d", k + 1); // + одна верная попытка
    }
    else if (r == '2')
    {
        srand(time(NULL));
        int k = 0;
        printf("guess a number from 1 to 1000\n");
        int g;
        g = rand() % 1000 + 1;
        int min = 0, max = 1001;
        char z[2];
        do {
            printf("%d\n", g);
            scanf("%s", &z);
            if (z[0] == '<')
            {
                min = g;
                g = min + ((max - min) / 2);
                k = k + 1;
            }
            else if (z[0] == '>')
            {
                max = g;
                g = min + ((max - min) / 2);
                k = k + 1;
            }
            else if (z[0] == '=')
            {
                printf("i found\n");
                printf("number of attempts = %d", k + 1); // + одна верная попытка
                break;
            }
            else
            {
                printf("incorrect\n");
            }
        } while (1);
    }
}