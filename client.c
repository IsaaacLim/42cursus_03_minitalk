#include "minitalk.h"

static void	ft_send_string(int pid, char *str, int last)
{
	int	x;

	while (*str)
	{
		x = 0;
		while (x < 8)
		{
			if ((*str << x) & 0x80)
			{
				kill(pid, SIGUSR1);
			//	write (1, "1", 1);
			}
			else
			{
				kill(pid, SIGUSR2);
			//	write (1, "0", 1);
			}
			x++;
			usleep(50);
		}
	//	write(1, "\n", 1);
		str++;
	}
	if (last == 0)
	{	
		ft_send_string(pid, "\n", 1);
	}
}
int main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
		ft_putstr("run: ./client <PID> \"Message\"\n");
	else
	{
		//ft_putstr("ok\n");
		pid = ft_atoi(argv[1]);
		//printf("%d\n", pid);
		ft_send_string(pid, argv[2], 0);
	}
}
