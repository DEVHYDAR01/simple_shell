#include "shell.h"
/**
 * parse_command - This function will determine the type of the command
 * @command: our commands to be parsed.
 *
 * AUTHORS:MARWAN MAI & DEVHYDAR.
 * Description - EXTERNAL_COMMAND (1) represents commands like /bin/ls
 * INTERNAL_COMMAND (2) represents commands like exit, env
 * PATH_COMMAND (3) represents commands found in the PATH like ls
 * INVALID_COMMAND (-1) represents invalid commands
 *
 * Return: constant returning the type of command is returned.
 */
int parse_command(char *command)
{
	int i;
	char *internal_command[] = {"env", "exit", NULL};
	char *path = NULL;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (i = 0; internal_command[i] != NULL; i++)
	{
		if (__our_strcmp_comparestr(command, internal_command[i]) == 0)
			return (INTERNAL_COMMAND);
	}
	path = check_path(command);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}

	return (INVALID_COMMAND);
}

/**
 * execute_command - This function will execute
 * a command that is based on it's type
 * @tokenized_command: This is the tokenized form
 * of the command (ls -l == {ls, -l, NULL})
 * @command_type: This the type of the command
 *
 * Return: void is returned
 */
void execute_command(char **tokenized_command, int command_type)
{
	void (*func)(char **command);

	if (command_type == EXTERNAL_COMMAND)
	{
		if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == PATH_COMMAND)
	{
		if (execve(check_path(tokenized_command[0]), tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == INTERNAL_COMMAND)
	{
		func = get_func(tokenized_command[0]);
		func(tokenized_command);
	}
	if (command_type == INVALID_COMMAND)
	{
		__our_printedstring(shell_name, STDERR_FILENO);
		__our_printedstring(": 1: ", STDERR_FILENO);
		__our_printedstring(tokenized_command[0], STDERR_FILENO);
		__our_printedstring(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * check_path - This function will check wheather
 * a command is found in the PATH.
 * @command: This is the command to be used
 *
 * Return: path where the command is found in, NULL if not found is returned.
 */
char *check_path(char *command)
{
	char **path_array = NULL;
	char *temp, *temp2, *path_cpy;
	char *path = _getenv("PATH");
	int i;

	if (path == NULL || __our_strlen_count_string(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (__our_strlen_count_string(path) + 1));
	__our_strcpy_string_buffer(path, path_cpy);
	path_array = __our_tokenizeinput(path_cpy, ":");
	for (i = 0; path_array[i] != NULL; i++)
	{
		temp2 = __our_strcat_concatstr(path_array[i], "/");
		temp = __our_strcat_concatstr(temp2, command);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(path_array);
			free(path_cpy);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(path_cpy);
	free(path_array);
	return (NULL);
}

/**
 * get_func - This function will retrieve a function that is
 * based on the command given and a mapping
 * @command: This is the string to check against the mapping
 *
 * Return: pointer to the proper function, or null on fail is returned
 */
void (*get_func(char *command))(char **)
{
	int i;
	function_map mapping[] = {
		{"env", __our_env_currentenvirons}, {"exit", __our_quit_exit_shell}
	};

	for (i = 0; i < 2; i++)
	{
		if (__our_strcmp_comparestr(command, mapping[i].command_name) == 0)
			return (mapping[i].func);
	}
	return (NULL);
}

/**
 * _getenv - This function will get the value of an environment variable
 * @name: This is the name of the environment variable
 *
 * Return: the value of the variable as a string is returned
 */
char *_getenv(char *name)
{
	char **my_environ;
	char *pair_ptr;
	char *name_cpy;

	for (my_environ = environ; *my_environ != NULL; my_environ++)
	{
		for (pair_ptr = *my_environ, name_cpy = name;
		     *pair_ptr == *name_cpy; pair_ptr++, name_cpy++)
		{
			if (*pair_ptr == '=')
				break;
		}
		if ((*pair_ptr == '=') && (*name_cpy == '\0'))
			return (pair_ptr + 1);
	}
	return (NULL);
}
