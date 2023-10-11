#include <stdio.h> //						<<
#define SET_BIT(value, pos)    (value |= (1U << (pos)))
#define CLEAR_BIT(value, pos)  (value &= ~(1U << (pos)))
#define TOGGLE_BIT(value, pos) (value ^= (1U << (pos)))
#define CHECK_BIT(value, pos)  (value & (1U << (pos)))

int main()
{
	unsigned int flag_nr = 126;
	unsigned int data1[15] = {0};
	TOGGLE_BIT(data1[flag_nr >> 5], flag_nr & 31);
	printf("%d\nHello World, \n%d / \n%d", flag_nr >> 5, data1[3], CHECK_BIT(data1[3], 29+2));

	return 0;
}
