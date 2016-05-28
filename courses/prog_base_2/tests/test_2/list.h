#ifndef _LIST
#define _LIST

typedef struct list list;
list* list_new();
void list_delete(list* l);
void list_resize(list* l, int newCap);

void list_push(list* l, void* ptr);
void* list_pop(list* l);

void** list_at(list* l, int pos);

int list_size(list* l);
int list_capacity(list * l);

#endif
