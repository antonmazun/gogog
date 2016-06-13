#ifndef JSON_H
#define JSON_H
#include "list.h"
typedef struct admin_s {
    int id;
    char name[256];
    char surname[256];
    int birthdate;
    double rate;
    int creating_year;
    int followers;
} admin_t;

char * list_to_xml_id(list_t list, int i) ;
char * list_to_xml1(list_t list);
char * list_to_html_id(list_t list, int i);
char * list_to_html(list_t list);
list_t xml_to_list(char *text);
#endif
