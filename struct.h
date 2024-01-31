typedef struct objects
{
    int id;
    int x;
    int y;
    int Vx;//based on frame
    int Vy;//based on frame
    int health;//precent
    int sizeX;
    int sizeY;
    int damage;
    int direction;//0 is up 1 is down
    char fileShape[20];//just name witout .txt
    struct objects * next;
    struct objects * previous;
    struct objects * airplane;
} obj;
typedef obj * objP;
int max_y, max_x;