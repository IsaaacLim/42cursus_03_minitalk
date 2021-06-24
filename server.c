#include "minitalk.h"

static char c;
static int size;

/*static void	handler(int sig)
{
	if (sig == SIGUSR1)
		c += (1 << size);
	else
		c += (0 << size);
	size--;
}*/

static void	ft_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
		c += (1 << size);
	else
		c += (0 << size);
	size--;
	if (size == -1 && c == 4)
	{
		kill(info->si_pid, SIGUSR1);
		//write(1, "o", 1);
	}
}

int main(void)
{
	int pid;
	struct sigaction sa;
	
	c = 0;
	size = 7;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	//signal(SIGUSR1, handler);
	//signal(SIGUSR2, handler);
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		if (size == -1)
		{
			if (c != 4)
				write(1, &c, 1);
			else
				write(1, "\n", 1);
			c = 0;
			size = 7;
		}
	}
}
