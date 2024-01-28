int add_mine(objP airplane, int frame)
{
    srand(time(NULL) + frame);
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = rand() % 250 + 10;
    newOB->y = -40;
    newOB->Vy = 3;
    newOB->damage = 10;
    newOB->direction = 1;
    newOB->health = 100;
    strcpy(&(newOB->fileShape), "mine");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}
int add_shoot(objP airplane, int frame)
{
    srand(time(NULL) + frame);
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = airplane->x + 15;
    newOB->y = airplane->y;
    newOB->Vy = 3;
    newOB->damage = 100;
    newOB->direction = 0;
    strcpy(&(newOB->fileShape), "shoot");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}int add_shoot_enemy(objP airplane, int frame,objP enemy)
{
    srand(time(NULL) + frame);
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = enemy->x + 5;
    newOB->y = enemy->y;
    newOB->Vy = 1;
    newOB->damage = 5;
    newOB->direction = 1;
    strcpy(&(newOB->fileShape), "shoot.enemy");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}int add_fighter(objP airplane, int frame){
    srand(time(NULL) + frame);
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = rand() % 250 + 10;
    newOB->y = -40;
    newOB->Vy = 2;
    newOB->damage = 20;
    newOB->direction = 1;
    strcpy(&(newOB->fileShape), "fighter");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}
int delete_enemy(int id, objP airplane)
{
    objP current = airplane->next;
    while (current)
    {
        if (current->id == id)
        {
            if (current->next)
            {
                objP tmp = current->previous;
                objP tmp2 = current->next;
                free(current);
                tmp->next = tmp2;
                tmp2->previous = tmp;
            }
            else
            {
                objP tmp = current->previous;
                free(current);
                tmp->next = NULL;
            }
            return 0;
        }
        current = current->next;
    }
}
int update_enemy(objP airplane, int frame, int *board)
{

    objP current = airplane->next;
    while (current)
    {

        if (current->direction == 1 && frame % current->Vy == 0)
            current->y++;
        if (current->direction == 0 && frame % current->Vy == 0)
            current->y--;
        int row;
        int len;
        if(!strcmp(current->fileShape, "fighter") && frame%20 == 0){
            add_shoot_enemy(airplane,frame,current);
        }
        print_imageXY(current->fileShape, current, &row, &len, board, airplane);
        objP tmp = current;
        if ((!strcmp(current->fileShape, "mine") || !strcmp(current->fileShape, "fighter") || !strcmp(current->fileShape, "shoot.enemy"))  && (tmp->x > 270 || tmp->y > 30))
        {
            delete_enemy(tmp->id, airplane);
        }
        else if (!strcmp(current->fileShape, "shoot") && (tmp->y < -40))
        {
            delete_enemy(tmp->id, airplane);
        }
        current = current->next;
    }
}