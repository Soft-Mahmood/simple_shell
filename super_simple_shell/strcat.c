#include "shell.h"

/**
 * _strcat concatenates two strings
 * @fnstr is the string to be appended to
 * @instr is the string to append
 * returns the concatenated string
 */
char *_strcat(char *fnstr, char *instr)
{
	int len = 0, len2 = 0, total_len = 0, j = 0;

	/*test total length of both strings to reallocate*/
	while (fnstr[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (instr[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	fnstr = _realloc(fnstr, len, sizeof(char) * total_len + 1);

	while (instr[j] != '\0')
	{
		fnstr[len] = instr[j];
		len++;
		j++;
	}
	fnstr[len] = '\0';

	return (fnstr);
}
