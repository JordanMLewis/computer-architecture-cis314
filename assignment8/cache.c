/*
	Author: Jordan M Lewis
	Date: 3 March 2017
	Class: CIS 314
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_OF_CACHE 16

typedef unsigned char* byte_pointer;

typedef struct set{
	unsigned char valid;
	unsigned int tag;
	unsigned int data;
} set;

int calculateBlockOffsetFromAddress(int address){
	return address & 0x3;
}

int calculateSetFromAddress(int address){
	return ((address >> 2) & 0xF);
}

int calculateTagFromAddress(int address){
	return address >> 6;
}

int getOffsetBytes(int value, int byteOffset){
	return (value >> (byteOffset * 8)) & 0xFF;
}

set* createArrayOfSets(){
	set* cacheArray = malloc( (sizeof(set)) * SIZE_OF_CACHE );
	for(int i = 0; i < SIZE_OF_CACHE; i++){
		cacheArray[i].valid = 0;
	}
	return cacheArray;
}

void show_bytes(byte_pointer start, int len){
	int i;
	for (i = 0; i < len; i++){
		//interpret as hexidecimal
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void show_long(long x){
	//Allocate enough memory for a short int
	show_bytes ((byte_pointer) &x , sizeof(long));
}

void printCache(set* setPointer){

	set* sp = setPointer;
	char valid;
	for(int i = 0; i < SIZE_OF_CACHE; i++){
		valid = sp[i].valid;

		if(valid == 1){
			printf("set: %d - tag: %d - valid: %d - value:", i, sp[i].tag, 1);
			show_long(sp[i].data);
		}
	}
}

int main(int argc, char** argv){

	//Create cache of 16 sets
	set* cacheArray = createArrayOfSets();

	printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
	int tag;
	int set;
	int blockOffset;
	char command;
	scanf(" %c", &command); 

	while(command != 'q'){

		//read
		if(command == 'r'){ 
			printf("Enter 32-bit unsigned hex address: "); 
			int address; scanf(" %x", &address);

			set = calculateSetFromAddress(address);
			tag = calculateTagFromAddress(address);
			blockOffset = calculateBlockOffsetFromAddress(address);

			printf("looking for set: %d - tag: %d\n", set, tag);

			//make sure the set is valid
			//make sure the tag matches
			if(cacheArray[set].valid == 1){
				printf("found set: %d - tag: %d - offset: %d - valid: %d - value: %x\n", 
							set, cacheArray[set].tag, blockOffset, cacheArray[set].valid, getOffsetBytes(cacheArray[set].data, blockOffset));
				
				if(cacheArray[set].tag == tag){
					printf("hit!\n");	
				} else {
					printf("tags don't match - miss!\n");
				}
			} else {
				printf("no valid set found - miss!\n");
			}

		//write
		} else if (command == 'w'){
			printf("Enter 32-bit unsigned hex address: "); 
			int address; scanf(" %x", &address);
			printf("Enter 32-bit unsigned hex value: ");
			int value;   scanf(" %x", &value);

			set = calculateSetFromAddress(address);
			tag = calculateTagFromAddress(address);
			blockOffset = calculateBlockOffsetFromAddress(address);

			//check to see if the set is valid
			//If valid, print the evicted set
			//Else, just write it in.
			if(cacheArray[set].valid == 1){
				printf("evicting block - set: %d - tag: %d - valid: %d - value:", set, cacheArray[set].tag, cacheArray[set].valid);
				show_long(cacheArray[set].data);
				
				cacheArray[set].tag = tag;
				cacheArray[set].data = value;
				printf("wrote set: %d - tag: %d - valid: %d - value:", set, cacheArray[set].tag, cacheArray[set].valid);
				show_long(cacheArray[set].data);

			} else {
				cacheArray[set].valid = 1;
				cacheArray[set].tag = tag;
				cacheArray[set].data = value;
				printf("wrote set: %d - tag: %d - valid: %d - value:", set, cacheArray[set].tag, cacheArray[set].valid);
				show_long(cacheArray[set].data);
			}

		//print
		} else if (command == 'p'){ printCache(cacheArray); }

		printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
		scanf(" %c", &command);
	}

	return 0;
}
