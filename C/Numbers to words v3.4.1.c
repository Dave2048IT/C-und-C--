#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ----------------------------------------------------------------------- */
/*
  Easy embeddable cross-platform high resolution timer function. For each 
  platform we select the high resolution timer. You can call the 'ns()' 
  function in your file after embedding this. 
*/
#include <stdint.h>
#if defined(__linux)
#  define HAVE_POSIX_TIMER
#  include <time.h>
#  ifdef CLOCK_MONOTONIC
#     define CLOCKID CLOCK_MONOTONIC
#  else
#     define CLOCKID CLOCK_REALTIME
#  endif
#elif defined(__APPLE__)
#  define HAVE_MACH_TIMER
#  include <mach/mach_time.h>
#elif defined(_WIN32)
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#endif
static uint64_t ns() {
  static uint64_t is_init = 0;
#if defined(__APPLE__)
	static mach_timebase_info_data_t info;
	if (0 == is_init) {
	  mach_timebase_info(&info);
	  is_init = 1;
	}
	uint64_t now;
	now = mach_absolute_time();
	now *= info.numer;
	now /= info.denom;
	return now;
#elif defined(__linux)
	static struct timespec linux_rate;
	if (0 == is_init) {
	  clock_getres(CLOCKID, &linux_rate);
	  is_init = 1;
	}
	uint64_t now;
	struct timespec spec;
	clock_gettime(CLOCKID, &spec);
	now = spec.tv_sec * 1.0e9 + spec.tv_nsec;
	return now;
#elif defined(_WIN32)
	static LARGE_INTEGER win_frequency;
	if (0 == is_init) {
	  QueryPerformanceFrequency(&win_frequency);
	  is_init = 1;
	}
	LARGE_INTEGER now;
	QueryPerformanceCounter(&now);
	return (uint64_t) ((1e9 * now.QuadPart)  / win_frequency.QuadPart);
#endif
}
/* ----------------------------------------------------------------------- */

// scat is not used! But maybe for other things.
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

	const char *THOUSANDS[7] = {" ", "Thousand ", "Million ", "Billion ", "Trillion ", "Quadrillion ", "Quintillion "};
	char *words = malloc(251);
	char *words2 = NULL;
	
	// Check for minus sign
	if (num < 0) {
		num = -num;
		strcpy(words, "Minus ");
	}
	
	unsigned char i = 0, over1 = 0;
	long a = 1, n2;
	
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
			words2 = helper(n2 % 1000);
			strcat(words, words2);
			strcat(words, THOUSANDS[i]);
		}
	}
	
	free(words2);
	for (i = 0; words[i] != '\0'; i++);
	i -= 2;
	words[i] = '\0';
	return words;
}

int main()
{
	double seconds, end, start;
	
	long num1;
	char *erg = NULL, *unit = malloc(15);
	
	if (unit) {
		printf("\n Memory is reserved\n");
	} else {
		printf("\n No free memory available: %d\n", EXIT_FAILURE);
		return EXIT_FAILURE;
	}
	
	printf("\nHello. Please enter a number: ");
	scanf("%ld", &num1);
	printf("%s", "And now the unit please: ");
	scanf("%s", unit);
	
	start = ns();
	erg = numberToWords(num1);
	
	if (num1 == 0x7FFFFFFFFFFFFFFF) printf("Maximum of Int64.\n");
	else if (num1 == -0x8000000000000000) printf("Minimum of Int64.\n");
	
	if (strcmp(erg, "")) {
		printf("\n%ld\n%s %s", num1, erg, unit);
	}
	
	free(erg);
	free(unit);
	
	end = ns();
	seconds = (end - start) / 1000000000;
	printf ("\n\nThis program took %lf seconds (%lf micro seconds) to run.\n", seconds, seconds * 1000000);
	return 0;
}
