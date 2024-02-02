int add_mine(objP airplane, int frame)
{
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    int s = current;if(s<0)s*=-1;
    srand(s*time(NULL));
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = rand() % 250 + 10;
    newOB->y = -40;
    newOB->Vy = 5;
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
}int add_shoot_right(objP airplane, int frame)
{
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = airplane->x + 15-14;
    newOB->y = airplane->y+8;
    newOB->Vy = 3;
    newOB->damage = 50;
    newOB->direction = 0;
    newOB->health = 100;
    strcpy(&(newOB->fileShape), "shoot");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}int add_shoot_left(objP airplane, int frame)
{
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = airplane->x + 15+14;
    newOB->y = airplane->y+8;
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
        newOB->health = 50;
        strcpy(&(newOB->fileShape), "bomb");
        current->next = newOB;
        newOB->previous = current;
        newOB->id = current->id + 1;
    }
    return 0;
}int bounce_health(objP airplane, int frame, objP enemy)
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
        newOB->Vy = 10;
        newOB->direction = 1;
        newOB->health = 30;
        strcpy(&(newOB->fileShape), "bounce.health");
        current->next = newOB;
        newOB->previous = current;
        newOB->id = current->id + 1;
    }
    return 0;
}int bounce_gun(objP airplane, int frame, objP enemy)
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
        newOB->Vy = 10;
        newOB->direction = 1;
        newOB->health = 50;
        strcpy(&(newOB->fileShape), "bounce.gun");
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
    int s = current;if(s<0)s*=-1;
    srand(s*time(NULL));
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = rand() % 250 + 10;
    newOB->y = -40;
    newOB->Vy = 3;
    newOB->damage = 20;
    newOB->direction = 1;
    newOB->health = 200;
    strcpy(&(newOB->fileShape), "fighter");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}int add_drone(objP airplane, int frame)
{
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    int s = current;if(s<0)s*=-1;
    srand(s*time(NULL));
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = rand() % 250 + 10;
    newOB->y = -40;
    newOB->Vy = 3;
    newOB->damage = 20;
    newOB->direction = 5;
    newOB->health = 50;
    strcpy(&(newOB->fileShape), "drone");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}
int add_helicopter(objP airplane, int frame)
{
    objP current = airplane;
    while (current->next != NULL)
    {
        current = current->next;
    }
    int s = current;if(s<0)s*=-1;
    srand(s*time(NULL));
    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = rand() % 250 + 10;
    newOB->y = -40;
    newOB->Vy = 10;
    newOB->damage = 10;
    newOB->direction = 1;
    newOB->health = 50;
    strcpy(&(newOB->fileShape), "helicopter");
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

    objP newOB = (objP)calloc(1, sizeof(obj));
    newOB->x = 250;
    newOB->y = -40;
    newOB->Vy = 3;
    newOB->Vx = 1;
    newOB->damage = 27;
    newOB->direction = 4;
    newOB->health = 50;
    newOB->airplane = airplane;
    strcpy(&(newOB->fileShape), "bomber");
    current->next = newOB;
    newOB->previous = current;
    newOB->id = current->id + 1;
    return 0;
}

int add_bounce(objP airplane, int frame, objP enemy){
    int s = enemy;if(s<0)s*=-1;
    srand(s*time(NULL));
    if(rand()%30 > 15)
        bounce_gun(airplane,frame,enemy);
    else
        bounce_health(airplane,frame,enemy);
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
                if(!strcmp(current->fileShape,"helicopter")){
                    add_bounce(airplane,20,current);
                }
                objP tmp = current->previous;
                objP tmp2 = current->next;
                free(current);
                tmp->next = tmp2;
                tmp2->previous = tmp;
            }
            else
            {
                if(!strcmp(current->fileShape,"helicopter")){
                    bounce_health(airplane,20,current);
                }
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
int update_enemy(objP airplane, int frame, int *board,int * score)
{

    objP current = airplane->next;
    while (current)
    {
        if(current->direction == 5 && frame%5 == 0){
            if(current->x > airplane->x)
                current->x--;
            else if(current->x < airplane->x)
                current->x++;
            if(current->y > airplane->y)
                current->y--;
            else if(current->y < airplane->y)
                current->y++;
        }
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

        print_imageXY(current->fileShape, current, &row, &len, board, airplane,score);
        objP tmp = current;
        objP tmp2 = current->next;
        if (current)
        {                                                                                  
            if ((!strcmp(current->fileShape, "bomb") || !strcmp(current->fileShape, "fighter")|| !strcmp(current->fileShape, "bounce.health") || !strcmp(current->fileShape, "bounce.gun") || !strcmp(current->fileShape, "helicopter") || !strcmp(current->fileShape, "mine") || !strcmp(current->fileShape, "bomber")  || !strcmp(current->fileShape,"shoot.enemy")) && (tmp->x < -3 || tmp->x > 270 || tmp->y > 30))
            {
                delete_enemy(tmp->id, airplane);
            }
            else if (!strcmp(current->fileShape, "shoot") && (tmp->y < -40))
            {
                delete_enemy(tmp->id, airplane);
            }else if(current->health <= 0){
                delete_enemy(tmp->id, airplane);
            }
        }
        current = tmp2;
    }
}