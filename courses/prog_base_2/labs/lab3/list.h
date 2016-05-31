#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "event.h"
typedef struct list_s * list_t;
typedef struct events_s * events_t;
int list_size(list_t list);
int list_change(list_t list, int data, int pos);
int list_del(list_t list, int pos);
void list_add(list_t list, int data, int pos);
list_t list_new();
events_t * list_get_events(list_t list);
#endif // LIST_H_INCLUDEDs
