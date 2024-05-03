#include "main.h"
int signalInput()
{
	// SIGINT,SIGILL,SIGFPE,SIGKILL,SIGTERM,SIGSVEG,SEGUSR1,SIGSTOP
	pid_t pid;
	int signal;

    printf("Signal\t\t\t\t\tFunction\n");
    printf("--------------------------------------------\n");
    printf("SIGINT\t\t\t\t\tProgram Interrupt : 2\n");
    printf("SIGILL\t\t\t\t\tIllegal Instruction : 4\n");
    printf("SIGFPE\t\t\t\t\tFloating Point Exception : 8\n");
    printf("SIGKILL\t\t\t\t\tKill Signal : 9\n");
    printf("SIGTERM\t\t\t\t\tTermination Signal : 15\n");
    printf("SIGSEGV\t\t\t\t\tSegmentation Violation : 11\n");
    printf("SIGUSR1\t\t\t\t\tUser-defined Signal 1 : 10\n");
    printf("SIGSTOP\t\t\t\t\tStop Process : 19\n");
	printf("select the PID and the signal type you want to perform ");
	
    scanf("%d %d", &pid, &signal);
    
    int state = send_signal(pid,signal);
    return state;
}
