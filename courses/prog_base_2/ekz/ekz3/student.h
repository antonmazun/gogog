#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

typedef struct admin_s{


char name[100];
char surname[100];
char patronymic[150];
int byrthyear;
char city[150];

double number;
} admin_t;

void print(admin_t * p);
void printList(admin_t * arr , int size);


#endif // ADMIN_H_INCLUDED
