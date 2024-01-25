#include <stdio.h>
#include "print_image.h"
#include "set_color.h"
#include "menu.h"

int main(int argc, char const *argv[])
{
    
	// Initialize ncurses
    initscr();
    cbreak();  // Line buffering disabled
    noecho();  // Don't echo while we do getch
    keypad(stdscr, TRUE);  // Enable the keypad for arrow keys
    WINDOW *win = newwin(10, 20, 5, 5);
    box(win, 0, 0);
	clear();
    menu();
    endwin();
    return 0;
}
