#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "room.h"
#include "corpus.h"


struct Room_s {

int seats;
int time;

};

room_t * room_new(int seats){

room_t * self = malloc(sizeof(struct Room_s));

self->time = clock();
self->seats  = seats;

return self;

}

void room_free(room_t * self){

free(self);
}

int room_empty_seats(room_t * self){ //  повертає вільні місцця в аудиторії

return self->seats;
}


int room_take(room_t * self , int time){ // функція зайняття аудиторії на певний час(якщо беру на 10хв об 13 год то буде вільна в 13,10)
                                        // це робить іф

if( self->time <= clock()){

    self->time = time * CLOCKS_PER_SEC + clock(); //time - це час на який я хочу взяти аудит , CLOCKS_PER_SEC - тікі проц/сек , клок() - поточний час
    }
else
    return 1;

return 0;

}


int room_busy(room_t * self){
if(self->time > clock())
    return 1;
else
    return 0;

}


