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
			free_2d_array(processes);
			return (NULL);
		}
		index++;
	}

	pclose(file);
	processes[index] = NULL;

	return (processes);
}


/**
 * free_2d_array - frees a 2d arrays of char
 * @arr: the 2d array
 *
 * Return: void
 */
void free_2d_array(char **arr)
{
	int i;

	if (arr != NULL)
	{
		for (i = 0; arr[i]; i++)
			free(arr[i]);
		free(arr);
		arr = NULL;
	}
}
