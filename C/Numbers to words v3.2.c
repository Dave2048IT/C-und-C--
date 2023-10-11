#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is not used! But maybe for other things.
char *scat(char *s, char *t) {
	char *p = malloc (strlen(s) + strlen(t) + 1);	/* 1: you will have to reserve memory to hold the copy. */
	int ptr = 0, temp = 0;	/* 2: initialise some helpers */

	while (s[temp] != '\0') {	/* 3: use the temp to "walk" over string 1 */
		p [ptr++] = s [temp++];
	}
	temp = 0;
	while (t[temp] != '\0') {	/* and string two */
		p [ptr++] = t [temp++];
	}
	return p;
}

char* helper(short num) {
	const char *LESS_THAN_20[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	const char *TENS[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	// char a[64] = {0};
	char *a = malloc(64);

go1:
	if (num == 0)
		return a;
	else if (num < 20) {
		strcat(a, LESS_THAN_20[num]);
		strcat(a, " ");
		return a;
	}
	else if (num < 100) {
		strcat(a, TENS[num / 10]);
		strcat(a, " ");
		// strcat(a, helper(num % 10));
		num %= 10;
		goto go1;
		// return a;
	}
	else {
		strcat(a, LESS_THAN_20[num / 100]);
		strcat(a, " Hundred ");
		// strcat(a, helper(num % 100));
		num %= 100;
		goto go1;
		// return a;
	}
}

char* numberToWords(long num) {
	if (num == 0) return "Zero";

	const char *THOUSANDS[8] = {" ", "Thousand ", "Million ", "Billion ", "Trillion ", "Quadrillion ", "Quintillion ", "Sixillion "};
	char *words = malloc(251);
	
	// Check for minus sign
	if (num < 0) {
		num = -num;
		strcpy(words, "Minus ");
	}
	
	char i = 0, over1 = 0;
	long a = 1, numc = num, n2;
	
	while (a <= num) {
		// Just for safety
		if (++i > 15) {
			printf("Endless loop detected.");
			return "";
		}
		
		if (a < 0 || (a * 1000) % 1000) {
			// a = 1000000000;
			over1 = 1;
			break;
		}
		a *= 1000;
	}
	if (!over1) a /= 1000;
	
	while (a) {
		n2 = num / a;
		a /= 1000;
		i--;
		if (n2 % 1000 != 0) {
			// strcpy(words2, words);
			strcat(words, helper(n2 % 1000));
			strcat(words, THOUSANDS[i]);
		}
	}
	
	// return words.trim();
	return words;
}

int main()
{
	long num1;
	char *erg = malloc(251);
	char *unit = malloc(15);
	
	if (erg && unit) {
		printf("\n Memory is reserved\n");
	} else {
		printf("\n No free memory available: %d\n", EXIT_FAILURE);
		return EXIT_FAILURE;
	}
	
	printf("\nHello. Please enter a number: ");
	scanf("%ld", &num1);
	strcpy(erg, numberToWords(num1));
	// erg = numberToWords(num1);
	
	if (strcmp(erg, "")) {
		printf("%s", "And now the unit please: ");
		scanf("%s", unit);
		printf("\n%ld\n%s %s", num1, erg, unit);
	}
	
	free(erg);
	free(unit);
	return 0;
}
