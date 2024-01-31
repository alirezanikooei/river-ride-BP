#include <ncurses.h>
#include <string.h>

#define MAX_LEN 1000

int print_image(char name[]);

int print_image(char name[])
{
    // Initialize ncurses
    initscr();
    cbreak(); // Line buffering disabled
    noecho(); // Don't echo while we do getch

    char filename[strlen(name) + 10];
    strcpy(filename, "image/");
    strcat(filename, name);
    strcat(filename, ".txt");
    FILE *fptr = NULL;
    char read_string[MAX_LEN];
    if ((fptr = fopen(filename, "r")) == NULL)
    {
        // Print error message using ncurses
        printw("error opening %s\n", filename);
        refresh();
        endwin(); // Clean up ncurses before returning
        return -1;
    }
    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printw("%s", read_string);
    printw("\n");
    fclose(fptr);

    // Clean up ncurses
    refresh();
    return 0;
}
int print_imageXY(char name[], objP ob, int *row, int *len, int board[][400], objP airplane)
{

    // if(!strcmp("bomber",ob->fileShape)){}
    char filename[strlen(name) + 10];
    strcpy(filename, "image/");
    strcat(filename, name);
    strcat(filename, ".txt");
    FILE *fptr = NULL;
    char read_string[MAX_LEN];
    if ((fptr = fopen(filename, "r")) == NULL)
    {
        // Print error message using ncurses
        printw("error opening %s\n", filename);
        refresh();
        endwin(); // Clean up ncurses before returning
        exit(-1);
        return -1;
    }
    char shape[MAX_LINE_LENGTH] = {};
    *len = 0;
    *row = 0;
    while (fgets(shape, MAX_LINE_LENGTH, fptr) != NULL)
    {
        // Print each line of the shape at the desired position
        if (strlen(shape) > *len)
            *len = strlen(shape);
        // move(getcury(stdscr), getcurx(stdscr) + 5);
        for (int i = 0; i < strlen(shape); i++)
        {
            if (shape[i] == ' ' || shape[i] == '\n' || shape[i] == '\t' || shape[i] == '\r')
                continue;
            mvprintw(ob->y + 35 + *row, ob->x - 25 + i, "%c", shape[i]);
            int row_i = ob->x - 25 + i + 50;
            int col_i = ob->y + 35 + (*row) + 50;
            if (!strcmp(ob->fileShape, "airplane"))
                board[row_i][col_i] = 1;
            else if (!strcmp(ob->fileShape, "shoot"))
            {
                board[row_i][col_i] = ob->id;
            }
            else if (!strcmp(ob->fileShape, "shoot.enemy"))
            {
                if (board[row_i][col_i] == 1)
                {
                    airplane->health -= ob->damage;
                    board[row_i][col_i] = 0;
                    delete_enemy(ob->id, airplane);
                    fclose(fptr);
                    refresh();
                    return 0;
                }
            }else if (!strcmp(ob->fileShape, "bomb"))
            {
                if (board[row_i][col_i] == 1)
                {
                    airplane->health -= ob->damage;
                    board[row_i][col_i] = 0;
                    delete_enemy(ob->id, airplane);
                    fclose(fptr);
                    refresh();
                    return 0;
                }
            }else if (!strcmp(ob->fileShape, "bomber"))
            {
                if (board[row_i][col_i] == 1)
                {
                    ob->airplane->health -= ob->damage;
                    board[row_i][col_i] = 0;
                    delete_enemy(ob->id, ob->airplane);
                    fclose(fptr);
                    refresh();
                    return 0;
                } else if (board[row_i][col_i] >= 2)
                {
                    board[row_i][col_i] == 0;
                    if (ob && ob->airplane->id)
                        delete_enemy(ob->id, ob->airplane);
                    fclose(fptr);
                    refresh();
                    return 0;
                }
            }
            else
            {
                if (board[row_i][col_i] == 1)
                {
                    airplane->health -= ob->damage;
                    if (ob && airplane->id)
                        delete_enemy(ob->id, airplane);
                    board[row_i][col_i] = 0;
                    fclose(fptr);
                    refresh();
                    return 0;
                }
                else if (board[row_i][col_i] >= 2)
                {
                    board[row_i][col_i] == 0;
                    if (ob && airplane->id)
                        delete_enemy(ob->id, airplane);
                    fclose(fptr);
                    refresh();
                    return 0;
                }
            }
        }

        (*row)++;
    }
    fclose(fptr);
    refresh();
    return 0;
}
