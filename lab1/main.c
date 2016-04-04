#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
void main(void)
{
    int working = 1;
    while (working)
    {
           int menuItemNumber = 0;
           int validNumberEntered = 0;
           char ch1;
           printf ("Pi=%f\n", M_PI);
           fflush(stdin);
           printf("1 - Evaluate\n");
           printf("2 - Quit\n");

           validNumberEntered = scanf("%i", &menuItemNumber);

           if (!validNumberEntered)
           {
                printf("Not an integer value entered. Please, try again.\n");
                continue;
           }

           switch (menuItemNumber)
           {
                case 1:
                {
                    float arg1 = 0;
                    float result1 = 0;
                    float result2 = 0;


                    printf("Argument: ");
                    validNumberEntered = scanf("%f%c", &arg1, &ch1);

                    if (!validNumberEntered)
                    {
                        printf("Not a floating-point number was entered. Please, try again.\n");
                        continue;
                    }
                   if (ch1!=10)
                    {
                        ch1 = 10;
                        printf ("Wrong Argument\n");
                        continue;
                    }
                    result1 = (sin(2*arg1)+sin(5*arg1)-sin(3*arg1))/(cos(arg1)+1-2*(pow(sin(2*arg1),2)));
                    result2 = 2*sin(arg1);
                    printf("Result: %f\n", result1);
                    printf("Result: %f\n", result2);
                    break;
               }
          case 2:
          {
           working = 0;
           break;
          }
          default:
          {
            printf("Wrong choice, please, try again.\n");
            break;
          }

        }
    }
}







