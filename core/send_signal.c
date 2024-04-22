#include "core.h"

/**
 * send_signal - send a signal to a specific process or a group of processes
 *
 * Return: no thing
 */

void send_signal(pid_t pid, int signal)
{
	if (!kill(pid, signal))
	{
		printf("Signal %d sent to process ID %d successfully.\n", signal, pid);
	}
	else
	{
		perror("Error sending signal");
	}
}
