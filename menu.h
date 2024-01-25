
//#include <termios.h>

#define clear() printf("\033[H\033[J")
static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old);         /* grab old terminal i/o settings */
    current = old;              /* make new settings same as old settings */
    current.c_lflag &= ~ICANON; /* disable buffered i/o */
    if (echo)
    {
        current.c_lflag |= ECHO; /* set echo mode */
    }
    else
    {
        current.c_lflag &= ~ECHO; /* set no echo mode */
    }
    tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* Read 1 character without echo */
char getch(void)
{
    return getch_(0);
}

int menu()
{

    int n = 0;
    while (1)
    {
        
        if (n > 8)
            n = n % 4;
        if (n < 0)
            n += 4;
            printf("\x1b[H\x1b[J");
        set_color("green");
        print_image("menu");
        set_color("");
        if (n % 4 == 0)
            set_color("blue");
        print_image("menu.play");
        set_color("");
        if (n % 4 == 1)
            set_color("blue");
        print_image("menu.level");
        set_color("");
        if (n % 4 == 2)
            set_color("blue");
        print_image("menu.logs");
        set_color("");
        if (n % 4 == 3)
            set_color("red");
        print_image("menu.quit");
        set_color("");
        char c;
        c = getch();
        if (c == 'w' || c == 65)
            n--;
        if (c == 's' || c == 66)
            n++;
                clear();

        if (c == 10){
            break;
            // if(c%4 == 0)
            //     play();
            // else if(c%4 == 1)
            //     level();
            // else if(c%4 == 2)
            //     logs();
            // else
            //     quit();
        }
    }
    return 0;
}