#ifndef CORE_H
#define CORE_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define BUFFER_SIZE 1024

char **list_processes();
char **send_signal(pid_t pid, int signal);

#endif
