/*
** June 2024
** Magdalena Martinez Sanchez
** MINES_GAME
** calculate.c
*/

#include "../include/mines_games.h"

void calculate_adjacent(map_t* map)
{
    int directions[8][2] = {
        {-1, -1},  {-1, 0},  {-1, 1},
        { 0, -1},            { 0, 1},
        { 1, -1},  { 1, 0},  { 1, 1}
    };

    //EMPEZAMOS EN 1 PARA EVITAR LOS BORDES
    for (int i = 1; i < map->rows * 2; i+=2) {
        for (int j = 1; j < map->cols * 2; j+=2) {
            if (map->map[i][j] == ' ') {
                int mines_counter = 0;
                //contamos las minas adyacentes para cada celda del mapa
                for(int d = 0; d < 8; d++) {
                    int di = i + directions[d][0] * 2; //desplazamiento de filas
                    int dj = j + directions[d][1] * 2; //desplazamiento de columnas

                    if (di >= 1 && di < map->rows * 2 && dj >= 1 && dj < map->cols * 2) {
                        if (map->map[di][dj] == 'X') {
                            mines_counter++;
                        }
                    }
                }

                if (mines_counter > 0) {
                    map->map[i][j] = '0' + mines_counter;
                }
            }
        }
    }
}


void reveal_empty(map_t* map, map_t* map_solved, int y, int x)
{
    int directions[8][2] = {
        {-1, -1},  {-1, 0},  {-1, 1},
        { 0, -1},            { 0, 1},
        { 1, -1},  { 1, 0},  { 1, 1}
    };;

    if (y < 1 || y >= map->rows * 2 || x < 1 || x >= map->cols * 2 || map_solved->map[y][x] != ' ') {
        return;
    }

    map->map[y][x] = 'o';
    map_solved->map[y][x] = 'o';


    for(int d = 0; d < 8; d++) {
        int di = y + directions[d][0] * 2; //desplazamiento de filas
        int dj = x + directions[d][1] * 2; //desplazamiento de columnas

        if (di >= 1 && di < map->rows * 2 && dj >= 1 && dj < map->cols * 2 && map_solved->map[di][dj] == ' ') {
            reveal_empty(map, map_solved, di, dj);
        }
    }
}