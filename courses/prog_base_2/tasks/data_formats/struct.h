#include <stdio.h>

typedef struct Admin admin;
admin * admin_create();
void set_network(admin * p,char * network_name, char * network_language ,/* int release */int i);
void set_admin(admin * p,char * admin_name,char * admin_surn, char * admin_birthdate, char * admin_company, int hours);
void admin_free(admin * p);
void admin_print(admin * p);
