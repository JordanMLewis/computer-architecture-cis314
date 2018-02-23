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

void inner4(vec_ptr u, vec_ptr v, data_t* dest){
	long int i;
	int length = vec_length(u);
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
	data_t sum = (data_t) 0;

	for(i = 0; i < length; i++){
		sum = sum + udata[i] * vdata[i];
	}
	*dest = sum;
}

int main(){
	//test inner4 procedure
	vec_ptr u = malloc(sizeof(data_t) * VECTOR_SIZE);
	vec_ptr v = malloc(sizeof(data_t) * VECTOR_SIZE);
	data_t* dest = malloc(sizeof(data_t));

	//start clock
	struct timeval start;
	gettimeofday(&start, NULL);

	//execute
	inner4(u, v, dest);

	struct timeval current;
	gettimeofday(&current, NULL);

	//Stop clock
	long long elapsed = (current.tv_sec - start.tv_sec)*1000000LL + (current.tv_usec - start.tv_usec);
	printf("%f\n", elapsed/1000000.0);	
}
