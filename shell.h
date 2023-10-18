#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

/**
 *struct map - This struct will map a command name to a function
 *
 *@command_name: This is the name of the command
 *@func: This will be the function that executes the command.
 */

typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;


/*This are our constants*/
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/*This  will be our first helper functions*/
char **__our_tokenizeinput(char *input_string, char *delim);
void __our_printedstring(char *string, int stream);
void __our_remove_newline(char *str);
void __our_strcpy_string_buffer(char *source, char *dest);
int __our_strlen_count_string(char *string);


/*This is our second helper functions*/
int __our_strcmp_comparestr(char *first, char *second);
char *__our_strcat_concatstr(char *destination, char *source);
int __our_strspn_prefixsubstr(char *str1, char *str2);
int __our_strcspn_computes_segment_str(char *str1, char *str2);
char *__our_strchr_locates_charstr(char *s, char c);

/*This will be our third helper functions*/
char *__our_strtok_tokenizestr(char *string, char *delim, char **save_ptr);
int __our_atoi_str_to_int(char *s);
void *__our_realloc_memoryblock(void *ptr,
		unsigned int old_size, unsigned int new_size);
void __our_ctrl_c_handler(int signum);
void __our_remove_comment_ignores(char *input);

/*This are some utilities functions called utils*/
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);

/*This are our built_in functions*/
void __our_env_currentenvirons(char **tokenized_command
		__attribute__((unused)));
void __our_quit_exit_shell(char **tokenized_command);

/*main*/
extern void __our_non_interactive(void);
extern void __our_initializer(char **current_command, int type_command);

#endif /*This is the end of our SHELL_H*/
