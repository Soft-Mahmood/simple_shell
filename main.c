#include "shell.h"

/**
 * main - the main function on which the function runs
 * @argc: is the number of arguments passed
 * @argv: is the arguments parsed intp the program
 * @env: is the string passed to the shell
 * implements EOF
 * Prints errors on failure
 * Return: 0 on sucsess
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	prompt(env);
	return (0);
}
