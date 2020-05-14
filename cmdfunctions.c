#include "monty.h"
/**
 * mpush - function that push an item in top of the stack
 * @stack: double linked list
 * @num: number of the line
 */
void mpush(stack_t **stack, unsigned int num)
{
	stack_t *node = malloc(sizeof(stack_t));
	int i;
	char *command = strtok(NULL, DELIM);

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (command == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", num);
		exit(EXIT_FAILURE);
	}
	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[0] == '-' && i == 0)
			continue;
		if (isdigit(command[i]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", num);
			exit(EXIT_FAILURE);
		}
	}
	node->n = atoi(command);
	node->prev = NULL;
	node->next = NULL;

	if (*stack != NULL)
	{
		node->next = *stack;
		(*stack)->prev = node;
	}
	*stack = node;
}
/**
 * mpall - function that print the stack
 * @stack: double linked list
 * @num: number of the line
 */
void mpall(stack_t **stack, unsigned int num)
{
	stack_t *tmp = *stack;
	(void)num;

	if (tmp == NULL || *stack == NULL)
		return;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * mnop - function that does nothing
 * @stack: double linked list
 * @line_number: number of lines
 */
void mnop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
