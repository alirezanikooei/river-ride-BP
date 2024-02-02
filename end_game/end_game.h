void end_game(int score,int firstTime,objP airplane,char name[20]){
    free_objects(airplane);
    clear();
    clear();
    refresh();
    int tmScore = score;
    int timeLen = time(NULL) - firstTime;
    int score_num[10] = {0};
    int i = 0;
    int k = 10;
    while (score != 0)
    {
        score_num[i] = score % 10;
        score /= 10; 

        refresh();
        i++;
    }i--;
    set_color("cyan");
    print_image_score("score",15,-10);
    set_color("green");
    for (;i>=0 ; i--)
    {
        char n[7] = {}; 
        strcpy(n,"nums/");
        n[5] = 48 + score_num[i];
        print_image_score(n,50-i*8,100);
    }
    set_color("");
    

    time_t unix_timestamp = time(NULL)+12600;  // Replace with your desired timestamp // 12600 iran timezone
    struct tm *tm_info;
    tm_info = gmtime(&unix_timestamp);
    FILE *file = fopen("history/logs.txt", "a");
    char level_name[12] = {};
    get_level_name(level_name);
    fprintf(file, "%.5d %.4d %d %.2d %.2d %.2d %.2d %.2d %20s %13s\n",tmScore,timeLen, tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday,tm_info->tm_hour,tm_info->tm_min,tm_info->tm_sec,name, level_name);
    fclose(file);
    while (1){
        int key = getch();
        if(key == '\n'){
            menu_game();
        }
    }
}
int free_objects(objP airplane){
    objP current = airplane;
    while (current)
    {
        objP tmp = current;
        current = current->next;
        free(tmp);
    }
    
}