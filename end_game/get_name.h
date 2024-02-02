int get_name(char name[20],int score,int firstTime,objP airplane){
    clear();
    set_color("blue");
    print_image("entername");
    set_color("");
    refresh();
    curs_set(1);
    move(2,92);
    echo();
    getstr(name);
    noecho();
    curs_set(0);
    end_game(score,firstTime,airplane,name);
    return 0;
}
