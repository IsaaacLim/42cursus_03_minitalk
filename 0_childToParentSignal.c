/*
** Child process is delayed 5 secs before sending a signal to the Parant process
** to run the handler_sigusr1 function that just gives a hint
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

int x = 0;

void handler_sigusr1(int sig)
{
	if (x == 0) //if no input
		printf("\n(HINT) Remeber that multiplication is repetitive addition\n");
}

int main ()
{
	int pid = fork();
	struct sigaction sa = { 0 };
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handler_sigusr1;

	if (pid == -1)
		return 1;
	if (pid == 0)
	{
		sleep(5); //wait 5 sec
		kill(getppid(), SIGUSR1); //sends SIGUSR1 to Parent process
	}
	else
	{
		//Parent process
		sigaction(SIGUSR1, &sa, NULL);
		printf("What is 3 x 5: ");
		scanf("%d", &x);
		if (x == 15)
			printf("Right!\n");
	}
	wait(NULL);
}