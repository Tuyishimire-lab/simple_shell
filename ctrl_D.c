/**
 * ctrl_D - exits program if Ctrl-D was pressed
 * @i: characters read via get_line
 * @command: user's typed in command
 * @env: environmental variable linked list
 */
void ctrl_D(int i, char *command, list_t *env)
{
        if (i == 0) /* handles Ctrl+D */
        {
                free(command); /* exit with newline if in shell */
                free_linked_list(env);
                if (isatty(STDIN_FILENO))/* ctrl+d prints newline */
                        write(STDOUT_FILENO, "\n", 1);
                exit(0);
        }
}

