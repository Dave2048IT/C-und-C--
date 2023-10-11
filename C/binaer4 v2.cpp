//Ausgabe von kompletten Byteblöcken
#include <stdio.h>

void main()
{
    unsigned int zahl;
    unsigned char i, rest, binaer[32];
    printf("\tProgramm zum Umwandeln von Dezimal- in Binaerzahlen");
    printf("\n\nEingabe Dezimalzahl: ");
    scanf("%d", &zahl);
    fflush(stdin);
    for (i = 0; zahl != 0 || i == 0 || (i&7) != 0; i++)
    {
        rest = zahl & 1;
        zahl >>= 1;
        binaer[i] = rest;
    }
    printf("Binaerzahl: ");
    for (i--; i != 255; i--)
    {
    	printf("%i", binaer[i]);
    	if ((i & 7) == 0)
    		printf(" ");
    }
    getchar();
}
