#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void sig_handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n#cisfun$ ", strlen("\n#cisfun$ "));
}

void executeCommand(char *cmd)
{
	char *rgv[MAX_C];
	int x = 0;

	cmd = trim(cmd);

	if (strlen(cmd) == 0)
		return;
	
	rgv[x] = strtok(cmd, " \n");

	while (rgv[x])
	{
		x++;
		rgv[x] = strtok(NULL, " \n");
	}

	if (access(rgv[0], X_OK) == -1)
	{
		perror("./shell");
	}
	else
	{
		if (fork() == 0)
		{
			execvp(rgv[0], rgv);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
}
