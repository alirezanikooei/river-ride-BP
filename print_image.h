#include <ncurses.h>
#include <string.h>

#define MAX_LEN 1000

int print_image(char name[]);

int print_image(char name[]) {
    // Initialize ncurses
    initscr();
    cbreak();  // Line buffering disabled
    noecho();  // Don't echo while we do getch
    
    char filename[strlen(name) + 10];
    strcpy(filename, "image/");
    strcat(filename, name);
    strcat(filename, ".txt");
    FILE *fptr = NULL;
    char read_string[MAX_LEN];
    if ((fptr = fopen(filename, "r")) == NULL) {
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
    endwin();

    return 0;
}


