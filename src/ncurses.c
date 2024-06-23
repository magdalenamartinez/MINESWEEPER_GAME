/*
** June 2024
** Magdalena Martinez Sanchez
** MINES_GAME
** ncurses.c
*/

#include "../include/mines_games.h"

void init_ncurses() 
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
}

void draw_grid(map_t* map)
{
    for (int i = 0; i < map->rows * 2 + 1; i++) {
        for (int j = 0; j < map->cols * 2 + 1; j++) {
            move(i, j);
            addch(map->map[i][j]);
        }
    }
    refresh();
}

void handle_mouse(map_t* map) 
{
    int ch;
    int x = 1, y = 1;

    move(y, x);
    refresh();

    while ((ch = getch()) != 'q') {
        switch (ch) {
            case KEY_UP:
                if (y > 1) y -= 2;
                break;
            case KEY_DOWN:
                if (y < map->rows * 2 - 1) y += 2;
                break;
            case KEY_LEFT:
                if (x > 1) x -= 2;
                break;
            case KEY_RIGHT:
                if (x < map->cols * 2 - 1) x += 2;
                break;
            case '\n': // Enter key
                if (map->map[y][x] == 'o') {
                    map->map[y][x] = 'X';
                    mvaddch(y, x, 'X');
                }
                refresh();
                break;
        }
        move(y, x);
        refresh();
    }
}