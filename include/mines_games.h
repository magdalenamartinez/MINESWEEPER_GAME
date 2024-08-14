/*
** June 2024
** Magdalena Martinez Sanchez
** MINES_GAME
** mines_games.h
*/

#ifndef MINES_GAMES_H
#define MINES_GAMES_H
    #define ERROR_EXIT 83
    #include <stdio.h>
    #include <stdlib.h>
    #include <ncurses.h>
    typedef struct map {
        char** map;
        int rows;
        int cols;
        int mines;
    } map_t;
    /*utilities.c*/
    int get_random_int(int min, int max);
    void play_sound(const char* sound_file);
    /*map.c*/
    void print_map(map_t* map);
    map_t* generate_map();
    void place_mines(map_t* new_map); 
    map_t* copy_map(map_t* original_map);
    /*ncurses.c*/
    void init_ncurses();
    void draw_grid(map_t* map);
    void handle_mouse(map_t* map, map_t *map_solved);
    void do_move(map_t* map, map_t* map_solved, int y, int x);
    /*calculate.c*/
    void calculate_adjacent(map_t* map);
    void reveal_empty(map_t* map, map_t* map_solved, int y, int x);
    

#endif /*MINES_GAMES_H*/