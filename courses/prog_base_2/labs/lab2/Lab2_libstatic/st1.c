#include "libstatic.h"
#include <stdio.h>
#include <stdlib.h>

struct word_s {

int size;
char * words[100];

};

 word_t * word_new(){

 word_t * self = malloc(sizeof(struct word_s));
 for(int i  = 0 ; i < 100; i++)
    self -> words[i] = NULL;
 self -> size  = 0;

 return self;

}


void word_add(word_t * self , char  * word){
self->words[self->size] = malloc(sizeof(strlen(word)));
strcpy(self->words[self->size++], word); // копі

 }

char * word_get(word_t * self  , int pos){

 if(pos < self->size && pos >= 0){

    return self->words[pos];


 }
else return NULL;
 }



 int word_count(word_t * self ){

 return self->size;

 }

void word_free(word_t * self){

for(int i = 0 ; i < self->size ; i++)
    free(self->words[i]);
free(self);

}
