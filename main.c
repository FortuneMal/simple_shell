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
    char *cmd;
    size_t bufsize = 0;

    signal(SIGINT, sig_handler);

    while (1)
    {
        displayPrompt(isatty(STDIN_FILENO));
        getline(&cmd, &bufsize, stdin);

        if (feof(stdin))
        {
            printf("\n");
            free(cmd);
            exit(EXIT_SUCCESS);
        }

        executeCommand(cmd);
        free(cmd);
    }

    return 0;
}
