#include <stdio.h>
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  //
#include <cmocka.h>
#include "D:\arraydz.h"


static void new_void_create_remove(void **state)
{
   arr_t * arr = arr_new(5);
    assert_int_equal(arr_length(arr), 5);
    arr_remove(&arr);
    assert_null(arr);
}

static void new_void_add(void **state)
{
arr_t * arr = arr_new(5);
assert_int_equal(arr_add(arr, 1, 189), ARR_OK);
assert_int_equal(arr_add(arr, 8, 19), ARR_OVERFLOW);
int elem = 0;
assert_int_equal(arr_get(arr, 1, &elem), ARR_OK);
assert_int_equal(elem, 189);
assert_int_equal(arr_get(arr, 37, &elem), ARR_OVERFLOW);
arr_remove(&arr);
}

static void new_void_plus( void **state ){

arr_t * arr = arr_new(10);
arr_t * arr1 = arr_new(10);
arr_random(arr  , 10);
arr_random(arr1  , 10);
int elem1  = -1;
int elem2 = -1;
int elem3 = -1;
arr_get(arr ,2,&elem1);
arr_get(arr1,2,&elem2);
arr_t * arr2 = arr_plus(arr , arr1);
arr_get (arr2 , 2 , &elem3);
assert(elem3 == (elem1 + elem2));
arr_remove(&arr);
arr_remove(&arr1);
arr_remove(&arr2);


}



static void new_void_glue( void**state){
 int el1;
 int el2;
arr_t * arr = arr_new(15);
arr_t * arr1 = arr_new(28);
arr_random(arr ,10);
arr_t * arr2 = arr_glue(arr, arr1);

 el1 = 5;
 el2 = 10;
arr_get(arr1 , 2 , &el1);
arr_get(arr2 ,2 + 15 ,&el2);
assert_int_equal(el1 , el2);
arr_remove(&arr);
arr_remove(&arr1);
arr_remove(&arr2);
}


static void new_void_count(void ** state){
int j;
int mas[] = {1 ,5 , 2 , 2 , 2 ,2};


arr_t * arr = arr_new(6);
for (j = 0; j < 6; j++)
    arr_add(arr , j , mas[j]);

assert_int_equal(arr_count(arr), 2);

}


int main(void) {
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_add),cmocka_unit_test(new_void_glue),cmocka_unit_test(new_void_create_remove),
        cmocka_unit_test(new_void_plus),cmocka_unit_test(new_void_count),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
