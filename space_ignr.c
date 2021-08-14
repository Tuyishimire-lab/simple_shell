#include "shell.h"

/**
 *
 * ignore_space - returns string without spaces in front
 * @str: string
 * Return: a
new string
 */
char *ignore_space(char *str)
{
        while (*str == ' ')
                str++;
        return (str);
}
