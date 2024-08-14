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
       //RESOLVEMOS MAPA
       map_t* map_solved = copy_map(map);
       place_mines(map_solved);
       calculate_adjacent(map_solved);

       print_map(map);

       init_ncurses();
       draw_grid(map);
       while (1) {
            handle_mouse(map, map_solved);
        }


    } else {
        return ERROR_EXIT;
    }
}



