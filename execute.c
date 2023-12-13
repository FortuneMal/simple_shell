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
 * Return: No return value.
 */

void executeCommand(char *command)
{
	pid_t childPid;
	int status;
	char *args[2];
	char *token = strtok(command, " ");

	if (token == NULL)
	{
		fprintf(stderr, "invalid command\n");
		return;
	}

	args[0] = token;
	args[1] = NULL;

	childPid = fork();

	switch (childPid)
	{
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
			break;

		case 0:
			if (execvp(args[0], args) == -1)
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
				exit(EXIT_FAILURE);
			}
			break;

		default:
			waitpid(childPid, &status, 0);
			break;
	}
}
