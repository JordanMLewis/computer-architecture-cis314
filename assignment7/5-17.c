/*
Write a modified version of inner4 as specified by 5.17
and a main() function to test the modified inner4 procedure. 
Your main() method should also print the time elapsed during 
execution of the inner4 function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define VECTOR_SIZE 100000 

typedef long long data_t;
typedef data_t *vec_ptr;

data_t* get_vec_start(vec_ptr v) {
	return v;
}

int vec_length(vec_ptr v) {
	return VECTOR_SIZE;
}

//Modified version of inner4 using four-way loop unrolling
void inner4(vec_ptr u, vec_ptr v, data_t* dest){
	long int i;
	int length = vec_length(u);
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
	data_t sum1 = (data_t) 0;
	data_t sum2 = (data_t) 0;
	data_t sum3 = (data_t) 0;
	data_t sum4 = (data_t) 0;

	int remainingLoops = length % 4;
	int unrolledLoops = length - remainingLoops;

	//4-way loop unrolling
	for(i = 0; i < unrolledLoops; i+=4){
		sum1 += (udata[i  ] * vdata[i  ]);
		sum2 += (udata[i+1] * vdata[i+1]);
		sum3 += (udata[i+2] * vdata[i+2]);
		sum4 += (udata[i+3] * vdata[i+3]);
	}

	//Compute remining loops
	for(; i < length; i++){
		sum1 += (udata[i] * vdata[i]);
	}

	//Add all sums together
	sum1 += sum2 + sum3 + sum4;
	*dest = sum1;
}

int main(){
	//test inner4 procedure
	//start clock
	vec_ptr u = malloc(sizeof(data_t) * VECTOR_SIZE);
	vec_ptr v = malloc(sizeof(data_t) * VECTOR_SIZE);
	data_t* dest = malloc(sizeof(data_t));

	//start clock
	struct timeval start;
	gettimeofday(&start, NULL);

	inner4(u, v, dest);

	//Stop clock
	struct timeval current;
	gettimeofday(&current, NULL);

	//Stop clock
	long long elapsed = (current.tv_sec - start.tv_sec)*1000000LL 
						+ (current.tv_usec - start.tv_usec);

	printf("%f\n", elapsed/1000000.0);	
}