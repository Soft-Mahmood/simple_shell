### Simple_Shell
This is a simple UNIX command interpreter that replicates the functionality of the shell.
This program was written entirely in C as a milestone project for the first sprint of the ALX Software engineering course.

After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl-D.

In non-interactive mode, echo your desired command and pipe it into the program like this:

```sh
echo "ls" | ./shell
```

In non-interactive mode, the program will exit after finishing your desired command(s).

### Included commands
Our shell has support for the following built-in commands:

| Command             | Definition                                                                                |
| ------------------- | ----------------------------------------------------------------------------------------- |
| exit                | Exit the shell, with an optional exit status, n.                                          |
| env                 | Print the environment.                                                                    |
| setenv [var][value] | Set an environment variable and value. If the variable exists, the value will be updated. |
| unsetenv [var]      | Remove an environment variable.                                                           |
| cd [dir]            | Change the directory.                                                                     |
| ls                  | list the contents of the current directory                                                |

### Included files.
- main.c - function for calling the shell and initializing the shell struct.
- shell.c - functions for running the basic shell logic in non-interactive mode.
- allocate.c - function for the allocation of memory.
- builtins.c - functions for builtin commands like ctrl + C, ctrl + D, etc.
- env.c - functions for manipulating the environment.
- envlist.c - functions for manipulating the environment struct linked list.
- execute.c - functions for built-in commands execute and exit.
- \_getline.c - function for reading the user's input.
- prompt.c - function to prompt the user for input.
- setenv.c - functions for manipulating environmental variables.
- cd.c - functions for the cd built-in.
- strcat_functions.c - inbuilt functions for concatenating strings.
- strdup_functions.c - inbuilt functions for duplicating strings.
- strtok1.c - string tokenizing functions.
- strtok2.c - string tokenizing functions.
- which.c - function for refreshing user commands before execution.
- other_str_fucntions.c - other builtin functions for string manipulation.
- errors.c - functions for dealing with errors
- shell.h - header file

### Credits
The code is collectively written and compiled by [Mahmood - softmahmood@gmail.com] and [Neverce - nevercekansiime@gmail.com]
