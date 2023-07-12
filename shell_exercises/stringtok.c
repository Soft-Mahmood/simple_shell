#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

/**
 * this function splits a string
 * returns an array of each word
 */
int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;
	char *token;

	while (1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		printf("buffer getline: %s", buffer);

		token = strtok(buffer, " ");
		while (token)
		{
			printf("buffer strtok: %s\n", token);
			token = strtok(NULL, " ");
		}
	}
	return (0);
}
