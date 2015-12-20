#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct human {
	char name[150];
	char surname[150];
	int age;
	int weight;
	int high;
	
};


int main(void) {
	struct human p;
	struct human *pp;
	pp=&p;
	puts("Enter name:");
	fflush(stdin);
	gets(p.name);
	puts ("Enter surname:");
	fflush(stdin);
	gets(p.surname);
	puts("Enter age:");
	fflush(stdin);
	scanf("%i", &p.age);
	puts("Enter weight:");
	fflush(stdin);
	scanf("%i" , &p.weight);
	puts("Enter high");
	fflush(stdin);
	scanf("%i" , &p.high);
	
	printf("name: %s; surname: %s; age: %i; weight: %i; high: %i;" , pp->name, pp->surname, pp->age, pp->weight, pp->high);
	return 0;

}
