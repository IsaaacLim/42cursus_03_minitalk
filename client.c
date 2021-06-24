#include "minitalk.h"

static void ft_completed(int sig)
{
	ft_putstr("Message successfully sent & print\n");
}

static void	ft_send_string(int pid, char *str, int last)
{
	int	x;
	char end[1];

	end[0] = 4;
	while (*str)
	{
		x = 0;
		while (x < 8)
		{
			if ((*str << x) & 0x80)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			x++;
			usleep(50);
		}
		str++;
	}
	if (last == 0)
		ft_send_string(pid, end, 1);
}

int main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
		ft_putstr("run: ./client <PID> \"Message\"\n");
	else
	{
		signal(SIGUSR1, ft_completed);
		pid = ft_atoi(argv[1]);
		ft_send_string(pid, argv[2], 0);
		usleep(50);
	}
}
