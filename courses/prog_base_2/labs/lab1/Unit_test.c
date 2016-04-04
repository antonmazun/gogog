#include <stdio.h>
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  //
#include <cmocka.h>
#include "corpus.h"
#include <time.h>

static void new_void_CorpusOk(void ** state){

corpus_t * self = NULL;
int number = 4;
int mas[4]  = { 1 , 2 , 3 , 4};
self  = corpus_new(number , mas);
 assert_non_null(self);
 corpus_free(self);
}

static void new_void_roomIsBusy( void ** state){

corpus_t * corpus = NULL;
int number =  2;
int mas[2] = {1,2};
corpus = corpus_new(number , mas);
room_t * self = NULL;
self = return_room( corpus , 1);
assert_int_equal(room_busy(self ) , 0);
assert_int_equal(room_take(self ,1),  0);
assert_int_equal(room_busy(self),  1);
clock_t time = clock();
while(clock() < time + CLOCKS_PER_SEC);
assert_int_equal(room_busy(self) , 0);
corpus_free(corpus);
}

static void new_void_roomCount(void ** state){

int number =  2;
int mas[2] = {1,2};
corpus_t * corpus  = NULL;
corpus = corpus_new(number , mas);
assert_int_equal(corpus_roomCount(corpus) , 2);
corpus_free(corpus);

}


static void new_void_emptySeats(void ** state){

int number =  2;
int mas[2] = {1,2};
corpus_t * corpus = corpus_new(number , mas);
room_t * room =  return_room( corpus,  1);
assert_int_equal(room_empty_seats(room) , 2);
corpus_free(corpus);
}


static void new_void_NoEmptySeats(void ** state){

int number =  2;
int mas[2] = {1,2};
corpus_t * corpus = corpus_new(number , mas);
room_t * room =  return_room( corpus,  5);
assert_null(room);// повертає нал
corpus_free(corpus);
}


static void new_void_RoomOk(void ** state){

int number =  2;
int mas[2] = {1,2};
room_t * self = NULL;
self  = room_new(number);
assert_non_null(self);
 room_free(self);

}

int main(void){

 const struct CMUnitTest tests[] = {

 cmocka_unit_test(new_void_CorpusOk),
 cmocka_unit_test(new_void_roomIsBusy),
 cmocka_unit_test(new_void_roomCount),
 cmocka_unit_test(new_void_emptySeats),
 cmocka_unit_test(new_void_NoEmptySeats),
 cmocka_unit_test( new_void_RoomOk),

 };

 return cmocka_run_group_tests(tests, NULL, NULL);
}
