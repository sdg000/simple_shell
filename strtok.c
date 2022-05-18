#include "main.h"
#include <string.h>

/**
 * main - function starts here
 * _strtok_r - a function ...
 * buffer: the chaine
 * seperator: the chaine
 *
 * Return: 1 or 0
 */

int main(void)
{
	char buffer[] = "coming home again";
	char *seperator = buffer;
	char *token;

	while (token = strtok_r(seperator, " ", &seperator))
	{
		printf("%s\n", token);
	}

	return (0);
}
