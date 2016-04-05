#ifndef LAB2FUNCTIONS_H_INCLUDED
#define LAB2FUNCTIONS_H_INCLUDED

#include <float.h>

float inputNumber()
{
    fflush(stdin);
    int validNumberFlag;
    float numberTemp = 0;
    char inputEnd;

    validNumberFlag = scanf("%f%c", &numberTemp, &inputEnd);

    while ((!validNumberFlag)||(10 != inputEnd))
    {
        inputEnd = 10;
        printf("Invalid number\nTry again(1)\nExit(other)\n");
        int choose = -1;
        fflush(stdin);
        scanf("%i", &choose);
        switch (choose)
        {
            case 1:
                {
                    printf("Input: ");
                    validNumberFlag = scanf("%f%c",&numberTemp, &inputEnd);
                    continue;
                }
            default:
                exit(0);
        }
    }
    return numberTemp;

}

float result(float x, float r)
{
/*
    switch (1)
    {
        case (int)((x < -10 )||(x <= -8-r)):
            return FLT_MIN;
            break;
        case ((x >= -10) && (x < -6)):
            return -(sqrt(pow(r,2)-pow((x+8),2))+2);
            break;
        case ((x >= -8+r) && (x < -4) && (r <= 2)):
            return 2;
            break;
        case (x < -4 && x >= -6):
            return (-(sqrt(pow(r,2)-pow((-6+8),2))+2)/(-6))*x+2; //kx + b
            break;

        case (x <= 2 && x >= -4):
            return -0.5 * x;
            break;
        case (x <= 4 && x > 2):
            return x-3;
            break;

        case (x > 4):
            return FLT_MIN;
            break;

        case ((x < -8-r) && (r < 2)):
            return FLT_MIN;
            break;
    }
*/


        if ((x <= 2) && (x >= -4))
        {
            return -0.5 * x;
        }
        else
        {
            if ((x <= 4) && (x > 2))
            {
                return x-3;
            }
            else
            {
                if (x > 4)
                {
                    return FLT_MIN;
                }
                else
                {
                    if (r<2)
                    {
                        if (x < -8-r)
                             return FLT_MIN;
                        else
                            if ((x >= -8-r)&&(x < -8+r))
                                return -(sqrt(pow(r,2)-pow((x+8),2))+2);
                            else
                                if ((x >= -8+r)&&(x < 4))
                                    return 2;

                    }
                    else
                    {
                        if (x < -10)
                        {
                            return FLT_MIN;
                        }
                        else
                        {
                            if ((x>=-10)&&(x<-6))
                            {
                                 return -(sqrt(pow(r,2)-pow((x+8),2))+2);
                            }
                            else
                            {
                                if (x < -4 && x >= -6)
                                {
                                    return (-(sqrt(pow(r,2)-pow((-6+8),2))+2)/(-6))*x+2; //kx + b
                                }

                            }
                        }
                    }
                }
            }
        }

}

void initTableHeader (float dx)
{

    printf("|---   x    ---|---   y   ---|- dx = %f -|\n", &dx);
}



#endif // LAB2FUNCTIONS_H_INCLUDED
