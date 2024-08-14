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

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
    }
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
                play_sound("bueno.wav");
                break;
            case KEY_DOWN:
                if (y < map->rows * 2 - 1) y += 2;
                play_sound("bueno.wav");
                break;
            case KEY_LEFT:
                if (x > 1) x -= 2;
                play_sound("bueno.wav");
                break;
            case KEY_RIGHT:
                if (x < map->cols * 2 - 1) x += 2;
                play_sound("bueno.wav");
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
            play_sound("boom.wav");
            //poner game over
            attron(COLOR_PAIR(1)); // Activar el color rojo para el mensaje
            mvprintw(map->rows * 2 + 2, 0, "GAME OVER! Press any key to exit.");
            attroff(COLOR_PAIR(1));
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
