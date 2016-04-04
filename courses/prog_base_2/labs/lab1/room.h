#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

typedef struct Room_s room_t;
room_t *room_new(int seats);
void room_free(room_t * self);
int room_empty_seats(room_t * self);
int room_empty_number(room_t * self);
int room_take(room_t * self , int time);
int room_busy(room_t * self);

#endif // ROOM_H_INCLUDED
