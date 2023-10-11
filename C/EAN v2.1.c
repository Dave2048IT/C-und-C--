// Von David
// Ein Programm zum Prüfen von Kreditkarten-Nummern


#include <stdio.h>

int main() {
	char z[17], part2;
	// char ints
	unsigned char part1 = part2 = 0, erg, i;
	printf("Bitte Kreditkarten-Nummer eingeben: ");
	scanf("%16s", &z);
	for (i = 0; z[i + 1] != '\0'; i++) {
		if (z[i] < 48 || z[i] > 57) {
			printf("Das ist keine Zahl!\n");
			break;
		}
		
		if (i % 2 == 0) {
			part1 += (z[i] - 48) * 2;
			if (z[i] - 48 > 4) part1 -= 9;
		}
		else part2 += (z[i] - 48);
	}
	erg = part1 + part2;
	erg %= 10;
	if (erg > 0) erg = 10 - erg;
	if (erg == z[i] - 48) printf("Die Nummer ist richtig.");
	else printf("Die Nummer ist falsch.");
}
