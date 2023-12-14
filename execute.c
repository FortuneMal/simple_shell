#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * sig_handler - Signal handler for Ctrl+C interruption.
 * @num: The signal number.
 */
void sig_handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n#cisfun$ ", strlen("\n#cisfun$ "));
}


/**
 * executeCommand - Execute the given command in a child process.
 * @command: The command to be executed.
 *
 */

void executeCommand(char *command)
{
	char *argument[MAX_C];
	int n = 0;

	command = trim(command);

	if (strlen(command) == 0)
		return;

	argument[n] = strtok(command, " \n");

	while (argument[n])
	{
		n++;
		argument[n] = strtok(NULL, " \n");
	}

	if (access(argument[0], X_OK) == -1)
	{
		perror("./shell");
	}
	else
	{
		if (fork() == 0)
		{
			execvp(argument[0], argument);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
}
