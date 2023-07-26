#include "shell.h"

/**
 * _cd - changes directory
 * @str: user's typed in command
 * @env: enviromental linked list to retrieve HOME and OLDPWD paths
 * @num: nth user command, to be used at error message
 * Return: 0 if success 2 if failed
 */
int _cd(char **str, list_t *env, int num)
{
	char *current = NULL, *dir = NULL;
	int exit_stat = 0;

	/* store current working directory */
	current = getcwd(current, 0);
	if (str[1] != NULL)
	{
		/* Usage: cd ~ */
		if (str[1][0] == '~')
		{
			dir = get_env("HOME", env);
			dir = c_strcat(dir, str[1]);
		}
		/* Usage: cd - */
		else if (str[1][0] == '-')
		{
			if (str[1][1] == '\0')
				dir = get_env("OLDPWD", env);
		}
		/* Usage: cd directory 1 */
		else
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, str[1]);
			}
			else
				dir = _strdup(str[1]);
		}
		exit_stat = cd_execute(env, current, dir, str[1], num);
		free(dir);
	}
	else /* Usage: cd */
		cd_home(env, current);
	/*free_double_ptr(str); frees user input */
	return (exit_stat);
}

/**
 * cd_execute - executes changing the directory
 * @env: bring in environmental linked list to update PATH and OLDPWD
 * @current: bring in current working directotry
 * @dir: bring in directory path to change to
 * @str: bring in the 1st argument to write out error
 * @num: bring in the line number to write out error
 * Return: 0 if success, and return 2 if fail
 */
int cd_execute(list_t *env, char *current, char *dir, char *str, int num)
{
	int i = 0;

	if (access(dir, F_OK) == 0)
	{
		/*update env OLDPWD */
		c_setenv(&env, "OLDPWD", current);
		free(current);
		chdir(dir);
		current = NULL;
		/* get the current working dir with getcwd */
		current = getcwd(current, 0);
		/* then we update the pwd environment */
		c_setenv(&env, "PWD", current);
		free(current);
	}
	else
	{
		cant_cd_to(str, num, env);
		free(current);
		i = 2;
	}
	return (i);
}

/**
 * cd_home - change directory to home
 * @env: bring in environmental linked list to update PATH and OLDPWD
 * @current: bring in current working directotry
 */
void cd_home(list_t *env, char *current)
{
	char *home = NULL;

	home = get_env("HOME", env);
	/* update the oldpwd env */
	c_setenv(&env, "OLDPWD", current);
	free(current);
	/* if exist, go to home dir */
	if (access(home, F_OK) == 0)
		chdir(home);
	current = NULL;
	current = getcwd(current, 0);
	c_setenv(&env, "PWD", current); /* update env PWD */
	free(current);
	free(home);
}
