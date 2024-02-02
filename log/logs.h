long long int date_to_time(int y, int m, int d, int h, int min, int s){
    if(m<7)
        return (y - 1970) * 365 * 24 * 60 * 60 + m * 31 * 24 * 60 * 60 + d * 24 * 60 * 60 + h * 60 * 60 + min * 60 + s;
    return (y - 1970) * 365 * 24 * 60 * 60 + (6) * 31 * 24 * 60 * 60 + (m-6) * 30 * 24 * 60 * 60 + d * 24 * 60 * 60 + h * 60 * 60 + min * 60 + s;

}

void logs()
{
    clear();
    print_image("menu.logs");
    refresh();

    FILE *file = fopen("history/logs.txt", "r");
    if (file == NULL)
    {
        printw("Error opening file!\n");
        getch(); // Wait for user input
        return;
    }

    int row = 0;
    int highScore = 0;
    attron(A_BOLD);
    char name[20] ={};
    int i = 0;
    fseek(file, 0, SEEK_END);
    long long sumDate = 0;
    int first = 0;
    while (1)
    {
        char line[MAX_LINE_LENGTH] = {};
        i++;
        fseek(file, -66 * i, SEEK_END);
        fgets(line, MAX_LINE_LENGTH, file);
        int score, timeLEN, y, m, d, h, min, s;
        char level_name[13] = {};
        sscanf(line, "%d %d %d %d %d %d %d %d %s %s %s\n", &score, &timeLEN, &y, &m, &d, &h, &min, &s,name,level_name);
        if (first == 0)
            sumDate = date_to_time(y, m, d,h, min, s);
        first = 1;
        long long tmp = date_to_time(y, m, d,h, min, s);
        if (tmp > sumDate)
            break;
        sumDate = tmp;

        if (score > highScore)
            highScore = score;
        mvprintw(row + 10, 3, "%s", name);
        mvprintw(row + 10, 25, "score: %d", score);
        mvprintw(row + 10, 39, "duration: %d\"", timeLEN);
        mvprintw(row + 10, 60, "date: %d-%d-%d", y, m, d);
        mvprintw(row + 10, 77, "%d:%d:%d", h, min, s);
        mvprintw(row + 10, 100, "level: %s",level_name);
        row++;
    }
    attron(A_BOLD);
    attron(A_UNDERLINE);
    set_color("green");
    mvprintw(8, 3, "high score: %d", highScore);
    set_color("");
    fclose(file);
    attroff(A_BOLD);
    attroff(A_UNDERLINE);
    while (1)
    {
        if (getch() == '\n')
        {
            break;
        }
    }
}
