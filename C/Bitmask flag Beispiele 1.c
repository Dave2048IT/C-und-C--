/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#define LOG_ERRORS            1  // 2^0, bit 0
#define LOG_WARNINGS          2  // 2^1, bit 1
#define LOG_NOTICES           4  // 2^2, bit 2
#define LOG_INCOMING          8  // 2^3, bit 3
#define LOG_OUTGOING         16  // 2^4, bit 4
#define LOG_LOOPBACK         32  // and so on...

#include <stdio.h>

int main()
{
    // Only 6 flags/bits used, so a char is fine
    unsigned char flags, i;
    printf("%d: %d\n", ++i, flags);
    
    // initialising the flags
    // note that assigning a value will clobber any other flags, so you
    // should generally only use the = operator when initialising vars.
    flags = LOG_ERRORS;
    printf("%d: %d\n", ++i, flags);
    // sets to 1 i.e. bit 0
    
    //initialising to multiple values with OR (|)
    flags = LOG_ERRORS | LOG_WARNINGS | LOG_INCOMING;
    printf("%d: %d\n", ++i, flags);
    // sets to 1 + 2 + 8 i.e. bits 0, 1 and 3
    
    // setting one flag on, leaving the rest untouched
    // OR bitmask with the current value
    flags |= LOG_INCOMING;
    printf("%d: %d\n", ++i, flags);
    
    // testing for a flag
    // AND with the bitmask before testing with ==
    if ((flags & LOG_WARNINGS) == LOG_WARNINGS);
       //...
    
    // testing for multiple flags
    // as above, OR the bitmasks
    if ((flags & (LOG_INCOMING | LOG_OUTGOING))
             == (LOG_INCOMING | LOG_OUTGOING));
       //...
    
    // removing a flag, leaving the rest untouched
    // AND with the inverse (NOT) of the bitmask
    flags &= ~(LOG_ERRORS | LOG_INCOMING);
    printf("%d: %d\n", ++i, flags);
    
    // toggling a flag, leaving the rest untouched
    flags ^= LOG_LOOPBACK;
    printf("%d: %d\n", ++i, flags);

    return 0;
}
