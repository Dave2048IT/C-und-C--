#include <stdio.h>

int main()
{
    short grenzwert = 90, plaetze = 100, i = 0, z = 0;
    printf("%d %d %d %d\n\n", grenzwert, plaetze, i, z);
    unsigned char sensors[100] = {0};
    do {
        // printf("%d", sensors[i]);
        if (i < 94)
            sensors[i] = 1;
        if (sensors[i]) z++;
        else z--;
    } while (++i < plaetze);
    printf("\n%d Plätze => ", z);
    printf("%s", z >= 90 ? "besetzt" : "frei");
    return 0;
}
