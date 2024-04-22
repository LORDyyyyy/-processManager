#include "core.h"

/**
 * send_signal - send a signal to a specific process or a group of processes
 *
 * @pid: the ID of the process
 * @signal: represents the signal that will be sent
 * Return: 1 if success otherwise 0
 */

int send_signal(pid_t pid, int signal)
{
	if (!kill(pid, signal))
	{
		return (1);
	}
	else
	{
		perror("Error sending signal");
		return (0);
	}
}
