#include <signal.h>
#include <stdio.h>


void handleSigInt(int sig)
{
	printf("Received signal %d\n", sig);
	getchar();
}
