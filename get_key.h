int kbhit(void)
{
      timeout(0); 
    int ch = getch();
  timeout(-1); 
    if (ch != ERR)
    {
        ungetch(ch);
        return 1;
    }
    else
    {
        return 0;
    }
}
int get_key(){
    if (kbhit()){
        int key = getch();
        return key;
    }
    return 0;
    
}