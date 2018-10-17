#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int);

int main(int argc, char * argv[])
{
	if(signal(SIGHUP, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGHUP\n");
	if(signal(SIGINT, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGINT\n");
	if(signal(SIGQUIT, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGQUIT\n");
	if(signal(SIGILL, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGILL\n");
	if(signal(SIGTRAP, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGTRAP\n");
	if(signal(SIGABRT, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGABRT\n");
	if(signal(SIGBUS, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGBUS\n");
	if(signal(SIGFPE, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGFPE\n");
	if(signal(SIGKILL, sig_handler) == SIG_ERR) //important
		printf("\nCant catch SIGKILL\n");
	if(signal(SIGUSR1, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGHUSR1\n");
	if(signal(SIGSEGV, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGSEGV\n");
	if(signal(SIGUSR2, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGUSR2\n");
	if(signal(SIGPIPE, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGPIPE\n");
	if(signal(SIGALRM, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGALRM\n");
	if(signal(SIGTERM, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGTERM\n");
	if(signal(SIGSTKFLT, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGSTKFLT\n");
	if(signal(SIGCHLD, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGCHLD\n");
	if(signal(SIGCONT, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGCONT\n");
	if(signal(SIGSTOP, sig_handler) == SIG_ERR) //important
		printf("\nCant catch SIGSTOP\n");
	if(signal(SIGTSTP, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGTSTP\n");
	if(signal(SIGTTIN, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGTTIN\n");
	if(signal(SIGTTOU, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGTTOU\n");
	if(signal(SIGURG, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGURG\n");
	if(signal(SIGXCPU, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGXCPU\n");
	if(signal(SIGXFSZ, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGXFSZ\n");
	if(signal(SIGVTALRM, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGVTALRM\n");
	if(signal(SIGPROF, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGPROF\n");
	if(signal(SIGWINCH, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGWINCH\n");
	if(signal(SIGIO, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGHIO\n");
	if(signal(SIGPWR, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGPWR\n");
	if(signal(SIGSYS, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGSYS\n");
	if(signal(SIGRTMIN, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN\n");
	if(signal(SIGRTMIN+1, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+1\n");
	if(signal(SIGRTMIN+2, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+2\n");
	if(signal(SIGRTMIN+3, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+3\n");
	if(signal(SIGRTMIN+4, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+4\n");
	if(signal(SIGRTMIN+5, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+5\n");
	if(signal(SIGRTMIN+6, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+6\n");
	if(signal(SIGRTMIN+7, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+7\n");
	if(signal(SIGRTMIN+8, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+8\n");
	if(signal(SIGRTMIN+9, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+9\n");
	if(signal(SIGRTMIN+10, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+10\n");
	if(signal(SIGRTMIN+11, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+11\n");
	if(signal(SIGRTMIN+12, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+12\n");
	if(signal(SIGRTMIN+13, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+13\n");
	if(signal(SIGRTMIN+14, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+14\n");
	if(signal(SIGRTMIN+15, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMIN+15\n");
	if(signal(SIGRTMAX-14, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-14\n");
	if(signal(SIGRTMAX-13, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-13\n");
	if(signal(SIGRTMAX-12, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-12\n");
	if(signal(SIGRTMAX-11, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-11\n");
	if(signal(SIGRTMAX-10, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-10\n");
	if(signal(SIGRTMAX-9, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-9\n");
	if(signal(SIGRTMAX-8, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-8\n");
	if(signal(SIGRTMAX-7, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-7\n");
	if(signal(SIGRTMAX-6, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-6\n");
	if(signal(SIGRTMAX-5, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-5\n");
	if(signal(SIGRTMAX-4, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-4\n");
	if(signal(SIGRTMAX-3, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-3\n");
	if(signal(SIGRTMAX-2, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-2\n");
	if(signal(SIGRTMAX-1, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX-1\n");
	if(signal(SIGRTMAX, sig_handler) == SIG_ERR)
		printf("\nCant catch SIGRTMAX\n");

	while(1)
		sleep(1);

	return 0;
}

void sig_handler(int sig)
{
	if(sig == SIGHUP)
		printf(" Received SIGHUP\n");
	if(sig == SIGINT)
		printf(" Received SIGINT\n");
	if(sig == SIGQUIT)
		printf(" Received SIGQUIT\n");
	if(sig == SIGILL)
		printf(" Received SIGILL\n");
	if(sig == SIGTRAP)
		printf(" Received SIGTRAP\n");
	if(sig == SIGABRT)
		printf(" Received SIGABRT\n");
	if(sig == SIGBUS)
		printf(" Received SIGBUS\n");
	if(sig == SIGFPE)
		printf(" Received SIGFPE\n");
	if(sig == SIGKILL)
		printf(" Received SIGKILL\n");
	if(sig == SIGUSR1)
		printf(" Received SIGUSR1\n");
	if(sig == SIGSEGV)
		printf(" Received SIGSEGV\n");
	if(sig == SIGUSR2)
		printf(" Received SIGUSR2\n");
	if(sig == SIGPIPE)
		printf(" Received SIGPIPE\n");
	if(sig == SIGALRM)
		printf(" Received SIGALRM\n");
	if(sig == SIGTERM)
		printf(" Received SIGTERM\n");
	if(sig == SIGSTKFLT)
		printf(" Received SIGSTKFLT\n");
	if(sig == SIGCHLD)
		printf(" Received SIGCHLD\n");
	if(sig == SIGCONT)
		printf(" Received SIGCONT\n");
	if(sig == SIGSTOP)
		printf(" Received SIGSTOP\n");
	if(sig == SIGTSTP)
		printf(" Received SIGTSTP\n");
	if(sig == SIGTTIN)
		printf(" Received SIGTTIN\n");
	if(sig == SIGTTOU)
		printf(" Received SIGTTOU\n");
	if(sig == SIGURG)
		printf(" Received SIGURG\n");
	if(sig == SIGXCPU)
		printf(" Received SIGXCPU\n");
	if(sig == SIGXFSZ)
		printf(" Received SIGXFSZ\n");
	if(sig == SIGVTALRM)
		printf(" Received SIGVTALRM\n");
	if(sig == SIGPROF)
		printf(" Received SIGPROF\n");
	if(sig == SIGWINCH)
		printf(" Received SIGWINCH\n");
	if(sig == SIGIO)
		printf(" Received SIGIO\n");
	if(sig == SIGPWR)
		printf(" Received SIGPWR\n");
	if(sig == SIGSYS)
		printf(" Received SIGSYS\n");
	if(sig == SIGRTMIN)
		printf(" Received SIGRTMIN\n");
	if(sig == SIGRTMIN+1)
		printf(" Received SIGRTMIN+1\n");
	if(sig == SIGRTMIN+2)
		printf(" Received SIGRTMIN+2\n");
	return;
}
