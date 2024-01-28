int play()
{
    // board get
    attron(A_BOLD);
    int board[400][400]; // 0 for what is and 1 for the id
    getmaxyx(stdscr, max_y, max_x);
    int frame = 1;
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

    while (1)
    {
        
        if (frame % 120 == 0)
        {
            add_enemy(airplane,frame);
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
        move_airplane(key, airplane, &shoot_y, max_x, max_y);


        damage(airplane,max_x,max_y);
        // repeat frame
        if(frame%30 == 0){
        for (int i = 0; i < 400; i++)
            for(int j = 0;j<400;j++)
                board[i][j] = 0;
        }
        frame++;
        usleep(17000);
        if (airplane->health <= 0)
        {
            end_game(score);
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