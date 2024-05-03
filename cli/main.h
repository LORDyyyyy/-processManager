#ifndef MAIN_H
#define MAIN_H
#include "../core/core.h"
#include <sys/ioctl.h>
#include <unistd.h>
int typeInput();
int signalInput();
void formatePrinting(char **arr);

#endif // MAIN_H