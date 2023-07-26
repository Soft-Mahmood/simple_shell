#include "shell.h"

/**
 * find_env - find given environmental variable in linked list
 * @env: environmental variable linked list
 * @str: variable name
 * Return: idx of node in linked list
 */
int find_env(list_t *env, char *str)
{
	int j = 0, index = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->env_var_str)[j] == str[j]) /* find desired env variable */
			j++;
		if (str[j] == '\0') /* if matches entirely, break, return idx */
			break;
		env = env->next;
		index++;
	}
	if (env == NULL)
		return (-1);
	return (index);
}

/**
 * _unsetenv - remove node in environmental linked list
 * @env: linked list
 * @str: user's typed in command (e.g. "unsetenv MAIL")
 * Return: 0 on success
 */
int _unsetenv(list_t **env, char **str)
{
	int index = 0, j = 0;

	if (str[1] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}
	index = find_env(*env, str[1]); /* get idx of node to delete */
	free_double_ptr(str);
	if (index == -1) /* check if index errored */
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	j = delete_nodeint_at_index(env, index); /* delete node */
	if (j == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	return (0);
}

/**
 * _setenv - create or modify existing
 * environmental variable in linked list
 * @env: linked list
 * @str: user's typed in command (e.g. "setenv USER Superman")
 * Return: 0 on success, 1 on fail
 */
int _setenv(list_t **env, char **str)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;

	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}
	cat = _strdup(str[1]); /* concatenate strings to be new node data */
	cat = _strcat(cat, "=");
	cat = _strcat(cat, str[2]);
	index = find_env(*env, str[1]); /* find idx to traverse to node */
	if (index == -1)
	{
		add_end_node(env, cat); /* doesn't exist? create env var */
	}
	else
	{
		holder = *env;
		while (j < index)
		{
			holder = holder->next;
			j++;
		}
		free(holder->env_var_str);/*else free malloced data*/
		holder->env_var_str = _strdup(cat);/*assign to new malloced data*/
	}
	free(cat);
	free_double_ptr(str);
	return (0);
}

/**
 * c_setenv - custom _setenv by concatenating string first before setting
 * @env: environmental variable linked list
 * @name: environmental variable name (e.g. "OLDPWD")
 * @dir: directory path (e.g. "/home/vagrant/directory1")
 * Return: 0 on success (e.g. "OLDPWD=/home/vagrant/directory1")
 */
int c_setenv(list_t **env, char *name, char *dir)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;

	cat = _strdup(name); /* create new concatenated string */
	cat = _strcat(cat, "=");
	cat = _strcat(cat, dir);
	index = find_env(*env, name); /* get idx to env var in linked list */

	/* traverse to idx, free node data, reassign data */
	holder = *env;
	while (j < index)
	{
		holder = holder->next;
		j++;
	}
	free(holder->env_var_str);
	holder->env_var_str = _strdup(cat);
	free(cat);
	return (0);
}
