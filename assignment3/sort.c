#include <stdio.h>
#include <stdlib.h>

int* createArray(int arrayLength){
	//create pointer with enough space for specified length
	int* arrayPointer = malloc(arrayLength * (sizeof(int)));

	int added;

	//Fill the array with values
	for(int i = 0; i < arrayLength; i++){
		printf("Enter the next element: ");
		scanf("%d", &added);
		arrayPointer[i] = added;
	}

	return arrayPointer;
}

int* selectionSort(int* arrayPointer, int length){
	/*Selection sort code from: 
	http://www.programmingsimplified.com/c/source-code/c-program-selection-sort
	Modified by: Jordan Lewis
	*/
	int n, c, d, position, swap;
	n = length;

	for ( c = 0 ; c < ( n - 1 ) ; c++ ){
		position = c;
        	for ( d = c + 1 ; d < n ; d++ ){
        		if ( arrayPointer[position] > arrayPointer[d] )
            			position = d;
      		}
		if ( position != c ){
         		swap = arrayPointer[c];
         		arrayPointer[c] = arrayPointer[position];
         		arrayPointer[position] = swap;
		}
	}//end for

   return arrayPointer;
}

void printArray(int* myArray, int length){
	printf("\nMy sorted array:\n");
	//int k;
	for(int i = 0; i < length; i++){
		printf("%d\n", myArray[i]);
	}
}

int main(){

	//Get an signed int from the user for length of array
	int arrayLength;
	printf("Please enter number of elements: ");

	//Store in the memory location of arrayLength
	scanf("%d", &arrayLength);

	//Create pointer to array
	int* myArray = createArray(arrayLength);

	//Sort and print the array
	myArray = selectionSort(myArray, arrayLength);
	printArray(myArray, arrayLength);

	//Deallocate array
	free(myArray);
}
