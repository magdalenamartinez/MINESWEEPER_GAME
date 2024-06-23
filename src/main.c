/*
** June 2024
** Magdalena Martinez Sanchez
** MINES_GAME
** main.c
*/

#include "../include/mines_games.h"

int main(int argc, char** argv)
{
    if (argc == 1) {
       map_t* map = generate_map();
       print_map(map);
       init_ncurses();
       draw_grid(map);
       while (1) {
            handle_mouse(map);
        }

    } else {
        return ERROR_EXIT;
    }
}



