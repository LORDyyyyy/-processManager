#include "main.h"
void signalInput()
{
	// SIGINT,SIGILL,SIGFPE,SIGKILL,SIGTERM,SIGSVEG,SEGUSR1,SIGSTOP
	pid_t pid;
	int signal;
	printf("select the PID and the signal type you want to perform ");
	scanf("%d %d", &pid, &signal);
}
