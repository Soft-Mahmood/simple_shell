#include "shell.h"

/**
 * numlen - counts number of 0s in a tens power number
 * @n: number
 * Return: returns count of digits
 */
int numlen(int n)
{
	int count = 0;
	int num = n;

	while (num > 9 || num < -9)
	{
		num /= 10;
		count++;
	}
	return (count);
}
/**
 * int_to_string - turns an int into a string
 * @number: int
 * Return: returns the int as a string. returns NULL if failed
 */

char *int_to_string(int number)
{
	int digits, tens, i = 0, t = 0, x;
	char *res;

	digits = number;
	tens = 1;

	if (number < 0)
		t = 1;
	res = malloc(sizeof(char) * (numlen(digits) + 2 + t));
	if (res == NULL)
		return (NULL);
	if (number < 0)
	{
		res[i] = '-';
		i++;
	}
	for (x = 0; digits > 9 || digits < -9; x++)
	{
		digits /= 10;
		tens *= 10;
	}
	for (digits = number; x >= 0; x--)
	{
		if (digits < 0)
		{
			res[i] = (digits / tens) * -1 + '0';
			i++;
		}
		else
		{
			res[i] = (digits / tens) + '0';
			i++;
		}
		digits %= tens;
		tens /= 10;
	}
	res[i] = '\0';
	return (0);
}

/**
 * c_atoi - converts string to int
 * @s: is a string
 * Return: number if success and -1 when the sring non number xters.
 */
int c_atoi(char *s)
{
	int i = 0;
	unsigned int num = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9') /* calculate num */
			num = num * 10 + (s[i] - '0');
		if (s[i] > '9' || s[i] < '0') /* account for non-numbers */
			return (-1);
		i++;
	} return (num);
}

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: number of spaces between the strings.
 * 0 if the strings are the same
 */
int _strcmp(char *str1, char *str2)
{
	int x = 0;

	while ((*str1 + x) == *(str2 + x) && *(str1 + x))
		x++;

	if (*(str2 + x))
		return (*(str1 + x) - *(str2 + x));
	else
		return (0);
}

/**
 * _strcpy - copies the string pointed to by the @instr
 * @fnstr: to the buffer pointed to by @fnstr
 * @instr: initial string
 * Return: the copy of the original source
 */
char *_strcpy(char *fnstr, char *instr)
{
	int i, len;

	for (len = 0; instr[len] != '\0'; len++)
	{
		for (i = 0; i <= len; i++)
			fnstr[i] = instr[i];
	} return (fnstr);
}
