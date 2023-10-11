#include <stdio.h>
#include <stdlib.h>
#define start_adr 0x200
#define end_adr 0x7FFFF7FF


int main()
{
    printf("%x - %x = %x", end_adr, start_adr, end_adr - start_adr);
    int arrayAdrs[6] = {13, 9, 14, 1, 0, 5};
    int adrLen = sizeof(arrayAdrs) / sizeof(arrayAdrs[0]);
    // printf("\n%d", adrLen);
    int adrNr;
    printf("\nWelche Nr.? ");
    scanf("%d", &adrNr);
    if (adrNr > adrLen)
    {
        printf("Zu hoch. Bitte 0 - 6. Enter.");
        getchar();
        getchar();
        return 0;
    }
    int adrOffset = start_adr;
    for (int i = 0; i < adrNr; i++) {
        adrOffset += arrayAdrs[i];
    }
    printf("\nOffset: %d", adrOffset);
    int *adrPtr = adrOffset;
    printf("\nPointer: %p. Gültig? %d", adrPtr, adrPtr != NULL);
    int adrEndOffset = adrOffset + arrayAdrs[adrNr] - 1;
    printf("\nEnd-Pointer: %d -> %p", adrEndOffset, adrEndOffset);
    int adrAlloc = malloc(arrayAdrs[adrNr]);
    printf("\nEchtes Offset: %p", adrAlloc);
    printf("\nGröße: %d", arrayAdrs[adrNr]);
    return 0;
}
