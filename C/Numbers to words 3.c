#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *scat(char *s, char *t) {
	char *p = malloc (strlen(s) + strlen(t) + 1);	/* 1: you will have to reserve memory to hold the copy. */
	int ptr = 0, temp = 0;	/* 2: initialise some helpers */

	while (s[temp] != '\0') {	/* 5: use the temp to "walk" over string 1 */
		p [ptr++] = s [temp++];
	}
	temp = 0;
	while (t[temp] != '\0') {	/* and string two */
		p [ptr++] = t [temp++];
	}
	return p;
}

char* helper(int num) {
	const char *LESS_THAN_20[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	const char *TENS[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	// char a[32] = {0};
	char *a = malloc(60);

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

char* numberToWords(int num) {
	if (num == 0) return "Zero";

	const char *THOUSANDS[4] = {" ", "Thousand ", "Million ", "Billion "};
	char *words = malloc(251);
	
	// Check for minus sign
	if (num < 0) {
		num = -num;
		strcpy(words, "Minus ");
	}
	int i = 0, numc = num, n2;
	for (int a = 1; a < num; a *= 1000, i++);
	
	while (num > 0) {
		n2 = numc / num;
		if (n2 % 1000 != 0) {
			// strcpy(words2, words);
			strcat(words, helper(n2 % 1000));
			strcat(words, THOUSANDS[--i]);
		}
		num /= 1000;
	}
	
	// return words.trim();
	return words;
}

int main()
{
	int num1 = -1234;
	char* erg = numberToWords(num1);
	printf("Hello World.");
	printf("\n\n%s", erg);
	// free(erg);
	return 0;
}
