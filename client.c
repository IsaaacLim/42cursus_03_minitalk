#include "minitalk.h"

int main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
		ft_putstr("./client <PID> \"Message\"\n");
	else
	{
		ft_putstr("ok\n");
		pid = ft_atoi(argv[1]);
		printf("%d\n", pid);
	}
}