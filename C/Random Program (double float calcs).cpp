/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <cmath>

int func(int n)
{
    if(n == 1)
        return 1;
    
    return func(n/3) + 1;
}

double fact(int n)
{
    int res = 1;
    for(int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return (double)res;
}

int main()
{
    for(int i = 1; i < 100; i++){
        printf("%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f\n", log(log((double)i)), log((double)i), log((double)fact(i)), pow((double)i, 1.1), i * log((double)i), sqrt((double)i), (double)(i * i), fact(i), fact(i+1), pow(2, (double)i), pow(3, (double)i), pow(2, (double)(i+1)));
    }

    return 0;
}
