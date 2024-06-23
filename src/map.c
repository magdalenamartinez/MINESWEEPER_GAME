/*
** June 2024
** Magdalena Martinez Sanchez
** MINES_GAME
** map.c
*/

#include "../include/mines_games.h"


map_t* generate_map()
{
    map_t* new_map = (map_t*) malloc(sizeof(map_t));
    new_map->rows = get_random_int(5, 20);
    new_map->cols = new_map->rows * 2;
    int percentage = get_random_int(20, 50);
    new_map->mines = (percentage/100) * new_map->rows; 

    //Doble de espacio para las celdas
    new_map->map = malloc(sizeof(char*) * (new_map->rows * 2 + 1));
    for (int i = 0; i < new_map->rows * 2 + 1; i++) {
        new_map->map[i] = malloc(sizeof(char) * (new_map->cols * 2 + 1));
        for (int j = 0; j < new_map->cols * 2 + 1; j++) {
            if (i % 2 == 0 ) {
                new_map->map[i][j] = '-';
            } else if ( j % 2 == 0) {
                new_map->map[i][j] = '|';
            } else {
                new_map->map[i][j] = 'o';
            }
            if (j == 0) {
                new_map->map[i][j] = '|';
            }
        }
        new_map->map[i][new_map->cols * 2] = '|';
       
        new_map->map[i][new_map->cols * 2 + 1] = '\0';
    }
    return new_map;
}

void print_map(map_t* map)
{
    for (int i = 0; i < map->rows * 2 + 1; i++) {
        for (int j = 0; j < map->cols * 2 + 2; j++) {
            printf("%c", map->map[i][j]);
        }
        printf("\n");
    }
}