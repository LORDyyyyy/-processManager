#include "core.h"
#include <stdio.h>

/**
 * list_process - prints list of proceess
 *
 * Return: no thing
 */

void list_processes()
{
    FILE *file = popen("ps - e -o pid,comm", "r");
    if (!file)
    {
        perror("Error opening processs list");
        return;
    }

}
