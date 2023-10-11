#include <stdio.h>

int ggt(int z1, int z2)
{
    int a = z1;
    if (z1 == 0 || z2 == 0) {
        printf("Berechnung nicht moeglich!\n");
        return -1;
    }
	
	while (z1 % a || z2 % a) {
		a--;
		if (a < 2) return 1;
	}
    /*
	if (z1 < z2) {
        a = z2;
        while (z1 % a) a += z2;
    } else {
        a = z1;
        while (z2 % a) a += z1;
    }
	*/
    return a;
}

double potenzieren(int B, int E) {
    double P = 1;
    int A = E;
    if (B == 0 && E != 0) P = 0;
    if (E > 0) {
    	while (A > 0) {
    		P *= B;
    		A--;
    	}
    } else if (E < 0) {
    	while (A < 0) {
    		P /= B;
    		A++;
    	}
    }
    return P;
}

void main()
{
	int zahl1, zahl2;
	printf("Eingabe Zahl1: ");
	scanf("%i", &zahl1);
	fflush(stdin);
	printf("Eingabe Zahl2: ");
	scanf("%i", &zahl2);
	fflush(stdin);
	
	printf("\nGroesster gemeinsamer Teiler: %d", ggt(zahl1, zahl2));
	printf("\n%i hoch %i = %lf", zahl1, zahl2, potenzieren(zahl1, zahl2));
	getchar();
}