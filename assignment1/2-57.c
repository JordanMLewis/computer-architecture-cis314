#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, int len){
	int i;
	for (i = 0; i < len; i++){
		//interpret as hexidecimal
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void show_short(short x){
	//Print the bytes using a pointer to input
	//Allocate enough memory for a short int
	show_bytes ((byte_pointer) &x , sizeof(short));
}

void show_long(long x){
	//Allocate enough memory for a short int
	show_bytes ((byte_pointer) &x , sizeof(long));
}

void show_double(double x){
	//Allocate enough memory for a short int
	show_bytes ((byte_pointer) &x , sizeof(double));
}

int main(int argc, char** argv){

	short a = 1;
	long b = 123123;
	double c = 123123;

	show_short(a);
	show_long(b);
	show_double(c);

	return 0;
}