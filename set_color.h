#include <ncurses.h>
#include <string.h>

int set_color(char color[]);

int set_color(char color[]) {
    start_color(); // Initialize color pairs
    init_pair(1, COLOR_RED, COLOR_BLACK);     // Red text on black background
    init_pair(2, COLOR_GREEN, COLOR_BLACK);   // Green text on black background
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);  // Yellow text on black background
    init_pair(4, COLOR_BLUE, COLOR_BLACK);    // Blue text on black background
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK); // Purple text on black background
    init_pair(6, COLOR_CYAN, COLOR_BLACK);    // Cyan text on black background
    init_pair(7, COLOR_WHITE, COLOR_BLACK);   // White text on black background

    if (color[0] == '\0') {
        attron(COLOR_PAIR(7)); // Default color pair
    } else if (!strcmp(color, "red")) {
        attron(COLOR_PAIR(1));
    } else if (!strcmp(color, "green")) {
        attron(COLOR_PAIR(2));
    } else if (!strcmp(color, "yellow")) {
        attron(COLOR_PAIR(3));
    } else if (!strcmp(color, "blue")) {
        attron(COLOR_PAIR(4));
    } else if (!strcmp(color, "purple")) {
        attron(COLOR_PAIR(5));
    } else if (!strcmp(color, "cyan")) {
        attron(COLOR_PAIR(6));
    } else if (!strcmp(color, "dark")) {
        attron(COLOR_PAIR(7));
    }
    return 0;
}
