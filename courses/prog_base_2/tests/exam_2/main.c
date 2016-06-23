#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "main.h"

static void game_test1(void ** state)
{
    int size = 5;
    game_t * game[size];
    game[0] = game_new("Skyrim", 2011);
    game[1] = game_new("Witcher", 2007);
    game[2] = game_new("Most Wanted", 2005);
    game[3] = game_new("Underground", 2003);
    game[4] = game_new("Assasins Creed", 2007);
    assert_int_equal(2003, game_get_year(game_get_oldest(game, size)));
}

static void game_test2(void ** state)
{
    int size = 5;
    game_t * game[size];
    game[0] = game_new("Skyrim", 2011);
    game[1] = game_new("Witcher", 2007);
    game[2] = game_new("Most Wanted", 2003);
    game[3] = game_new("Undergtound", 2003);
    game[4] = game_new("Assasins Creed", 2007);
    assert_int_equal(2003, game_get_year(game_get_oldest(game, size)));
    assert_string_equal("Most Wanted", game_get_name(game_get_oldest(game, size)));
}

static void game_test3(void ** state)
{
    int size = 5;
    game_t * game[size];
    game[0] = game_new("Skyrim", 2011);
    game[1] = game_new("Witcher", 2007);
    game[2] = game_new("Most Wanted", 1998);
    game[3] = game_new("Undergtound", 2003);
    game[4] = game_new("Assasins Creed", 2007);
    assert_int_equal(1998, game_get_year(game_get_oldest(game, size)));
    assert_string_equal("Most Wanted", game_get_name(game_get_oldest(game, size)));
}

static void game_test4(void ** state)
{
    game_t ** game = NULL;
    assert_null(game_get_oldest(game, 9));
}

int main(){

    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(game_test1),
        cmocka_unit_test(game_test2),
        cmocka_unit_test(game_test3),
        cmocka_unit_test(game_test4),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
