#include "shell.h"

/**
 *env - This function will print the current - environnement
 *@tokenized_command: This is the command that is entered.
 *
 *Return: void is returned
 */

void __our_env_currentenvirons(char **tokenized_command
		__attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		__our_printedstring(environ[i], STDOUT_FILENO);
		__our_printedstring("\n", STDOUT_FILENO);
	}
}

/**
 * __our_quit_exit_shell - This function will exit or quit the shell
 * @tokenized_command: The command to be entered
 *
 * Return: void is returned
 */

void __our_quit_exit_shell(char **tokenized_command)
{
	int num_token = 0, arg;

	for (; tokenized_command[num_token] != NULL; num_token++)
		;
	if (num_token == 1)
	{
		free(tokenized_command);
		free(line);
		free(commands);
		exit(status);
	}
	else if (num_token == 2)
	{
		arg = __our_atoi_str_to_int(tokenized_command[1]);
		if (arg == -1)
		{
			__our_printedstring(shell_name, STDERR_FILENO);
			__our_printedstring(": 1: exit: Illegal number: ", STDERR_FILENO);
			__our_printedstring(tokenized_command[1], STDERR_FILENO);
			__our_printedstring("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(tokenized_command);
			free(commands);
			exit(arg);
		}
	}
	else
		__our_printedstring("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
