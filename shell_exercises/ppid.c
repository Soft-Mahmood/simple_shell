#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * ppid gets the PId of the parent process.
 * always successful
 */
int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}