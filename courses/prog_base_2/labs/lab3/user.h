#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "event.h"
#include "list.h"
typedef struct list_s * list_t;
typedef struct user_s * user_t;
typedef struct events_s * events_t;
typedef void (*elem_add)(int data, int pos);
typedef void (*elem_del)(int data, int pos);
typedef void (*elem_change)(int bef_data, int cur_data, int pos);
typedef void (*elem_sum)();
elem_add user_add(user_t user);
elem_del user_del(user_t user);
elem_change user_change(user_t user);
elem_sum user_sum(user_t user);

user_t user_new(int id);
void user_del_subscribe(user_t user, elem_del callb, list_t list);
void user_add_subscribe(user_t user, elem_add callb, list_t list);
void user_change_subscribe(user_t user, elem_change callb, list_t list);
void user_sum_subscribe(user_t user, elem_add callb, list_t list);

#endif // USER_H_INCLUDED
