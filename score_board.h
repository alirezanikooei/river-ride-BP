int score_board(int *score,objP airplane,int frame,int level){
    (*score) += (int)(pow(frame/2,1.01) / 20) - (int)(pow((frame-1)/2,1.01) / 20) + (int)(level/10);
    mvprintw(2,5,"|score : %d",*score);
    mvprintw(3,5,"|health : %%%d",airplane->health);
    
    char level_name[12];get_level_name(level_name);
    mvprintw(4,5,"%s",level_name);
    //                 int i = 0;
    //                 objP current = airplane;
    //             while (current->next != NULL)
    //             {
    //                 // if(!strcmp(current->fileShape,"fighter"))
    //                     i++;
    //                 current = current->next;
    //             }
    //  mvprintw(5,5,"%d",i);
}