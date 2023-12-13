#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * executeCommand - Execute a command using fork and execlp.
 * @command: The command to be executed along with its arguments.
 * Return: No explicit return value. The function exits on failure.
 */

void executeCommand(char *command)
{
	pid_t childPid;
	int status;

	childPid = fork();

	switch (childPid)
	{
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
			break;

		case 0:
		{
			char *args[64];
			char *token = strtok(command, "");
			int i = 0;

			while (token != NULL)
			{
				args[i++] = token;
				token = strtok(NULL, "");
			}

			args[i] = NULL;

			if (execvp(args[0], args) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		break;

		default:
		waitpid(childPid, &status, 0);
		break;
	}
}
