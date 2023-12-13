#include <signal.h>
#include <stdio.h>

/**
 * handleSigInt - Display a prompt and wait for the user to type a command.
 * @sig: The signal to exit
 * Return: No return
 */

void handleSigInt(int sig)
{
	printf(" Received signal %d\n", sig);
	getchar();
}
