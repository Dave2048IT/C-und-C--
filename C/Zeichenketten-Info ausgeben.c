#include <stdio.h>

int main()
{
	char i, mi, gc, kc, misc[51], s[51];
	i = mi = gc = kc = 0;
	printf("Bitte Zeichenkette eingeben: ");
	// scanf("%50s", &s);
	fgets(s, 50, stdin);
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') gc++;
		else if (s[i] >= 'a' && s[i] <= 'z') kc++;
		else { misc[mi] = s[i]; mi++; }
	}
	// i--;
	s[--i] = '\0';
	misc[--mi] = '\0';
	
	// printf("\nEingebeben: %s\n", s);
	printf("Anzahl Grossbuchstaben: %d\n", gc);
	printf("Anzahl Kleinbuchstaben: %d\n", kc);
	printf("Sonstige Zeichen: %s\n", misc);
	
	return 0;
}
