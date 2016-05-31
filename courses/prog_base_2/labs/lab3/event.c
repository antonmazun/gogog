#include "event.h"
#include <stdlib.h>
#include <stdio.h>

struct events_s{


    void * clb[5]; // вказывник на масив колбеків

};



events_t events_new()
{
    int i;
    events_t events = malloc(sizeof(struct events_s));
    for (i = 0; i < 5; i++)
    {
        events->clb[i] = NULL;
    }
    return events;
}

int events_contains_user(events_t events, void * clb) // провіряє чи містить подія цей колбек
{
    int i;
    for (i = 0; i < 5; i++)
        if (events->clb[i] == clb)
            return 1;
    return 0;
}

void events_add_callback(events_t events, void * clb) // добавляється колбек в івент
{
    int i;
    for (i = 0; i < 5; i++)
        if (events->clb[i] == NULL)
        {
            events->clb[i] = clb;
            break;
        }
}

void events_add(events_t ev, int data, int pos)
{
  int i;

    for (i = 0; i < 5; i++)
        // puts("22222");
        if (ev->clb[i] != NULL)
    {


           ((elem_add)ev->clb[i])(data, pos); // викликає всі колбеки при події адд

    }
}

void events_del(events_t ev, int data, int pos) //
{
  int i;
    for (i = 0; i < 5; i++)
        if (ev->clb[i] != NULL)
           ((elem_del)ev->clb[i])(data, pos); //викликає всі колбеки при подіїї дел

}

void events_change(events_t ev, int bef_data, int cur_data, int pos)
{
  int i;
    for (i = 0; i  < 5; i++)
        if (ev->clb[i] != NULL)
           ((elem_change)ev->clb[i])(bef_data, cur_data, pos);
}

void events_sum(events_t ev) //
{
    int i;
    for (i = 0; i < 5; i++)
        if (ev->clb[i] != NULL)
           ((elem_sum)ev->clb[i])();// виклик  всіх колбеків коли сума більша 100
}
