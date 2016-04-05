#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "lab2Functions.h"

int working = 1;
int main()
{
    int w = 1;
    int m = 0;
    while (w)
    {

        printf("1-Calculate\n0-Exterminate\n");
        fflush(stdin);
        int v = scanf("%i", &m);
        switch (m)
        {
            case 1:
            {
                float x1 = 0;
                float x2 = 0;
                float dx = 0;
                float r = 0;
                int choose=1;
                    printf("r = ");
                    r  = inputNumber();
                    while (r <= 0)
                    {
                        printf("r must be greater than 0\nTry again(1)\nExit (other)\n");

                        scanf("%f", &choose);
                        switch(choose)
                        {
                            case 1:
                                {
                                    printf("Input: ");
                                    inputNumber();
                                    break;
                                }
                            default:
                                exit(0);

                        }
                    }
                    printf("x1 = ");
                    x1 = inputNumber();
                    printf("x2 = ");
                    x2 = inputNumber();

                    while ((x2 < x1))
                    {
                        printf("x2 must be greater than x1\nTry again(1)\nExit (other)\n");

                        scanf("%f", &choose);
                        switch(choose)
                        {
                            case 1:
                                {
                                    printf("Input: ");
                                    x2 = inputNumber();
                                    break;
                                }
                            default:
                                exit(0);

                        }
                    }
                    printf("dx = ");
                    dx = inputNumber();
                    while (dx <= 0)
                    {
                        printf("dx must be greater than 0\nTry again(1)\nExit (other)\n");

                        scanf("%f", &choose);
                        switch(choose)
                        {
                            case 1:
                                {
                                    printf("Input: ");
                                    inputNumber();
                                    break;
                                }
                            default:
                                exit(0);

                        }
                    }

                float fooResult;
                float xCurrent = x1;
                initTableHeader(dx);
                do
                {
                    fooResult = result(xCurrent, r);
                    if (FLT_MIN == fooResult)
                        printf("|___%8.4f___|___Not exist___|\n", xCurrent);
                    else
                        printf("|___%8.4f___|___%9.4f___|\n", xCurrent, fooResult);
                    xCurrent += dx;
                }while (xCurrent <= x2);
                break;
            }
            default:
            {
                w = 0;
                break;
            }
        }

    }
}

