#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

typedef struct admin_s{

int number;
char name[100];
char surname[100];
int hours;
int data;
double Rank;
} admin_t;

void print(admin_t * p);
void printList(admin_t * arr , int size);


#endif // ADMIN_H_INCLUDED
