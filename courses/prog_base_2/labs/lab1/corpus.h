#ifndef CORPUS_H_INCLUDED
#define CORPUS_H_INCLUDED
#include "room.h"

typedef struct Corpus_s corpus_t;

corpus_t * corpus_new(int rooms , int seats[rooms] );
int corpus_roomCount(corpus_t * self);
void corpus_free(corpus_t * self);
room_t * corpus_return_room(corpus_t * self , int index);

#endif // CORPUS_H_INCLUDED
