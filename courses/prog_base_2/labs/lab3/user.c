#include "user.h"
#include <stdlib.h>
struct user_s{
    int id;
    elem_add add;
    elem_change change;
    elem_del del;
    elem_sum sum;
};

user_t user_new(int id)
{
    user_t user = malloc(sizeof(struct user_s));
    user->id = id;
    user->add = NULL;
    user->del = NULL;
    user->change = NULL;
    user->sum = NULL;
    return user;
}

elem_add user_add(user_t user)
{
    if (user == NULL)
        return NULL;
    return user->add;
}

elem_del user_del(user_t user)
{
    if (user == NULL)
        return NULL;
    return user->del;
}

elem_change user_change(user_t user) //повернути вазівник на кол бек функцію
{
    if (user == NULL)
        return NULL;
    return user->change;
}

void user_add_subscribe(user_t user, elem_add callb, list_t list)// записує кол бек
{
    user->add = callb;
    if (!events_contains_user(list_get_events(list)[0], callb))
    {
        events_add_callback(list_get_events(list)[0], callb);
    }
}

void user_del_subscribe(user_t user, elem_del callb, list_t list) //  підписатись на подію видалення елементу зі списку
{
    user->del = callb;
    if (!events_contains_user(list_get_events(list)[1], callb))
    {
        events_add_callback(list_get_events(list)[1], callb);
    }
}

void user_change_subscribe(user_t user, elem_change callb, list_t list) //підписатись на функцію чендж
{
    user->change = callb;
    if (!events_contains_user(list_get_events(list)[2], callb))
    {
        events_add_callback(list_get_events(list)[2], callb);
    }
}

void user_sum_subscribe(user_t user, elem_add callb, list_t list) // підписатись на функцію перевірки
{
    user->sum = callb;
    if (!events_contains_user(list_get_events(list)[3], callb))
    {
        events_add_callback(list_get_events(list)[3], callb);
    }
}

elem_sum user_sum(user_t user) // повертає кол бек
{
    if (user == NULL)
        return NULL;
    return user->sum;
}
