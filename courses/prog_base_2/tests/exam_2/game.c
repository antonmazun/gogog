#include "game.h"
#include <stdlib.h>
#include <string.h>

struct game_s {
    char * name ;
    int year;
    char ** mods;
    int mods_count;
};

game_t * game_new(char * name, int year)
{
    game_t * game = malloc(sizeof(struct game_s));
    game->name = malloc(sizeof(char) * strlen(name));
    strcpy(game->name, name);
    game->year = year;
    game->mods = NULL;
    game->mods_count = 0;
    return game;
}

int game_get_year(game_t * game)
{
    return game->year;
}

char * game_get_name(game_t * game)
{
    return game->name;
}

char ** game_get_mods(game_t * game)
{
    return game->mods;
}

void game_add_mod(game_t * game, char * mod)
{
    char ** old_mods = game->mods;
    game->mods = malloc(sizeof(char *) * (game->mods_count + 1));
    if (old_mods != NULL)
    {
        for (int i = 0; i < game->mods_count; i++)
            game->mods[i] = old_mods[i];
        free(old_mods);
    }
    game->mods[game->mods_count] = malloc(sizeof(char) * strlen(mod));
    strcpy(game->mods[game->mods_count++], mod);
}

game_t * game_get_oldest(game_t ** games, int size)
{
    if (games == NULL)
        return NULL;
    int min = games[0]->year;
    game_t * oldest_game = games[0];
    for (int i = 0; i < size; i++)
        if (games[i]->year < min)
        {
            min = games[i]->year;
            oldest_game = games[i];
        }
    return oldest_game;
}
