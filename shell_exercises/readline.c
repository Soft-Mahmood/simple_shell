#include <stdio.h>
#include <stdlib.h>

/**
 * writes $ and waits for the user to enter a command
 * then prints the command on the next line.
 */
int main(void)
{
	char *buffer = malloc(sizeof(char));
	size_t len = 1024;

	while (1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		printf("%s", buffer);
	}
	return (0);
}
