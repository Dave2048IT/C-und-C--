#include <stdio.h>

double mittelwert(int arr[], short a)
{
	short x;
	double m = 0, i = x = a;
	while (x > 0) {
		m += arr[--x];
	}
	m /= i;
	return m;
}

void main(){
	int x[] = {3,7,9,5,10}; // = 6.8
	// 5,4,89,0,7
	double a = mittelwert(x, sizeof(x) / sizeof(x[0]));
	printf("\n%f ist der Mittelwert.", a);
	
}