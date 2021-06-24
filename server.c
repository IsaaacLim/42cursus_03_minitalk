#include "minitalk.h"

static char c;
static int size;

static void	handler(int sig)
{
	if (sig == SIGUSR1)
		c += (1 << size);
	else
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
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		if (size == -1)
		{
			write(1, &c, 1);
			c = 0;
			size = 7;
		}
	}
}
