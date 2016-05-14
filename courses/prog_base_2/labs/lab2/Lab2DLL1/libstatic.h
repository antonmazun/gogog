#ifndef LIBSTATIC_H_INCLUDED
#define LIBSTATIC_H_INCLUDED

typedef struct word_s word_t ;
word_t * word_new();
void word_add(word_t * self , char  * word);
char * word_get(word_t * self  , int pos);
int word_count(word_t * self );
void word_free(word_t * self);


#endif // LIBSTATIC_H_INCLUDED
