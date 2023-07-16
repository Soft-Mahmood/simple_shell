#include "shell.h"

/**
 * the function prompt.c 
 * writes $ on the screen and waits for the user to enter a command
 * returns a pointer to the string of characters in the command.
 * returns 0 on failure.
 */
char prompt(void)
{
	char *buffer = malloc(sizeof(char));
	size_t len = 1024;

	while (1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);

		return (buffer);
	}
	return (0);
}
