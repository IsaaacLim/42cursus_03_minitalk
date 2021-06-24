#include <stdio.h>
#include <signal.h>
#include <unistd.h>
# include <sys/types.h>

void handler_sigusr1(int sig)
{
	write(STDOUT_FILENO, "1", 1);
}

void handler_sigusr2(int sig)
{
	write(STDOUT_FILENO, "0", 1);
}

int main()
{
	int x;
	int pid;
	
	x = -3;
	pid = getpid();
	signal(SIGUSR1, handler_sigusr1);
	signal(SIGUSR2, handler_sigusr2);
	while (x++ <= 3)
	{
		if (x == 1)
			kill(pid ,SIGUSR1);
		else if (x == 0)
			kill (pid, SIGUSR2);
		else
			write(1, "-", 1);
	}
	printf("\n");	
}
