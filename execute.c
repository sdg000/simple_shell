#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"

/**
 * shell_1_0 - function
 *@cmd: the command input of user
 *@env: the environment
 *
 *Return: void
 */

void shell_1_0(char *cmd, char **env)
{
	if (_strcmp("env", cmd) == 0)
	{
		int i = 0;

		while (env[i] != NULL)
		{
			puts(env[i]);
			putchar('\n');
			i++;
		}
	}
}

/**
 * _executecmd - a function ...
 * @cmd: the chaine
 * @argc: the number of arguments
 * @argv: the programme arguments
 * @env: the environement programme execute
 *
 * Return: 1 or 0
 */

void	_executecmd(char **cmd, char **argv, char **env)
{
	int status, i = 0, exec_ret = 0;
	pid_t pid = 0;
	char *cmdsrc;

	shell_1_0(cmd[0], env);
	cmdsrc = (char *) malloc((_strlen(cmd[0]) + 6) * sizeof(char));

	if (strncmp("/bin/", cmd[0], 5) != 0)
		cmdsrc = _strcat(cmdsrc, "/bin/");
	cmdsrc = _strcat(cmdsrc, cmd[0]);
	pid = fork();
	if (pid < 0)
	{
		perror("Error:");
		return;
	}
	else if (pid == 0)
	{
		exec_ret = execve(cmdsrc, cmd, NULL);

		if (exec_ret < 0)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	/*_puts("\n");*/
	/*UNUSED(argc);*/
}
