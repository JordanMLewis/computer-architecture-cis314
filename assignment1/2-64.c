#include <stdio.h>

typedef unsigned char* byte_pointer;

int any_odd_one(unsigned x){
	/* 
	Return 1 when any odd bit of x equals 1; 0 otherwise.
	Assume w=32. 
	
	0xAAAAAAAA has all odd bits set to 1 (... 1010 1010):
		1010 1010 1010 1010 1010 1010 1010 1010

	So using & with the input will keep any pairs of ones
	if they are in an odd bit. So if any pairs were kept, 
	we return boolean of 0 or 1.
	*/
	int result = (x & 0xAAAAAAAA) != 0;

	return result;
}

void main(){
	printf("%i\n", any_odd_one(0x0));
	printf("%i\n", any_odd_one(0x1));
	printf("%i\n", any_odd_one(0x2));
	printf("%i\n", any_odd_one(0x3));
	printf("%i\n", any_odd_one(0xFFFFFFFF));
	printf("%i\n", any_odd_one(0x55555555));
}
