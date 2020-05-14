#include "monty.h"
/**
 * free_node - frees a stack_t stack
 * @stack: stack to be freed
 * Return: void
 */
void free_node(stack_t **stack)
{
	stack_t *current;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}

/**
 * freestack - frees line and fp
 * @stack: stack to free
 * @line: line to free from getline
 * @fp: file pointer to free
 * Return: void
 */
void freestack(stack_t *stack, char *line, FILE *fp)
{
	if (stack != NULL)
		free_node(&stack);

	free(line);
	fclose(fp);
}
