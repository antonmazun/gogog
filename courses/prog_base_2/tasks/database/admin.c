#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include "datab.h"
#include "admin.h"


void print(admin_t * p){

printf("number: %i\nname: %s\nsurname: %s\nSubscribes: %i\nYears: %i\nrank %f\n\n" , p->number , p->name , p->surname , p->subscribes , p->years ,p->Rank);
}

void printList(admin_t * arr , int size){
for(int i =0 ; i < size ; i++)
    print(&arr[i]);
}
