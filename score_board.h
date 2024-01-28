int score_board(objP airplane,int frame){
    int score = pow(frame/2,1.0001) / 20;
    mvprintw(2,5,"|score : %d",score);
    mvprintw(3,5,"|health : %%%d",airplane->health);
    mvprintw(airplane->y+35,airplane->x-25,"%d %d",airplane->Vx,airplane->Vy);
    return score;
}