#include <stdio.h>
#include <string.h>
#include <limits.h>

int check_prize(int* i, int p) {
	if (*i >= -p) {
		*i += p;
		printf("\nDu hast noch %d übrig.", *i);
	} else {
		printf("\nDir fehlen noch %d.", -p-(*i));
	}
	// return i;
}

int check_max32reward(int* i, int r) {
	if (*i + r < 0) {
		*i = INT_MAX;
	} else {
		*i += r;
	}
	char *i2 = (char *) malloc(10);
	strcpy(i2, "");
	// sprintf(i2, "%d", *i);
	if (*i == INT_MAX) strcpy(i2, ": Maximum"); // i2 = i + ": Maximum";
	printf("\nDu hast jetzt %d%s.", *i, i2);
	
	// return i;
}

void check_values(int* i, int val) {
	if (val < 0) check_prize(i, val);
	else if (val > 0) check_max32reward(i, val);
}

int main() {
	printf("Hello World und %d\n\n", INT_MAX);
	int coins = 0, diamonds = 0, value;
	char ans, weiter;
	
	do {
	/*
	printf("1: Plus\n"
	"2: Minus\n"
	"0: Beenden -> ");
	scanf("%c", &ans);
	if (ans == '1') {
	*/
	printf("1: Münzen\n"
	"2: Diamanten \n"
	"anderes: Beenden -> ");
	scanf("%c", &ans);
	
	printf("Wert Inc/Dec: ");
	scanf("%d", &value);
	
	if (ans == '1') check_values(&coins, value);
	else if (ans == '2') check_values(&diamonds, value);
	// }
	printf("\nMünzen: %d | Diamanten: %d", coins, diamonds);
	printf ("\nWeiter? y: ");
	getchar();
	scanf ("%c", &ans);
	getchar();
	
	} while (ans == 'y');
	printf("Frohes Schaffen. Na?");

	return 0;
}