/*
** fork() - Returns the PID of the child process in the parent; 0 is returned
**	 to the child; if fails, -1 is return to the parent &
**	 no child process is created 
** usleep() - sleep specified in micro seconds
** kill() - sends signal to a process
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int	main ()
{
	int pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0) //child process
	{
		while (1) //infinite loop
			printf("In child process\n");
			usleep(500000); //so that it doesn't print so fast
	}
	else
	{
		sleep(1); //so it can let the child process run for awhile
		kill(pid, SIGKILL); //sends the SIGKILL signal to the child process
		wait(NULL); //to stop zombie processes(?)
	}

}