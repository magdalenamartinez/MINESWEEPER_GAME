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

/*
    KEY UP - DOWN - LEFT - RIGHT -> para moverse, no realiza ninguna accion
    si pulsa enter -> se estudia la posicion
*/
void handle_mouse(map_t* map, map_t *map_solved) 
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
                do_move(map, map_solved, y, x);
                /*if (map->map[y][x] == ' ') {
                    map->map[y][x] = 'X';
                    mvaddch(y, x, 'X');
                }*/
                refresh();
                break;
        }
        move(y, x);
        refresh();
    }
}

void do_move(map_t* map, map_t* map_solved, int y, int x)
{
    switch (map_solved->map[y][x])
    {
        case 'X': 
            for (int i = 0; i < map->rows * 2 + 1; i++) {
                for (int j = 0; j < map->cols * 2 + 1; j++) {
                    map->map[i][j] = map_solved->map[i][j];
                    if (map->map[i][j] == ' ') {
                        map->map[i][j] = 'o';
                    }
                }
            }
            draw_grid(map);
            //poner game over
            printw("\nGame Over! Press any key to exit.\n");
            getch();
            exit(0);
            refresh();
            break;
        case ' ': 
            //recorrer y poner o
            reveal_empty(map, map_solved, y, x);
            draw_grid(map);
            refresh();
            break;
        default:
            map->map[y][x] = map_solved->map[y][x];
            mvaddch(y, x, map->map[y][x]);
            refresh();
            break;  
    }    
}
