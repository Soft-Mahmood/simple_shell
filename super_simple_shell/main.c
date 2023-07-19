#include "shell.h"

/**
 * argc is the number of arguments passed
 * argv is the arguments parsed intp the program
 * env is the string passed to the shell
 * implements EOF
 * Prints errors on failure
 * returns 0 on sucsess
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	prompt(env);
	return (0);
}
