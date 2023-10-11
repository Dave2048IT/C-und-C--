#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sync_it(char *t1, char* t2) {
	printf("t1: %s\n", t1);
	// t1[0][0] = 234;
}

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
	
	short games, len;
	unsigned char game_trophies[] = {12, 0, 3, 27};
	games = len = sizeof(game_trophies);
	/*
	for (char i = 0; i < len; i++) {
	    game_trophies[i] = 24;
	}
	*/
	unsigned char max_trophies = find_max(game_trophies, len);
	// unsigned char max_trophies = 254;
	
	char trophies[games][max_trophies];
	char server_trophies[games][max_trophies];
	
	// char synced_trophies[games][max_trophies];
	// char trophies[games];
	
	printf("Vor Sync:\n\n");
	for (short i = 0; i < len; i++) {
		// trophies[i][game_trophies];
		for (short j = 0; j < game_trophies[i]; j++) {
			trophies[i][j] = rand() % 2;
			server_trophies[i][j] = rand() % 2;
			// synced_trophies[i][j] = trophies[i][j] | server_trophies[i][j];
			
			// printf("Trophäe %d erhalten von Spiel %d: %d\n", j, i + 1, trophies[i][j]);
			// printf("Server-Trophäe %d   von Spiel %d: %d\n", j, i + 1, server_trophies[i][j]);
			// printf("Lokal: %d | Server: %d | Sync: %d\n", trophies[i][j], server_trophies[i][j], synced_trophies[i][j]);
			printf("S%d T%d - Lokal: %d | Server: %d \tVor\n", i + 1, j + 1, trophies[i][j], server_trophies[i][j]);
		}
		printf("\n");
	}
	
	printf("\nNach Sync:\n\n");
	for (short i = 0; i < len; i++) {
		for (short j = 0; j < game_trophies[i]; j++) {
			trophies[i][j] |= server_trophies[i][j];
			server_trophies[i][j] |= trophies[i][j];
			
			// if (trophies[i][j] == 1 && server_trophies[i][j] == 0) server_trophies[i][j] = 1;
			// else if (trophies[i][j] == 0 && server_trophies[i][j] == 1) trophies[i][j] = 1;
			printf("S%d T%d - Lokal: %d | Server: %d \tNach\n", i + 1, j + 1, trophies[i][j], server_trophies[i][j]);
		}
		printf("\n");
	}
	
	// sync_it(&trophies, &server_trophies);
	printf("Größe von trophies (Gesamt): %ld", sizeof(trophies));
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nZeit: %f s", time_spent);
}
