int add_effect(int key, int frame, objP airplane)
{
    if (frame%8 != 0)
    {
        set_color("red");
        mvprintw(airplane->y + 56, airplane->x - 3, "/||\\");
        mvprintw(airplane->y + 56, airplane->x - 16, "/||\\");
    }
    if (frame%4 != 0)
    {
        set_color("yellow");
        mvprintw(airplane->y + 57, airplane->x - 4, "/||||\\");
        mvprintw(airplane->y + 57, airplane->x - 17, "/||||\\");
    }
    if (frame%2 != 0)
    {
        set_color("yellow");
        mvprintw(airplane->y + 58, airplane->x - 5, "/||||||\\");
        mvprintw(airplane->y + 58, airplane->x - 18, "/||||||\\");
    }
    set_color("");
    if(key == KEY_DOWN || key == 's'){
        mvprintw(airplane->y + 43, airplane->x - 24, "\\\\                            //");
        mvprintw(airplane->y + 42, airplane->x - 25, "\\\\                              //");
    }
}