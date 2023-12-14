#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * exitShell - Exits the shell.
 * Description: This function prints a message and exits the program.
 */

void exitShell(void)
{
	printf("About to exit shell.\n");
	exit(EXIT_SUCCESS);
}
