#include <stdlib.h>
#include "list.h"
#include "event.h"
#include <limits.h>
//#include <cmocka.h>

struct list_node_s{
    struct list_node_s * next;
    struct list_node_s * prev;
    int data;
};

struct list_s{
    struct list_node_s * head;
    struct list_node_s * tail;
    int size;
    events_t events[4];// масив юзерів які підписані на подію;

};


void list_sum_check(list_t list){
    int i;
    struct list_node_s * cur_node = list->head->next;
    int sum = 0;
    for (i = 0; i < list->size; i++)
    {
        sum += cur_node->data;
        cur_node = cur_node->next;
    }
    if (sum > 100)
        events_sum(list->events[3]);
}

list_t list_new ()
{
    int i ;
    list_t list = malloc(sizeof(struct list_s));
    list->head = malloc(sizeof(struct list_node_s));
    list->tail = malloc(sizeof(struct list_node_s));
    list->head->prev = NULL;
    list->tail->next = NULL;
    list->head->next = list->tail;
    list->tail->prev = list->head;
    list->size = 0;
    for( i = 0 ; i < 4 ; i++){

        list->events[i] = events_new();

    }

    return list;
}

void list_add(list_t list, int data, int pos)
{   int i;
    struct list_node_s * new_node = malloc(sizeof(struct list_node_s));

    struct list_node_s * cur_node = list->head;
    if (list->size < pos)
        pos = list->size;
    for (i = 0; i < pos; i++)
    {
        cur_node = cur_node->next;
    }
    new_node->data = data;
    new_node->prev = cur_node;
    new_node->next = cur_node->next;
    cur_node->next->prev = new_node;
    cur_node->next = new_node;
    list->size++;
    events_add(list->events[0], data, pos);
    list_sum_check(list);
}

int list_del(list_t list, int pos)
{
    int i;
    int data;
    struct list_node_s * cur_node = list->head->next;
    if (list->tail == cur_node)
        return INT_MIN;
    if (pos >= list->size )
    {
        pos = list->size - 1;
    }
    for (i = 0; i < pos; i++)
        cur_node = cur_node->next;
    data = cur_node->data;
    cur_node->prev->next = cur_node->next;
    cur_node->next->prev = cur_node->prev;
    free(cur_node);
    list->size--;
    events_del(list->events[1], data, pos);
    list_sum_check(list);
    return data;
}


int list_change(list_t list, int data, int pos)
{
    int i;
    int tmp_data;
    struct list_node_s * cur_node = list->head->next;
          puts("done");
    if (list->tail == cur_node)
        return INT_MIN;
    if (pos >= list->size )
    {
        return INT_MIN;
    }


    for (i = 0; i < pos; i++)
        cur_node = cur_node->next;
    tmp_data = cur_node->data;
    cur_node->data = data;
    events_change(list->events[2], tmp_data, data, pos);
    list_sum_check(list);
    return tmp_data;
}

events_t * list_get_events(list_t list) //повертаэ маив подый
{
    return list->events;
}

int list_size(list_t list)
{
    return list->size;
}

void list_free(list_t list)
{
    int i;
    for (i = 0; i < list->size; i++)
        list_del(list, 0);
    free(list->tail);
    free(list->head);
    free(list);
}
