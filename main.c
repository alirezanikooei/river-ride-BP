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
	clear();
    menu();
    endwin();
    return 0;
}
