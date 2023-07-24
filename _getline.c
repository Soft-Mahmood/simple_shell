#include "shell.h"

/**
 * get_line - stores into a malloced buffer the user's command into shell
 * @str: is the buffer
 * Return: the number of characters read
 */
size_t get_line(char **str)
{
	ssize_t i = 0, size = 0, n = 0;
	ssize_t t = 0, t2 = 0;
	char buffer[1024];

	/* read while there is stdin > buffer; */
	while (t2 == 0 && (i = read(STDIN_FILENO, buffer, 1024 - 1)))
	{
		if (i == -1) /* check if read errored */
			return (-1);

		buffer[i] = '\0'; /* terminate buffer with \0 to use with _strcat */
		n = 0;
		/* last loop if \n is found in the stdin read */
		while (buffer[n] != '\0')
		{
			if (buffer[n] == '\n')
				t2 = 1;
			n++;
		}

		/* copy what's read to buffer into get_line's buffer */
		if (t == 0) /* malloc the first time */
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buffer);
			size = i;
			t = 1;
		}
		else /* _realloc via _strcat with each loop */
		{
			size += i;
			*str = _strcat(*str, buffer);
		}
	}
	return (size);
}
