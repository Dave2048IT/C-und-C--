#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double get_exp() { return 6.0 / 5; } // 1.2

int frequency_of(short n, short op) {
	/// char* res = {"coins", "diamonds", "tickets", "other"};
	if (!op) return n;
	int vals[] = {8500, 70, 25, 1000};
	return vals[n];
}

int calc_Price(int items, short res, short op) {
	// Die Preise in CENT !!!
	if (frequency_of(res, op) == NULL) return -1;
	
	if (items <= 0) return -2;
	int price = ceil( pow(items, 1 / get_exp() ) / frequency_of(res, op) * 100 );
	return price;
}

int calc_items(int price, short res, short op) {
	// Hier auch in CENT !!!
	if (frequency_of(res, op) == NULL) return -1;
	
	if (price <= 0) return -2;
	int items = floor( pow(price * frequency_of(res, op) / 100, get_exp() ) );
	return items;
}

int main()
{
	int itm, pri;
	short res, op;
	printf("Wie viel Wert? ");
	scanf("%hd", &res);
	printf("Option: ");
	scanf("%hd", &op);
	
	printf("\nWie viele Items? ");
	scanf("%d", &itm);
	printf("Preis: %.2lf €", (double) calc_Price(itm, res, op) / 100);
	
	printf("\nWie viel Cent? ");
	scanf("%d", &pri);
	printf("Anzahl: %d Items", calc_items(pri, res, op));

	return 0;
}
