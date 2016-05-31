#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED
#include "user.h"
typedef struct events_s * events_t;
typedef struct user_s * user_t;
events_t events_new();
void events_add(events_t ev, int data, int pos);
void events_del(events_t ev, int data, int pos);
void events_change(events_t ev, int bef_data, int cur_data, int pos);
void events_add_callback(events_t events, void * clb);
int events_contains_user(events_t events, void * clb);
void events_sum(events_t ev);

#endif // EVENT_H_INCLUDED
