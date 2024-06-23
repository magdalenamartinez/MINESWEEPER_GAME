/*
** June 2024
** Magdalena Martinez Sanchez
** MINES_GAME
** utilities.c
*/

#include "../include/mines_games.h"

int get_random_int(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}