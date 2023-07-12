#include <stdio.h>

/**
 * this program prints all arguments
 * without using ac
 */
int main(int ac, char **av)
{
	int count;

	if (ac > 1)
	{
		for (count = 1; count < ac; count++)
		{
			printf("%s\n", av[count]);
		}
	}
	else
	{
		return (0);
	}
	return (0);
}
