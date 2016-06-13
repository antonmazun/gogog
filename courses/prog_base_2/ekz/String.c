#include "string.h"
#include "stdio.h"

int count_string(char * s1 , char * s2){

    int i;
    int count = 0;
   // char * tmp = s1;

   while((strstr(s1 , s2)) != NULL){

    count++;
   }
   return count;
}
