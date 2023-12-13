#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>

void displayPrompt(void);
void executeCommand(char *command);
void handleSigInt(int sig);

#endif
