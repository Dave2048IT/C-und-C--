#include <stdio.h>

char* ersetzen(char* text, char s, char r) {
	char* t2 = malloc(30);
	strcpy(t2, text);
	
	char pos;
	for (pos = 0; t2[pos] != '\0'; pos++) {
		if (t2[pos] == s) t2[pos] = r;
	}
	return t2;
}

char* reverse(char* text) {
	char* t2 = malloc(30);
	strcpy(t2, text);
	
	char pos, pos2;
	for (pos = 0; text[pos] != '\0'; pos++);
	pos2 = pos - 1;
	
	while(pos--) {
		t2[pos] = text[pos2 - pos];
	}
	return t2;
}

int main()
{
	char text[30], erg[30], a, b;
	
	// Ersetzen
	printf("Bitte Text eingeben: ");
	scanf("%29s", &text);
	// fflush(stdin);
	getchar();
	
	printf("1. Zeichen eingeben: ");
	scanf("%c", &a);
	getchar();
	printf("2. Zeichen eingeben: ");
	scanf("%c", &b);
	getchar();
	
	strcpy(erg, ersetzen(text, a, b));
	printf("%s wurde zu %s.\n", text, erg);
	
	
	// Reverse
	printf("\nBitte Text eingeben: ");
	scanf("%29s", &text);
	// fflush(stdin);
	getchar();
	
	strcpy(erg, reverse(text));
	printf("%s ist umgekehrt %s.\n", text, erg);
	
	return 0;
}
