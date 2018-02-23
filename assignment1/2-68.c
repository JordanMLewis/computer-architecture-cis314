#include <stdio.h>


int lower_one_mask(int n) {
	/*
	* Mask with least signficant n bits set to 1
	* Examples: 
	* n = 6 --> 0x3F, 
	* n = 17 --> 0x1FFFF
	* Assume 1 <= n <= w

	We begin with w 1's:
		1111 1111 1111 1111 1111 1111 1111 1111

	Then, we shift right (32 - n) bits (ex. n = 16)
		0000 0000 0000 0000 1111 1111 1111 1111

	Leaving us with the least significant 16 bits set to 1

	*/
	unsigned int masked = (0xFFFFFFFF >> (32 - n));

	return masked;
}

void main(){
	printf("%i\n", lower_one_mask(1));
	printf("%i\n", lower_one_mask(2));
	printf("%i\n", lower_one_mask(3));
	printf("%i\n", lower_one_mask(5));
}
