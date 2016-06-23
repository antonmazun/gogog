#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

typedef struct game_s game_t;
game_t * game_get_oldest(game_t ** games, int size);
void game_add_mod(game_t * game, char * mod);
char ** game_get_mods(game_t * game);
char * game_get_name(game_t * game);
int game_get_year(game_t * game);
game_t * game_new(char * name, int year);

#endif // GAME_H_INCLUDED
