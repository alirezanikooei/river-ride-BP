
void logs() {
    clear();
    print_image("menu.logs");
    refresh();
    
    FILE *file = fopen("history/logs.txt", "r");
    if (file == NULL) {
        printw("Error opening file!\n");
        getch(); // Wait for user input
        return;
    }

    char line[MAX_LINE_LENGTH];
    int row = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        mvprintw(row + 10, 3, "%s\n", line);
        row++;
    }

    fclose(file);
    getch();
}
