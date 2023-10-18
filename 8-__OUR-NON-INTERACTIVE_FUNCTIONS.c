#include "shell.h"
/**
 * __our_non_interactive - This function will handle the non_interactive mode
 *
 * Return: void
 */
void __our_non_interactive(void)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &n, stdin) != -1)
		{
			__our_remove_newline(line);
			__our_remove_newline(line);
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
		exit(status);
	}
}
