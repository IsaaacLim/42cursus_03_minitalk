#include "minitalk.h"

static void	ft_send_string(int pid, char *str, int last)
{
	int		x;
	char	end[1];

	end[0] = 4;
	while (*str)
	{
		x = -1;
		while (++x < 8)
		{
			if ((*str << x) & 0x80)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_failed(1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_failed(1);
			}
			usleep(50);
		}
		str++;
	}
	if (last == 0)
		ft_send_string(pid, end, 1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_failed(0);
	else
	{
		signal(SIGUSR1, ft_completed);
		pid = ft_atoi(argv[1]);
		ft_send_string(pid, argv[2], 0);
		usleep(50);
	}
}
