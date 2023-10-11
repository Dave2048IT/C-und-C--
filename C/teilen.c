#include <stdio.h>

int teilen(int a, int b, int *x) {
	*x = a % b;
	return a / b;
}

int main()
{
	int a, b, x, z;
	printf("Bitte Zahlen eingeben: ");
	scanf("%d %d", &a, &b);
	z = teilen(a, b, &x);
	printf("%d / %d = %d Rest %d.", a, b, z, x);

	return 0;
}
