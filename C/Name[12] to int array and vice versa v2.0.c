#include <stdio.h>
#include <string.h>

int main()
{
    int c;
    int pts = 0;
    char name[12] = "";
    int score[4] = {0};
    printf("Pts: ");
    scanf("%d", &pts);
    printf("Name: ");
    while ((c = getchar()) != '\n' && c != EOF) { };
    fgets(name, 12, stdin);
    printf("Alte Länge: %lu\n", strlen(name));
    if (name[strlen(name) - 1] == '\n')
        name[strlen(name) - 1] = '\0';
    printf("Neue Länge: %lu\n", strlen(name));
    score[0] = pts;
    
    printf("%s: %d", name, score[0]);
    strcpy((char*) &score[1], name);
    printf("\n\n%d | %s", score[0], (char*) &score[1]);
    return 0;
}
