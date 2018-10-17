#include <signal.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
	int a = kill(1, SIGKILL);
	if(a==0) //kill successful
		printf("Init kill successfully: %d\n", a);
	if(a < 0) //kill unsuccessful
		printf("Init wasnt killed: %d\n", a);
}

