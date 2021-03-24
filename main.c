#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//честно возьмём материалы урока
#include "utils.h"

//для задания 1
//сортируем двумерный массив
void bubbleSort2d(int* arr, int rows, int cols)
{
    int counter=0;
    int arrSize = rows*cols;
    //для хранения временной переменной
    for (int i = 0; i<(arrSize-1) ; i++)
    {
        for (int j = 0; j<(arrSize-i-1); j++)
        {
            if((*(arr+j))>(*(arr+j+1)))
            {
                swapInt((arr+j),(arr+j+1));
            }
            //считаем количество циклов (интереса ради)
            counter++;
        }
    }
    printf("Cycles done: %d\n", counter);
}

//выводим наше творчество
void printArray(int* arr, int rows, int cols)
{
    for (int i = 0; i<rows ; i++)
    {
        for (int j = 0; j<cols; j++)
        {
            printf("%d\n",*((arr+i*rows)+j));
            //для экспериментов с указателями
            //printf("j: %d\n", j);
            //printf("test: %d\n", *((arr+0)+6));
        }
    }
}

//для задания 3
double tpkCalc(double t)
{
    return sqrt(fabs(t)) + 5 * pow(t, 3);
}

//сама функция TPK
void tpkFunc()
{
    double a[11], res;
    for (int i = 0; i < 11; i++)
    {
        printf("Step: %d out of 11. Type your random number:\n", (i+1));
        scanf("%lf", &a[i]);
    }

    for (int i = 10; i >= 0; i--)
    {
        res = tpkCalc(a[i]);
        if (res > 400)
            printf("The calculation result is too large. Step: %d\n", i);
        else
            printf("Step: %d Calculation value is: %lf\n", i, res);
    }
}
int main()
{
    //задание 1
    int inArray[3][3]={{1,9,2},{5,7,6},{4,3,8}};
    //определяем размеры массива
    int arraySize = sizeof(inArray)/sizeof(inArray[0][0]);
    int arrayDim1 = sizeof(inArray)/sizeof(inArray[0]);
    int arrayDim2 = arraySize/arrayDim1;

    printf("The new value is: %d\n", arraySize);
    printf("Unsorted Array:\n");
    printArray((int*)inArray, arrayDim1, arrayDim2);
    bubbleSort2d((int*)inArray, arrayDim1, arrayDim2);
    printf("Sorted Array:\n");
    printArray((int*)inArray, arrayDim1, arrayDim2);

    //задание 2 выполнено на PantUML
    //задание 3.
    tpkFunc();

    return 0;

}