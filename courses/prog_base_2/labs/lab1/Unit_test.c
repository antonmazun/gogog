#include <stdio.h>
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  //
#include <cmocka.h>
#include "corpus.h"
#include <time.h>

static void corpus_new__roomsAndSeats__self(void ** state){

corpus_t * self = NULL;
int number = 4;
int mas[4]  = { 1 , 2 , 3 , 4};
self  = corpus_new(number , mas);
 assert_non_null(self);
 corpus_free(self);
}

static void room_busy__self__0OR1( void ** state){

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

static void corpus_Room_count__self__roomCount(void ** state){

int number =  2;
int mas[2] = {1,2};
corpus_t * corpus  = NULL;
corpus = corpus_new(number , mas);
assert_int_equal(corpus_roomCount(corpus) , 2);
corpus_free(corpus);

}


static void room_empty_seats__self__emptySeats(void ** state){

int number =  2;
int mas[2] = {1,2};
corpus_t * corpus = corpus_new(number , mas);
room_t * room =  return_room( corpus,  1);
assert_int_equal(room_empty_seats(room) , 2);
corpus_free(corpus);
}


static void room_empty_seats__self__NoemptySeats(void ** state){

int number =  2;
int mas[2] = {1,2};
corpus_t * corpus = corpus_new(number , mas);
room_t * room =  return_room( corpus,  5);
assert_null(room);// повертає нал
corpus_free(corpus);
}


static void room_new__seats__self(void ** state){

int number =  2;
int mas[2] = {1,2};
room_t * self = NULL;
self  = room_new(number);
assert_non_null(self);
 room_free(self);

}

int main(void){

 const struct CMUnitTest tests[] = {

 cmocka_unit_test(corpus_new__roomsAndSeats__self),
 cmocka_unit_test(room_busy__self__0OR1),
 cmocka_unit_test(corpus_Room_count__self__roomCount),
 cmocka_unit_test(room_empty_seats__self__emptySeats),
 cmocka_unit_test(room_empty_seats__self__NoemptySeats),
 cmocka_unit_test(room_new__seats__self),

 };

 return cmocka_run_group_tests(tests, NULL, NULL);
}
