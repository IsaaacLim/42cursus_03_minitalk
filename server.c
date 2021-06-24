#include "minitalk.h"

static char c;
static int size;

static void	handler_sigusr1(int sig)
{
	c += (1 << size);
	size--;
}

static void handler_sigusr2(int sig)
{
	c += (0 << size);
	size--;
}

int main(void)
{
	int pid;

	c = 0;
	size = 7;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, handler_sigusr1);
	signal(SIGUSR2, handler_sigusr2);
	while (1)
	{
		if (size > 0)
		{
			write(1, &c, 1);
			c = 0;
			size = 7;
		}
	}
}