#include <stdio.h>
#include <string.h>

#define POSITIONS   10
#define NAME_LEN    16

int main()
{
    int c;
    int pts = 0;
	int board = 0;
    char name[NAME_LEN] = "";
    char scores[POSITIONS][NAME_LEN + 8] = {""};
    printf("Pts: ");
    scanf("%d", &pts);
	printf("Board: ");
    scanf("%d", &board);
    printf("Name: ");
    while ((c = getchar()) != '\n' && c != EOF) { };
    fgets(name, NAME_LEN, stdin);
    printf("Alte Länge: %lu\n", strlen(name));
    if (name[strlen(name) - 1] == '\n')
        name[strlen(name) - 1] = '\0';
    printf("Neue Länge: %lu\n", strlen(name));
    for (c = 0; c < POSITIONS; c++) {
		// int itp = 0;
		for (int i = 0; i < 4; i++) {
		    scores[c][i] = (pts + c) >> i*8;
		    scores[c][i+4] = (board + c) >> i*8;
		    // itp = itp << 8 | static_cast<unsigned char>(scores[c][i]);
		}
		
		// printf("%s: %d", name, scores[c][8]);
		// strcpy((char*) scores[c][4], (char*) board + c);
		
		strcpy(&scores[c][8], name);
		printf("\n%d | %d | %s", *(int*)(scores[c]+0), *(int*)(scores[c]+4), &scores[c][8]);
	}
    return 0;
}
