#include "shell.h"

/**
 * _strcpy copies the string pointed to by the @instr
 * to the buffer pointed to by @fnstr
 * returns the copy of the original source
 */
char *_strcpy(char *fnstr, char *instr)
{
	int i, len;

	for (len = 0; instr[len] != '\0'; len++)
	{
		for (i = 0; i <= len; i++)
			fnstr[i] = instr[i];
	}
	return (fnstr);
}
