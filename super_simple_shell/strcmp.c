#include "shell.h"

/**
 * _strcmp compares two strings
 * str1 being the first string
 * str2 being the second sttring
 * returns the number of spaces between them
 * returns 0 if the strings are the same
 */
int _strcmp(char *str1, char *str2)
{
	int x = 0;

	while (*(str1 + x) == *(str2 + x) && *(str1 + x))
		x++;

	if (*(str2 + x))
		return (*(str1 + x) - *(str2 + x));
	else
		return (0);
}
