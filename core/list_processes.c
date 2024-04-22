#include "core.h"

/**
 * list_process - prints list of proceess
 *
 * Return: no thing
 */

void list_processes()
{
	char buffer[BUFFER_SIZE];
	FILE *file = popen(
		"ps -e -o user,pid,%cpu,%mem,vsz,rss,tty,stat,start,time,command", "r");
	if (!file)
	{
		perror("Error opening processs list");
		return;
	}
	printf("USER         PID %%CPU %%MEM    VSZ   RSS TTY      STAT START   "
		   "TIME COMMAND\n");

	while (fgets(buffer, BUFFER_SIZE, file))
	{
		printf("%s\n", buffer);
	}

	pclose(file);
}
