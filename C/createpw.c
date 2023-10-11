#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createpw(char* pw) {
	char c, nums = 0, i = 0, min = 33, max = 126;
	while (i < 8) {
		// check = 0;
		while (1) {
			c = rand() % (max - min + 1) + min;
			if (c >= '0' && c <= '9') {
				if (nums < 2) { // bleibe auf 2 Ziffern
					nums++;
					break;
				}
			}
			else if (i - 6 < nums) break; // erhoehe auf 2 Ziffern
		}
		pw[i] = c;
		i++;
	}
	pw[i] = '\0';
}

void main()
{
	char pw[9];
	srand(time(NULL));
	createpw(pw);
	printf("\nDas generierte Passwort ist: %s", pw);
	printf("\nin ASCII: \n");
	for (char i = 0; i < 8; i++) {
		printf("%d\n", pw[i]);
	}
	
	getchar();
}
