void end_game(int score){
    clear();
    mvprintw(20,20,"you lose. score : %d",score);
    int key = getch();
    menu();
}