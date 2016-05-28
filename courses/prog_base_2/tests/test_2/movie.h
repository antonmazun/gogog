#ifndef _MOVIE
#define _MOVIE
#include <time.h>
#include "encoding.h"

#define MAX_MOVIE_NAME_LENGTH 40

typedef struct Movie {
  char name[MAX_MOVIE_NAME_LENGTH];
  int year;
  time_t discover_time;
} Movie;

void movie_from_xml(Movie* m, char* s);
char* movie_to_xml(Movie* m);

#endif
