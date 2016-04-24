#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include "datab.h"
#include "admin.h"


void print(admin_t * p){

printf("number %i\tname %s\tsurname %s\tHours %i\tdata %i\trank %d" , p->number , p->name , p->surname , p->hours , p->data ,p->Rank);
}

void printList(admin_t * arr , int size){

for(int i =0 ; i < size ; i++)
    print(&arr[i]);
}
