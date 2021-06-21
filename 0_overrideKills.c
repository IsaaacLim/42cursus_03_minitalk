/*
** ctrl c (SIGINT)
**   have handler function to run whenever SIGNINT signal is received,
**   instead of the usual program INTERUPT.
** ctrl z (SIGTSTP)
** kill -TERM PID (SIGTERM)
** kill -KILL PID (SIGKILL) or [kill -9 PID]
**   Can't handle this. This is an order, not request
**
** sigaction - Newer function that provides more information and portable
*/

# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>

void handler(int num)
{
	write(STDOUT_FILENO, "I won't die HAHAHA!\n", 20);
}


int	main(int argc, char **argv)
{
	struct sigaction sa;
	sa.sa_handler = handler; //&handler also does the same?
	
	signal(SIGINT, handler);
	signal(SIGTERM, handler);
	signal(SIGTSTP, handler);
	signal(SIGKILL, handler); //won't work
	//sigaction(SIGINT, &sa, NULL);
	//sigaction(SIGTERM, &sa, NULL);

	while (1)
	{
		printf("Wasting your cycles. %d\n", getpid());
		sleep(1);
	}
}