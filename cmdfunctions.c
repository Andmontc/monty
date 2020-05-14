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
	char *command = strtok(monty.args, " \t");

	command = strtok(NULL, " \t");
	if (node == NULL)
	{
		freestack(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (command == NULL || checkint(command) == -1)
	{
		free(node);
		freestack(stack);
		fprintf(stderr, "L%u: usage: push integer\n", num);
		exit(EXIT_FAILURE);
	}
	i = atoi(command);
	node->prev = NULL;
	node->n = i;

	if ((*stack) == NULL)
	{
		node->next = NULL;
		*stack = node;
	}
	else
	{
		node->next = *stack;
		node->next->prev = node;
		(*stack) = node;
	}
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
