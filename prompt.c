#include "shell.h"
#include <unistd.h>
#include <string.h>

/**
 * displayPrompt - Display the shell prompt if allowed by the flag.
 * @flg: A flag indicating whether to display the prompt or not.
 */

void displayPrompt(bool flg)
{
	if (flg && isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#cisfun$ ", strlen("#cisfun$ "));
	}
}
