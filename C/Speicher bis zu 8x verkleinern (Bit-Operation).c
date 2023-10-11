/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    unsigned char total_coins = 21, coins[(total_coins + 7) / 8], j = sizeof(coins);
    /*
    printf("Test Anfang\n");
    printf("%d\n", total_coins);
    printf("%d\n", sizeof(coins));
    printf("%d\n", j);
    printf("\nTest Ende\n\n");
    */
    
    for (char i = 0; i < j; i++) {
        coins[i] = (i * 2353 / 13 + i) % 256;
        printf("%d: %d // ", i, coins[i]);
    }
    
    printf("\n\nIn Bit:\n");
    unsigned char mask = 128;
    for (char i = 0; i < total_coins; i++) {
        printf("%d-%d: %d / ", i/8, i%8, coins[i/8] & mask);
        mask >>= 1;
        if (!mask) mask = 128;
        if (i%8 == 7) printf("\n");
    }
    
    printf("\n\nIst es nicht 0?\n");
    mask = 128;
    for (char i = 0; i < total_coins; i++) {
        printf("%d: %s / ", i, coins[i/8] & mask ? "ja" : "nein");
        mask >>= 1;
        if (!mask) mask = 128;
        if (i%8 == 7) printf("\n");
    }
    
    return 0;
}