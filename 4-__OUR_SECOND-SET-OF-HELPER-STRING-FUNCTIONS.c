#include "shell.h"

/**
 *__our_strcmp_comparestr - This function will set to compare two strings
 *@first: This is our first string to compare
 *@second: This is our second string to compare
 *
 * Return: difference of the two strings is returned
 */

int __our_strcmp_comparestr(char *first, char *second)
{
	int j = 0;

	while (first[j] != '\0')
	{
		if (first[j] != second[j])
			break;
		j++;
	}
	return (first[j] - second[j]);
}

/**
 *__our_strcat_concatstr - This function will concat two strings
 *@destination: This the string to be concatenated to
 *@source: This is the string concatenated
 *
 * Return: address of the new string is returned
 */

char *__our_strcat_concatstr(char *destination, char *source)
{
	char *newest_string =  NULL;
	int len_dest = __our_strlen_count_string(destination);
	int len_source = __our_strlen_count_string(source);

	newest_string = malloc(sizeof(*newest_string) * (len_dest + len_source + 1));
	__our_strcpy_string_buffer(destination, newest_string);
	__our_strcpy_string_buffer(source, newest_string + len_dest);
	newest_string[len_dest + len_source] = '\0';
	return (newest_string);
}

/**
 *__our_strspn_prefixsubstr - This function will get
 *the length of a prefix substring.
 *@str1: This is the string to be searched
 *@str2: This is the string to be used
 *
 *Return: number of bytes in the initial segment
 *of 5 which are part of accept is returned
 */

int __our_strspn_prefixsubstr(char *str1, char *str2)
{
	int k = 0;
	int matchlink = 0;

	while (str1[k] != '\0')
	{
		if (__our_strchr_locates_charstr(str2, str1[k]) == NULL)
			break;
		matchlink++;
		k++;
	}
	return (matchlink);
}

/**
 *__our_strcspn_computes_segment_str - This function will
 *compute a segment of str1.
 *which will consist of characters not in str2
 *@str1: This is the string to be searched
 *@str2: This is the string to be used
 *
 *Return: index at which a char in str1 exists in str2 is returned
 */


int __our_strcspn_computes_segment_str(char *str1, char *str2)
{
	int length = 0;
	int l;

	for (l = 0; str1[l] != '\0'; l++)
	{
		if (__our_strchr_locates_charstr(str2, str1[l]) != NULL)
			break;
		length++;
	}
	return (length);
}


/**
 *__our_strchr_locates_charstr - This function will locate a char in a string
 *@s: This will be the string to be searched
 *@c: This will be the char that is checked
 *
 *Return: pointer to the first occurence of c in s is returned
 */

char *__our_strchr_locates_charstr(char *s, char c)
{
	int k = 0;

	for (; s[k] != c && s[k] != '\0'; k++)
		;
	if (s[k] == c)
		return (s + k);
	else
		return (NULL);
}

