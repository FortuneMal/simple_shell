#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

/**
 *main-check the code.
 * Return: Always 0.
 */

int main(void)
{
	size_t bufferSize = 0;
	char *command = NULL;
	int Result;

	signal(SIGINT, handleSigInt);

	do {
		displayPrompt();

		Result = getline(&command, &bufferSize, stdin);

		if (Result == -1 || feof(stdin))
		{
			free(command);
			exit(EXIT_SUCCESS);
		}

		switch (Result)
		{
			case 0:
				printf("\n");
				break;

			default:
				command[strcspn(command, "\n")] = '\0';
				executeCommand(command);
				break;
		}
	} while (1);

	free(command);
	return (0);
}
