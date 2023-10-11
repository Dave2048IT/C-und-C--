#include <stdio.h>

long fakultaet(int z) {
	long e;
	if(z>1)
		e=z*fakultaet(z-1);
	else
		e=1;
	return e;
}


int main()
{
	long a, b;
	printf("Bitte Zahl eingeben: ");
	scanf("%d", &a);
	b = fakultaet(a);
	printf("%d! = %d.", a, b);

	return 0;
}
