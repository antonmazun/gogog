#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "event.h"
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  //.h"
#include <cmocka.h>


void ev_add(int data, int pos){
    printf ("user 1 knows add elem %i in %i pos\n\n", data, pos);
}

void ev_add1(int data, int pos){
    printf ("user 2 knows add elem %i in %i pos\n\n", data, pos);
}

void ev_del(int data, int pos){
    printf ("user 2 knows del elem %i in %i pos\n\n", data, pos);
}

void ev_change(int bef_data, int cur_data, int pos){
    printf ("user 1 knows change %i on %i in %i\n\n", bef_data, cur_data, pos);
}

void ev_sum()
{
   printf ("user 2 knows sum\n\n");
}

static void list_new_list(void ** state){

list_t * self = NULL;
self = list_new();
assert_non_null(self);
list_free(self);
}


static void list_change_int(void ** state){

    list_t list = list_new();

    list_add(list , 6 , 0);

    list_add(list , 7 , 0);

    assert_int_equal(list_change(list , 15 , 0) , 7);


    assert_int_equal(list_del(list , 1) , 6);
    assert_int_equal(list_del(list , 0) , 15);
    list_free(list);

}

static void list_add_test(void ** state){

    list_t list = list_new();

    list_add(list , 6 , 0);
    list_add(list , 7 , 0);
    assert_int_equal(list_del(list , 1) , 6);
    assert_int_equal(list_del(list , 0) , 7);
    list_free(list);

}
int main()
{


    const struct CMUnitTest tests[] = {

 cmocka_unit_test(list_new_list),
 cmocka_unit_test(list_add_test),
 cmocka_unit_test(list_change_int),



 };
    int i;
    list_t list = list_new();
    user_t user = user_new(1);// створюється юзерs
    puts("das");
    user_add_subscribe(user, ev_add, list); // підписка на функцію адд

    user_t user1 = user_new(2);
    user_change_subscribe(user, ev_change, list);// підписка на зміни
    user_add_subscribe(user1, ev_add1, list); //підписка на функці. адд
    user_del_subscribe(user1, ev_del, list); // підписка на видал
    user_sum_subscribe(user1, ev_sum, list); // підписка на перевірку суми



    for( i = 0; i < 10; i++)
    {
        list_add(list, i, i);
    }

    for ( i = 0; i < 10; i++)
    {
        list_change(list, i + 7, i);
    }
    for ( i = 0; i < 10; i++)
    {
        list_del(list, 2);
    }



 return cmocka_run_group_tests(tests, NULL, NULL);

}

