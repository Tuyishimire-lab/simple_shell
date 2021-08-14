#include "shell.h"

/**
 * env_linked_list - creates a linked list from environmental variables
 * @env: environmental variables
 * Return: linked list
 */
list_t *env_linked_list(char **env)
{
        list_t *head;
        int i = 0;

        head = NULL;
        while (env[i] != NULL)
        {
                add_end_node(&head, env[i]);
                i++;
        }
        return (head);
}

/**
 * _env - prints environmental variables
 * @str: user's command into shell (i.e. "env")
 * @env: environmental variables
 * Return: 0 on success
 */
int _env(char **str, list_t *env)
{
        free_double_ptr(str); /* frees user input */
        print_list(env); /* prints env */
        return (0);
}

/**
 * c_strdup - custom string duplication; excludes beginning bytes
 * @str: string to duplicate (e.g. environmental variable PATH=/bin:/bin/ls)
 * @cs: number of bytes to exclude (e.g. excludes "PATH=")
 * Return: string (e.g. /bin:/bin/ls)
 */
char *c_strdup(char *str, int cs)
{
        char *duplicate_str;
        int i, len = 0;

        if (str == NULL) /* validate str input */
                return (NULL);

        /* calculate len + null terminator to malloc */
        while (*(str + len))
                len++;
        len++;

        /* allocate memory but exclude environmental variable title (PATH) */
        duplicate_str = malloc(sizeof(char) * (len - cs));
        if (duplicate_str == NULL)
                return (NULL);

        i = 0;
        while (i < (len - cs))
        {
                *(duplicate_str + i) = *(str + cs + i);
                i++;
        }
        return (duplicate_str);
}

/**
 * get_env - finds and returns a copy of the requested environmental variable
 * @str: string to store it in
 * @env: entire set of environmental variables
 * Return: copy of requested environmental variable
 */
char *get_env(char *str, list_t *env)
{
        int j = 0, cs = 0;

        while (env != NULL)
        {
                j = 0;
                while ((env->var)[j] == str[j]) /* find desired env variable */
                        j++;
                if (str[j] == '\0' && (env->var)[j] == '=')
                        break;
                env = env->next;
        }

        while (str[cs] != '\0') /* find how many bytes in env variable title */
                cs++;
        cs++; /*counts 1 more for = sign*/
        return (c_strdup(env->var, cs)); /* make a copy of variable w/o title */
}

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
                while ((env->var)[j] == str[j]) /* find desired env variable */
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
 * _setenv - create or modify existing environmental variable in linked list
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
                free(holder->var); /* else free malloced data */
                holder->var = _strdup(cat); /* assign to new malloced data */
        }
        free(cat);
        free_double_ptr(str);
        return (0);
}

