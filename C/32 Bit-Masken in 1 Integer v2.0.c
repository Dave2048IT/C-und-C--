#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int total_coins = 65, i, j = (total_coins + 31) / 32, mask = 1, coins[j];
	/*
	printf("Test Anfang\n");
	printf("%d\n", total_coins);
	printf("%d\n", sizeof(coins));
	printf("%d\n", j);
	printf("\nTest Ende\n\n");
	*/
	
	for (i = 0; i < j; i++) {
		coins[i] = (2 - i) * 55 + 12;
		printf("%d: %d // ", i, coins[i]);
	}
	
	printf("\n\nIn Bit:\n");
	for (i = 0; i < total_coins; i++) {
		printf("%d-%d: %d / ", i/32, i%32, coins[i/32] & mask);
		if (i%32 != 31) mask <<= 1;
		else mask = 1;
		if (i%8 == 7) printf("\n");
	}
	
	printf("\n\nIst es nicht 0?\n");
	mask = 1;
	for (i = 0; i < total_coins; i++) {
		printf("%d: %s / ", i, coins[i/32] & (1 << (i%32)) ? "ja" : "nein");
		if (i%8 == 7) printf("\n");
	}
	
	return 0;
}