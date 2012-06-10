#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_random_array(int min_value, int max_value, int count);
int* merge_sort(int* array, int size);
int* merge_arrays(int* a, int size_a, int* b, int size_b);

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
    print_array("in", array, item_count);


    clock_t start, end;
    start = clock();

    int* sorted_array = merge_sort(array, item_count);
    print_array("out", sorted_array, item_count);

    end = clock();

    double elapsed = (double) (end - start) / CLOCKS_PER_SEC;
    printf("\nElapsed: %f\n\n", elapsed);

}



int* merge_arrays(int* a, int size_a, int* b, int size_b){
    int* merged_array = malloc(sizeof(int) * (size_a + size_b));
    int ia = 0, ib = 0, i = 0;
    while (ia < size_a && ib < size_b){
        if (a[ia] < b[ib]){
            merged_array[i] = a[ia];
            ia = ia + 1;
        } else {
            merged_array[i] = b[ib];
            ib = ib + 1;
        }
        i = i + 1;
    }

    if (ib < size_b){
        // copy the rest of b
        for (; ib < size_b;ib++){
            merged_array[i] = b[ib];
            i = i + 1;
        }
    } else {
        // copy the rest of a
        for (; ia < size_a;ia++){
            merged_array[i] = a[ia];
            i = i + 1;
        }
    }

#ifdef DEBUG
    printf("============\nMERGED:\n");
    print_array("a", a, size_a);
    print_array("b", b, size_b);
    print_array("merge", merged_array, size_a+size_b);
#endif

    return merged_array;
}

int* merge_sort(int* array, int size){

    /* You cant sort an array of 1 */
    if (size <= 1){
        return array;
    }

    /* split list into two parts around a center point */
    int* part_a = malloc(sizeof(int) * size);
    int* part_b = malloc(sizeof(int) * size);
    int middle = size/2;

    /* Copy the contents of each side of the array into the new arrays */
    int i = 0, a = 0, b = 0;
    for (i = 0; i < size; i++){
        if (i < middle){
            part_a[a] = array[i];
            a = a + 1;
        } else {
            part_b[b] = array[i];
            b = b + 1;
        }
    }

    /* Now do the same recursively */
    int* part_aa = merge_sort(part_a, a);
    int* part_bb = merge_sort(part_b, b);

    /* Merge the results */
    int* merged = merge_arrays(part_aa, a, part_bb, b);

    /* Free up the temp arrays used */
    free(part_a);
    free(part_b);

    return merged;
}
