#include <stdio.h>
#include "shell.h"
#include <stdlib.h>
#include <string.h>


/**
 * add_nodeinstruction_end - a function ...
 * @head: the list
 * @str: the chaine
 *
 * Return: 1 or 0
 */

instruction_l *add_nodeinstrction_end(instrction_l **head, char *str)
{
	instrction_l *new, *ptr = *head;

	new =  malloc(sizeof(instrction_l));
	/*new->str = malloc(sizeof(char) * _strlen(str));*/
	new->str = strdup(str);

	if (new == NULL)
		return (NULL);

	new->str = str;
	new->next = NULL;

	if (ptr == NULL)
	{
		*head = new;
		return (*head);
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
	return (new);
}
