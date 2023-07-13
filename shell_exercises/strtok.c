#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv)
{
	int j;
	char *str, *str, *token;

	if (argc != 4)
	{
		fprintf(stderr, "Usage: %s string delim\n", argv[0]);
		exit (EXIT_FAILURE);
	}

	for (j = 1; str = argv[1]; j++; str = NULL)
	{
		token = strtok(str, argv[2]);
		if (token == NULL)
			break;
		printf("%d:%s\n", j, token);
	}

	exit(EXIT_SUCCESS);
}	
