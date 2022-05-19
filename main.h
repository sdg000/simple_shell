#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#define UNUSED(x) (void)(x)
#define MAX_LINE 2024


/**
 * struct instruction_l - instruction linked list
 * @str: the string
 * @next: point to the nex node
 *
 * Description: instruction linked list node structure
 * for holberton project
 */
typedef struct instruction_l
{
	char *str;
	struct instruction_l *next;
} instruction_l;

int _putchar(char c);
int _strlen(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
void _executecmd(char **cmd, int argc, char **argv, char **env);
void ft_putnbr(int nb);
char *_strcat(char *dest, char *src);
char *_strtok(char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
instruction_l *add_nodeinstruction_end(instruction_l **head, char *str);
instruction_l **list_instrctions(instruction_l **head, char *str);
char *_strdup(char *src);

/*Realloc and assign lineptr*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
#endif
