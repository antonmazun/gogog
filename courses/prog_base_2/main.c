#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraydz.h"
#include "time.h"

int main(void){
	srand(time(NULL));
	int size;
	printf ("Please enter size array\n");
	scanf("%i" , &size);
	arr_t * arr = arr_new(size);
	arr_random(arr, 10);
	arr_print(arr);
	printf(" length =%i\n", arr_length(arr));
	if(!arr_add(arr, 5, 100))
		printf ("\nsucsess\n");
	arr_print(arr);
	arr_t * arr1 = arr_new(size);
	arr_random(arr1, 4);
	arr_print(arr1);
	arr_t * arr2 = arr_plus(arr, arr1);
	arr_print(arr2);
	puts("glue:\n");
	arr_t  * arr4 = arr_glue(arr ,arr1);
	arr_print(arr4);
	int  c = arr_count(arr1);
	printf(" count  = %i  \n" , c);
	arr_t * arr3 = arr_unic(arr,arr1);
	arr_print(arr3);
	arr_remove(&arr);
	arr_remove(&arr1);
	arr_remove(&arr2);
	arr_remove(&arr3);
	arr_remove(&arr4);
	if (arr == NULL && arr1 == NULL && arr2 == NULL)
		printf ("\nsucsess");
	return 0;
}
