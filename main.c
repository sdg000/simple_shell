#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <stdio.h>

/**
 * _arguments - a function
 * @str: string of characters
 * @arglist: the list of list argument
 * Return: the chaine
 */

char **_arguments(char *str, char **arglist, const char *seperator)
{
	char *cmd = _strdup(str);
	char *arg;
	/*const char *separator = " ";*/
	int i = 0;

	arg = _strtok(cmd, separator);
	while (arg != NULL)
	{
		arglist[i] = _strdup(arg);
		i++;
		arg = _strtok(NULL, separator);
	}
	arglist[i] = NULL;
	free(cmd);
	return (arglist);
}

/**
 * main - check the code
 *@argc: the number of the argument
 *@argv: the argument list of the table
 *@env:  the variable of the environement
 * Return: Always 0.
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0, status = 0, _len;
	char *arg_list[MAX_LINE];

	_puts("($) ");
	while ((read = _getline(&line, &len, stdin)) != -1)
	{
		_len = _strlen(line);
		line[_len - 1] = '\0';
		_puts("($) ");
		if (strncmp("exit", line, 4) == 0)
		{
			if (_len > 4)
				status = atoi(&line[5]);
			free(line);
			exit(status);
		}
		_executecmd(_arguments(line, arg_list), argc, argv, env);
	}

	if (line)
		free(line);

	UNUSED(argc);
	UNUSED(argv);
	UNUSED(env);
	UNUSED(i);
	UNUSED(arg_list);
	return (0);
}
