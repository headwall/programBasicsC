#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int* initArray(int n)
{
    int i;
    int *a = (int*) malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
        a[i] = -100 + rand() % 200;
    return a;
}

int findMin(int *a, int n)
{
    int minim = abs(a[0]);
    int i, ind = 0;

    for(i = 1; i < n; i++)
    {
        if(abs(a[i]) < minim)
        {
            minim = abs(a[i]);
            ind = i;
        }
    }
    return ind;
}

int firstNull(int *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
        if(a[i] == 0) return i;
    return -1;
}

int sumAfterFirstNull(int *a, int n)
{
    int i, sum;
    int firstNullInd = firstNull(a, n);
    if(firstNullInd > 0)
    {
        for(i = firstNullInd + 1; i < n; i++)
            sum += abs(a[i]);
        return sum;
    }
    else
        return NULL;
}

int *swap(int *a, int n)
{
    int i, j, temp;
    if((n - 1) % 2 == 0)
        j = n - 1;
    else
        j = n - 2;

    for(i = 1; i < n; i = i + 2)
    {
        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j -= 2;
        }
        else
            break;
    }
    return a;
}

int *initMatrix(int n)
{
    int i, j;
    int *matrix = (int*)malloc(n * n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            int offset = i * n + j; //смещение от начала массива
            *(matrix + offset) = -100 + rand() % 200;
            printf("%3i ", *(matrix + offset));

        }
        printf("\n");
    }
    return matrix;
}

int findLocalMin(int *m, int n)
{
    int i, j, pr, kol = 0;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            pr = 0;

            if((i - 1) * n + j >= 0)
                if(*(m + i * n + j) < *(m + (i - 1) * n + j))
                    pr++;
                else;
            else
                pr++;

            if(i * n + j + 1 < n * (i + 1))
                if(*(m + i * n + j) < *(m + i * n + j + 1))
                    pr++;
                else;
            else
                pr++;

            if(((i + 1) * n + j) < n * n)
                if(*(m + i * n + j) < *(m + (i + 1) * n + j))
                    pr++;
                else;
            else
                pr++;

            if(i * n + j - 1 >= n * i)
                if(*(m + i * n + j) < *(m + i * n + j - 1))
                    pr++;
                else;
            else
                pr++;

            if(4 == pr)
            {
                kol++;
                printf("min %d\n", *(m + i * n + j));
            }
        }
    return kol;
}

int sumAbs(int *m, int n)
{
    int i, j, sum = 0;
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            sum += abs(*(m + i * n + j));
    return sum;
}

int main()
{
    int *a;
    int i, n;

    fflush(stdin);
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");

    printf("Введите размер массива: ");
    while (!scanf("%d", &n))
        printf("Wrong");

    a = initArray(n);

    for(i = 0; i < n; i++)
        printf("%i ", a[i]);
    printf("\n");

    int ind = findMin(a, n);

    printf("Минимальный по модулю элемент = %i\n", a[ind]);

    int sum = sumAfterFirstNull(a, n);
    if(NULL != sum)
        printf("Cумма модулей элементов, расположенных после первого элемента, равного нулю = %i\n", sum);
    else
        printf("Массив не содержит нулей\n");

    a = swap(a, n);
    for(i = 0; i < n; i++)
        printf("%i ", a[i]);

    free(a);

    printf("\n\n");
    int *m = initMatrix(n);

    int kolLocalMin = findLocalMin(m, n);
    int sumOverMainD = sumAbs(m, n);
    printf("Количество локальных минимумов = %i\n", kolLocalMin);
    printf("Cумма модулей элементов, расположенных выше главной диагонали = %i\n", sumOverMainD);

    free(m);
    return 0;
}
