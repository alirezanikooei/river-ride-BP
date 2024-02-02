int play()
{
    // board get
    attron(A_BOLD);
    int board[400][400]; // 0 for what is and 1 for the id
    getmaxyx(stdscr, max_y, max_x);
    int frame = 0;
    int score = 0;

    int level = get_level();
    int tLevel = level_time(level);
    int mintLevel = level_time_min(level);
    // init airplane
    objP airplane = (objP)calloc(1, sizeof(obj));
    airplane->x = (max_x - 1) / 2 + 10;
    airplane->y = (max_y - 1) / 2 - 30;
    airplane->health = 100;
    airplane->Vx = 0;
    airplane->Vy = 0;
    airplane->id = 1;
    int shoot_y = airplane->y + 40;
    strcpy(airplane->fileShape, "airplane");

    int row = 0;
    int len = 0;
    int shoot = 0;
    int firstTime = time(NULL);
    while (1)
    {
        border_write();
        // move airplane
        int key = get_key();

        // check the shoot
        if (key == ' ' && shoot == 0)
        {
            add_shoot(airplane, frame);
            if (airplane->damage)
            {
                add_shoot_right(airplane, frame);
                add_shoot_left(airplane, frame);
            }
            shoot += 15;
        }
        if (shoot > 0)
            shoot--;
        move_airplane(key, airplane, &shoot_y, max_x, max_y);
        add_effect(key, frame, airplane);
        if (frame % (int)(tLevel) == 0)
        {
            add_mine(airplane, frame);
        }
        if (frame % (int)(tLevel * 1.5) == 30)
        {
            add_fighter(airplane, frame);
        }
        if (level > 0 && frame % (int)(tLevel * 2) == 59)
        {
            add_bomber(airplane, frame);
        }
        if (level > 0 && frame % (int)(tLevel * 3) == 89)
        {
            add_drone(airplane, frame);
        }
        if (frame % (int)(mintLevel) == 0)
        {
            add_helicopter(airplane, frame);
        }

        // score board
        score_board(&score, airplane, frame, level);

        update_enemy(airplane, frame, board, &score);
        if (airplane->health > 70)
            set_color("green");
        else if (airplane->health > 30)
            set_color("yellow");
        else
        {
            set_color("red");
            if (airplane->health < 15 && frame % 2 == 0)
                set_color("");
        }
        print_imageXY("airplane", airplane, &row, &len, board, airplane, &score);
        airplane->sizeY = row + 34;
        airplane->sizeX = len - 45;
        set_color("");

        // repeat frame
        if (frame % 5 == 0)
        {
            for (int i = 0; i < 400; i++)
                for (int j = 0; j < 400; j++)
                    if (board[i][j] != 0)
                        board[i][j] = 0;
        }
        frame++;
        long double t = 16666.6666667;
        int tMIn = score / 50;
        t-=tMIn;
        usleep(t);
        if (airplane->health <= 0)
        {
            char name[20] = {};
            get_name(name, score, firstTime, airplane);
            break;
        }
        clear();
        refresh();
    }
    attroff(A_BOLD);
}
