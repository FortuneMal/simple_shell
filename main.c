#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 *main-check the code.
 * Return: Always 0.
 */

int main(void)
{
	size_t bufferSize = 0;
	char *command = NULL;

	int Result;

	do {
		displayPrompt();

		Result = getline(&command, &bufferSize, stdin);

		switch (Result)
		{
			case -1:
				perror("getline");
				exit(EXIT_FAILURE);
				break;

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
