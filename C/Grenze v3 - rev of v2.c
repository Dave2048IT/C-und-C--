#include <stdio.h>

void getBin(int num, char *str)
{
	*(str+36) = '\0';
	unsigned int mask = 0x80000000;
	unsigned char i = 0;
	// Insert leading zeros
	
	while(mask != 0) {
		*str++ = !!(mask & num) + '0';
		if ((++i & 7) == 0) {
			*str++ = ' ';
		}
		mask >>= 1;
	}
}

int main()
{
	int z1, z2, a;
	char str[37];
	printf("Bitte die 1. Zahl eingeben: ");
	scanf("%d", &z1);
	printf("Bitte die 2. Zahl eingeben: ");
	scanf("%d", &z2);
	a = z1;
	while (a < z2 + 1) {
		getBin(a, str);
		printf("\n| Dez: %d\t | Hexa: %X\t | Oct: %o\t | Bin: %s", a, a, a, str);
		a++;
	}
	if (a>z1) printf("\n\nDiese Zahlen sind zwischen %d und %d.", z1, z2);
	if (a-z1 == 1) printf("\nDazwischen ist 1 Zahl.");
	else printf("\nDazwischen sind %d Zahlen.", a-z1);
	return 0;
}
