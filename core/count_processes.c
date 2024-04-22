#include "core.h"


/**
 * @brief Return the number of running processes using the ps and wc command
 *
 * @param[char *] command The ps command, appending wc -l command to it
 * @return the number of running processes
 */
int count_process(char *command)
{
	char wc_buffer[10];

	strcat(command, " | wc -l");

	FILE *wc_file = popen(command, "r");

	if (!wc_file)
		return (0);

	int number_of_processes = 0;
	while (fgets(wc_buffer, 10, wc_file))
	{
		wc_buffer[strlen(wc_buffer) - 1] = '\0';
		number_of_processes = atoi(wc_buffer);
	}

	pclose(wc_file);
	free(command);

	return (number_of_processes);
}
