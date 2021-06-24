#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static char c;
static int size;

void handler_sigusr1(int sig)
{
	c += (1 << size);
	size--;
	//write(STDOUT_FILENO, "1", 1);
}

void handler_sigusr2(int sig)
{
	c += (0 << size);
	size--;
	//write(STDOUT_FILENO, "0", 1);
}

int main()
{
	char	*str;
	int		x;
	int		pid;
	
	str = "abc";
	pid = getpid();
	signal(SIGUSR1, handler_sigusr1);
	signal(SIGUSR2, handler_sigusr2);
	while (*str)
	{
		c = 0;
		size = 7;
		x = 0;
		while (x < 8)
		{
			if ((*str << x) & 0x80)
				kill(pid ,SIGUSR1);
			else if (!((*str << x) & 0x80))
				kill (pid, SIGUSR2);
			else
				write(1, "-", 1);
			x++;
		}
		if (c != 97) //for EOF signal
			write(1, &c, 1);
		else
			write(1, "\n", 1);
		str++;
	}
	printf("\n");	
}
