int play()
{
    // board get
    attron(A_BOLD);
    int board[400][400]; // 0 for what is and 1 for the id
    getmaxyx(stdscr, max_y, max_x);
    int frame = 0;
    int score = 0;

    // init airplane
    objP airplane = (objP)calloc(1, sizeof(obj));
    airplane->x = (max_x - 1) / 2 - 10;
    airplane->y = (max_y - 1) / 2 - 25;
    airplane->health = 100;
    airplane->Vx = 0;
    airplane->Vy = 0;
    int shoot_y = airplane->y + 40;
    strcpy(airplane->fileShape, "airplane");

    int row = 0;
    int len = 0;
    int firstTime = time(NULL);
    while (1)
    {
        
        if (frame % 70 == 0)
        {
            add_mine(airplane,frame);
        }if(frame % 90 == 0){
            add_fighter(airplane,frame);
        }

        // score board
        score = score_board(airplane, frame);

        char shape[MAX_LINE_LENGTH] = {};

        update_enemy(airplane, frame,board);
        print_imageXY("airplane", airplane, &row, &len,board,airplane);
        airplane->sizeY = row + 34;
        airplane->sizeX = len - 45;

        border_write();
        // move airplane
        int key = get_key();
        if(key == ' ')
            add_shoot(airplane,frame);
        if(key == KEY_BACKSPACE)
            add_fighter(airplane,frame);
        move_airplane(key, airplane, &shoot_y, max_x, max_y);


        damage(airplane,max_x,max_y);
        // repeat frame
        if(frame%10 == 0){
        for (int i = 0; i < 400; i++)
            for(int j = 0;j<400;j++)
                board[i][j] = 0;
        }
        frame++;
        usleep(16666.6666667);
        if (airplane->health <= 0)
        {
            end_game(score,firstTime);
            break;
        }
        clear();
        refresh();
    }
    attroff(A_BOLD);
}
        // // shoot
        // shoot_y--;
        // if (shoot_y < 0)
        //     shoot_y = airplane->y + 40;
        // set_color("red");
        // mvprintw(shoot_y, airplane->x + 6, ".@.");
        // mvprintw(shoot_y, airplane->x - 25, ".@.");
        // 
        // set_color("");