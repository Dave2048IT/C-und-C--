#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define m_types 15
#define note_pos 8

// global variables


int calc_cash(int height_arr[], unsigned short mobjects[]) {
	int sum = 0;
	for (char i = 0; i < m_types; i++) {
		sum += height_arr[i] * mobjects[i];
		printf("%d * %d = %d\n", height_arr[i], mobjects[i], height_arr[i] * mobjects[i]);
	}
	return sum;
}

int main() {
	unsigned short mobjects[m_types]; // money objects (coins and notes)
	int height_arr[m_types];
	printf("Okjekte: \n");
	// Preparing
	for (unsigned short i = 0, v = 1; i < m_types; i++) {
		mobjects[i] = v;
		if (i % 3 == 1) v = v/2 * 5;
		else v *= 2;
		printf(" | %d", mobjects[i]);
		height_arr[i] = rand() % 13;
	}
	
	// Main functions
	printf("\n");
	printf("Geld: %d ct.", calc_cash( height_arr, mobjects ) );
	printf("\nOkay: %d\n", 1);

	return 0;
}