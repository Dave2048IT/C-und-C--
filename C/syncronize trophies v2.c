#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NELEMS_1D(x)  (sizeof(x) / sizeof((x)[0]))
#define NELEMS_2D(x)  (sizeof(x) / sizeof((x)[0][0]))

unsigned char find_max(unsigned char *t, short len) {
	unsigned char max = 1, i;
	for (i = 0; i < len; i++) {
		if (t[i] > max) max = t[i];
	}
	return max;
}

void main()
{
	printf("Gestartet\n");
	srand(time(NULL));
	clock_t begin = clock();
	
	short len;
	unsigned char games[] = {16, 1, 16, 255, 33};
	len = sizeof(games);
	
	char **trophies = (char **) calloc(len, sizeof(char *));
	char **server_trophies = (char **) calloc(len, sizeof(char *));
	for (char i = 0; i < len; i++) {
		trophies[i] = (char *) calloc(games[i], sizeof(char));
		server_trophies[i] = (char *) calloc(games[i], sizeof(char));
	}
	
	printf("Vor Sync:\n\n");
	for (short i = 0; i < len; i++) {
		// trophies[i][game_trophies];
		for (short j = 0; j < games[i]; j++) {
			trophies[i][j] = rand() % 2;
			server_trophies[i][j] = rand() % 2;
			printf("S%d T%d - Lokal: %d | Server: %d \tVor\n", i + 1, j + 1, trophies[i][j], server_trophies[i][j]);
		}
		printf("\n");
	}
	
	printf("\nNach Sync:\n\n");
	for (short i = 0; i < len; i++) {
		for (short j = 0; j < games[i]; j++) {
			trophies[i][j] |= server_trophies[i][j];
			server_trophies[i][j] |= trophies[i][j];
			printf("S%d T%d - Lokal: %d | Server: %d \tNach\n", i + 1, j + 1, trophies[i][j], server_trophies[i][j]);
		}
		printf("\n");
	}
	printf("Größe von trophies (Gesamt): %d", NELEMS_2D(trophies));
	
	free( trophies );
	free( server_trophies );
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nZeit: %f s", time_spent);
}
