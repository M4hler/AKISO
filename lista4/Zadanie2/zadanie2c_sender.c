#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int pid = atoi(argv[1]);

	for(int i = 0; i < 10; i++)
	{
		printf("%d signal sent to pid: %d\n", i+1, pid);
		kill(pid, SIGUSR1);
	}

	kill(pid, SIGUSR2);

	return 0;
}
