#include "monty.h"
/**
 * freestack - Function that free the double linked list
 * @stack: double linked list
 */
void freestack(stack_t **stack)
{
	int i;
	stack_t *ptr = *stack;

	for (i = 0; ptr != NULL; i++)
	{
		(*stack) = (*stack)->next;
		free(ptr);
		ptr = *stack;
	}
	fclose(monty.file);
}
/**
 * checkint - function that check for integers
 * @str: line to check
 * Return: 0 integer -1 error
 */
int checkint(char *str)
{
	if (!str)
		return (-1);

	str = strtok(str, "\n");

	if (*str == '-')
	{
		str++;
		if (*str == '\0')
			return (-1);
	}


	while (*str)
	{

		if (isdigit(*str) == 0)
			return (-1);

		str++;
	}

	return (0);
}
