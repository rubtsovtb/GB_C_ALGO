#include <stdio.h>

//для перестановки значений
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//для задания 1
//выводим данные массива
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("Array val: %d\n", arr[i]);
    printf("\n");
}

//быстрая сортировка с медианой
void qsMedian(int *arr, int first, int last)
{
    int i = first;
    int j = last;


    //выбираем медиану
    int x = arr[(first+last)/2];
    int iX = arr[first];
    int jX = arr[last];

    if ((x>iX && x<jX) || (x<iX && x>jX))
    {
        //сразу выбрали нужное значение
        x=x;
    }
    else if ((iX>x && iX<jX) || (iX<x && iX>jX))
    {
        x = iX;
        swap(&arr[iX],&arr[(first+last)/2]);
    }
    else
    {
        x = jX;
        swap(&arr[jX],&arr[(first+last)/2]);
    }


    do
    {
        //ищем номер значений. не удовлетворяющих условиям
        while(arr[i] < x)
        {
            i++;
        }
        while(arr[j] > x)
        {
            j--;
        }

        if(i<=j)
        {
            swap(&arr[i],&arr[j]);
            i++;
            j--;
        }
    } while(i<=j);
    if(i<last)
    {
        qsMedian(arr,i,last);
    }
    if(first<j)
    {
        qsMedian(arr,first,j);
    }
}

//сортировка вставками
void sortIserts(int* arr, int len)
{
    int temp, pos;
    for(int i=1;i<len;++i)
    {
        temp=arr[i];
        pos=i-1;
        while(pos>=0&&arr[pos]>temp)
        {
            arr[pos+1]=arr[pos];
            pos--;
        }
        arr[pos+1]=temp;
    }
}

//выбор подходящего метода
void selectSortMethod(int *arr, int first, int arrSize)
{
    if (arrSize>10)
    {
        qsMedian(arr, 0, arrSize - 1);
        printf("Method selected: qsMedian\n");
    }
    else
    {
        sortIserts(arr, arrSize);
        printf("Method selected: sortInsert\n");
    }
}

int main()
{
    //задание 1
    int arr[] = {10, 9, 1, 92, 1, 9, 3, 3, 6, 9, 3, 5, 6};
    //получаем размер массива
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    selectSortMethod(arr, 0, arrSize);
    printf("Sorted array: \n");
    printArray(arr, arrSize);
    return 0;
}