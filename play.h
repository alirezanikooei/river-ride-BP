
#define MAX_LINE_LENGTH 1000
typedef struct objects
{
    int x;
    int y;
    int Vx;
    int Vy;
    int health;
    int sizeX;
    int sizeY;
    char direction;
    char fileShape[20];
} obj;
typedef obj *objP;

int kbhit(void)
{
      timeout(0); 
    int ch = getch();
  timeout(-1); 
    if (ch != ERR)
    {
        ungetch(ch);
        return 1;
    }
    else
    {
        return 0;
    }
}

int play()
{
    objP airplane = (objP)calloc(1, sizeof(obj));
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    // Draw border
    chtype left_border = '<';
    chtype right_border = '>';
    chtype top_border = '\\';
    chtype bottom_border = '/';
    FILE *file = fopen("image/airplane.txt", "r");
    if (file == NULL)
    {
        endwin(); // End ncurses mode
        fprintf(stderr, "Error: Unable to open file.\n");
        return 1;
    }
    int center_y = (max_y - 1) / 2;
    int center_x = (max_x - 1) / 2;
    int shoot_y = center_y;
    while (1)
    {
        clear();
        // Open the file containing the shape

        // Read the contents of the file
        char shape[MAX_LINE_LENGTH];
        int row = 0;
        while (fgets(shape, MAX_LINE_LENGTH, file) != NULL)
        {
            // Print each line of the shape at the desired position
            mvprintw(center_y - 10 + row, center_x - 25, "%s", shape);
            row++;
        }
        set_color("red");
        mvprintw(shoot_y, center_x + 6, "0");
        mvprintw(shoot_y, center_x - 23, "0");
        set_color("");
        shoot_y--;
        if (shoot_y < center_y - 10)
            shoot_y = center_y;
        wborder(stdscr, left_border, right_border, top_border, bottom_border, '@', '@', '@', '@');
        if (kbhit())
        {
            int key = getch();
            if (key == KEY_RIGHT)
            {
                center_x += 3;
            }
            if (key == KEY_LEFT)
            {
                center_x -= 3;
            }
            if (key == KEY_UP)
            {
                center_y--;
                shoot_y--;
            }
            if (key == KEY_DOWN)
            {
                center_y++;
                shoot_y--;
            }
        }

        fseek(file, 0, SEEK_SET);
        usleep(33000);
        refresh();
    }
    fclose(file); // Close the file
}