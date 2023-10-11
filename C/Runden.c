#include <stdio.h>

double runden(double z, short s) {
	z += 0.0001;
	short a = s;
	while (s--) {
		z *= 10;
	}
	// if (( (int) z * 10) % 10 > 4) z++;
	z += 0.5;
	z = (int) z;
	s = a;
	while (s--) {
		z /= 10;
	}
	return z;
}

void main(){
	double x;// = 2.4738;
	short y;// = 2;
	printf("Zahl eingeben: ");
	scanf("%lf", &x);
	printf("Nachkomma-Stellen: ");
	scanf("%d", &y);
	double a = runden(x, y);
	printf("\n%f ist die gerundete (gewuenschte) Zahl.", a);
}