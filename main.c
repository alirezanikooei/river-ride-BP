#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "print_image.h"
#include "set_color.h"
#include "menu.h"
#include "play.h"

int main(int argc, char const *argv[])
{
    
	// Initialize ncurses
    initscr();
    cbreak();  // Line buffering disabled
    noecho();  // Don't echo while we do getch
    keypad(stdscr, TRUE);  // Enable the keypad for arrow keys
    curs_set(0); 
	clear();
    play();
    //menu();

    endwin();
    return 0;
}
 