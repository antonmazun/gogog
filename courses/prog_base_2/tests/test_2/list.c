#include "list.h"

#include <stdlib.h>

#define EL_SIZE (sizeof(void*))

struct list{
  void** data;
  int size;
  int capacity;
};

list* list_new(){
  list* ret;
  ret = malloc(sizeof(list));
  ret->data = malloc(EL_SIZE * 10);
  ret->size = 0;
  ret->capacity = 10;
  return ret;
}
void list_delete(list* l){
  free(l->data);
  free(l);
}
void list_resize(list* l, int newCap){
  l->data =  realloc(l->data, EL_SIZE * newCap);
  l->capacity = newCap;
  if(newCap < l -> size) l->size = newCap;
}

void list_push(list* l, void* e){
  if(l->size + 1 >= l->capacity)
    list_resize(l, l->capacity * 2 + 1);
  l->data[l->size++] = e;
}

void* list_pop(list* l){
  if(l->size == 0)
    return NULL;
  else return l->data[--l->size];
}

void** list_at(list* l,int pos){
  if(pos > l->size || pos < 0 )
    return NULL;
  return l->data[pos];
}

int list_size(list* l){
  return l->size;
}

int list_capacity(list* l){
  return l->capacity;
}
