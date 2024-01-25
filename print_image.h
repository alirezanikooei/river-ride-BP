
#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000

int print_image(char name[]);

int print_image(char name[])
{
    char filename[strlen(name)+10];
    strcpy(filename,"image/");
    strcat(filename,name);
    strcat(filename,".txt");
    FILE *fptr = NULL;
    char read_string[MAX_LEN];
    if ((fptr = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "error opening %s\n", filename);
        return -1;
    }
    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s",read_string);
    printf("\n");
    fclose(fptr);
    return 0;
}