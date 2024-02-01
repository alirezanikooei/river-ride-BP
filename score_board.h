int score_board(objP airplane,int frame,int level){
    int score = pow(frame/2,1.0001) / 20;
    mvprintw(2,5,"|score : %d",score);
    mvprintw(3,5,"|health : %%%d",airplane->health);
    
    char level_name[12];get_level_name(level_name);
    mvprintw(4,5,"%s",level_name,level);
    return score;
}
                //     objP current = airplane;
                // while (current->next != NULL)
                // {
                //     i++;
                //     current = current->next;
                // }