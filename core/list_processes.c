#include "core.h"

/**
 * list_process - prints list of proceess
 *
 * @type: the type of process 0 for USER 1 for SYSTEM 2 for BOTH
 *
 * Return: array of strings containing process information
 */

char **list_processes(int type)
{
	char buffer[BUFFER_SIZE];
	FILE *file = popen(
		"ps -e -o user,pid,%cpu,%mem,vsz,rss,tty,stat,start,time,command", "r");
	if (!file)
	{
		perror("Error opening processs list");
		return (NULL);
	}
	int number_of_process = 1;
	while (fgets(buffer, BUFFER_SIZE, file))
	{
		number_of_process++;
	}
	fseek(file, 0, SEEK_SET);

	char **processes = malloc(number_of_process * sizeof(char *));
	if (processes == NULL)
	{
		return (NULL);
	}

	int index = 0;
	while (fgets(buffer, BUFFER_SIZE, file))
	{
		processes[index] = strdup(buffer);
		if (processes[index] == NULL)
		{
			for (int i = 0; i < index; i++)
			{
				free(processes[i]);
			}
			free(processes);
			return (NULL);
		}
		index++;
	}

	pclose(file);

	processes[index] = NULL;

	return (processes);
}
