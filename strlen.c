#include "main.h"
/**
* _strlen - function
*
* @s: the chaine
* Return: Always 0.
*/

int _strlen(char *s)
{

	if (*s == '\0')
		return (0);
	else
		return (1 + _strlen(s + 1));
}

