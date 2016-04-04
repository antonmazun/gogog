#include <stdio.h>
#include <stdlib.h>
#include "corpus.h"
#include "room.h"
#include <time.h>

struct Corpus_s {

    room_t ** rooms; // масив вказівників
    int roomCount;
};

corpus_t * corpus_new(int rooms , int seats[rooms] ){ // number з тесту передається як rooms конструктор

corpus_t * self = malloc(sizeof(struct Corpus_s));
if(self == NULL || rooms <= 0)
    return NULL;
self->roomCount = rooms;
self ->rooms = malloc(sizeof(room_t *) * rooms);
for(int i =0; i < rooms ; i++)
    self->rooms[i] = room_new(seats[i]);
return self;
}


void corpus_free(corpus_t * self){

for(int i = 0; i < self->roomCount; i++)
    room_free(self->rooms[i]);
    free(self);
}



int corpus_roomCount(corpus_t * self){ // кількість аудиторій

return self->roomCount;
}



room_t * return_room(corpus_t * self , int index){  //повертає  пусту аудиторію з корпусу;
if(index < self->roomCount && index >= 0)
    return self->rooms[index];
else
    return NULL;
}
