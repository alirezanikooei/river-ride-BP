#include <stdio.h>
#include "print_image.h"
#include "set_color.h"
#include "menu.h"
#include <unistd.h>
#include <time.h>
#include <ncurses.h>
int main(int argc, char const *argv[])
{
    printf("\e[?25h");
    menu();
    
    return 0;
}
