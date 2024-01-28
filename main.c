#define MAX_LINE_LENGTH 1000
#include "all_include.h"

int main(int argc, char const *argv[])
{
    
	// Initialize ncurses
    initscr();
    cbreak();  // Line buffering disabled
    noecho();  // Don't echo while we do getch
    keypad(stdscr, TRUE);  // Enable the keypad for arrow keys
    curs_set(0); 
	clear();

    menu();
    
    endwin();
    return 0;
}
 