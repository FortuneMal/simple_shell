#include "shell.h"
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
/**
 *main-check the code.
 * Return: Always 0.
 */
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *command;

	size_t bufsize = 0;

	signal(SIGINT, sig_handler);

	while (1)
	{
		displayPrompt(isatty(STDIN_FILENO));
		getline(&command, &bufsize, stdin);

		if (feof(stdin))
		{
			printf("\n");
			free(command);
			exit(EXIT_SUCCESS);
		}

		executeCommand(command);
		free(command);
	}

	return (0);
}
