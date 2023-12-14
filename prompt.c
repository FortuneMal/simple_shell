#include "shell.h"
#include <unistd.h>
#include <string.h>

void displayPrompt(bool flg)
{
	if (flg && isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#cisfun$ ", strlen("#cisfun$ "));
	}
}
