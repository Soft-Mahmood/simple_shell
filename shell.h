#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <strings.h>
#include <signal.h>
#include <fcntl.h>
#include <wait.h>
#include <dirent.h>

/**
 * struct list - is a linked list for env variables
 * @env_var_str: holds env variables string
 * @next: points to the next node
 */
typedef struct list
{
	char *env_var_str;
	struct list *next;
} list_t;

size_t get_line(char **str);
char *_strcat(char *fnstr, char *instr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *fnstr, char *instr);
int _strcmp(char *str1, char *str2);
int prompt(char **en);
char *c_ignore(char *str);
void ctrl_D(int i, char *command, list_t *env);
void ctrl_c(int n);
int built_in(char **token, list_t *env, int num, char **command);
void free_linked_list(list_t *list);
int delete_nodeint_at_index(list_t **head, int index);
list_t *add_end_node(list_t **head, char *str);
size_t print_list(list_t *h);
void free_double_ptr(char **str);
char *_which(char *str, list_t *env);
int find_env(list_t *env, char *str);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);
char *get_env(char *str, list_t *env);
char *c_strdup(char *str, int cs);
list_t *env_linked_list(char **env);
int _env(char **str, list_t *env);
void not_found(char *str, int c_n, list_t *env);
void cant_cd_to(char *str, int c_n, list_t *env);
void illegal_number(char *str, int c_n, list_t *env);
char **c_str_tok(char *str, char *delm);
int c_t_size(char *str, char delm);
char *c_strcat(char *dest, char *src);
int c_setenv(list_t **env, char *name, char *dir);
void cd_home(list_t *env, char *current);
int cd_execute(list_t *env, char *current, char *dir, char *str, int num);
int _cd(char **str, list_t *env, int num);
int _execve(char **s, list_t *env, int num);
void c_exit(char **str, list_t *env);
int __exit(char **str, list_t *env, int num, char **command);
int c_atoi(char *s);
char *_strdup(char *str);
char **_str_tok(char *str, char *delm);
char *ignore_delm(char *str, char delm);
int t_size(char *str, char delm);
int t_strlen(char *str, int pos, char delm);
char *int_to_string(int number);
int numlen(int n);
void non_interactive(list_t *env);
char *c_ignore(char *str);
char *ignore_space(char *str);

#endif
