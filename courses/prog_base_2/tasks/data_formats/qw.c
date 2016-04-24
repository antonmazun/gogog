#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>




// gcc main.c cJSON.c -lm
int main() {
	FILE * fr = fopen("Admin.json", "r");
    char text[10000];
    char line[10000];
    int size = 2;
    admin * p[size];            // create array of struture pointers

   for (int i = 0; i < size; i++){ // fill it
    p[i] = admin_create();
    }
    while(fgets(line, 10000, fr) != NULL) {  // read file
        strcat(text, line);
    }
    parse(text,p);
                    // to parse json file


	for (int i = 0; i < size; i++){
    admin_free(p[i]);
    }
	return 0;
}
