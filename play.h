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
    airplane->id = 1;
    int shoot_y = airplane->y + 40;
    strcpy(airplane->fileShape, "airplane");

    int row = 0;
    int len = 0;
    int firstTime = time(NULL);
    while (1)
    {
        
        if (frame % 60 == 0)
        {
            add_mine(airplane,frame);
        }
        if(frame % 90 == 0){
            add_fighter(airplane,frame);
        }if(frame % 150 == 0){
            add_bomber(airplane,frame);
        }

        // score board
        score = score_board(airplane, frame);


        update_enemy(airplane, frame,board);
        if(airplane->health > 70)
            set_color("green");
        else if(airplane->health > 30)
            set_color("yellow");
        else{
            set_color("red");
            if(airplane->health < 15 && frame%2 == 0)
                set_color("");
        }
        print_imageXY("airplane", airplane, &row, &len,board,airplane);
        airplane->sizeY = row + 34;
        airplane->sizeX = len - 45;
        set_color("");
        border_write();
        // move airplane
        int key = get_key();
        if(key == ' ')
            add_shoot(airplane,frame);
        if(key == KEY_MOUSE)
            add_mine(airplane,frame);
        move_airplane(key, airplane, &shoot_y, max_x, max_y);


        // repeat frame
        if(frame%5 == 0){
        for (int i = 0; i < 400; i++)
            for(int j = 0;j<400;j++)
                if(board[i][j] != 0)
                    board[i][j] = 0;
        }
        frame++;
        usleep(16666.6666667);
        if (airplane->health <= 0)
        {
        //    end_game(score,firstTime,airplane);
            char name[20] = {};
           get_name(name,score,firstTime,airplane);
           break;
        }
        clear();
        refresh();
    }
    attroff(A_BOLD);
}
