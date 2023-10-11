// David
// EBA: LK - Funktionen


#include <stdio.h>

char position(char* text, char c) {
	// int char
	char pos;
	for (pos = 0; text[pos] != '\0'; pos++) {
		if (text[pos] == c) return pos + 1;
	}
	return 0;
}

short qsumme(int a) {
	int sum = 0, b = 1, c, d;
	for (d = 0; b <= a; d++) {
		b *= 10;
	}
	while (d--) {
		c = a % b;
		b /= 10;
		sum += c/b;
	}
	// sum += a%b;
	return sum;
}

int minimum(int arr[], char n) {
	int min = arr[0];
	for (char i = 1; i < n; i++) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

char identisch(char* text1, char* text2) {
	// int char
	char pos;
	for (pos = 0; text1[pos] != '\0' || text2[pos] != '\0'; pos++) {
		if (text1[pos] != text2[pos]) return 0;
	}
	return 1;
}

int main()
{
	char text[32], text2[32] = "Test1", c, pos;
	int zahl, qs, x[4] = {394, 111, 309149, 102};
	
	// Position
	printf("Bitte Text eingeben: ");
	scanf("%31s", &text);
	// fflush(stdin);
	getchar();
	
	printf("Bitte Zeichen eingeben: ");
	scanf("%c", &c);
	pos = position(text, c);
	
	if (pos) printf("%c gefunden bei Pos. %d", c, pos);
	else printf("%c nicht gefunden.", c);
	
	// Quersumme
	printf("\n\nBitte Zahl eingeben: ");
	scanf("%d", &zahl);
	qs = qsumme(zahl);
	printf("Die Quersumme von %d ist %d.", zahl, qs);
	
	// Minimum
	zahl = minimum(x, 4);
	printf("\n\nDas Minimum ist %d.\n\n", zahl);
	
	// Identisch
	c = identisch(text, text2);
	if (c) printf("Ja, %s und %s sind gleich.", text, text2);
	else printf("Nein, %s und %s sind verschieden.", text, text2);
	
	return 0;
}
