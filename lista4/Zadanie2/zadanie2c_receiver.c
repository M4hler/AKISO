#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void sig_handler(int);

int main(int argc, char * argv[])
{
	printf("PID: %d\n", getpid());

	if(signal(SIGUSR1, sig_handler) == SIG_ERR)
		printf(" Cant catch SIGUSR1\n");
	if(signal(SIGUSR2, sig_handler) == SIG_ERR)
		printf(" Cant catch SIGUSR2\n");

	while(1)
	{
		sleep(1);
	}

	return 0;
}

void sig_handler(int sig)
{
	if(sig == SIGUSR1)
		printf(" Signal SIGUSR1 received\n");
	if(sig == SIGUSR2)
		printf(" Signal SIGUSR2 received\n");
	return;
}
