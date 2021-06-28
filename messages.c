#include "minitalk.h"

void	ft_completed(int sig)
{
	ft_putstr("Message successfully sent & print\n");
}

void	ft_failed(int type)
{
	if (type == 0)
		ft_putstr("run: ./client <PID> \"Message\"\n");
	else if (type == 1)
		ft_putstr("PID not found, check PID\n");
	exit(type);
}
