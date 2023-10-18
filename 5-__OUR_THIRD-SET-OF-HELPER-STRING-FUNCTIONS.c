#include "shell.h"


/**
 *__our_strtok_tokenizestr - This function will tokenizes some string
 *@string: This  will be the string to be tokenized
 *@delim: Our good old delimiter to be used to tokenize the string
 *@save_ptr: This is a pointer to be used to keep track of the next token
 *
 *Return: The next available token is returned.
 */
char *__our_strtok_tokenizestr(char *string, char *delim, char **save_ptr)
{
	char *finish;

	if (string == NULL)
		string = *save_ptr;

	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	string = string + __our_strspn_prefixsubstr(string, delim);
	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	finish = string + __our_strcspn_computes_segment_str(string, delim);
	if (*finish == '\0')
	{
		*save_ptr = finish;
		return (string);
	}

	*finish = '\0';
	*save_ptr = finish + 1;
	return (string);
}

/**
 * __our_atoi_str_to_int - This function will convvert string to an integer
 * @s: This will be string that is changed
 *
 * Return: converted int is returned.
 */
int __our_atoi_str_to_int(char *s)
{
	unsigned int m = 0;

	do {
		if (*s == '-')
			return (-1);
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0'  && *s <= '9')
			m = (m * 10) + (*s - '0');
		else if (m > 0)
			break;
	} while (*s++);
	return (m);
}

/**
 * __our_realloc_memoryblock - This function will reallocates a memory block
 * @ptr: This will be the pointer to
 * our memory previously allocated with a call to malloc
 * @old_size: This is the size of ptr
 * @new_size: This will be the size of the new memory to be allocated
 *
 * Return: The pointer to the address of the new memory block is returned
 */
void *__our_realloc_memoryblock(void *ptr,
		unsigned int old_size, unsigned int new_size)
{
	void *temp_block;
	unsigned int k;

	if (ptr == NULL)
	{
		temp_block = malloc(new_size);
		return (temp_block);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_block = malloc(new_size);
		if (temp_block != NULL)
		{
			for (k = 0; k < min(old_size, new_size); k++)
				*((char *)temp_block + k) = *((char *)ptr + k);
			free(ptr);
			return (temp_block);
		}
		else
			return (NULL);

	}
}

/**
 * __our_ctrl_c_handler - This function will handle the signal raised by CTRL-C
 * @signum: This is the signal number
 *
 * Return: void is returned
 */
void __our_ctrl_c_handler(int signum)
{
	if (signum == SIGINT)
		__our_printedstring("\n($) ", STDIN_FILENO);
}

/**
 * __our_remove_comment_ignores - This function will ignore
 * everything after a '#' char.
 * @input: This is the input to be used
 *
 * Return: void
 */
void __our_remove_comment_ignores(char *input)
{
	int k = 0;

	if (input[k] == '#')
		input[k] = '\0';
	while (input[k] != '\0')
	{
		if (input[k] == '#' && input[k - 1] == ' ')
			break;
		k++;
	}
	input[k] = '\0';
}


