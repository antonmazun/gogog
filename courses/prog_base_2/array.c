#include "arraydz.h"
#include "time.h"
#define MAX_ARRAY_SIZE 50


struct arr_s{
	int *arr;
	int size;
	arr_status_t status;
};

arr_t * arr_new(int size) {
	if (size <= 0 || size > MAX_ARRAY_SIZE)
		return NULL;
    arr_t * self = malloc(sizeof(struct arr_s));
    self->arr = malloc( size  * sizeof(int));
    self->size = size;
    self->status = ARR_OK;
    return self;
}
void arr_random(arr_t * arr, unsigned max){

	int i;
	for(i = 0; i < arr->size; i++)
		arr->arr[i] = rand() % max;	

}
int arr_length(arr_t * arr)
{
	return arr->size;
}

void arr_print(arr_t * arr){
	int i;
	for(i = 0 ; i < arr->size; i++)
		printf ("%i\t", arr->arr[i]);
	printf("\n");
}

void arr_remove(arr_t ** arr){
	
	free((*arr)->arr);
	free(*arr);
	*arr = NULL;
}


int arr_add(arr_t * arr , int index , int elem ){
	
if(index >= arr->size || index < 0){
	return 1;
}		
arr->arr[index] = elem;
return 0;
}


arr_t * arr_plus(arr_t * arr1 , arr_t * arr2){
	
int size = ( arr1->size > arr2->size ) ? arr1->size : arr2->size;

arr_t * arr = arr_new(size);
int i;
for (i = 0; i < size; i++){
	arr->arr[i] = 0;
	if (i < arr1->size)
		arr->arr[i] += arr1->arr[i];	
	if (i < arr2->size)
		arr->arr[i] += arr2->arr[i];
}
return arr;
}



arr_t  * arr_glue (arr_t * arr1 , arr_t * arr2){
	arr_t * arr = arr_new(arr1->size + arr2->size);
	int i;
	for(i = 0; i < arr1->size; i++)
		arr->arr[i] = arr1->arr[i];
	for(i = 0; i < arr2->size; i++)
		arr->arr[i+arr1->size] = arr2->arr[i];	
	return arr;
}

int arr_count(arr_t * arr1){
int count = 0 ;
int i , j;
int status = 0;
for (i = 0; i < arr1->size; i++){
status = 0;

	for (j = 0; j < arr1->size; j++)
		if (arr1->arr[i] == arr1->arr[j] && i != j)
		{
		
			status = 1;
			break;
		}
	if (status == 0)
		count++;
	}
return  count;
}


arr_t * arr_unic(arr_t * arr1, arr_t * arr2)
{
	arr_t * arr = arr_new(arr_count(arr1) + arr_count(arr2));
	int pos = 0, i, j,status;
	for (i = 0; i < arr1->size; i++){
		status = 0;
		for (j = 0; j < arr1->size; j++)
			if (arr1->arr[i] == arr1->arr[j] && i != j)
			{
				status = 1;
				break;
			}
		if (status == 0){
			arr->arr[pos] = arr1->arr[i];
			pos++;
		}
		}
	for (i = 0; i < arr2->size; i++){
		status = 0;
		for (j = 0; j < arr2->size; j++)
			if (arr2->arr[i] == arr2->arr[j] && i != j)
			{
				status = 1;
				break;
			}
		if (status == 0){
			arr->arr[pos] = arr2->arr[i];
			pos++;
		}
		}
	return arr;	 
}
