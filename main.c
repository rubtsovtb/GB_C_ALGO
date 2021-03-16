#include <stdio.h>
//задаём функцию для проверки числа на простоту
int isPrime(int n)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main() {
    int checkPrime;
    printf("Input value to test primality");
    scanf("%d", &checkPrime);
    printf("Your integer is prime (1 - Yes), (0 - No). Answer: %d\n", isPrime(checkPrime));
    return 0;
}
