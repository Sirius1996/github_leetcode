#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 32

int reverse(int x)
{
    int num[MAXSIZE] = {0};
    int bit = 0;
    long long newNumber = 0;
    int count = 0;

    while(x != 0)
    {
    	num[bit] = x % 10;
        x = x/10;
        bit++;
    }
    count = bit;

    for(int i = 0; i < bit; i++)
    {
        newNumber = newNumber+(num[i]*pow(10.0,count-1));
        count--;
    }

    if(newNumber>INT32_MAX||newNumber<INT32_MIN)
        return 0;

    return newNumber;

}

int main()
{
    int number = 10;
    int result = 10;
    scanf("%d", &number);
    result = reverse(number);
    printf("%d", result);

    return 0;

}
