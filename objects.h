int add_mine(objP airplane, int frame)
{
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    srand(time(NULL) + current + frame);
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = rand() % 250 + 10;
    newOB->y = -40;
    newOB->Vy = 3;
    newOB->damage = 10;
    newOB->direction = 1;
    newOB->health = 50;
    strcpy(&(newOB->fileShape), "mine");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}
int add_shoot(objP airplane, int frame)
{
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = airplane->x + 15;
    newOB->y = airplane->y;
    newOB->Vy = 3;
    newOB->damage = 50;
    newOB->direction = 0;
    newOB->health = 100;
    strcpy(&(newOB->fileShape), "shoot");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}
int add_shoot_enemy(objP airplane, int frame, objP enemy)
{
    if (enemy)
    {
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
        newOB->health = 100;
        strcpy(&(newOB->fileShape), "shoot.enemy");
        current->next = newOB;
        newOB->previous = current;
        newOB->id = current->id + 1;
    }
    return 0;
}int bomb_shoot_enemy(objP airplane, int frame, objP enemy)
{
    if (enemy)
    {
        objP current = airplane;
        while (current->next != NULL)
        {
            current = current->next;
        }
        objP newOB = (objP)calloc(1, sizeof(obj));
        newOB->x = enemy->x + 5;
        newOB->y = enemy->y;
        newOB->Vy = 1;
        newOB->damage = 20;
        newOB->direction = 1;
        newOB->health = 100;
        strcpy(&(newOB->fileShape), "bomb");
        current->next = newOB;
        newOB->previous = current;
        newOB->id = current->id + 1;
    }
    return 0;
}
int add_fighter(objP airplane, int frame)
{
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    srand(time(NULL) + current + frame);
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = rand() % 250 + 10;
    newOB->y = -40;
    newOB->Vy = 2;
    newOB->damage = 20;
    newOB->direction = 1;
    newOB->health = 100;
    strcpy(&(newOB->fileShape), "fighter");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}
int add_bomber(objP airplane, int frame)
{

    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    srand(time(NULL) + current + frame);
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = 250;
    newOB->y = -40;
    newOB->Vy = 3;
    newOB->Vx = 1;
    newOB->damage = 20;
    newOB->direction = 4;
    newOB->health = 100;
    newOB->airplane = airplane;
    strcpy(&(newOB->fileShape), "bomber");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}

int delete_enemy(int id, objP airplane)
{

    if (id == 1)
        return 0;
    objP current = airplane->next;
    while (current)
    {
        if (current->id == id)
        {
            if (current->next != NULL)
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
    return 0;
}
int update_enemy(objP airplane, int frame, int *board)
{

    objP current = airplane->next;
    while (current)
    {

        if ((current->direction == 1 || current->direction == 3 || current->direction == 4) && frame % current->Vy == 0)
            current->y++;
        if (current->direction == 0 && frame % current->Vy == 0)
            current->y--;
        if ((current->direction == 4) && ((frame % current->Vx) == 0))
            current->x--;
        int row = 0;
        int len = 0;
        if (!strcmp(current->fileShape, "fighter") && frame % 20 == 0)
        {
            add_shoot_enemy(airplane, frame, current);
        }if (!strcmp(current->fileShape, "bomber") && frame % 30 == 0)
        {
            bomb_shoot_enemy(airplane, frame, current);
        }

        print_imageXY(current->fileShape, current, &row, &len, board, airplane);
        objP tmp = current;
        objP tmp2 = current->next;
        if (current)
        {
            if ((!strcmp(current->fileShape, "bomb") || !strcmp(current->fileShape, "mine") || !strcmp(current->fileShape, "bomber")  || !strcmp(current->fileShape, "shoot.enemy")) && (tmp->x < -3 || tmp->x > 270 || tmp->y > 30))
            {
                delete_enemy(tmp->id, airplane);
            }
            else if (!strcmp(current->fileShape, "shoot") && (tmp->y < -40))
            {
                delete_enemy(tmp->id, airplane);
            }
        }
        current = tmp2;
    }
}