/* show.c - small program emulating terminal's less command using ncurses library */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>

#define ESC 27 

void show(FILE * f, const char * f_name);
void update(FILE * f, WINDOW * w, int rows, int cols);

int main(int argc, char * argv[]){
 
    if (argc != 2){
        fprintf(stderr, "Correct usage should be: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE * p2f = fopen(argv[1], "r");
    if (p2f == NULL){
        fprintf(stderr, "Error: can't open %s !\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    show(p2f, argv[1]);
    fclose(p2f);
    return 0;
}

void update(FILE * f, WINDOW * w, int rows, int cols){

    int s;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if ((s = fgetc(f)) != EOF)
                wprintw(w, "%c", s);
            if (s == '\n')
                break;
        }
    }

    while ((s = wgetch(w)) != ESC){
        if (s == 32){
            for (int i = 0; i < cols; i++){
                if ((s = fgetc(f)) != EOF)
                    wprintw(w, "%c", s);
                if (s == '\n')
                    break;
            }
            wrefresh(w);
        }
    }
}

void show(FILE * f, const char * f_name){

    WINDOW * w, * inner_w;
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();
    printw("File: %s\n", f_name);
    refresh();

    w = newwin(LINES - 1, COLS - 1, 1, 1);
    box(w, 0, 0);
    wrefresh(w);

    inner_w = newwin(LINES - 3, COLS - 3, 2, 2);
    scrollok(inner_w, 1);
    keypad(inner_w, 1);
    update(f, inner_w, LINES - 3, COLS - 3);
    endwin();
}
