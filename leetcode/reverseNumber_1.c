#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 32

int reverse(int x)
{
    int num[32] = {0};
    int remain = 0;
    int provider;
    int bit = 0;
    long long newNumber = 0;
    int count = 0;
    int flag = 0;
    int res;

    if(x < 0)
    {
        provider = -x;
        flag=1;
    }

    while(provider != 0)
    {
    	remain = provider % 10;
        provider = provider/10;
        num[bit] = remain;
        bit++;
    }
    count = bit;

    for(int i = 0; i < bit; i++)
    {
        newNumber = newNumber+(num[i]*pow(10.0,count-1));
        count--;
    }

    if(newNumber>INT32_MAX)
        return 0;
        
    if(flag==1)
        return -newNumber;
    else
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
