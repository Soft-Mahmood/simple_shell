#include "shell.h"

/**
 * env_linked_list - creates a linked list from environmental variables
 * @env: environmental variables
 * Return: linked list
 */
list_t *env_linked_list(char **env)
{
	list_t *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		add_end_node(&head, env[i]);
		i++;
	}
	return (head);
}

/**
 * _env - prints environmental variables
 * @str: user's command into shell (i.e. "env")
 * @env: environmental variables
 * Return: 0 on success
 */
int _env(char **str, list_t *env)
{
	free_double_ptr(str); /* frees user input */
	print_list(env); /* prints env */
	return (0);
}

/**
 * get_env - finds and returns a copy of the requested environmental variable
 * @str: string to store it in
 * @env: entire set of environmental variables
 * Return: copy of requested environmental variable
 */
char *get_env(char *str, list_t *env)
{
	int j = 0, cs = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->env_var_str)[j] == str[j]) /* find desired env variable */
			j++;
		if (str[j] == '\0' && (env->env_var_str)[j] == '=')
			break;
		env = env->next;
	}

	while (str[cs] != '\0') /* find how many bytes in env variable title */
		cs++;
	cs++; /*counts 1 more for = sign*/
	return (c_strdup(env->env_var_str, cs));
	/* make a copy of variable w/o title */
}
