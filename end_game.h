void end_game(int score,int firstTime){
    clear();
    int timeLen = time(NULL) - firstTime;
    mvprintw(20,20,"you lose. score : %d // time : %d",score, timeLen);
        int score_num[10] = {0};
    int i = 0;
    int k = 10;
    while (score != 0)
    {
        score_num[i] = score / k;
        score /= k; 
        char n[6] = {0}; 
        strcat(n,"nums/");
        n[5] = 48 + score_num[i];
        //fprintf(stderr,n);
        //exit(-1);
        move(50,20);
        print_image(n);
        i++;k*=10;
    }


    time_t unix_timestamp = time(NULL)+12600;  // Replace with your desired timestamp // 12600 iran timezone
    struct tm *tm_info;

    tm_info = gmtime(&unix_timestamp);
    FILE *file = fopen("history/logs.txt", "a");
    fprintf(file, "%d %d %d %d %d %d %d\n",score, tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,tm_info->tm_hour,tm_info->tm_min,tm_info->tm_sec);
    mvprintw(10,10,"Year: %d\n", tm_info->tm_year + 1900);
    mvprintw(11,10,"Month: %d\n", tm_info->tm_mon + 1);
    mvprintw(12,10,"Day: %d\n", tm_info->tm_mday);
    mvprintw(13,10,"Hour: %d\n", tm_info->tm_hour);
    mvprintw(14,10,"Minute: %d\n", tm_info->tm_min);
    mvprintw(15,10,"Second: %d\n", tm_info->tm_sec);
    
    fclose(file);
    while (get_key()!=KEY_ENTER);
    
}