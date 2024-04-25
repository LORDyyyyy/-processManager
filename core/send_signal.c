#include "core.h"

/**
 * @brief Send a signal to a specific process or a group of processes
 *
 * @param[pid_t] pid The ID of the process
 * @param[const int] signal The signal type that will be sent
 * @return 1 on success, 0 otherwise
 */
int send_signal(pid_t pid, const int signal)
{
	if (!kill(pid, signal))
		return (1);
	return (0);
}
