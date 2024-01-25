#include <stdlib.h>
#include <ncurses.h>

int menu()
{
    int n = 0;
    int c; // Use int instead of char to capture arrow key values
    do{
        switch (c)
        {
            case KEY_UP:
                n--;
                break;
            case KEY_DOWN:
                n++;
                break;
            case 10: // Enter key
                // Handle menu selection here
                // if (n == 0)
                //     //play();
                // else if (n == 1)
                //     //level();
                // else if (n == 2)
                //     //logs();
                // else if (n == 3)
                //     //quit();
                break;
        }
         clear();

        if (n > 3)
            n = n % 4;
        if (n < 0)
            n += 4;
        set_color("green");
        print_image("menu");
        set_color("");
        if (n%4 == 0)
            set_color("blue");
        print_image("menu.play");
        set_color("");
        if (n%4 == 1)
            set_color("blue");
        print_image("menu.level");
        set_color("");
        if (n%4 == 2)
            set_color("blue");
        print_image("menu.logs");
        set_color("");
        if (n%4 == 3)
            set_color("red");
        print_image("menu.quit");
        set_color("");
        
        // Handle arrow key inputs


        refresh();
    }
    while ((c = wgetch(stdscr)) != 'q'); // Use wgetch(stdscr) to get input from standard screen
    return 0;
}
