#include "main.h"

int input(){
    char input[50];
    int type;
    printf("Select the process type you want to perform.\n");
    printf("system or user process?\n");
    start:
    scanf("%s",input);

    if(strcmp(input, "system") == 0 || strcmp(input, "System") == 0)
    type =0;

    else if(strcmp(input, "user") == 0 || strcmp(input, "User") == 0)
    type=1;

    else {
    printf("invalid choice, please enter valid one\n");
    goto start;
    }
    
    return type;
}
