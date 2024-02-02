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
int print_image_score(char name[], int x, int y)
{

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
    int row = 0;
    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
    {
        mvprintw(10 + y + row, x, "%s", read_string);
        row++;
    }
    fclose(fptr);
    refresh();
    return 0;
}
int print_imageXY(char name[], objP ob, int *row, int *len, int board[][400], objP airplane, int *score)
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
    if (!strcmp(ob->fileShape, "fighter") && ob->health < 200)
        set_color("red");
    if (!strcmp(ob->fileShape, "bounce.health"))
        set_color("green");
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
            else if (!strcmp(ob->fileShape, "drone"))
            {
                if (board[row_i][col_i] == 1)
                {
                    airplane->damage = 0;
                    airplane->health -= ob->damage;
                    board[row_i][col_i] = 0;
                    delete_enemy(ob->id, airplane);
                    set_color("");
                    fclose(fptr);
                    refresh();
                    return 0;
                }
                else if (board[row_i][col_i] >= 2 && ob->id != board[row_i][col_i])
                {
                    delete_enemy(board[row_i][col_i], airplane);
                    board[row_i][col_i] == 0;
                    if (ob && ob->id)
                        ob->health -= 50;
                    set_color("");
                    fclose(fptr);
                    (*score) += 10;
                    refresh();
                    return 0;
                }
                else
                {
                    board[row_i][col_i] = ob->id;
                }
            }
            else if (!strcmp(ob->fileShape, "shoot.enemy"))
            {
                if (board[row_i][col_i] == 1)
                {
                    airplane->damage = 0;
                    airplane->health -= ob->damage;
                    board[row_i][col_i] = 0;
                    delete_enemy(ob->id, airplane);
                    set_color("");
                    fclose(fptr);
                    refresh();
                    return 0;
                }
            }
            else if (!strcmp(ob->fileShape, "bomb"))
            {
                if (board[row_i][col_i] == 1)
                {
                    airplane->damage = 0;
                    airplane->health -= ob->damage;
                    board[row_i][col_i] = 0;
                    delete_enemy(ob->id, airplane);
                    set_color("");
                    fclose(fptr);
                    refresh();
                    return 0;
                }
            }
            else if (!strcmp(ob->fileShape, "bounce.health"))
            {
                if (board[row_i][col_i] == 1)
                {
                    airplane->health += ob->health;
                    if (airplane->health > 100)
                        airplane->health = 100;
                    board[row_i][col_i] = 0;
                    delete_enemy(ob->id, airplane);
                    set_color("");
                    fclose(fptr);
                    refresh();
                    return 0;
                }
            }
            else if (!strcmp(ob->fileShape, "bounce.gun"))
            {
                if (board[row_i][col_i] == 1)
                {
                    airplane->damage = 1;
                    board[row_i][col_i] = 0;
                    delete_enemy(ob->id, airplane);
                    set_color("");
                    fclose(fptr);
                    refresh();
                    return 0;
                }
            }
            else if (!strcmp(ob->fileShape, "bomber"))
            {
                if (board[row_i][col_i] == 1)
                {
                    ob->airplane->damage = 0;
                    ob->airplane->health -= ob->damage;
                    board[row_i][col_i] = 0;
                    delete_enemy(ob->id, ob->airplane);
                    set_color("");
                    fclose(fptr);
                    refresh();
                    return 0;
                }
                else if (board[row_i][col_i] >= 2)
                {
                    delete_enemy(board[row_i][col_i], ob->airplane);
                    board[row_i][col_i] == 0;
                    if (ob && ob->airplane->id)
                        ob->health -= 50;
                    set_color("");
                    fclose(fptr);
                    (*score) += 7;
                    refresh();
                    return 0;
                }
            }
            else
            {
                if (board[row_i][col_i] == 1)
                {
                    airplane->damage = 0;
                    airplane->health -= ob->damage;
                    if (ob && airplane->id)
                        delete_enemy(ob->id, airplane);
                    board[row_i][col_i] = 0;
                    set_color("");
                    fclose(fptr);
                    refresh();
                    return 0;
                }
                else if (board[row_i][col_i] >= 2)
                {
                    delete_enemy(board[row_i][col_i], airplane);
                    board[row_i][col_i] == 0;
                    if (ob && airplane->id)
                        ob->health -= 50;
                    set_color("");
                    fclose(fptr);
                    (*score) += 3;
                    refresh();
                    return 0;
                }
            }
        }

        (*row)++;
    }
    set_color("");
    fclose(fptr);
    refresh();
    return 0;
}
