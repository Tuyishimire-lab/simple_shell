![shellproject](https://user-images.githubusercontent.com/68068538/129479572-2b6a7e69-c9d1-442d-80f1-a8ea9655fd54.png)
# simple_shell
A shell in a linux operating system takes input from you in the form of command processes it , and gives an output. It is the interface through which the user works on the programs, commands, and scripts. A shell is accesed by a terminal which runs it.

**PURPOSE**

The purpose of the simple shell project is to understand:

>How a shell works

>PID and PPIDs

>How processes are created

>The three prototypes of a main

>How the shell uses PATH to find and execute programs

>The end of file condition

**_COMPILATION_**

gcc -Wall -Wextra -Werror -pendantic *.c -o shell

**CCOMMAND EXECUTION**

After receiving a command, the simple shell will tokenize it into words using "" as a delimiter. With consideration of the index of the user input where the first word will be considered as the command and the rest will be its arguments.

**FUNCTIONALITY AND SYSTEM CALLS**

read,exit,signal,write,malloc,wait,free,wait,getcwd,execve,chdir,eccess

**ABOUT FILES**

main.c ----- intrance into programm.

shell.h ---- prototypes of functions across all the c files.

prompt.c --- shell reprompting and execution

c_strtok.c == tokenizes PATH to include ":" as NULL, checks current dir

cd.c === changes directories

environ_ls.c === prints and creates linked list of environmental variables

execv.c === executes a free commmand and exits the program

exit.c === handles whenever the user types in exit

free_dptr.c ===  free double pointers

get_env.c ==== finds and copy all environmental variables which are available

getline.c === reads user's tyeped input from the buffer.

i_t_ostr.c ==== converts integer into strings to write error message.

link_ls.c ===  print and frees linked list

man_1_simple_shell === the manuall for using our simple shell project

non_intr.c ==== when shell is called out of shell/terminal

p_error.c === prints special error message for certain fails

realloc.c === handles reallocation

set_env.c === finds environmental variables set them and unset them

str_tok.c  === tokenizes user input and returns array

strcat.c ==== concatenates two strings

strcmp.c ==== compare two strings

strcpy.c === copies strings

strdup.c == string duplication

which.c === appends commands to PATHs, returns matches.
