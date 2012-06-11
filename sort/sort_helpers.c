#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort_helpers.h"

/* Dump the contents of an array of integers */
void print_array(const char* name, int* a, int len){
    int i;
    printf("%s: ", name);
    for(i = 0; i < len; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

/* Allocate and build an array of specified size with numbers in the specified range */
int* generate_random_array(int min_value, int max_value, int count){
    int* array = malloc(count * sizeof(int));
    if (array != NULL){
        int i = 0;

        time_t t;
        time(&t);
        srand((int)t);

        for(i = 0; i < count; i++){
            float rnd_float = rand()/(float)RAND_MAX;
            int rnd = (int)(rnd_float * (float)(max_value - min_value)) + min_value;
            array[i] = rnd;
        }
    }

    return array;
}
