#include "shell.h"


/**
 * built_in - handles builtins (exit, env, cd)
 * @token: user's typed command
 * @env: environmental variable
 * @num: take in nth user command typed to write error message
 * @command: bring in command to free
 * Return: 1 if acted on builtin, 0 if not
 */
int built_in(char **token, list_t *env, int num, char **command)
{
        int i = 0;

        /* if user types "exit", free cmd tokens, and exit */
        if (_strcmp(token[0], "exit") == 0)
        {
                i = __exit(token, env, num, command);
        }
        /* if user types "env", print, free cmd tokens, and reprompt */
        else if (_strcmp(token[0], "env") == 0)
        {
                _env(token, env);
                i = 1;
        }
        /* if user types "cd" , it will change directory */
        else if (_strcmp(token[0], "cd") == 0)
        {
                i = _cd(token, env, num);
        }
        /* if user types "setenv", create or modify linked list node */
        else if (_strcmp(token[0], "setenv") == 0)
        {
                _setenv(&env, token);
                i = 1;
        }
        /* if user types "setenv", remove linked list node */
        else if (_strcmp(token[0], "unsetenv") == 0)
        {
                _unsetenv(&env, token);
                i = 1;
        }
        return (i);
}
