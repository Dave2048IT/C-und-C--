#include <stdio.h>

short cross_sum(int a) {
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

int main()
{
	printf("Hello World\n");
	int a;
	scanf("%d", &a);
	printf("Quersumme: %d", cross_sum(a));

	return 0;
}
