#include "shell.h"

/**
 * __our_tokenizeinput - This function will tokenize input
 * and it will store it into an array
 *@input_string: This will be our input to be parsed into it
 *@delim: This is our delimiter to be used which
 *needs to be a one character string
 *
 *Return: It will return array of tokens
 */

char **__our_tokenizeinput(char *input_string, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = __our_strtok_tokenizestr(input_string, delim, &save_ptr);

	while (token != NULL)
	{
		av = __our_realloc_memoryblock(av, sizeof(*av)
				* num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = __our_strtok_tokenizestr(NULL, delim, &save_ptr);
		num_delim++;
	}

	av = __our_realloc_memoryblock(av, sizeof(*av)
			* num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}

/**
 *__our_printedstring - This function will print a string to the stdout (1)
 *@string: This will be the string to be printed
 *@stream: This stream will allow us to print to the stdout
 *
 *Return: return nothing void
 */
void __our_printedstring(char *string, int stream)
{
	int k = 0;

	while (string[k] != '\0')
	{
		write(stream, &string[k], 1);
		k++;
	}
}

/**
 *__our_remove_newline - This fuunction will remove a new line from a string
 *@str: This is the string that will be used
 *
 *
 *Return: void
 */

void __our_remove_newline(char *str)
{
	int k = 0;

	while (str[k] != '\0')
	{
		if (str[k] == '\n')
			break;
		k++;
	}
	str[k] = '\0';
}

/**
 * __our_strcpy_string_buffer - This function will
 * copy a string to another buffer.
 * @source: This will be our source that it will copy from.
 * @dest: Here will be our destination to copy.
 *
 * Return: void returns nothing
 */

void __our_strcpy_string_buffer(char *source, char *dest)
{
	int k = 0;

	for (k = 0; source[k] != '\0'; k++)
		dest[k] = source[k];
	dest[k] = '\0';
}

/**
 *__our_strlen_count_string - This function will count length of a string
 *@string: This will be the string that is to be counted
 *
 * Return: it will return length of the string
 */

int __our_strlen_count_string(char *string)
{
	int mylength = 0;

	if (string == NULL)
		return (mylength);
	for (; string[mylength] != '\0'; mylength++)
		;
	return (mylength);
}
