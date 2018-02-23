#include <stdio.h>

int decode2(int x, int y, int z){
	/*
	x at %ebp+8, 
	y at %ebp+12, 
	z at %ebp+16

	1 movl 12(%ebp), %edx (assigning (long))
		//move y into a new variable
	2 subl 16(%ebp), %edx (subtraction (long))
		//
		 %edx = 16(%ebp) - %edx
	3 movl %edx, %eax     (assigning (long))
	4 sall $31, %eax      (Shift left (long))
	5 sarl $31, %eax	  (Shift right (long))
	6 imull 8(%ebp), %edx (Integer multiplication (long))
	7 xorl %edx, %eax     (Exclusive OR, Logical)

	//%eax is return value

	//1
	//2
	//  (y-z)
	//3
	//4
	// ((y-z) << 31)
	//5
	// (((y-z) << 31) >> 31)
	//6
	// x * (y-z)
	//7
	// (((y - z) << 31) >> 31) ^ (x * (y-z))
	*/
	return (((y - z) << 31) >> 31) ^ (x * (y-z));

}

int main(){
	printf("%d\n", decode2(1, 2, 4));    //should be -2
	printf("%d\n", decode2(-4, -8, -12));//should be -16
	printf("%d\n", decode2(2, 5000, 2)); //should be 9996
}
