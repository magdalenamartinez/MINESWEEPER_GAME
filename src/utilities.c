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

void play_sound(const char* sound_file)
{
    // Ejecuta el comando afplay en segundo plano usando "&"
    char command[256];
    snprintf(command, sizeof(command), "afplay %s &", sound_file);
    system(command);
}