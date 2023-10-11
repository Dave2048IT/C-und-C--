#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Global variables
char romZiff[8] = "IVXLCDM";
char sc = '$'; // special char


char romIndex(char c) {
    for (char i = 0; i < 7; i++) {
		if (c == romZiff[i]) return i;
	}
	return -1;
}

char* cap(char* t) {

	// Convert to upper case
	char *s = t;
	while (*s) {
		*s = toupper((unsigned char) *s);
		s++;
	}
	return t;
}

char* dec2rom(int dec) { // char *romZiff
	if (dec < 0) return "(Negativ nicht verfuegbar)";
	else if (dec == 0) return "(Leer)";

	char tmp[64], ziffer = 0, cnums, total_i = 0;
	char *rom = (char *) malloc(64);
	short nums[4];
	int i = dec;

	while (i) {
		nums[ziffer] = i % 1000;
		i /= 1000;
		ziffer++;
	}
	cnums = ziffer;

	int j = 0;
	for ( ; j < cnums; j++) {
		dec = nums[j];
		int index = 0;
		for ( ; dec > 0; index += 2) {
			ziffer = dec % 10;
			i = 0;
			if (ziffer == 4) {
				tmp[i++] = romZiff[index];
				tmp[i++] = romZiff[index+1];
			}
			else if (ziffer == 9) {
				tmp[i++] = romZiff[index];
				tmp[i++] = romZiff[index+2];
			}
			else {
				if (ziffer > 4) {
					tmp[i++] = romZiff[index+1];
					ziffer -= 5;
				}
				for ( ; ziffer > 0; ziffer--)
					tmp[i++] = romZiff[index];
			}

			tmp[i] = '\0';
			dec /= 10;
			// rom = tmp + rom;
			strcat(tmp, rom);
			strcpy(rom, tmp);
			total_i += i;
		}

		i = 0;
		if (cnums - j > 1) {
			tmp[i++] = ' ';
			tmp[i++] = sc;

			if (nums[j + 1]) tmp[i++] = ' ';
			tmp[i] = '\0';
			strcat(tmp, rom);
			strcpy(rom, tmp);
			total_i += i;
		}
		rom[total_i] = '\0';
	}

	return rom;
}

char check_rom(char* rom) {
	// Prüfen von IVXLCDM.
	char c2, i2, valid = 1;
	for (char i = 0; rom[i] != '\0'; i++) {
		// c2 = rom[i + 1];
		
		// NUL?
		/*
		for (i2 = 0; i2 < 3; i2++) {
			if (rom[i + i2] == '\0') break;
		}
		if (i2 < 3) continue;
		*/
		// 2+ 5er
		if (romIndex(rom[i]) % 2 == 1 &&
		rom[i] == rom[i + 1]) return 0;
		// 2+ kleinere Indexe
		if (romIndex(rom[i]) <= romIndex(rom[i + 1]) &&
		romIndex(rom[i + 1]) < romIndex(rom[i + 2]) ) {
			// valid = 0;
			return 0;
		}
		// 4+ gleiche
		for (i2 = 0; i2 < 4; i2++) {
			if (rom[i + i2] != rom[i]) break;
		}
		if (i2 == 4) return 0;
		
		// if (!valid) return 0;
	}
	return 1;
}

int rom2dec(char* rom) { // char *romZiff
	if (!check_rom(rom)) {
		// printf("Folge ungueltig!\n");
		return -2;
	}
	
	int dec = 0, lastVal, romWert, curVal;
	char ziffern[64], mark[2], *token, rl, i, i2 = 0, i3 = 0;
	mark[0] = sc;
	mark[1] = '\0';

	strcpy(ziffern, cap(rom));
	token = strtok(ziffern, mark);

	rl = sizeof(romZiff) - 1;
	// for (int sc_wert = 1; token != NULL; sc_wert *= 1000) {
	while (token != NULL) {
		dec *= 1000;
		lastVal = 0;

		// Find the right chars
		for (i = i2; ziffern[i] != '\0'; i++);
		i--;
		i2 = i + 2;

		for ( ; i >= i3; i--) {
			curVal = 0;
			romWert = 1;
			int j = 0;
			for ( ; j < rl; j++) {
				if (ziffern[i] == romZiff[j]) {
					curVal = romWert;
					break;
				}
				romWert = j%2 ? romWert*2 : romWert*5;
			}
			if (curVal == 0 && ziffern[i] != '_' && ziffern[i] != sc)
				return -1;
			if (curVal >= lastVal)
				dec += curVal;
			else
				dec -= curVal;
			lastVal = curVal;
		}
		i3 = i2;
		token = strtok(NULL, mark);
	}

	return dec;
}

char* tsep(int num) {
	// char *str[14];
	char total_i, i, j, len, seps, sepl = 3, *str = (char *) malloc(15);
	sprintf(str, "%d", num);

	for (i = 0; str[i] != '\0'; i++);
	total_i = i;
	len = i;
	seps = (i - 1) / sepl;

	for (i = len - sepl; i > 0; i -= sepl) {
		for (j = sepl; j--;) {
			str[i+j + seps] = str[i+j];
		}
		str[i + --seps] = '.';
		total_i++;
		// seps--;
	}
	str[total_i] = '\0';
	return str;
}

void mfunc1() {
	char drom[64];
	int zahl;
	printf("\nBitte Zahl eingeben: ");
	scanf("%d", &zahl);
	strcpy(drom, dec2rom(zahl));
	printf("Roemische Zahl: %s\n", drom);
}

void mfunc2() {
	char wrom[64];
	printf("\nBitte roemisch eingeben: ");
	scanf("%63s", &wrom);
	int rdec = rom2dec(wrom);

	if (rdec == -2) {
		printf("Ungueltige Folge.\n");
	}
	else if (rdec != -1) {
		printf("Eingelesen: %s\n", wrom);
		printf("In Zahl: %s\n", tsep(rdec));
		// printf("In Zahl: %d\n", rdec);
	}
	else printf("Ungueltige Eingabe.\n");
}

int main() {
	printf("\tRoemische Zahlen");
	mfunc1();
	mfunc2();

	printf("\nBitte Enter druecken.");
	getchar();
	getchar();
}
