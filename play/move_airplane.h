int move_airplane(int key, objP object, int *shoot_y, int maxX, int maxY)
{
    if (maxX - object->sizeX > object->x + 3 && (key == KEY_RIGHT || key == 'd'))
    {
        object->x += 5;
    }
    if (0 < object->x - object->sizeX - 20 && (key == KEY_LEFT || key == 'a'))
    {
        object->x -= 5;
    }
    if (0 < object->sizeY + object->y - 25 && (key == KEY_UP || key == 'w'))
    {
        object->y -= 2;
        *shoot_y -= 2;
    }
    if (maxY - object->sizeY > object->y + 3 && (key == KEY_DOWN || key == 's'))
    {
        object->y += 2;
        *shoot_y -= 2;
    }
}