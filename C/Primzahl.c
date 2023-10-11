#include <stdio.h>
#include <math.h>

char isprim(int n) {
	if (n < 2) return -1;
	else if (n % 2 == 0) return 0;
	else if (n == 2) return 1;
	register int t, n2;
	n2 = sqrt(n) + 1;
	for (t = 3; t < n2; t+=2) {
		if (n % t == 0) return 0; // oder t
	}
	return 1; // oder 0
}

int main()
{
	int z, x;
	printf("Bitte Zahl eingeben: ");
	scanf("%d", &x);
	z = isprim(x);
	if (z == -1) printf("Ungueltige Zahl!");
	else if (z) printf("Ja, %d ist eine Primzahl.", x); // !z
	else printf("Nein, %d ist keine Primzahl.", x);

	return 0;
}
