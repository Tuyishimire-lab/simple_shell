#include "shell.h"
#include "ctrl_D.c"
#include "cntrl_c.c"
#include "builtin_hdl.c"
#include "space_ignr.c"

/**
 * prompt - repeatedly prompts user and executes user's cmds if applicable
 * @en: envrionmental variables
 * Return: 0 on success
 */
int prompt(char **en)
{
        list_t *env;
        size_t i = 0, n = 0;
        int command_line_no = 0, exit_stat = 0;
        char *command, *n_command, **token;

        env = env_linked_list(en);
        do {
                command_line_no++;
                if (isatty(STDIN_FILENO)) /* reprompt if in interactive shell */
                        write(STDOUT_FILENO, "$ ", 2);
                else
                        non_interactive(env);
                signal(SIGINT, ctrl_c); /* makes ctrl+c not work */
                command = NULL; i = 0; /* reset vars each time loop runs */
                i = get_line(&command); /* read user's cmd in stdin */
                ctrl_D(i, command, env); /* exits shell if ctrl-D */
                n_command = command;
                command = ignore_space(command);
                n = 0;
                while (command[n] != '\n') /* replace get_line's \n with \0 */
                        n++;
                command[n] = '\0';
                if (command[0] == '\0') /* reprompt if user hits enter only */
                {
                        free(n_command); continue;
                }
                token = NULL; token = _str_tok(command, " "); /*token user cmd*/
                if (n_command != NULL)
                        free(n_command);
                exit_stat = built_in(token, env, command_line_no, NULL);
                if (exit_stat)
                        continue;
                exit_stat = _execve(token, env, command_line_no);
        } while (1); /* keep on repeating till user exits shell */
        return (exit_stat);
}
