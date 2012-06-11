#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "sort_helpers.h"

int* quicksort(int* array, int size);

int main(int argc, char** argv){
    int i = 0;
    int item_count = 0;

    if (argc < 2){
        exit(1);
    }
    else{
        item_count = atoi(argv[1]);
    }

    int* array = generate_random_array(1, 1000, item_count);
#ifdef DEBUG
    print_array("in", array, item_count);
#endif

    clock_t start, end;
    start = clock();

    int* sorted_array = quicksort(array, item_count);
#ifdef DEBUG
    print_array("out", sorted_array, item_count);
#endif

    end = clock();

    double elapsed = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Elapsed: %f\n", elapsed);
}

int* quicksort(int* array, int size){

    if (size <= 1){
        return array;
    }

    // pick a pivot point (just use the first one)
    int pivot = array[0];

    // split into two based on pivot
    int* part_a = malloc(sizeof(int) * size);
    int* part_b = malloc(sizeof(int) * size);

    int i, ia=0, ib=0;
    for (i = 1; i < size; i = i + 1){
        if (array[i] <= pivot){
            part_a[ia] = array[i];
            ia = ia + 1;
        } else {
            part_b[ib] = array[i];
            ib = ib + 1;
        }
    }

    // recurse
    int* part_aa = quicksort(part_a, ia);
    int* part_bb = quicksort(part_b, ib);

    // combine
    int* sorted = malloc(sizeof(int) * size);
    memcpy(sorted, part_aa, sizeof(int) * ia);
    sorted[ia] = pivot;
    memcpy(&(sorted[ia+1]), part_bb, sizeof(int) * ib);

    free(part_a);
    free(part_b);

    return sorted;
}







