#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "parse.h"
struct Network{
char  name[25];
char language[15];
int release;

};
struct Admin{
char  name[20];
char  surname[20];
char  birthdate[20];
char  company[20];
int hours;
struct Network net[1];
};

admin * admin_create(){
admin * p = malloc(sizeof(struct Admin));
return p;
}


void set_admin (admin * p,char * admin_name,char * admin_surn, char * admin_birthdate, char * admin_company, int hours){
strcpy(p->name,admin_name);
strcpy(p->surname,admin_surn);
strcpy(p->birthdate,admin_birthdate);
strcpy(p->company,admin_company);
p->hours = hours;
}

void set_network(admin * p,char * network_name, char * network_language , /*int release ,*/int i){
strcpy(p->net[i].name,network_name);
strcpy(p->net[i].language,network_language);
//strcpy(p->net[i].release ,network_release);
}

void admin_print(admin * p){
printf("Name: %s, Surname: %s, Birthdate: %s, Company: %s", p->name,p->surname,p->birthdate,p->company);
for (int i =0 ; i < 1; i++){
    printf("Network: %s, Language: %s, Release: %s", p->net[i].name,p->net[i].language,p->net[i].release);
}

printf("\n\n");
}

void admin_free(admin * p){
free(p);
}
