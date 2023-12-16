#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_C 20

void displayPrompt(bool flg);
void sig_handler(int num);
void executeCommand(char *cmd);
void prompt(bool flg);
void *trim(char *str);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

#endif
