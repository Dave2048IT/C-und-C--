#include <stdio.h>

short length(char zk[]) {
	short i;
	for (i = 0; zk[i] != '\0'; i++);
	return i;
}

short anzahlz(char zk[], char c) {
	short i, a = 0;
	for (i = 0; zk[i] != '\0'; i++)
		if (zk[i] == c) a++;
	return a;
}

void main()
{
	char zk[21], zeichen;
	printf("Eingabe Zeichenkette: ");
	scanf("%20s", zk);
	getchar();
	fflush(stdin);
	printf("Eingabe Zeichen: ");
	scanf("%c", &zeichen);
	fflush(stdin);
	printf("Länge der Zeichenkette %i\n",length(zk));
	printf("%c kommt in %s %d mal vor",zeichen,zk,anzahlz(zk,zeichen));
	
	getchar();
}