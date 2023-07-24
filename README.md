### simple_shell
This is a simple UNIX command interpreter that replicates the functionality of the shell.
This program was written entirely in C as a milestone project for the first sprint of the ALX Software engineering course.

After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl-D.

In non-interactive mode, echo your desired command and pipe it into the program like this:

```sh
echo "ls" | ./shell
```

In non-interactive mode, the program will exit after finishing your desired command(s).

### included commands
Our shell has support for the following built-in commands:

| Command             | Definition                                                                                |
| ------------------- | ----------------------------------------------------------------------------------------- |
| exit [n]            | Exit the shell, with an optional exit status, n.                                          |
| env                 | Print the environment.                                                                    |
| setenv [var][value] | Set an environment variable and value. If the variable exists, the value will be updated. |
| unsetenv [var]      | Remove an environment variable.                                                           |
| cd [dir]            | Change the directory.                

### Included files.
 main.c - functions for calling the shell and initializing the shell struct
- shell.c - functions for running the basic shell logic
- shell_helpers.c - functions for helping the shell run
- split_string.c - functions for splitting string from the user
- string_helpers1.c - functions for manipulating strings
- string_helpers2.c - functions for manipulating strings
- built_ins.c - functions for built-ins
- built_in_helpers.c - functions for helping the built-in functions
- help.c - functions for the help built-in
- help2.c - functions for the help built-in
- cd.c - functions for the cd built-in
- cd2.c - functions for the cd built-in
- \_getenv.c - functions for getting elements from the environment
- env.c - functions for the env, setenv, and unsetenv built-ins
- llfuncs1.c - linked list functions
- llfuncs2.c - linked list functions
- expansions.c - functions for dealing with the $? and $\$ expansions
- check_path.c - functions for checking the path of an executable
- error_handler.c - functions for dealing with errors
- free.c - functions for freeing allocated memory
- holberton.h - header file

The code is collectively written and compiled by [Mahmood(softmahmood@gmail.com)] and [Neverce(nevercekansiime@gmail.com)]
