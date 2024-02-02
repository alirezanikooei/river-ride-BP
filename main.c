/*
Amirkabir University of Technology CE Department (CE AUT)
teacher Dr.Zeinali hzeinali@aut.ac.ir
Alirezanikooei 40231053 (ar.nikooei@aut.ac.ir) also (alirezanikooei84@gmail.com)
date 1402/11
*/

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
