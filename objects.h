int add_enemy(objP airplane,int frame)
{
    srand(time(NULL)+frame);
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    printw("%d", current->health);
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = rand()%250+10;
    newOB->y = -40;
    newOB->Vy = 3;
    newOB->damage = 20;
    newOB->direction = 1;
    strcpy(&(newOB->fileShape), "mine");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id+1;
    return 0;
}

int delete_enemy(int id,objP airplane){
    objP current = airplane->next;
    while (current){        
        if(current->id == id){
            if(current->next){
                objP tmp = current->previous;
                objP tmp2 = current->next;
                free(current);
                tmp->next = tmp2;
                tmp2->previous = tmp;
            }else{
                objP tmp = current->previous;
                free(current);
                tmp->next = NULL;
            }
            return 0;
        }
        current = current->next;
    }
}
int update_enemy(objP airplane, int frame,int * board)
{
     

    objP current = airplane->next;
    while (current)
    {       
        if (frame % current->Vy == 0)
            current->y++;
        int row;
        int len;
        print_imageXY(current->fileShape,current,&row ,&len,board,airplane);
        objP tmp = current;
        current = current->next;
        if(tmp->x > 270 || tmp->y > 30){
            delete_enemy(tmp->id,airplane);
       }
    }
}