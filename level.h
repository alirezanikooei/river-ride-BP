int level()
{
    attroff(A_BOLD);
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
            case KEY_RIGHT:
                set_level(n);
                return 0;
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
            set_color("green");
        print_image("beginner");
        set_color("");
        if (n%4 == 1)
            set_color("blue");
        print_image("normal");
        set_color("");
        if (n%4 == 2)
            set_color("yellow");
        print_image("professional");
        set_color("");
        if (n%4 == 3)
            set_color("red");
        print_image("superstar");
        set_color("");
        
        // Handle arrow key inputs


        refresh();
    }
    while ((c = wgetch(stdscr)) != 'q'); // Use wgetch(stdscr) to get input from standard screen
    return 0;
}
int set_level(int n){
    FILE* file;
    file = fopen("level.bin", "w");
    fwrite(&n, 1, sizeof(int), file);
    fclose(file);
    clear();
    set_color("green");
    print_image("level.change");
    set_color("");
    sleep(2);
}
int get_level(){
    int n = 0;
    FILE* file;
    file = fopen("level.bin", "r");
    fread(&n, 1, sizeof(int), file);
    fclose(file);
    return n;
}
int get_level_name(char level_name[12]){
    int level = get_level();
    strcpy(level_name,"");
    if(level == 0)
        strcpy(level_name,"Beginner");
    if(level == 1)
        strcpy(level_name,"Normal");
    if(level == 2)
        strcpy(level_name,"Professional");
    if(level == 3)
        strcpy(level_name,"Superstar");
    return 0;
}