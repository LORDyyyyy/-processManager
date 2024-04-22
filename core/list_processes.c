#include "core.h"

/**
 * list_process - prints list of proceess
 *
 * @type: the type of process 0 for USER 1 for SYSTEM 2 for BOTH
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
	char **processes = malloc(MAX_PROCESSES * sizeof(char *));
	if (processes == NULL)
	{
		perror("Memory allocation failed");
		return NULL;
	}

	int index = 0;
	while (fgets(buffer, BUFFER_SIZE, file))
	{
		processes[index] = strdup(buffer);
		if (processes[index] == NULL)
		{
			perror("Memory allocation failed");
			for (int i = 0; i < index; i++)
			{
				free(processes[i]);
			}
			free(processes);
			return NULL;
		}
		index++;
	}

	pclose(file);

	processes[index] = NULL;

	return processes;
}
