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
    int percentage = get_random_int(5, 45);

    new_map->mines = (int)(((float)percentage / 100) * (new_map->rows * new_map->cols)); 

    //Doble de espacio para las celdas
    new_map->map = malloc(sizeof(char*) * (new_map->rows * 2 + 1));

    for (int i = 0; i < new_map->rows * 2 + 1; i++) {
        new_map->map[i] = malloc(sizeof(char) * (new_map->cols * 2 + 1));
        for (int j = 0; j < new_map->cols * 2 + 1; j++) {
            if (i % 2 == 0) { //borde
                new_map->map[i][j] = '-';
            } else if (j % 2 == 0) { //borde
                new_map->map[i][j] = '|';
            } else {
                new_map->map[i][j] = ' ';
            }
            if (j == 0) { //borde
                new_map->map[i][j] = '|';
            }
        }
        new_map->map[i][new_map->cols * 2] = '|';
        new_map->map[i][new_map->cols * 2 + 1] = '\0';
    }

    return new_map;
}

map_t* copy_map(map_t* original_map)
{
    map_t* new_map = (map_t*) malloc(sizeof(map_t));
    new_map->rows = original_map->rows;
    new_map->cols = original_map->cols;
    new_map->mines = original_map->mines;

    new_map->map = malloc(sizeof(char*) * (new_map->rows * 2 + 1));

    for (int i = 0; i < new_map->rows * 2 + 1; i++) {
        new_map->map[i] = malloc(sizeof(char) * (new_map->cols * 2 + 1));
        for (int j = 0; j < new_map->cols * 2 + 1; j++) {
            new_map->map[i][j] = original_map->map[i][j];
        }
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

void place_mines(map_t* new_map) 
{
   int mines_placed = 0;
    while (mines_placed < new_map->mines) {
        int row = get_random_int(1, new_map->rows * 2);
        int col = get_random_int(1, new_map->cols * 2);
        
        if (row % 2 != 0 && col % 2 != 0 && new_map->map[row][col] == ' ') {
            new_map->map[row][col] = 'X';
            mines_placed++;
        }
    }
}