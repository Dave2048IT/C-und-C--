#include <stdio.h> //						<<
#define SET_BIT(value, pos)    (value |= (1U << (pos)))
#define CLEAR_BIT(value, pos)  (value &= ~(1U << (pos)))
#define TOGGLE_BIT(value, pos) (value ^= (1U << (pos)))
#define CHECK_BIT(value, pos)  (value & (1U << (pos)))

#define POS_2_MASK(pos, len)   (~((1 << len) - 1 << pos))
// The macro above outputs at POS_2_MASK (5, 3) ->
//          -225 (0b 11111111 11111111 11111111 00011111).

// Or another example: Override only the bits from pos 12 - 17 ->
// from -782,337 (0b 11111111 11110100 00001111 11111111).
// to   -602,113 (0b 11111111 11110110 11001111 11111111).

// With this call:
// x = (x & POS_2_MASK (pos, len)) | (new_value << pos);
// with these values:
// x = (x & POS_2_MASK (12, 6)) | (0x2C << 12);
// so this macro can be created:
#define NEW_VALUE_FROM_MASK(x, pos, len, new_value)   (x = (x & POS_2_MASK (pos, len)) | (new_value << pos))

// Pay attention to the size of the new values,
// otherwise it can also set other bits to 1    !!!

int main()
{
	unsigned int flag_nr = 126;
	unsigned int data1[15] = {0};
	TOGGLE_BIT(data1[flag_nr >> 5], flag_nr & 31);
	printf("%d\nHello World, \n%d / \n%d",
		flag_nr >> 5,
		data1[3],
		CHECK_BIT(data1[3], 29+2)
	);

	return 0;
}
