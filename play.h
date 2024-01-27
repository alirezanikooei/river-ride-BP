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

int play()
{
    objP airplane = (objP)calloc(1, sizeof(obj));
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    int center_y = (max_y - 1) / 2;
    int center_x = (max_x - 1) / 2;
    int frame = 0;
    airplane->x = center_x - 10;
    airplane->y = center_y - 25;
    airplane->health = 100;
    int shoot_y = airplane->y + 40;
    strcpy(airplane->fileShape, "airplane");

    FILE *file = fopen("image/airplane.txt", "r");
    if (!file)
        exit(-1);
    struct timeval current_time;
    while (1)
    {
                int row = 0;
        int len = 0;
        gettimeofday(&current_time, NULL);  
        srand(current_time.tv_usec);
         
         attron(A_BOLD);
         int score = pow(frame,1.001) / 20;
         mvprintw(2,5,"|score : %d",score);
         mvprintw(3,5,"|health : %%%d",airplane->health);
         
         //attroff(A_BOLD);
        frame++;
        char shape[MAX_LINE_LENGTH] = {};

        while (fgets(shape, MAX_LINE_LENGTH, file) != NULL)
        {
            // Print each line of the shape at the desired position
            if(strlen(shape)>len)
                len = strlen(shape);
            mvprintw(airplane->y+35 + row, airplane->x-25, "%s", shape);
            row++;
        }
        airplane->sizeY = row+34;
        airplane->sizeX = len-45;
        set_color("red");
        mvprintw(shoot_y, airplane->x + 6, ".@.");
        mvprintw(shoot_y, airplane->x - 25, ".@.");
        

        set_color("");

        shoot_y--;
        if (shoot_y < 0)
            shoot_y = airplane->y + 40;

        border_write();
        int key = get_key();
        move_object(key,airplane, &shoot_y,max_x,max_y);

        fseek(file, 0, SEEK_SET);
        usleep(33000);
        if(airplane->health <= 0){
            printw("end");
        }
        clear();
        refresh();
    }
    fclose(file); // Close the file
}