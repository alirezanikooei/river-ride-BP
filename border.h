int border_write(){
    chtype left_border = '<';
    chtype right_border = '>';
    chtype top_border = '\\';
    chtype bottom_border = '/';
    wborder(stdscr, left_border, right_border, top_border, bottom_border, '@', '@', '@', '@');
}
