#include "core.h"

/**
 * @brief Returns a list of processes
 *
 * @param[const int] type the type of the process: 0 for USER and 1 for USER and
 * SYSTEM
 * @return an array of strings containing process information in a table format
 */
char **list_processes(const int type)
{
	char buffer[BUFFER_SIZE];
	char *command;
	int index = 0;

	switch (type)
	{
		case 0:
			asprintf(&command, "ps -U %s -o user,pid,%%cpu,%%mem,time,command",
					 getlogin());
			break;
		case 1:
			asprintf(&command, "ps -e -o user,pid,%%cpu,%%mem,time,command");
			break;
		default:
			return (NULL);
	}

	int number_of_process = count_process(strdup(command));
	if (!number_of_process)
		return (NULL);

	FILE *file = popen(command, "r");
	if (!file)
		return (NULL);

	char **processes = malloc((number_of_process + 1) * sizeof(char *));
	if (processes == NULL)
		return (NULL);

	while (index < number_of_process && fgets(buffer, BUFFER_SIZE, file))
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
	free(command);
	
    for (; index <= number_of_process; index++)
		processes[index] = NULL;

	return (processes);
}
