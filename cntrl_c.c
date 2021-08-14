#include "shell.h"

/**
 * ctrl_c - ignore Ctrl-C input and prints prompt again
 * @n: takes in int from signal
 */
void ctrl_c(int n)
{
        (void)n;
        write(STDOUT_FILENO, "\n$ ", 3);
}
