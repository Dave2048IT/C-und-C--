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
    printf("Alte Länge: %d\n", strlen(name));
    if (name[strlen(name) - 1] == '\n')
        name[strlen(name) - 1] = '\0';
    printf("Neue Länge: %d\n", strlen(name));
    printf("%s: %d", name, pts);
    
    score[0] = pts;
    for (c = 0; c < 3; c++) {
        if (name[c*4] == '\0') break;
        for (int i = 0; i < 4; i++) {
            score[c + 1] += name[c*4 + i] << i*8;
        }
    }
    
    /*char decoded_name[12] = "";
    for (c = 0; c < 3; c++) {
        if (score[c + 1] == 0) break;
        for (int i = 0; i < 4; i++) {
            decoded_name[c*4 + i] = score[c + 1] >> i*8;
        }
    }
    */
    char (*decoded_name) = &score[1];
    // decoded_name = &score[2];
    printf("\n\n%d | %s", pts, decoded_name);
    return 0;
}
