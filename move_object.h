int move_object(int key, objP object, int *shoot_y, int maxX, int maxY)
{
    if (maxX - object->sizeX > object->x + 3 && key == KEY_RIGHT)
    {
        mvprintw(4, 5, "%d", object->sizeX);
        mvprintw(5, 5, "%d", maxX);
        object->x += 3;
    }
    if (0 < object->x - object->sizeX - 20 && key == KEY_LEFT)
    {
        object->x -= 3;
    }
    if (0 < object->sizeY + object->y - 25 && key == KEY_UP)
    {
        object->y -= 2;
        *shoot_y -= 2;
    }
    if (maxY - object->sizeY > object->y + 3 && key == KEY_DOWN)
    {
        object->y += 2;
        *shoot_y -= 2;
    }
}