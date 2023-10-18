#include "shell.h"

	char **commands = NULL;
	char *line = NULL;
	char *shell_name = NULL;
	int status = 0;

/**
 * main - This our main shell that is coded by -
 * Authors : DEVHYDAR
 * 			 MARWAN MAI
 * @argc: This are the number of arguments passed
 * @argv: This are the program arguments to be parsed
 *
 * applies the functions in utils and helpers
 * implements EOF
 * Prints error on Failure
 * Return: 0 on success is returned
 */


int main(int argc __attribute__((unused)), char **argv)
{
	

	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	signal(SIGINT, __our_ctrl_c_handler);
	shell_name = argv[0];
	while (1)
	{
		__our_non_interactive();
		__our_printedstring(" ($) ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			__our_remove_newline(line);
			__our_remove_comment_ignores(line);
			commands = __our_tokenizeinput(line, ";");

		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = __our_tokenizeinput(commands[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = parse_command(current_command[0]);

			__our_initializer(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);

	return (status);
}

	