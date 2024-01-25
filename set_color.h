#include <stdio.h>
#include <string.h>
int set_color(char color[]);
int set_color(char color[]){
    if(color[0] == '\0'){
        printf("\033[0;37m");
    }else if(!strcmp(color,"red")){
        printf("\033[0;31m");
    }else if (!strcmp(color,"green"))
    {
        printf("\033[0;32m");
    }else if (!strcmp(color,"yellow "))
    {
        printf("\033[0;33m");
    }else if (!strcmp(color,"blue"))
    {
        printf("\033[0;34m");
    }else if (!strcmp(color,"purple"))
    {
        printf("\033[0;35m");
    }else if (!strcmp(color,"cyan"))
    {
        printf("\033[0;36m");
    }else if (!strcmp(color,"dark"))
    {
        printf("\033[0;30m");
    }
    
}