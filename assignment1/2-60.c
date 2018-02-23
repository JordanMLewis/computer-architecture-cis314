#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b){
	/*
	Will replace byte 0,1,2,3,..., i mod 4 of x with char b.

	Example:
	replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
	replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
	*/

	//Multiply i by 8 to represent 1 byte
	unsigned int byteShiftCount = i * 8;

	//Shift the input unsigned char to the correct location
	unsigned int shiftedChar = b << byteShiftCount;

	//Shift over FF to the correct byte
	//Zero out byte that will change using FF
	unsigned cleanInput = x & ~(0x000000FF << byteShiftCount);

	//Exclusive OR the prepared input with the byte to add
	//(This part replaces the gap in the original byte string)
	cleanInput = cleanInput ^ shiftedChar;

	return cleanInput;
}

void main(){
	printf("0x%X\n", replace_byte(0x12345678, 2, 0xAB));
	printf("0x%X\n", replace_byte(0x12345678, 0, 0xAB));
}
