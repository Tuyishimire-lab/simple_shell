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

**COMMAND EXECUTION**

After receiving a command, the simple shell will tokenize it into words using "" as a delimiter. With consideration of the index of the user input where the first word will be considered as the command and the rest will be its arguments.

**FUNCTIONALITY AND SYSTEM CALLS**

read,exit,signal,write,malloc,wait,free,wait,getcwd,execve,chdir,eccess

**ABOUT FILES**

main.c ----- intrance into programm.

shell.h ---- prototypes of functions across all the c files.

getline.c === reads user's tyeped input from the buffer.

man_1_simple_shell === the manuall for using our simple shell project



