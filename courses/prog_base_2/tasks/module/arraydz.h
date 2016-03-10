#ifndef ARRAY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include "time.h"
#include <stdlib.h>

typedef enum arr_status_t {
    ARR_OK,       // 0
    ARR_OVERFLOW, // 1
    ARR_EMPTY
} arr_status_t;

typedef struct arr_s arr_t;
void arr_random(arr_t * arr, unsigned max);
void arr_print(arr_t * arr);
arr_t * arr_new(int size);
void arr_remove(arr_t ** arr);
int arr_length(arr_t * arr); 
int arr_add(arr_t * arr , int index , int elem );
arr_t * arr_plus(arr_t * arr1 , arr_t * arr2);
arr_t  * arr_glue (arr_t * arr1 , arr_t * arr2);
int arr_count(arr_t * arr1);
arr_t * arr_unic(arr_t * arr1, arr_t * arr2);


#endif
