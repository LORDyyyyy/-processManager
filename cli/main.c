#include "main.h"
int get_terminal_width();
int main()
{
    char choice;
    while (1)
    {
        printf("-----------------------------------------------------\n");
        int type =
            typeInput();
        char **arr = list_processes(type);
        formatePrinting(arr);

        int state = signalInput();

        if (state)
            printf("The signal was sent successfully\n");

        else
            printf("Failed to send the signal\n\n");
        printf("do you want to continue? (Y/N)\n");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y')
            continue;
        else
            break;
    }
    return 0;
}