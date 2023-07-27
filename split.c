#include "main.h"

/**
 * swap_char - swaps | and & for non-printed chars
 * @input: input string
 * @bool: type of swap
 * Return: swapped string
 */
char *swap_char(char *input, int bool)
{
	int j;

	if (bool == 0)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == '|')
			{
				if (input[j + 1] != '|')
					input[j] = 16;
				else
					j++;
			}

			if (input[j] == '&')
			{
				if (input[j + 1] != '&')
					input[j] = 12;
				else
					j++;
			}
		}
	}
	else
	{
		for (j = 0; input[j]; j++)
		{
			input[j] = (input[j] == 16 ? '|' : input[j]);
			input[j] = (input[j] == 12 ? '&' : input[j]);
		}
	}
	return (input);
}

/**
 * add_nodes - Add separators and command lines in the lists
 * @head_s: Head of separator list
 * @head_l: Head of command lines list
 * @input: Input string
 * Return: No return
 */
void add_nodes(sep_list **head_s, line_list **head_l, char *input)
{
	int j;
	char *line;

	input = swap_char(input, 0);

	for (j = 0; input[j]; j++)
	{
		if (input[j] == ';')
			add_sep_node_end(head_s, input[j]);

		if (input[j] == '|' || input[j] == '&')
		{
			add_sep_node_end(head_s, input[j]);
			j++;
		}
	}

	line = _strtok(input, ";|&");
	do {
		line = swap_char(line, 1);
		add_line_node_end(head_l, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);

}

/**
 * go_next - Go to the next command line stored
 * @list_s: Separator list
 * @list_l: Command line list
 * @datash: Data structure
 * Return: No return
 */
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash)
{
	int loop_sep;
	sep_list *ls_s;
	line_list *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (datash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - splits command lines according to
 * the separators ;, | and &, and executes them
 * @datash: data structure
 * @input: input string
 * Return: 0 to exit, 1 to continue
 */
int split_commands(data_shell *datash, char *input)
{

	sep_list *head_s, *list_s;
	line_list *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash->input = list_l->line;
		datash->args = split_line(datash->input);
		loop = exec_line(datash);
		free(datash->args);

		if (loop == 0)
			break;

		go_next(&list_s, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_list(&head_s);
	free_line_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_line - tokenizes the input string
 * @input: input string.
 * Return: string splitted.
 */
char **split_line(char *input)
{
	size_t bsize;
	size_t j;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (j = 1; token != NULL; j++)
	{
		if (j == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, j, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[j] = token;
	}

	return (tokens);
}
