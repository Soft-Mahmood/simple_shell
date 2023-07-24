#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @fnstr: is the string to be appended to
 * @instr: is the string to append
 * Return: the concatenated string
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
/**
 * c_strcat - concatenate two strings ignoring the first character ("~" in cd)
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */
char *c_strcat(char *dest, char *src)
{
	int len = 0;
	int len2 = 0;
	int total_len = 0;
	int j = 0;

	/* find total length of both strings to _realloc */
	while (dest[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	/* _realloc because dest was malloced outside of function */
	dest = _realloc(dest, len, sizeof(char) * total_len + 1);

	j = 1; /* ignore the first character */
	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}

	dest[len] = '\0';

	return (dest);
}
