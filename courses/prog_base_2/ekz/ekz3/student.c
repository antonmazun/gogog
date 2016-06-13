#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include "datab.h"
#include "student.h"


void print(admin_t * p){

printf("\nname: %s\nsurname: %s\nPatronymic: %s\nByrthyear: %i \ncity : %s \nrank %f\n\n" ,  p->name , p->surname , p->patronymic , p->byrthyear, p->city , p->number);
}

void printList(admin_t * arr , int size){
for(int i =0 ; i < size ; i++)
    print(&arr[i]);
}
