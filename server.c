#include "minitalk.h"

//static char c;
//static int shift;

/*static void	handler(int sig)
{
	if (sig == SIGUSR1)
		c += (1 << shift);
	else
		c += (0 << shift);
	shift--;
}*/

static void	ft_handler(int sig, siginfo_t *info, void *context)
{
	//t_serverVar *charVar; //check
	if (sig == SIGUSR1)
		g_var.c += (1 << g_var.shift);
	else
		g_var.c += (0 << g_var.shift);
	g_var.shift--;
	if (g_var.shift == -1 && g_var.c == 4)
		kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	int pid;
	struct sigaction sa;
	g_var.c = 0;
	g_var.shift = 7;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		if (g_var.shift == -1)
		{
			if (g_var.c != 4)
				write(1, &g_var.c, 1);
			else
				write(1, "\n", 1);
			g_var.c = 0;
			g_var.shift = 7;
		}
	}

	//To do, change global variable to structs
}
