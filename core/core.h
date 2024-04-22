#ifndef CORE_H
#define CORE_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define BUFFER_SIZE 1024
#define USER 0
#define SYSTEM 1
#define BOTH 2

char **list_processes(int type);
int send_signal(pid_t pid, int signal);

/* helpers */
void free_2d_array(char **arr);

#endif
