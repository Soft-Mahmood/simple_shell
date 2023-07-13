#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * this program creates a child
 * waits for the child to execute and exit
 * a does so 5 times.
 * returns 0 on success.
 * returns -1 on any failure.
 */
int main(void)
{
	int status;
	int j;
	pid_t child_pid;
	pid_t parent_pid;
	char *argv[] = {"/tmp/ls", "-1", "/usr/", NULL};

	/*prints parent pid*/
	parent_pid = getpid();
	printf("Before children '%u\n'", parent_pid);

	/*loop for children*/
	for (j = 1; j < 6; j++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			printf("Child '%i\n'", j);
			printf("PID is: '%u\n'",child_pid);
			
			/*executing the program*/
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				return (EXIT_FAILURE);
			}
			printf("child '%i\n' done", j);
		}
		else 
		{
			wait(&status);
			printf("Going to the next child");
		}
	}
	return (EXIT_SUCCESS);
}
