#include <stdio.h>

//Для задания 1
void printBinary(unsigned a)
{
    if (a != 0)
    {
        printBinary(a / 2);
    }
    else
    {
        printf("%d", 0);
        return;
    }
    printf("%d", a % 2);
    return;
}

//Для задания 2
int toPower(int a, int b)
{
    int res = a;
    for(int i=1; i < b; i++)
    {
        res = res*a;
    }
    return res;
}

//Для задания 3
int toPower1(int a, int b)
{
    if (b != 0)
        return (a * toPower1(a, b - 1));
    else
        return 1;
}

//Для задания 4
int toPower2(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return toPower2(a, b - 1) * a;
    else
    {
        int c = toPower2(a, b / 2);
        return c * c;
    }
}

int main()
{
    //Задание 1
    unsigned toBinary;
    printf("Enter your positive integer\n");
    scanf("%d", &toBinary);
    printf("The result is:\n");
    printBinary(toBinary);
    printf("\n");

    //Задание 2,3,4
    int a = 9;
    int b = 5;
    printf("The result of power raising 1 is: %d\n", toPower(a, b));
    printf("The result of power raising 2 is: %d\n", toPower1(a, b));
    printf("The result of power raising 3 is: %d\n", toPower2(a, b));

    //Задание 5

    return 0;
}
